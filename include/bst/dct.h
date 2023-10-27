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

typedef struct bst_dct_kv {
    bst_str_t key;
    void *value;
} bst_dct_kv_t;


BST_API(bst_dct_t*)
bst_dct_new(size_t capacity, bst_dct_free_func_t free_func);

BST_API(bst_dct_t*)
bst_dct_init(bst_dct_t *self, size_t capacity, bst_dct_free_func_t free_func);

BST_API(void)
bst_dct_deinit(bst_dct_t *self);

BST_API(void)
bst_dct_free(bst_dct_t *self);

BST_API(size_t)
bst_dct_count(bst_dct_t *self);

BST_API(void*)
bst_dct_set(bst_dct_t *self, bst_str_t *key, void *value);

BST_API(void*)
bst_dct_setc(bst_dct_t *self, char *key, void *value);

BST_API(void*)
bst_dct_get(bst_dct_t *self, bst_str_t *key);

BST_API(void*)
bst_dct_getc(bst_dct_t *self, char *key);

BST_API(void)
bst_dct_del(bst_dct_t *self, bst_str_t *key);

BST_API(void)
bst_dct_delc(bst_dct_t *self, char *key);

BST_API(bst_dct_kv_t*)
bst_dct_iter(bst_dct_t *self);

BST_API(bst_dct_kv_t*)
bst_dct_next(bst_dct_t *self, bst_dct_kv_t *kv);

#endif
