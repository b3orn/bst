/*
 * vecd.h
 *
 * float precision vectors and matrices
 *
 */

#ifndef BST_VECF_H
#define BST_VECF_H

#define BST_NANF ((float)nan(""))

#define BST_VEC2F(X, Y) ((bst_vec2f_t){(X), (Y)})

#define BST_VEC3F(X, Y, Z) ((bst_vec3f_t){(X), (Y), (Z)})

#define BST_VEC4F(X, Y, Z, W) ((bst_vec4f_t){(X), (Y), (Z), (W)})

#define BST_MAT2F(M11, M12, \
                  M21, M22) \
    ((bst_mat2f_t){(M11), (M12), \
                   (M21), (M22)})

#define BST_MAT3F(M11, M12, M13, \
                  M21, M22, M23, \
                  M31, M32, M33) \
    ((bst_mat3f_t){(M11), (M12), (M13), \
                   (M21), (M22), (M23), \
                   (M31), (M32), (M33)})

#define BST_MAT4F(M11, M12, M13, M14, \
                  M21, M22, M23, M24, \
                  M31, M32, M33, M34, \
                  M41, M42, M43, M44) \
    ((bst_mat4f_t){(M11), (M12), (M13), (M14), \
                   (M21), (M22), (M23), (M24), \
                   (M31), (M32), (M33), (M34), \
                   (M41), (M42), (M43), (M44)})

#define BST_VEC2F_NULL BST_VEC2F(0, 0)

#define BST_VEC3F_NULL BST_VEC3F(0, 0, 0)

#define BST_VEC4F_NULL BST_VEC4F(0, 0, 0, 0)

#define BST_MAT2F_IDENTITY BST_MAT2F(1, 0, 1, 0)

#define BST_MAT3F_IDENTITY BST_MAT3F(1, 0, 0, 1, 0, 0, 1, 0, 0)

#define BST_MAT4F_IDENTITY BST_MAT4F(1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0)

#define BST_VEC2F_ARR(V) ((float[2])(V))

#define BST_VEC3F_ARR(V) ((float[3])(V))

#define BST_VEC4F_ARR(V) ((float[4])(V))

#define BST_MAT2F_ARR(V) ((float[4])(V))

#define BST_MAT3F_ARR(V) ((float[9])(V))

#define BST_MAT4F_ARR(V) ((float[16])(V))


typedef struct bst_vec2f {
    float x;
    float y;
} bst_vec2f_t;

typedef struct bst_vec3f {
    float x;
    float y;
    float z;
} bst_vec3f_t;

typedef struct bst_vec4f {
    float x;
    float y;
    float z;
    float w;
} bst_vec4f_t;

typedef struct bst_mat2f {
    float m11;
    float m12;
    float m21;
    float m22;
} bst_mat2f_t;

typedef struct bst_mat3f {
    float m11;
    float m12;
    float m13;
    float m21;
    float m22;
    float m23;
    float m31;
    float m32;
    float m33;
} bst_mat3f_t;

typedef struct bst_mat4f {
    float m11;
    float m12;
    float m13;
    float m14;
    float m21;
    float m22;
    float m23;
    float m24;
    float m31;
    float m32;
    float m33;
    float m34;
    float m41;
    float m42;
    float m43;
    float m44;
} bst_mat4f_t;


/* vec2 */

BST_API(bst_vec2f_t*)
bst_vec2f_add(bst_vec2f_t *a, bst_vec2f_t *b, bst_vec2f_t *r);

BST_API(bst_vec2f_t*)
bst_vec2f_sub(bst_vec2f_t *a, bst_vec2f_t *b, bst_vec2f_t *r);

BST_API(bst_vec2f_t*)
bst_vec2f_mul(bst_vec2f_t *a, bst_vec2f_t *b, bst_vec2f_t *r);

BST_API(bst_vec2f_t*)
bst_vec2f_scale(float s, bst_vec2f_t *v, bst_vec2f_t *r);

BST_API(float)
bst_vec2f_dot(bst_vec2f_t *a, bst_vec2f_t *b);

BST_API(float)
bst_vec2f_norm(bst_vec2f_t *v);


/* vec3 */

BST_API(bst_vec3f_t*)
bst_vec3f_add(bst_vec3f_t *a, bst_vec3f_t *b, bst_vec3f_t *r);

BST_API(bst_vec3f_t*)
bst_vec3f_sub(bst_vec3f_t *a, bst_vec3f_t *b, bst_vec3f_t *r);

BST_API(bst_vec3f_t*)
bst_vec3f_mul(bst_vec3f_t *a, bst_vec3f_t *b, bst_vec3f_t *r);

BST_API(bst_vec3f_t*)
bst_vec3f_scale(float s, bst_vec3f_t *v, bst_vec3f_t *r);

BST_API(bst_vec3f_t*)
bst_vec3f_cross(bst_vec3f_t *a, bst_vec3f_t *b, bst_vec3f_t *r);

