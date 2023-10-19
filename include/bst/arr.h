/*
 * arr.h
 *
 * resizeable array
 *
 * - pointers to elements of the array can only be considered valid until the
 *   array is resized or a new element is inserted
 * - if you put pointers to something on the heap in the array it's your
 *   responsability to clean it up
 * 
 */

#ifndef BST_ARR_H
#define BST_ARR_H

#define BST_ARR_DEFAULT_LENGTH 16


typedef struct bst_arr {
    size_t item_size;
    size_t length;
    uint8_t *data;
} bst_arr_t;


/*
 * allocates an array of length number of item_size items
 */
BST_API(bst_arr_t*)
bst_arr_new(size_t item_size, size_t length);

BST_API(bst_arr_t*)
bst_arr_init(bst_arr_t *self, size_t item_size, size_t length);

BST_API(void)
bst_arr_deinit(bst_arr_t *self);

BST_API(void)
bst_arr_free(bst_arr_t *self);

BST_API(void*)
bst_arr_ptr(bst_arr_t *self, size_t offset);

/*
 * returns allocated number of elements
 */
BST_API(size_t)
bst_arr_length(bst_arr_t *self);

/*
 * returns total allocated size = length * item_size
 */
BST_API(size_t)
bst_arr_size(bst_arr_t *self);

BST_API(size_t)
bst_arr_item_size(bst_arr_t *self);

/*
 * clear count item_size items starting at offset
 */
BST_API(void)
bst_arr_clear(bst_arr_t *self, size_t offset, size_t count);

/*
 * insert count item_size items starting at index
 */
BST_API(size_t)
bst_arr_insert(bst_arr_t *self, size_t index, size_t count, const void *ptr);

/*
 * 
 */
BST_API(void)
bst_arr_remove(bst_arr_t *self, size_t index);

BST_API(void*)
bst_arr_get(bst_arr_t *self, size_t index);

/*
 * resizes the array
 * returns either the new total size or 0 in case of an error
 */
BST_API(size_t)
bst_arr_resize(bst_arr_t *self, size_t length);

#endif
