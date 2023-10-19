#include "bst/bst.h"
#define BST_DEBUG_MEMORY
#include "bst/debug.h"


BST_API(bst_lst_t*)
bst_lst_new(size_t item_size, size_t length, bst_lst_free_func_t free_func) {
    bst_lst_t *self;
    if (!item_size || !(self = malloc(sizeof(*self))))
        return NULL;

    if (!bst_arr_init(&self->elements, item_size, length)) {
        free(self);

        return NULL;
    }

    self->free_func = free_func;
    self->length = 0;

    return self;
}


BST_API(void)
bst_lst_free(bst_lst_t *self) {
    size_t i;
    if (!self)
        return;

    if (self->free_func) {
        for (i = 0; i < self->length; ++i) {
            self->free_func(bst_lst_get(self, i));
        }
    }

    bst_arr_deinit(&self->elements);
    free(self);
}


BST_API(size_t)
bst_lst_length(bst_lst_t *self) {
    if (!self)
        return 0;

    return self->length;
}


BST_API(void*)
bst_lst_append(bst_lst_t *self, void *item) {
    if (!self || !item)
        return NULL;

    if (!bst_arr_insert(&self->elements, self->length, 1, item))
        return NULL;

    ++self->length;

    return item;
}


BST_API(void*)
bst_lst_insert(bst_lst_t *self, size_t index, void *item) {
    if (!self || !item || index >= self->length)
        return NULL;

    if (!bst_arr_insert(&self->elements, index, 1, item))
        return NULL;

    return item;
}


BST_API(void*)
bst_lst_get(bst_lst_t *self, size_t index) {
    if (!self)
        return NULL;

    return bst_arr_get(&self->elements, index);
}


BST_API(void)
bst_lst_remove(bst_lst_t *self, size_t index) {
    if (!self || index >= self->length)
        return;

    if (self->free_func)
        self->free_func(bst_lst_get(self, index));

    if (index == self->length - 1) {
        bst_arr_remove(&self->elements, index);

        --self->length;

        return;
    }

    bst_arr_insert(&self->elements,
                   index,
                   self->length - index - 1,
                   bst_arr_ptr(&self->elements, index + 1));
    bst_arr_remove(&self->elements, self->length - 1);

    --self->length;
}