BST_API(float)
bst_vec3f_dot(bst_vec3f_t *a, bst_vec3f_t *b);

BST_API(float)
bst_vec3f_norm(bst_vec3f_t *v);


/* vec4 */

BST_API(bst_vec4f_t*)
bst_vec4f_add(bst_vec4f_t *a, bst_vec4f_t *b, bst_vec4f_t *r);

BST_API(bst_vec4f_t*)
bst_vec4f_sub(bst_vec4f_t *a, bst_vec4f_t *b, bst_vec4f_t *r);

BST_API(bst_vec4f_t*)
bst_vec4f_mul(bst_vec4f_t *a, bst_vec4f_t *b, bst_vec4f_t *r);

BST_API(bst_vec4f_t*)
bst_vec4f_scale(float s, bst_vec4f_t *v, bst_vec4f_t *r);

BST_API(float)
bst_vec4f_dot(bst_vec4f_t *a, bst_vec4f_t *b);

BST_API(float)
bst_vec4f_norm(bst_vec4f_t *v);


/* mat2 */

BST_API(bst_mat2f_t*)
bst_mat2f_add(bst_mat2f_t *a, bst_mat2f_t *b, bst_mat2f_t *r);

BST_API(bst_mat2f_t*)
bst_mat2f_sub(bst_mat2f_t *a, bst_mat2f_t *b, bst_mat2f_t *r);

BST_API(bst_mat2f_t*)
bst_mat2f_mul(bst_mat2f_t *a, bst_mat2f_t *b, bst_mat2f_t *r);

BST_API(bst_mat2f_t*)
bst_mat2f_dot(bst_mat2f_t *a, bst_mat2f_t *b, bst_mat2f_t *r);

BST_API(bst_mat2f_t*)
bst_mat2f_scale(float s, bst_mat2f_t *m, bst_mat2f_t *r);

BST_API(bst_mat2f_t*)
bst_mat2f_transpose(bst_mat2f_t *m, bst_mat2f_t *r);

BST_API(bst_vec2f_t*)
bst_mat2f_map(bst_mat2f_t *m, bst_vec2f_t *v, bst_vec2f_t *r);

BST_API(bst_vec2f_t*)
bst_mat2f_lmap(bst_mat2f_t *m, bst_vec2f_t *v, bst_vec2f_t *r);


/* mat3 */

BST_API(bst_mat3f_t*)
bst_mat3f_add(bst_mat3f_t *a, bst_mat3f_t *b, bst_mat3f_t *r);

BST_API(bst_mat3f_t*)
bst_mat3f_sub(bst_mat3f_t *a, bst_mat3f_t *b, bst_mat3f_t *r);

BST_API(bst_mat3f_t*)
bst_mat3f_mul(bst_mat3f_t *a, bst_mat3f_t *b, bst_mat3f_t *r);

BST_API(bst_mat3f_t*)
bst_mat3f_dot(bst_mat3f_t *a, bst_mat3f_t *b, bst_mat3f_t *r);

BST_API(bst_mat3f_t*)
bst_mat3f_scale(float s, bst_mat3f_t *m, bst_mat3f_t *r);

BST_API(bst_mat3f_t*)
bst_mat3f_transpose(bst_mat3f_t *m, bst_mat3f_t *r);

BST_API(bst_vec3f_t*)
bst_mat3f_map(bst_mat3f_t *m, bst_vec3f_t *v, bst_vec3f_t *r);

BST_API(bst_vec3f_t*)
bst_mat3f_lmap(bst_mat3f_t *m, bst_vec3f_t *v, bst_vec3f_t *r);


/* mat4 */

BST_API(bst_mat4f_t*)
bst_mat4f_add(bst_mat4f_t *a, bst_mat4f_t *b, bst_mat4f_t *r);

BST_API(bst_mat4f_t*)
bst_mat4f_sub(bst_mat4f_t *a, bst_mat4f_t *b, bst_mat4f_t *r);

BST_API(bst_mat4f_t*)
bst_mat4f_mul(bst_mat4f_t *a, bst_mat4f_t *b, bst_mat4f_t *r);

BST_API(bst_mat4f_t*)
bst_mat4f_dot(bst_mat4f_t *a, bst_mat4f_t *b, bst_mat4f_t *r);

BST_API(bst_mat4f_t*)
bst_mat4f_scale(float s, bst_mat4f_t *m, bst_mat4f_t *r);

BST_API(bst_mat4f_t*)
bst_mat4f_transpose(bst_mat4f_t *m, bst_mat4f_t *r);

BST_API(bst_vec4f_t*)
bst_mat4f_map(bst_mat4f_t *m, bst_vec4f_t *v, bst_vec4f_t *r);

BST_API(bst_vec4f_t*)
bst_mat4f_lmap(bst_mat4f_t *m, bst_vec4f_t *v, bst_vec4f_t *r);

#endif
