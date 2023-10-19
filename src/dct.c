#include "bst/bst.h"
#define BST_DEBUG_MEMORY
#include "bst/debug.h"


typedef struct bst_dct_kv {
    bst_str_t key;
    void *value;
} bst_dct_kv_t;


static size_t
bst_dct_hash(size_t size, char *key);

static bool
bst_dct_should_grow(bst_dct_t *self);

static bool
bst_dct_grow(bst_dct_t *self);

static void
bst_dct_kv_free(void *ptr);


BST_API(bst_dct_t*)
bst_dct_new(size_t size, bst_dct_free_func_t free_func) {
    size_t i;
    bst_lst_t *bucket;
    bst_dct_t *self;
    if (!(self = malloc(sizeof(*self))))
        return NULL;

    if (!bst_arr_init(&self->elements, sizeof(bst_lst_t), size)) {
        free(self);

        return NULL;
    }

    for (i = 0; i < bst_arr_length(&self->elements); ++i) {
        bucket = bst_arr_ptr(&self->elements, i);
        if (!bst_lst_init(bucket, sizeof(bst_dct_kv_t), 0, bst_dct_kv_free))
            goto error;
    }

    self->free_func = free_func;
    self->count = 0;

    return self;

error:
    for (size = i, i = 0; i < size; ++i) {
        bst_lst_deinit(bst_arr_ptr(&self->elements, i));
    }

    return NULL;
}


BST_API(void)
bst_dct_free(bst_dct_t *self) {
    size_t i, j;
    bst_lst_t *entries;
    bst_dct_kv_t *kv;
    if (!self)
        return;

    for (i = 0; i < bst_arr_length(&self->elements); ++i) {
        if (!(entries = bst_arr_get(&self->elements, i)))
            continue;

        for (j = 0; j < bst_lst_length(entries); ++j) {
            if (!(kv = bst_lst_get(entries, j)))
                continue;

            if (kv->value && self->free_func)
                self->free_func(kv->value);
        }

        bst_lst_deinit(entries);
    }

    bst_arr_deinit(&self->elements);
    free(self);
}


BST_API(size_t)
bst_dct_count(bst_dct_t *self) {
    if (!self)
        return 0;

    return self->count;
}


BST_API(void*)
bst_dct_set(bst_dct_t *self, char *key, void *value) {
    size_t index;
    bst_lst_t *bucket;
    bst_dct_kv_t *kv, kvn;
    if (!self || !key)
        return NULL;

    if (bst_dct_should_grow(self))
        bst_dct_grow(self);

    index = bst_dct_hash(bst_arr_length(&self->elements), key);
    bucket = bst_arr_get(&self->elements, index);

    printf("%zu: %s\n", index, key);

    for (index = 0; index < bst_lst_length(bucket); ++index) {
        if (!(kv = bst_lst_get(bucket, index)))
            return NULL;

        if (bst_str_eqc(&kv->key, 0, key)) {
            if (self->free_func && kv->value)
                self->free_func(kv->value);

            kv->value = value;

            return value;
        }
    }

    if (!(bst_str_init(&kvn.key, 0, key)))
        return NULL;

    kvn.value = value;

    if (!bst_lst_append(bucket, &kvn)) {
        bst_str_deinit(&kvn.key);

        return NULL;
    }

    ++self->count;

    return value;
}


BST_API(void*)
bst_dct_get(bst_dct_t *self, char *key) {
    size_t index;
    bst_lst_t *bucket;
    bst_dct_kv_t *kv;
    if (!self || !key)
        return NULL;

    index = bst_dct_hash(bst_arr_length(&self->elements), key);
    bucket = bst_arr_get(&self->elements, index);

    for (index = 0; index < bst_lst_length(bucket); ++index) {
        if (!(kv = bst_lst_get(bucket, index)))
            return NULL;

        if (bst_str_eqc(&kv->key, 0, key)) {
            return kv->value;
        }
    }

    return NULL;
}


BST_API(void)
bst_dct_del(bst_dct_t *self, char *key) {
    size_t index;
    bst_lst_t *bucket;
    bst_dct_kv_t *kv;
    if (!self || !key)
        return;

    index = bst_dct_hash(bst_arr_length(&self->elements), key);
    bucket = bst_arr_get(&self->elements, index);

    for (index = 0; index < bst_lst_length(bucket); ++index) {
        if (!(kv = bst_lst_get(bucket, index)))
            return;

        if (bst_str_eqc(&kv->key, 0, key)) {
            if (self->free_func && kv->value)
                self->free_func(kv->value);

            bst_lst_remove(bucket, index);

            --self->count;

            return;
        }
    }
}


/* internal */

static size_t
bst_dct_hash(size_t size, char *key) {
    char *c;
    size_t hash;
    if (!key)
        return SIZE_MAX;

    for (hash = 0, c = key; *c; ++c) {
        hash += (size_t)*c;
    }

    return hash % size;
}


static bool
bst_dct_should_grow(bst_dct_t *self) {
    return self->count > bst_arr_length(&self->elements);
}


static bool
bst_dct_grow(bst_dct_t *self) {
    BST_UNUSED(self);

    return false;
}


static void
bst_dct_kv_free(void *ptr) {
    bst_dct_kv_t *kv;

    if (!(kv = (bst_dct_kv_t*)ptr))
        return;

    bst_str_deinit(&kv->key);
}
