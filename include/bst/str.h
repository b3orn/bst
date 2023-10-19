/*
 * str.h
 *
 * dynamic string
 *
 */

#ifndef BST_STR_H
#define BST_STR_H

#define BST_STR_DEFAULT_SIZE 256


typedef struct bst_str {
    size_t size;
    size_t length;
    char *data;
} bst_str_t;


BST_API(bst_str_t*)
bst_str_new(size_t length, const char *buffer);

BST_API(bst_str_t*)
bst_str_from_path(const char *path);

BST_API(bst_str_t*)
bst_str_from_file(FILE *file, int length);

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
bst_str_write(bst_str_t *self, const char *buffer, size_t offset, size_t length);

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

#endif
