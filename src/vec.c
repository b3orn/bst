#include "bst/bst.h"


/* vec2 */

BST_API(bst_vec2_t*)
bst_vec2_add(bst_vec2_t *a, bst_vec2_t *b, bst_vec2_t *r) {
    if (!a || !b || !r)
        return NULL;

    *r = BST_VEC2(a->x + b->x, a->y + b->y);

    return r;
}


BST_API(bst_vec2_t*)
bst_vec2_sub(bst_vec2_t *a, bst_vec2_t *b, bst_vec2_t *r) {
    if (!a || !b || !r)
        return NULL;

    *r = BST_VEC2(a->x - b->x, a->y - b->y);

    return r;
}


BST_API(bst_vec2_t*)
bst_vec2_mul(bst_vec2_t *a, bst_vec2_t *b, bst_vec2_t *r) {
    if (!a || !b || !r)
        return NULL;

    *r = BST_VEC2(a->x * b->x, a->y * b->y);

    return r;
}


BST_API(bst_vec2_t*)
bst_vec2_scale(double s, bst_vec2_t *v, bst_vec2_t *r) {
    if (!v || !r)
        return NULL;

    *r = BST_VEC2(s * v->x, s * v->y);

    return r;
}


BST_API(double)
bst_vec2_dot(bst_vec2_t *a, bst_vec2_t *b) {
    if (!a || !b)
        return BST_NAN;

    return a->x * b->x + a->y * b->y;
}


BST_API(double)
bst_vec2_norm(bst_vec2_t *v) {
    if (!v)
        return BST_NAN;

    return sqrt(bst_vec2_dot(v, v));
}


/* vec3 */

BST_API(bst_vec3_t*)
bst_vec3_add(bst_vec3_t *a, bst_vec3_t *b, bst_vec3_t *r) {
    if (!a || !b || !r)
        return NULL;

    *r = BST_VEC3(a->x + b->x, a->y + b->y, a->z + b->z);

    return r;
}


BST_API(bst_vec3_t*)
bst_vec3_sub(bst_vec3_t *a, bst_vec3_t *b, bst_vec3_t *r) {
    if (!a || !b || !r)
        return NULL;

    *r = BST_VEC3(a->x - b->x, a->y - b->y, a->z - b->z);

    return r;
}


BST_API(bst_vec3_t*)
bst_vec3_mul(bst_vec3_t *a, bst_vec3_t *b, bst_vec3_t *r) {
    if (!a || !b || !r)
        return NULL;

    *r = BST_VEC3(a->x * b->x, a->y * b->y, a->z * b->z);

    return r;
}


BST_API(bst_vec3_t*)
bst_vec3_scale(double s, bst_vec3_t *v, bst_vec3_t *r) {
    if (!v || !r)
        return NULL;

    *r = BST_VEC3(s * v->x, s * v->y, s * v->z);

    return r;
}


BST_API(bst_vec3_t*)
bst_vec3_cross(bst_vec3_t *a, bst_vec3_t *b, bst_vec3_t *r) {
    if (!a || !b || !r)
        return NULL;

    *r = BST_VEC3(a->y * b->z - a->z * b->y,
                  a->z * b->x - a->x * b->z,
                  a->x * b->y - a->y * b->x);

    return r;
}


BST_API(double)
bst_vec3_dot(bst_vec3_t *a, bst_vec3_t *b) {
    if (!a || !b)
        return BST_NAN;

    return a->x * b->x + a->y * b->y + a->z * b->z;
}


BST_API(double)
bst_vec3_norm(bst_vec3_t *v) {
    if (!v)
        return BST_NAN;

    return sqrt(bst_vec3_dot(v, v));
}


/* vec4 */

BST_API(bst_vec4_t*)
bst_vec4_add(bst_vec4_t *a, bst_vec4_t *b, bst_vec4_t *r) {
    if (!a || !b || !r)
        return NULL;

    *r = BST_VEC4(a->x + b->x, a->y + b->y, a->z + b->z, a->w + b->w);

    return r;
}


BST_API(bst_vec4_t*)
bst_vec4_sub(bst_vec4_t *a, bst_vec4_t *b, bst_vec4_t *r) {
    if (!a || !b || !r)
        return NULL;

    *r = BST_VEC4(a->x - b->x, a->y - b->y, a->z - b->z, a->w - b->w);

    return r;
}


BST_API(bst_vec4_t*)
bst_vec4_mul(bst_vec4_t *a, bst_vec4_t *b, bst_vec4_t *r) {
    if (!a || !b || !r)
        return NULL;

    *r = BST_VEC4(a->x * b->x, a->y * b->y, a->z * b->z, a->w * b->w);

    return r;
}


