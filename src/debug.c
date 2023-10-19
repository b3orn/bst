#include "bst/bst.h"
#ifdef BST_DEBUG_MEMORY
#undef BST_DEBUG_MEMORY
#endif
#include "bst/debug.h"


BST_API(void*)
bst_debug_malloc(char *filename, size_t line, size_t size) {
    uint8_t *ptr;

    if(!(ptr = malloc(size + 3 * sizeof(size_t)))) {
        fprintf(stderr, "BST MEM DEBUG %s:%zu malloc(%zu) = NULL\n",
                filename,
                line,
                size);

        return NULL;
    }

    *(size_t*)ptr = size;

    memset(ptr + sizeof(size_t), 0xff, sizeof(size_t));
    memset(ptr + size + 2 * sizeof(size_t), 0xff, sizeof(size_t));

    fprintf(stderr, "BST MEM DEBUG %s:%zu malloc(%zu) = %p\n",
            filename,
            line,
            size,
            (void*)ptr);

    return (void*)(ptr + 2 * sizeof(size_t));
}


BST_API(void*)
bst_debug_calloc(char *filename, size_t line, size_t n, size_t size) {
    uint8_t *ptr;

    fprintf(stderr, "BST MEM DEBUG %s:%zu begin calloc(%zu, %zu)\n",
            filename,
            line,
            n,
            size);

    if (!(ptr = bst_debug_malloc(filename, line, n * size)))
        return NULL;

    memset(ptr, 0, n * size);

    fprintf(stderr, "BST MEM DEBUG %s:%zu end calloc(%zu, %zu)\n",
            filename,
            line,
            n,
            size);

    return (void*)ptr;
}


BST_API(void*)
bst_debug_realloc(char *filename, size_t line, void *ptr, size_t size) {
    void *ptr2;

    fprintf(stderr, "BST MEM DEBUG %s:%zu begin realloc(%p, %zu)\n",
            filename,
            line,
            (void*)ptr,
            size);

    if (!(ptr2 = bst_debug_malloc(filename, line, size))) {
        fprintf(stderr, "BST MEM DEBUG %s:%zu end realloc(%p, %zu) = NULL\n",
                filename,
                line,
                (void*)ptr,
                size);

        return NULL;
    }

    memcpy(ptr2, ptr, size);
    bst_debug_free(filename, line, ptr);

    fprintf(stderr, "BST MEM DEBUG %s:%zu end realloc(%p, %zu) = %p\n",
            filename,
            line,
            (void*)ptr,
            size,
            ptr2);

    return ptr2;
}


BST_API(void)
bst_debug_free(char *filename, size_t line, void *ptr) {
    uint8_t *ptr2;
    size_t size, x;
    char *under, *over;
    if (!ptr) {
        fprintf(stderr, "BST MEM DEBUG %s:%zu free(%p)\n",
                filename,
                line,
                (void*)ptr);
        return;
    }

    ptr2 = (uint8_t*)ptr - 2 * sizeof(size_t);
    size = *(size_t*)ptr2;

    under = "";
    over = "";

    memcpy(&x, (size_t*)ptr2 + 1, sizeof(size_t));

    if (x != ~0)
        under = ", LOWER BOUND VIOLATED";

    memcpy(&x, (size_t*)(ptr2 + size) + 2, sizeof(size_t));

    if (x != ~0)
        over = ", UPPER BOUND VIOLATED";

    fprintf(stderr, "BST MEM DEBUG %s:%zu free(%p) = %zu%s%s\n",
            filename,
            line,
            (void*)ptr2,
            size,
            under,
            over);

    free(ptr2);
}
