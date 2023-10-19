#include "bst/bst.h"
#include "bst/debug.h"


BST_API(bst_str_t*)
bst_str_new(size_t length, const char *buffer) {
    bst_str_t *self;
    if (buffer && !length)
        length = strlen(buffer);

    if (!(self = bst_lst_new(1, length + 1, NULL)))
        return NULL;

    if (buffer && bst_str_write(self, 0, length, buffer) != length) {
        bst_str_free(self);

        return NULL;
    }

    return self;
}


BST_API(bst_str_t*)
bst_str_from_path(const char *path) {
    FILE *file;
    bst_str_t *self;
    if (!(file = fopen(path, "r")))
        return NULL;

    self = bst_str_from_file(file, 0);

    fclose(file);

    return self;
}


BST_API(bst_str_t*)
bst_str_from_file(FILE *file, size_t length) {
    bst_str_t *self;
    long offset, size;
    if (!file || (offset = ftell(file)) == -1)
        return NULL;

    /* determine length from current file position if no length is provided */
    if (!length) {
        if (fseek(file, 0, SEEK_END) || (size = ftell(file)) == -1)
            return NULL;

        if (fseek(file, offset, SEEK_SET))
            return NULL;

        length = (size_t)size;
    }

    if (!(self = bst_str_new(length, NULL)))
        return NULL;

    /* fgets reads one less than the provided length and writes null byte */
    if (!fgets(bst_str_ptr(self, 0), (int)(length + 1), file)) {
        bst_str_free(self);

        return NULL;
    }

    return self;
}


BST_API(void)
bst_str_free(bst_str_t *self) {
    bst_lst_free(self);
}


BST_API(bst_str_t*)
bst_str_copy(bst_str_t *self, size_t offset, size_t length) {
    char *ptr;
    if (!self || !(ptr = bst_str_ptr(self, offset)))
        return NULL;

    if (!length || offset + length >= self->length - 1)
        length = self->length - 1 - offset;

    return bst_str_new(length, bst_str_ptr(self, offset));
}


BST_API(void)
bst_str_clear(bst_str_t *self) {
    if (!self)
        return;

    bst_arr_clear(&self->elements, 0, self->length);

    self->length = 0;
}


BST_API(char*)
bst_str_ptr(bst_str_t *self, size_t offset) {
    if (!self || offset >= self->length)
        return NULL;

    return (char*)bst_lst_get(self, offset);
}


BST_API(size_t)
bst_str_length(bst_str_t *self) {
    if (!self)
        return 0;

    return self->length;
}


BST_API(size_t)
bst_str_write(bst_str_t *self,
              size_t offset,
              size_t length,
              const char *buffer) {
    char c;
    if (!self || !buffer)
        return 0;

    if (!length)
        length = strlen(buffer);

    length = bst_arr_insert(&self->elements,
                            self->length,
                            length,
                            &buffer[offset]);
    if (!length) {
        return 0;
    }

    c = 0;
    self->length += length;

    if (!bst_arr_insert(&self->elements, self->length, 1, &c))
        return 0;

    return length;
}


BST_API(size_t)
bst_str_line_offset(bst_str_t *self, size_t offset) {
    size_t n;
    char *buffer;
    if (!self || !(buffer = bst_str_ptr(self, offset)))
        return 0;

    for (n = 0; n < self->length - offset; ++n) {
        if (buffer[n] == '\n') {
            return offset + n + 1;
        }
    }

    return self->length;
}


BST_API(size_t)
bst_str_line_length(bst_str_t *self, size_t offset) {
    size_t length;
    if ((length = bst_str_line_offset(self, offset)) < offset)
        return 0;

    return length - offset;
}


BST_API(bst_str_t*)
bst_str_trim(bst_str_t *self) {
    return bst_str_trim_right(bst_str_trim_left(self));
}


BST_API(bst_str_t*)
bst_str_trim_left(bst_str_t *self) {
    size_t offset, n, m;
    char *buffer;
    if (!self || !(buffer = bst_str_ptr(self, 0)))
        return NULL;

    for (n = 0; n < self->length && isspace((int)buffer[n]); ++n);

    offset = n;

    if (!offset)
        return self;

    self->length -= offset;

    for (n = 0, m = offset; n < self->length; ++n, ++m) {
        buffer[n] = buffer[m];
    }

    buffer[self->length] = 0;

    return self;
}


BST_API(bst_str_t*)
bst_str_trim_right(bst_str_t *self) {
    size_t n;
    char *buffer;
    if (!self || !self->length || !(buffer = bst_str_ptr(self, 0)))
        return self;

    for (n = 1; n < self->length; ++n) {
        if (!isspace((int)buffer[self->length - n]))
            break;
    }

    self->length -= n - 1;
    buffer[self->length] = 0;

    return self;
}
