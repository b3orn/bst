#include "bst/bst.h"
#define BST_DEBUG_MEMORY
#include "bst/debug.h"


static size_t
bst_arr_calculate_length(size_t length);


BST_API(bst_arr_t*)
bst_arr_new(size_t item_size, size_t length) {
    bst_arr_t *self;
    if (!(self = malloc(sizeof(*self))))
        return NULL;

    if (!bst_arr_init(self, item_size, length)) {
        free(self);

        return NULL;
    }

    return self;
}


BST_API(bst_arr_t*)
bst_arr_init(bst_arr_t *self, size_t item_size, size_t length) {
    if (!self || !item_size)
        return NULL;

    self->item_size = item_size;
    self->length = bst_arr_calculate_length(length);

    if (!(self->data = calloc(self->length, self->item_size)))
        return NULL;

    return self;
}


BST_API(void)
bst_arr_deinit(bst_arr_t *self) {
    if (!self)
        return;

    free(self->data);
}


BST_API(void)
bst_arr_free(bst_arr_t *self) {
    bst_arr_deinit(self);
    free(self);
}


BST_API(void*)
bst_arr_ptr(bst_arr_t *self, size_t offset) {
    if (!self || offset >= self->length)
        return NULL;

    return (void*)&self->data[offset * self->item_size];
}


BST_API(size_t)
bst_arr_length(bst_arr_t *self) {
    if (!self)
        return 0;

    return self->length;
}


BST_API(size_t)
bst_arr_size(bst_arr_t *self) {
    if (!self)
        return 0;

    return self->length * self->item_size;
}


BST_API(size_t)
bst_arr_item_size(bst_arr_t *self) {
    if (!self)
        return 0;

    return self->item_size;
}


BST_API(void)
bst_arr_clear(bst_arr_t *self, size_t offset, size_t count) {
    if (!self || offset >= self->length)
        return;

    if (!count || count > self->length)
        count = self->length - offset;

    memset(&self->data[offset * self->item_size], 0, count * self->item_size);
}


BST_API(size_t)
bst_arr_insert(bst_arr_t *self, size_t index, size_t count, const void *ptr) {
    if (!self)
        return 0;

    if (index + count >= self->length) {
        if (!bst_arr_resize(self, self->length + count))
            return 0;
    }

    memmove(&self->data[index * self->item_size],
            (const uint8_t*)ptr,
            count * self->item_size);

    return count;
}


BST_API(void)
bst_arr_remove(bst_arr_t *self, size_t index) {
    if (!self || index >= self->length)
        return;

    bst_arr_clear(self, index, 1);
}


BST_API(void*)
bst_arr_get(bst_arr_t *self, size_t index) {
    if (!self || index >= self->length)
        return NULL;

    return (void*)&self->data[index * self->item_size];
}


BST_API(size_t)
bst_arr_resize(bst_arr_t *self, size_t length) {
    uint8_t *data;
    if (!self)
        return 0;

    length = bst_arr_calculate_length(length);
    if (!(data = realloc(self->data, length * self->item_size)))
        return 0;

    if (length > self->length)
        memset(&data[self->length * self->item_size],
               0,
               (length - self->length) * self->item_size);

    self->data = data;
    self->length = length;

    return length;
}


/* internal */

static size_t
bst_arr_calculate_length(size_t length) {
    size_t n;

    if (!length)
        return BST_ARR_DEFAULT_LENGTH;

    n = length / BST_ARR_DEFAULT_LENGTH;

    if (length % BST_ARR_DEFAULT_LENGTH)
        ++n;

    return n * BST_ARR_DEFAULT_LENGTH;
}
