/*
 * vec.h
 *
 * vectors and matrices
 *
 */

#ifndef BST_VEC_H
#define BST_VEC_H

#define BST_MAT_INDEX(N, Y, X) ((N) * ((Y) - 1) + ((X) - 1))

#define BST_MAT2_INDEX(Y, X) BST_MAT_INDEX(2, Y, X)

#define BST_MAT3_INDEX(Y, X) BST_MAT_INDEX(3, Y, X)

#define BST_MAT4_INDEX(Y, X) BST_MAT_INDEX(4, Y, X)

#define BST_VEC2(X, Y) ((bst_vec2_t){(X), (Y)})

#define BST_VEC3(X, Y, Z) ((bst_vec3_t){(X), (Y), (Z)})

#define BST_VEC4(X, Y, Z, W) ((bst_vec4_t){(X), (Y), (Z), (W)})

#define BST_MAT2(M11, M12, \
                 M21, M22) \
    ((bst_mat2_t){(M11), (M12), \
                  (M21), (M22)})

#define BST_MAT3(M11, M12, M13, \
                 M21, M22, M23, \
                 M31, M32, M33) \
    ((bst_mat3_t){(M11), (M12), (M13), \
                  (M21), (M22), (M23), \
                  (M31), (M32), (M33)})

#define BST_MAT4(M11, M12, M13, M14, \
                 M21, M22, M23, M24, \
                 M31, M32, M33, M34, \
                 M41, M42, M43, M44) \
    ((bst_mat4_t){(M11), (M12), (M13), (M14), \
                  (M21), (M22), (M23), (M24), \
                  (M31), (M32), (M33), (M34), \
                  (M41), (M42), (M43), (M44)})

#define BST_VEC2_NULL BST_VEC2(0, 0)

#define BST_VEC3_NULL BST_VEC3(0, 0, 0)

#define BST_VEC4_NULL BST_VEC4(0, 0, 0, 0)

#define BST_MAT2_IDENTITY BST_MAT2(1, 0, 1, 0)

#define BST_MAT3_IDENTITY BST_MAT3(1, 0, 0, 1, 0, 0, 1, 0, 0)

#define BST_MAT4_IDENTITY BST_MAT4(1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0)

#define BST_VEC2_TO_ARRAY(V) ((double[2])(V))

#define BST_VEC3_TO_ARRAY(V) ((double[3])(V))

#define BST_VEC4_TO_ARRAY(V) ((double[4])(V))

#define BST_MAT2_TO_ARRAY(V) ((double[4])(V))

#define BST_MAT3_TO_ARRAY(V) ((double[9])(V))

#define BST_MAT4_TO_ARRAY(V) ((double[16])(V))


typedef struct bst_vec2 {
    double x;
    double y;
} bst_vec2_t;

typedef struct bst_vec3 {
    double x;
    double y;
    double z;
} bst_vec3_t;

typedef struct bst_vec4 {
    double x;
    double y;
    double z;
    double w;
} bst_vec4_t;

typedef struct bst_mat2 {
    double m11;
    double m12;
    double m21;
    double m22;
} bst_mat2_t;

typedef struct bst_mat3 {
    double m11;
    double m12;
    double m13;
    double m21;
    double m22;
    double m23;
    double m31;
    double m32;
    double m33;
} bst_mat3_t;

typedef struct bst_mat4 {
    double m11;
    double m12;
    double m13;
    double m14;
    double m21;
    double m22;
    double m23;
    double m24;
    double m31;
    double m32;
    double m33;
    double m34;
    double m41;
    double m42;
    double m43;
    double m44;
} bst_mat4_t;


/* vec2 */

BST_API(bst_vec2_t*)
bst_vec2_add(bst_vec2_t *a, bst_vec2_t *b, bst_vec2_t *r);

BST_API(bst_vec2_t*)
bst_vec2_sub(bst_vec2_t *a, bst_vec2_t *b, bst_vec2_t *r);

BST_API(bst_vec2_t*)
bst_vec2_mul(bst_vec2_t *a, bst_vec2_t *b, bst_vec2_t *r);

BST_API(bst_vec2_t*)
bst_vec2_scale(double s, bst_vec2_t *v, bst_vec2_t *r);

BST_API(double)
bst_vec2_dot(bst_vec2_t *a, bst_vec2_t *b);

BST_API(double)
bst_vec2_norm(bst_vec2_t *v);


/* vec3 */

BST_API(bst_vec3_t*)
bst_vec3_add(bst_vec3_t *a, bst_vec3_t *b, bst_vec3_t *r);

BST_API(bst_vec3_t*)
bst_vec3_sub(bst_vec3_t *a, bst_vec3_t *b, bst_vec3_t *r);

BST_API(bst_vec3_t*)
bst_vec3_mul(bst_vec3_t *a, bst_vec3_t *b, bst_vec3_t *r);