BST_API(bst_vec4_t*)
bst_vec4_scale(double s, bst_vec4_t *v, bst_vec4_t *r) {
    if (!v || !r)
        return NULL;

    *r = BST_VEC4(s * v->x, s * v->y, s * v->z, s * v->w);

    return r;
}


BST_API(double)
bst_vec4_dot(bst_vec4_t *a, bst_vec4_t *b) {
    if (!a || !b)
        return BST_NAN;

    return a->x * b->x + a->y * b->y + a->z * b->z + a->w * b->w;
}


BST_API(double)
bst_vec4_norm(bst_vec4_t *v) {
    if (!v)
        return BST_NAN;

    return sqrt(bst_vec4_dot(v, v));
}


/* mat2 */

BST_API(bst_mat2_t*)
bst_mat2_add(bst_mat2_t *a, bst_mat2_t *b, bst_mat2_t *r) {
    if (!a || !b || !r)
        return NULL;

    *r = BST_MAT2(a->m11 + b->m11, a->m12 + b->m12,
                  a->m21 + b->m21, a->m22 + b->m22);

    return r;
}


BST_API(bst_mat2_t*)
bst_mat2_sub(bst_mat2_t *a, bst_mat2_t *b, bst_mat2_t *r) {
    if (!a || !b || !r)
        return NULL;

    *r = BST_MAT2(a->m11 - b->m11, a->m12 - b->m12,
                  a->m21 - b->m21, a->m22 - b->m22);

    return r;
}


BST_API(bst_mat2_t*)
bst_mat2_mul(bst_mat2_t *a, bst_mat2_t *b, bst_mat2_t *r) {
    if (!a || !b || !r)
        return NULL;

    *r = BST_MAT2(a->m11 * b->m11, a->m12 * b->m12,
                  a->m21 * b->m21, a->m22 * b->m22);

    return r;
}


BST_API(bst_mat2_t*)
bst_mat2_dot(bst_mat2_t *a, bst_mat2_t *b, bst_mat2_t *r) {
    if (!a || !b || !r)
        return NULL;

    *r = BST_MAT2(a->m11 * b->m11 + a->m12 * b->m21,
                  a->m11 * b->m12 + a->m12 * b->m22,
                  a->m21 * b->m11 + a->m22 * b->m21,
                  a->m21 * b->m12 + a->m22 * b->m22);

    return r;
}


BST_API(bst_mat2_t*)
bst_mat2_scale(double s, bst_mat2_t *m, bst_mat2_t *r) {
    if (!m || !r)
        return NULL;

    *r = BST_MAT2(s * m->m11, s * m->m12, s * m->m21, s * m->m22);

    return r;
}


BST_API(bst_mat2_t*)
bst_mat2_transpose(bst_mat2_t *m, bst_mat2_t *r) {
    if (!m || !r)
        return NULL;

    *r = BST_MAT2(m->m11, m->m21, m->m12, m->m22);

    return r;
}


BST_API(bst_vec2_t*)
bst_mat2_map(bst_mat2_t *m, bst_vec2_t *v, bst_vec2_t *r) {
    if (!m || !v || !r)
        return NULL;

    *r = BST_VEC2(m->m11 * v->x + m->m12 * v->y,
                  m->m21 * v->x + m->m22 * v->y);

    return r;
}


BST_API(bst_vec2_t*)
bst_mat2_lmap(bst_mat2_t *m, bst_vec2_t *v, bst_vec2_t *r) {
    bst_mat2_t t;
    if (!m || !v || !r)
        return NULL;

    return bst_mat2_map(bst_mat2_transpose(m, &t), v, r);
}


/* mat3 */

BST_API(bst_mat3_t*)
bst_mat3_add(bst_mat3_t *a, bst_mat3_t *b, bst_mat3_t *r) {
    if (!a || !b || !r)
        return NULL;

    *r = BST_MAT3(a->m11 + b->m11, a->m12 + b->m12, a->m13 + b->m13,
                  a->m21 + b->m21, a->m22 + b->m22, a->m23 + b->m23,
                  a->m31 + b->m31, a->m32 + b->m32, a->m33 + b->m33);

    return r;
}


BST_API(bst_mat3_t*)
bst_mat3_sub(bst_mat3_t *a, bst_mat3_t *b, bst_mat3_t *r) {
    if (!a || !b || !r)
        return NULL;

    *r = BST_MAT3(a->m11 - b->m11, a->m12 - b->m12, a->m13 - b->m13,
                  a->m21 - b->m21, a->m22 - b->m22, a->m23 - b->m23,
                  a->m31 - b->m31, a->m32 - b->m32, a->m33 - b->m33);

    return r;
}


