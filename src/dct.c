#include "bst/bst.h"
#include "bst/debug.h"


static size_t
bst_dct_hash(size_t size, char *key);

static bool
bst_dct_should_grow(bst_dct_t *self);

static bool
bst_dct_grow(bst_dct_t *self);

static size_t
bst_dct_bucket_index(bst_lst_t *bucket, char *key);

static void
bst_dct_kv_free(void *ptr);


BST_API(bst_dct_t*)
bst_dct_new(size_t capacity, bst_dct_free_func_t free_func) {
    bst_dct_t *self;
    if (!(self = malloc(sizeof(*self))))
        return NULL;

    if (!bst_dct_init(self, capacity, free_func)) {
        free(self);

        return NULL;
    }

    return self;
}


BST_API(bst_dct_t*)
bst_dct_init(bst_dct_t *self, size_t capacity, bst_dct_free_func_t free_func) {
    size_t i;
    bst_lst_t *bucket;
    if (!self || !bst_arr_init(&self->elements, capacity, sizeof(bst_lst_t)))
        return NULL;

    capacity = bst_arr_capacity(&self->elements);
    for (i = 0; i < capacity; ++i) {
        bucket = bst_arr_ptr(&self->elements, i);
        if (!bst_lst_init(bucket, 0, sizeof(bst_dct_kv_t), bst_dct_kv_free))
            goto error;
    }

    self->free_func = free_func;
    self->count = 0;

    return self;

error:
    for (capacity = i, i = 0; i < capacity; ++i) {
        bst_lst_deinit(bst_arr_ptr(&self->elements, i));
    }

    bst_arr_deinit(&self->elements);

    return NULL;
}


BST_API(void)
bst_dct_deinit(bst_dct_t *self) {
    size_t capacity, length, i, j;
    bst_lst_t *entries;
    bst_dct_kv_t *kv;
    if (!self)
        return;

    capacity = bst_arr_capacity(&self->elements);
    for (i = 0; i < capacity; ++i) {
        if (!(entries = bst_arr_ptr(&self->elements, i)))
            continue;

        length = bst_lst_length(entries);
        for (j = 0; j < length; ++j) {
            if (!(kv = bst_lst_get(entries, j)))
                continue;

            if (kv->value && self->free_func)
                self->free_func(kv->value);
        }

        bst_lst_deinit(entries);
    }

    bst_arr_deinit(&self->elements);
}


BST_API(void)
bst_dct_free(bst_dct_t *self) {
    bst_dct_deinit(self);
    free(self);
}


BST_API(size_t)
bst_dct_count(bst_dct_t *self) {
    if (!self)
        return 0;

    return self->count;
}


BST_API(void*)
bst_dct_set(bst_dct_t *self, bst_str_t *key, void *value) {
    return bst_dct_setc(self, bst_str_ptr(key, 0), value);
}


BST_API(void*)
bst_dct_setc(bst_dct_t *self, char *key, void *value) {
    size_t index;
    bst_lst_t *bucket;
    bst_dct_kv_t *kv, kvn;
    if (!self || !key)
        return NULL;

    if (bst_dct_should_grow(self))
        bst_dct_grow(self);

    index = bst_dct_hash(bst_arr_capacity(&self->elements), key);
    bucket = bst_arr_ptr(&self->elements, index);

    if ((index = bst_dct_bucket_index(bucket, key)) != SIZE_MAX) {
        kv = bst_lst_get(bucket, index);

        kv->value = value;

        return value;
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
bst_dct_get(bst_dct_t *self, bst_str_t *key) {
    return bst_dct_getc(self, bst_str_ptr(key, 0));
}


BST_API(void*)
bst_dct_getc(bst_dct_t *self, char *key) {
    size_t index;
    bst_lst_t *bucket;
    if (!self || !key)
        return NULL;

    index = bst_dct_hash(bst_arr_capacity(&self->elements), key);
    bucket = bst_arr_ptr(&self->elements, index);

    if ((index = bst_dct_bucket_index(bucket, key)) == SIZE_MAX)
        return NULL;

    return ((bst_dct_kv_t*)bst_lst_get(bucket, index))->value;
}


BST_API(void)
bst_dct_del(bst_dct_t *self, bst_str_t *key) {
    bst_dct_delc(self, bst_str_ptr(key, 0));
}


BST_API(void)
bst_dct_delc(bst_dct_t *self, char *key) {
    size_t index;
    bst_lst_t *bucket;
    bst_dct_kv_t *kv;
    if (!self || !key)
        return;

    index = bst_dct_hash(bst_arr_capacity(&self->elements), key);
    bucket = bst_arr_ptr(&self->elements, index);

    if ((index = bst_dct_bucket_index(bucket, key)) == SIZE_MAX)
        return;

    kv = bst_lst_get(bucket, index);

    if (self->free_func && kv->value)
        self->free_func(kv->value);

    bst_lst_remove(bucket, index);

    --self->count;
}


BST_API(bst_dct_kv_t*)
bst_dct_iter(bst_dct_t *self) {
    size_t capacity, i;
    bst_lst_t *bucket;
    if (!self)
        return NULL;

    capacity = bst_arr_capacity(&self->elements);
    for (i = 0; i < capacity; ++i) {
        bucket = bst_arr_ptr(&self->elements, i);
        if (bst_lst_length(bucket))
            return bst_lst_get(bucket, 0);
    }

    return NULL;
}


BST_API(bst_dct_kv_t*)
bst_dct_next(bst_dct_t *self, bst_dct_kv_t *kv) {
    size_t capacity, i, bucket_index, key_index;
    bst_lst_t *bucket;
    if (!self || !kv)
        return NULL;

    bucket_index = bst_dct_hash(bst_arr_capacity(&self->elements),
                                bst_str_ptr(&kv->key, 0));
    bucket = bst_arr_ptr(&self->elements, bucket_index);
    key_index = bst_dct_bucket_index(bucket, bst_str_ptr(&kv->key, 0));

    if (key_index + 1 < bst_lst_length(bucket))
        return bst_lst_get(bucket, key_index + 1);

    capacity = bst_arr_capacity(&self->elements);
    for (i = bucket_index + 1; i < capacity; ++i) {
        bucket = bst_arr_ptr(&self->elements, i);
        if (bst_lst_length(bucket))
            return bst_lst_get(bucket, 0);
    }

    return NULL;
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
    return self->count > bst_arr_capacity(&self->elements);
}


static bool
bst_dct_grow(bst_dct_t *self) {
    BST_UNUSED(self);

    return false;
}


static size_t
bst_dct_bucket_index(bst_lst_t *bucket, char *key) {
    size_t i;
    bst_dct_kv_t *kv;

    for (i = 0; i < bst_lst_length(bucket); ++i) {
        if (!(kv = bst_lst_get(bucket, i)))
            return SIZE_MAX;

        if (bst_str_eqc(&kv->key, 0, key)) {
            return i;
        }
    }

    return SIZE_MAX;
}


static void
bst_dct_kv_free(void *ptr) {
    bst_dct_kv_t *kv;

    if (!(kv = (bst_dct_kv_t*)ptr))
        return;

    bst_str_deinit(&kv->key);
}
