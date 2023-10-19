#include "bst/bst.h"
#include "bst/debug.h"


static size_t
bst_str_calculate_chunk_size(size_t size);


BST_API(bst_str_t*)
bst_str_new(size_t length, const char *buffer) {
    size_t size;
    bst_str_t *self;

    if (!(self = malloc(sizeof(*self))))
        return NULL;

    size = 0;

    if (buffer && !length)
        length = strlen(buffer);

    if (length)
        size = length + 1;

    self->size = bst_str_calculate_chunk_size(size);
    self->length = 0;

    if (!(self->data = malloc(self->size)))
        goto error;

    self->data[0] = 0;

    if (buffer && bst_str_write(self, buffer, 0, length) != length)
        goto error;

    return self;

error:
    bst_str_free(self);

    return NULL;
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
bst_str_from_file(FILE *file, int length) {
    bst_str_t *self;
    long offset, size;
    if (!file || length < 0 || (offset = ftell(file)) == -1)
        return NULL;

    if (!length) {
        if (fseek(file, 0, SEEK_END) || (size = ftell(file)) == -1)
            return NULL;

        if (fseek(file, offset, SEEK_SET))
            return NULL;

        length = (int)size;
    }

    if (!(self = bst_str_new((size_t)length, NULL)))
        return NULL;

    if (!fgets(self->data, length + 1, file)) {
        bst_str_free(self);

        return NULL;
    }

    return self;
}


BST_API(void)
bst_str_free(bst_str_t *self) {
    free(self->data);
    free(self);
}


BST_API(bst_str_t*)
bst_str_copy(bst_str_t *self, size_t offset, size_t length) {
    if (!self || offset >= self->length || offset + length > self->length)
        return NULL;

    if (!length)
        length = self->length - offset;

    return bst_str_new(length, &self->data[offset]);
}


BST_API(void)
bst_str_clear(bst_str_t *self) {
    if (!self)
        return;

    self->length = 0;
    self->data[0] = 0;
}


BST_API(char*)
bst_str_ptr(bst_str_t *self, size_t offset) {
    if (!self || offset >= self->length)
        return NULL;

    return &self->data[offset];
}


BST_API(size_t)
bst_str_length(bst_str_t *self) {
    if (!self)
        return 0;

    return self->length;
}


BST_API(size_t)
bst_str_write(bst_str_t *self, const char *buffer, size_t offset, size_t length) {
    size_t size;
    char *data;
    if (!self || !buffer)
        return 0;

    if (!length)
        length = strlen(buffer);

    if (self->length + length + 1 > self->size) {
        size = bst_str_calculate_chunk_size(self->length + length + 1);
        if (!(data = realloc(self->data, size)))
            return 0;

        self->data = data;
        self->size = size;
    }

    strncpy(&self->data[self->length], &buffer[offset], length);

    self->length += length;
    self->data[self->length] = 0;

    return length;
}


BST_API(size_t)
bst_str_line_offset(bst_str_t *self, size_t offset) {
    size_t n;
    if (!self || offset >= self->length)
        return 0;

    for (n = offset; n < self->length; ++n) {
        if (self->data[n] == '\n') {
            return n + 1;
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
    if (!self)
        return NULL;

    for (n = 0; n < self->length && isspace((int)self->data[n]); ++n);

    offset = n;

    if (!offset)
        return self;

    self->length -= offset;

    for (n = 0, m = offset; n < self->length; ++n, ++m) {
        self->data[n] = self->data[m];
    }

    self->data[self->length] = 0;

    return self;
}


BST_API(bst_str_t*)
bst_str_trim_right(bst_str_t *self) {
    size_t n;
    if (!self || !self->length)
        return self;

    for (n = 1; n < self->length; ++n) {
        if (!isspace((int)self->data[self->length - n]))
            break;
    }

    self->length -= n - 1;
    self->data[self->length] = 0;

    return self;
}


/* internal */

static size_t
bst_str_calculate_chunk_size(size_t size) {
    size_t n;

    if (!size)
        return BST_STR_DEFAULT_SIZE;

    n = size / BST_STR_DEFAULT_SIZE;

    if (size % BST_STR_DEFAULT_SIZE)
        ++n;

    return n * BST_STR_DEFAULT_SIZE;
}
