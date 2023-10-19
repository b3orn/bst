/*
 * debug.h
 *
 * debugging tools
 *
 */

#ifndef BST_DEBUG_H
#define BST_DEBUG_H

#ifdef BST_DEBUG_ENABLED

#ifdef BST_DEBUG_MEMORY

#define malloc(size) bst_debug_malloc(__FILE__, __LINE__, size)

#define calloc(n, size) bst_debug_calloc(__FILE__, __LINE__, n, size)

#define realloc(ptr, size) bst_debug_realloc(__FILE__, __LINE__, ptr, size)

#define free(ptr) bst_debug_free(__FILE__, __LINE__, ptr)

#endif

#endif


BST_API(void*)
bst_debug_malloc(char *filename, size_t line, size_t size);

BST_API(void*)
bst_debug_calloc(char *filename, size_t line, size_t n, size_t size);

BST_API(void*)
bst_debug_realloc(char *filename, size_t line, void *ptr, size_t size);

BST_API(void)
bst_debug_free(char *filename, size_t line, void *ptr);

#endif
