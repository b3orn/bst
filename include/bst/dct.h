/*
 * dct.h
 *
 * dictionary
 *
 */

#ifndef BST_DCT_H
#define BST_DCT_H

typedef void (*bst_dct_free_func_t)(void *ptr);

typedef struct bst_dct {
    bst_arr_t elements;
    size_t count;
    bst_dct_free_func_t free_func;
} bst_dct_t;


BST_API(bst_dct_t*)
bst_dct_new(size_t size, bst_dct_free_func_t free_func);

BST_API(void)
bst_dct_free(bst_dct_t *self);

BST_API(size_t)
bst_dct_count(bst_dct_t *self);

BST_API(void*)
bst_dct_set(bst_dct_t *self, char *key, void *value);

BST_API(void*)
bst_dct_get(bst_dct_t *self, char *key);

BST_API(void)
bst_dct_del(bst_dct_t *self, char *key);

#endif
