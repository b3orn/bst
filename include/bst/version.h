/*
 * version.h
 *
 * version info
 *
 */

#ifndef BST_VERSION_H
#define BST_VERSION_H

#define BST_VERSION_MAJOR 0
#define BST_VERSION_MINOR 0
#define BST_VERSION_PATCH 0


typedef struct bst_version {
    size_t major;
    size_t minor;
    size_t patch;
} bst_version_t;


BST_API(const bst_version_t*)
bst_version(void);

#endif
