#include "bst/bst.h"
#include "bst/debug.h"


static size_t
bst_arr_calculate_capacity(size_t capacity);


BST_API(bst_arr_t*)
bst_arr_new(size_t capacity, size_t item_size) {
    bst_arr_t *self;
    if (!(self = malloc(sizeof(*self))))
        return NULL;

    if (!bst_arr_init(self, capacity, item_size)) {
        free(self);

        return NULL;
    }

    return self;
}


BST_API(bst_arr_t*)
bst_arr_init(bst_arr_t *self, size_t capacity, size_t item_size) {
    if (!self || !item_size)
        return NULL;

    self->item_size = item_size;
    self->capacity = bst_arr_calculate_capacity(capacity);

    if (!(self->data = calloc(self->capacity, self->item_size)))
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
bst_arr_ptr(bst_arr_t *self, size_t index) {
    if (!self || index >= self->capacity)
        return NULL;

    return (void*)&self->data[index * self->item_size];
}


BST_API(size_t)
bst_arr_capacity(bst_arr_t *self) {
    if (!self)
        return 0;

    return self->capacity;
}


BST_API(size_t)
bst_arr_size(bst_arr_t *self) {
    if (!self)
        return 0;

    return self->capacity * self->item_size;
}


BST_API(size_t)
bst_arr_item_size(bst_arr_t *self) {
    if (!self)
        return 0;

    return self->item_size;
}


BST_API(void)
bst_arr_clear(bst_arr_t *self, size_t index, size_t count) {
    if (!self || index >= self->capacity)
        return;

    if (!count || count > self->capacity)
        count = self->capacity - index;

    memset(&self->data[index * self->item_size], 0, count * self->item_size);
}


BST_API(size_t)
bst_arr_insert(bst_arr_t *self, size_t index, size_t count, const void *ptr) {
    if (!self)
        return 0;

    if (index + count >= self->capacity) {
        if (!bst_arr_resize(self, self->capacity + count))
            return 0;
    }

    memmove(&self->data[index * self->item_size],
            (const uint8_t*)ptr,
            count * self->item_size);

    return count;
}


BST_API(void)
bst_arr_remove(bst_arr_t *self, size_t index) {
    if (!self || index >= self->capacity)
        return;

    bst_arr_clear(self, index, 1);
}


BST_API(size_t)
bst_arr_resize(bst_arr_t *self, size_t capacity) {
    uint8_t *data;
    if (!self)
        return 0;

    capacity = bst_arr_calculate_capacity(capacity);
    if (!(data = realloc(self->data, capacity * self->item_size)))
        return 0;

    if (capacity > self->capacity)
        memset(&data[self->capacity * self->item_size],
               0,
               (capacity - self->capacity) * self->item_size);

    self->data = data;
    self->capacity = capacity;

    return capacity;
}


/* internal */

static size_t
bst_arr_calculate_capacity(size_t capacity) {
    size_t n;

    if (!capacity)
        return BST_ARR_DEFAULT_CAPACITY;

    n = capacity / BST_ARR_DEFAULT_CAPACITY;

    if (capacity % BST_ARR_DEFAULT_CAPACITY)
        ++n;

    return n * BST_ARR_DEFAULT_CAPACITY;
}
