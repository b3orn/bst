/*
 * str.h
 *
 * dynamic string
 *
 */

#ifndef BST_STR_H
#define BST_STR_H


typedef bst_lst_t bst_str_t;


BST_API(bst_str_t*)
bst_str_new(size_t length, const char *buffer);

BST_API(bst_str_t*)
bst_str_init(bst_str_t *self, size_t length, const char *buffer);

BST_API(bst_str_t*)
bst_str_from_path(const char *path);

BST_API(bst_str_t*)
bst_str_from_file(FILE *file, size_t length);

BST_API(void)
bst_str_deinit(bst_str_t *self);

BST_API(void)
bst_str_free(bst_str_t *self);

BST_API(bst_str_t*)
bst_str_copy(bst_str_t *self, size_t offset, size_t length);

BST_API(void)
bst_str_clear(bst_str_t *self);

BST_API(char*)
bst_str_ptr(bst_str_t *self, size_t offset);

BST_API(size_t)
bst_str_length(bst_str_t *self);

BST_API(size_t)
bst_str_write(bst_str_t *self,
              size_t offset,
              size_t length,
              const char *buffer);

BST_API(size_t)
bst_str_line_offset(bst_str_t *self, size_t offset);

BST_API(size_t)
bst_str_line_length(bst_str_t *self, size_t offset);

BST_API(bst_str_t*)
bst_str_trim(bst_str_t *self);

BST_API(bst_str_t*)
bst_str_trim_left(bst_str_t *self);

BST_API(bst_str_t*)
bst_str_trim_right(bst_str_t *self);

/*
 * compares the first length chars
 */
BST_API(bool)
bst_str_eq(bst_str_t *self, size_t length, bst_str_t *other);

BST_API(bool)
bst_str_eqc(bst_str_t *self, size_t length, char *buffer);

#endif
