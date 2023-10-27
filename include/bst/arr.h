/*
 * arr.h
 *
 * resizeable array
 *
 * - added elements are copied
 * - pointers to elements of the array can only be considered valid until the
 *   array is resized or a new element is inserted
 * - if you put pointers to something on the heap in the array it's your
 *   responsability to clean it up
 * 
 */

#ifndef BST_ARR_H
#define BST_ARR_H

#define BST_ARR_DEFAULT_CAPACITY 16


typedef struct bst_arr {
    uint8_t *data;
    size_t capacity;
    size_t item_size;
} bst_arr_t;


/*
 * allocates an array of `capacity` number of `item_size` items
 */
BST_API(bst_arr_t*)
bst_arr_new(size_t capacity, size_t item_size);

BST_API(bst_arr_t*)
bst_arr_init(bst_arr_t *self, size_t capacity, size_t item_size);

BST_API(void)
bst_arr_deinit(bst_arr_t *self);

BST_API(void)
bst_arr_free(bst_arr_t *self);

BST_API(void*)
bst_arr_ptr(bst_arr_t *self, size_t index);

/*
 * returns allocated number of elements, may be larger than what was specified
 */
BST_API(size_t)
bst_arr_capacity(bst_arr_t *self);

/*
 * returns total allocated size = capacity * item_size
 */
BST_API(size_t)
bst_arr_size(bst_arr_t *self);

BST_API(size_t)
bst_arr_item_size(bst_arr_t *self);

/*
 * clear count item_size items starting at index
 */
BST_API(void)
bst_arr_clear(bst_arr_t *self, size_t index, size_t count);

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

/*
 * resizes the array
 * returns either the new total size or 0 in case of an error
 */
BST_API(size_t)
bst_arr_resize(bst_arr_t *self, size_t capacity);

#endif