BST_API(bst_mat3_t*)
bst_mat3_mul(bst_mat3_t *a, bst_mat3_t *b, bst_mat3_t *r) {
    if (!a || !b || !r)
        return NULL;

    *r = BST_MAT3(a->m11 * b->m11, a->m12 * b->m12, a->m13 * b->m13,
                  a->m21 * b->m21, a->m22 * b->m22, a->m23 * b->m23,
                  a->m31 * b->m31, a->m32 * b->m32, a->m33 * b->m33);

    return r;
}


BST_API(bst_mat3_t*)
bst_mat3_dot(bst_mat3_t *a, bst_mat3_t *b, bst_mat3_t *r) {
    if (!a || !b || !r)
        return NULL;

    *r = BST_MAT3(a->m11 * b->m11 + a->m12 * b->m21 + a->m13 * b->m31,
                  a->m11 * b->m12 + a->m12 * b->m22 + a->m13 * b->m32,
                  a->m11 * b->m13 + a->m12 * b->m23 + a->m13 * b->m33,
                  a->m21 * b->m11 + a->m22 * b->m21 + a->m23 * b->m31,
                  a->m21 * b->m12 + a->m22 * b->m22 + a->m23 * b->m32,
                  a->m21 * b->m13 + a->m22 * b->m23 + a->m23 * b->m33,
                  a->m31 * b->m11 + a->m32 * b->m21 + a->m33 * b->m31,
                  a->m31 * b->m12 + a->m32 * b->m22 + a->m33 * b->m32,
                  a->m31 * b->m13 + a->m32 * b->m23 + a->m33 * b->m33);

    return r;
}


BST_API(bst_mat3_t*)
bst_mat3_scale(double s, bst_mat3_t *m, bst_mat3_t *r) {
    if (!m || !r)
        return NULL;

    *r = BST_MAT3(s * m->m11, s * m->m12, s * m->m13,
                  s * m->m21, s * m->m22, s * m->m23,
                  s * m->m31, s * m->m32, s * m->m33);

    return r;
}


BST_API(bst_mat3_t*)
bst_mat3_transpose(bst_mat3_t *m, bst_mat3_t *r) {
    if (!m  || !r)
        return NULL;

    *r = BST_MAT3(m->m11, m->m21, m->m31,
                  m->m12, m->m22, m->m32,
                  m->m13, m->m23, m->m33);

    return r;
}


BST_API(bst_vec3_t*)
bst_mat3_map(bst_mat3_t *m, bst_vec3_t *v, bst_vec3_t *r) {
    if (!m || !v || !r)
        return NULL;

    *r = BST_VEC3(m->m11 * v->x + m->m12 * v->y + m->m13 * v->z,
                  m->m21 * v->x + m->m22 * v->y + m->m23 * v->z,
                  m->m31 * v->x + m->m32 * v->y + m->m33 * v->z);

    return r;
}


BST_API(bst_vec3_t*)
bst_mat3_lmap(bst_mat3_t *m, bst_vec3_t *v, bst_vec3_t *r) {
    bst_mat3_t t;
    if (!m || !v || !r)
        return NULL;

    return bst_mat3_map(bst_mat3_transpose(m, &t), v, r);
}


/* mat4 */

BST_API(bst_mat4_t*)
bst_mat4_add(bst_mat4_t *a, bst_mat4_t *b, bst_mat4_t *r) {
    if (!a || !b || !r)
        return NULL;

    *r = BST_MAT4(a->m11 + b->m11, a->m12 + b->m12, a->m13 + b->m13, a->m14 + b->m14,
                  a->m21 + b->m21, a->m22 + b->m22, a->m23 + b->m23, a->m24 + b->m24,
                  a->m31 + b->m31, a->m32 + b->m32, a->m33 + b->m33, a->m34 + b->m34,
                  a->m41 + b->m41, a->m42 + b->m42, a->m43 + b->m43, a->m44 + b->m44);

    return r;
}


BST_API(bst_mat4_t*)
bst_mat4_sub(bst_mat4_t *a, bst_mat4_t *b, bst_mat4_t *r) {
    if (!a || !b || !r)
        return NULL;

    *r = BST_MAT4(a->m11 - b->m11, a->m12 - b->m12, a->m13 - b->m13, a->m14 - b->m14,
                  a->m21 - b->m21, a->m22 - b->m22, a->m23 - b->m23, a->m24 - b->m24,
                  a->m31 - b->m31, a->m32 - b->m32, a->m33 - b->m33, a->m34 - b->m34,
                  a->m41 - b->m41, a->m42 - b->m42, a->m43 - b->m43, a->m44 - b->m44);

    return r;
}


