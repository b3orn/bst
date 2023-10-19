#include "bst/bst.h"


static const bst_version_t bst_version_identifier = {
    .major = BST_VERSION_MAJOR,
    .minor = BST_VERSION_MINOR,
    .patch = BST_VERSION_PATCH,
};


BST_API(const bst_version_t*)
bst_version(void) {
    return &bst_version_identifier;
}
