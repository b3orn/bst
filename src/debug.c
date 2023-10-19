#include "bst/bst.h"
#ifdef BST_DEBUG_MEMORY
#undef BST_DEBUG_MEMORY
#endif
#include "bst/debug.h"


BST_API(void*)
bst_debug_malloc(char *filename, size_t line, size_t size) {
    uint8_t *ptr;

    ptr = malloc(size);

    fprintf(stderr, "BST MEM DEBUG %s:%zu malloc(%zu) = %p\n",
            filename,
            line,
            size,
            (void*)ptr);

    return (void*)ptr;
}


BST_API(void*)
bst_debug_calloc(char *filename, size_t line, size_t n, size_t size) {
    uint8_t *ptr;

    ptr = calloc(n, size);

    fprintf(stderr, "BST MEM DEBUG %s:%zu calloc(%zu, %zu) = %p\n",
            filename,
            line,
            n,
            size,
            (void*)ptr);

    return (void*)ptr;
}


BST_API(void*)
bst_debug_realloc(char *filename, size_t line, void *ptr, size_t size) {
    void *ptr2;

    ptr2 = realloc(ptr, size);

    fprintf(stderr, "BST MEM DEBUG %s:%zu realloc(%p, %zu) = %p\n",
            filename,
            line,
            (void*)ptr,
            size,
            ptr2);

    return ptr2;
}


BST_API(void)
bst_debug_free(char *filename, size_t line, void *ptr) {
    fprintf(stderr, "BST MEM DEBUG %s:%zu free(%p)\n",
            filename,
            line,
            (void*)ptr);
    free(ptr);
}