BST_API(bst_vec3_t*)
bst_vec3_scale(double s, bst_vec3_t *v, bst_vec3_t *r);

BST_API(bst_vec3_t*)
bst_vec3_cross(bst_vec3_t *a, bst_vec3_t *b, bst_vec3_t *r);

BST_API(double)
bst_vec3_dot(bst_vec3_t *a, bst_vec3_t *b);

BST_API(double)
bst_vec3_norm(bst_vec3_t *v);


/* vec4 */

BST_API(bst_vec4_t*)
bst_vec4_add(bst_vec4_t *a, bst_vec4_t *b, bst_vec4_t *r);

BST_API(bst_vec4_t*)
bst_vec4_sub(bst_vec4_t *a, bst_vec4_t *b, bst_vec4_t *r);

BST_API(bst_vec4_t*)
bst_vec4_mul(bst_vec4_t *a, bst_vec4_t *b, bst_vec4_t *r);

BST_API(bst_vec4_t*)
bst_vec4_scale(double s, bst_vec4_t *v, bst_vec4_t *r);

BST_API(double)
bst_vec4_dot(bst_vec4_t *a, bst_vec4_t *b);

BST_API(double)
bst_vec4_norm(bst_vec4_t *v);


/* mat2 */

BST_API(bst_mat2_t*)
bst_mat2_add(bst_mat2_t *a, bst_mat2_t *b, bst_mat2_t *r);

BST_API(bst_mat2_t*)
bst_mat2_sub(bst_mat2_t *a, bst_mat2_t *b, bst_mat2_t *r);

BST_API(bst_mat2_t*)
bst_mat2_mul(bst_mat2_t *a, bst_mat2_t *b, bst_mat2_t *r);

BST_API(bst_mat2_t*)
bst_mat2_dot(bst_mat2_t *a, bst_mat2_t *b, bst_mat2_t *r);

BST_API(bst_mat2_t*)
bst_mat2_scale(double s, bst_mat2_t *m, bst_mat2_t *r);

BST_API(bst_mat2_t*)
bst_mat2_transpose(bst_mat2_t *m, bst_mat2_t *r);

BST_API(bst_vec2_t*)
bst_mat2_map(bst_mat2_t *m, bst_vec2_t *v, bst_vec2_t *r);

BST_API(bst_vec2_t*)
bst_mat2_lmap(bst_mat2_t *m, bst_vec2_t *v, bst_vec2_t *r);


/* mat3 */

BST_API(bst_mat3_t*)
bst_mat3_add(bst_mat3_t *a, bst_mat3_t *b, bst_mat3_t *r);

BST_API(bst_mat3_t*)
bst_mat3_sub(bst_mat3_t *a, bst_mat3_t *b, bst_mat3_t *r);

BST_API(bst_mat3_t*)
bst_mat3_mul(bst_mat3_t *a, bst_mat3_t *b, bst_mat3_t *r);

BST_API(bst_mat3_t*)
bst_mat3_dot(bst_mat3_t *a, bst_mat3_t *b, bst_mat3_t *r);

BST_API(bst_mat3_t*)
bst_mat3_scale(double s, bst_mat3_t *m, bst_mat3_t *r);

BST_API(bst_mat3_t*)
bst_mat3_transpose(bst_mat3_t *m, bst_mat3_t *r);

BST_API(bst_vec3_t*)
bst_mat3_map(bst_mat3_t *m, bst_vec3_t *v, bst_vec3_t *r);

BST_API(bst_vec3_t*)
bst_mat3_lmap(bst_mat3_t *m, bst_vec3_t *v, bst_vec3_t *r);


/* mat4 */

BST_API(bst_mat4_t*)
bst_mat4_add(bst_mat4_t *a, bst_mat4_t *b, bst_mat4_t *r);

BST_API(bst_mat4_t*)
bst_mat4_sub(bst_mat4_t *a, bst_mat4_t *b, bst_mat4_t *r);

BST_API(bst_mat4_t*)
bst_mat4_mul(bst_mat4_t *a, bst_mat4_t *b, bst_mat4_t *r);

BST_API(bst_mat4_t*)
bst_mat4_dot(bst_mat4_t *a, bst_mat4_t *b, bst_mat4_t *r);

BST_API(bst_mat4_t*)
bst_mat4_scale(double s, bst_mat4_t *m, bst_mat4_t *r);

BST_API(bst_mat4_t*)
bst_mat4_transpose(bst_mat4_t *m, bst_mat4_t *r);

BST_API(bst_vec4_t*)
bst_mat4_map(bst_mat4_t *m, bst_vec4_t *v, bst_vec4_t *r);

BST_API(bst_vec4_t*)
bst_mat4_lmap(bst_mat4_t *m, bst_vec4_t *v, bst_vec4_t *r);

#endif
