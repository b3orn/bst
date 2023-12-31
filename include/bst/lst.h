/*
 * lst.h
 *
 * dynamic list
 *
 * - based on bst_arr_t from bst/arr.h
 * - copies elements
 */

#ifndef BST_LST_H
#define BST_LST_H


typedef void (*bst_lst_free_func_t)(void *ptr);

typedef struct bst_lst {
    bst_arr_t elements;
    size_t length;
    bst_lst_free_func_t free_func;
} bst_lst_t;


BST_API(bst_lst_t*)
bst_lst_new(size_t capacity, size_t item_size, bst_lst_free_func_t free_func);

BST_API(bst_lst_t*)
bst_lst_init(bst_lst_t *self,
             size_t capacity,
             size_t item_size,
             bst_lst_free_func_t free_func);

BST_API(void)
bst_lst_deinit(bst_lst_t *self);

BST_API(void)
bst_lst_free(bst_lst_t *self);

BST_API(size_t)
bst_lst_length(bst_lst_t *self);

BST_API(void*)
bst_lst_append(bst_lst_t *self, void *item);

BST_API(void*)
bst_lst_insert(bst_lst_t *self, size_t index, void *item);

BST_API(void*)
bst_lst_get(bst_lst_t *self, size_t index);

BST_API(void)
bst_lst_remove(bst_lst_t *self, size_t index);

#endif