BST_API(bst_mat4_t*)
bst_mat4_mul(bst_mat4_t *a, bst_mat4_t *b, bst_mat4_t *r) {
    if (!a || !b || !r)
        return NULL;

    *r = BST_MAT4(a->m11 * b->m11, a->m12 * b->m12, a->m13 * b->m13, a->m14 * b->m14,
                  a->m21 * b->m21, a->m22 * b->m22, a->m23 * b->m23, a->m24 * b->m24,
                  a->m31 * b->m31, a->m32 * b->m32, a->m33 * b->m33, a->m34 * b->m34,
                  a->m41 * b->m41, a->m42 * b->m42, a->m43 * b->m43, a->m44 * b->m44);

    return r;
}


BST_API(bst_mat4_t*)
bst_mat4_dot(bst_mat4_t *a, bst_mat4_t *b, bst_mat4_t *r) {
    if (!a || !b || !r)
        return NULL;

    *r = BST_MAT4(a->m11 * b->m11 + a->m12 * b->m21 + a->m13 * b->m31 + a->m14 * b->m41,
                  a->m11 * b->m12 + a->m12 * b->m22 + a->m13 * b->m32 + a->m14 * b->m42,
                  a->m11 * b->m13 + a->m12 * b->m23 + a->m13 * b->m33 + a->m14 * b->m43,
                  a->m11 * b->m14 + a->m12 * b->m24 + a->m13 * b->m34 + a->m14 * b->m44,
                  a->m21 * b->m11 + a->m22 * b->m21 + a->m23 * b->m31 + a->m24 * b->m41,
                  a->m21 * b->m12 + a->m22 * b->m22 + a->m23 * b->m32 + a->m24 * b->m42,
                  a->m21 * b->m13 + a->m22 * b->m23 + a->m23 * b->m33 + a->m24 * b->m43,
                  a->m21 * b->m14 + a->m22 * b->m24 + a->m23 * b->m34 + a->m24 * b->m44,
                  a->m31 * b->m11 + a->m32 * b->m21 + a->m33 * b->m31 + a->m34 * b->m41,
                  a->m31 * b->m12 + a->m32 * b->m22 + a->m33 * b->m32 + a->m34 * b->m42,
                  a->m31 * b->m13 + a->m32 * b->m23 + a->m33 * b->m33 + a->m34 * b->m43,
                  a->m31 * b->m14 + a->m32 * b->m24 + a->m33 * b->m34 + a->m34 * b->m44,
                  a->m41 * b->m11 + a->m42 * b->m21 + a->m43 * b->m31 + a->m44 * b->m41,
                  a->m41 * b->m12 + a->m42 * b->m22 + a->m43 * b->m32 + a->m44 * b->m42,
                  a->m41 * b->m13 + a->m42 * b->m23 + a->m43 * b->m33 + a->m44 * b->m43,
                  a->m41 * b->m14 + a->m42 * b->m24 + a->m43 * b->m34 + a->m44 * b->m44);

    return r;
}


BST_API(bst_mat4_t*)
bst_mat4_scale(double s, bst_mat4_t *m, bst_mat4_t *r) {
    if (!m || !r)
        return NULL;

    *r = BST_MAT4(s * m->m11, s * m->m12, s * m->m13, s * m->m14,
                  s * m->m21, s * m->m22, s * m->m23, s * m->m24,
                  s * m->m31, s * m->m32, s * m->m33, s * m->m34,
                  s * m->m41, s * m->m42, s * m->m43, s * m->m44);

    return r;
}


BST_API(bst_mat4_t*)
bst_mat4_transpose(bst_mat4_t *m, bst_mat4_t *r) {
    if (!m || !r)
        return NULL;

    *r = BST_MAT4(m->m11, m->m21, m->m31, m->m41,
                  m->m12, m->m22, m->m32, m->m42,
                  m->m13, m->m23, m->m33, m->m43,
                  m->m14, m->m24, m->m34, m->m44);

    return r;
}


BST_API(bst_vec4_t*)
bst_mat4_map(bst_mat4_t *m, bst_vec4_t *v, bst_vec4_t *r) {
    if (!m || !v || !r)
        return NULL;

    *r = BST_VEC4(m->m11 * v->x + m->m12 * v->y + m->m13 * v->z + m->m14 * v->w,
                  m->m21 * v->x + m->m22 * v->y + m->m23 * v->z + m->m24 * v->w,
                  m->m31 * v->x + m->m32 * v->y + m->m33 * v->z + m->m34 * v->w,
                  m->m41 * v->x + m->m42 * v->y + m->m43 * v->z + m->m44 * v->w);

    return r;
}


BST_API(bst_vec4_t*)
bst_mat4_lmap(bst_mat4_t *m, bst_vec4_t *v, bst_vec4_t *r) {
    bst_mat4_t t;
    if (!m || !v || !r)
        return NULL;

    return bst_mat4_map(bst_mat4_transpose(m, &t), v, r);
}
