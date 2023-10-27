/*
 * vecd.h
 *
 * double precision vectors and matrices
 *
 */

#ifndef BST_VECD_H
#define BST_VECD_H

#define BST_NAND ((double)nan(""))

#define BST_VEC2D(X, Y) ((bst_vec2d_t){(X), (Y)})

#define BST_VEC3D(X, Y, Z) ((bst_vec3d_t){(X), (Y), (Z)})

#define BST_VEC4D(X, Y, Z, W) ((bst_vec4d_t){(X), (Y), (Z), (W)})

#define BST_MAT2D(M11, M12, \
                  M21, M22) \
    ((bst_mat2d_t){(M11), (M12), \
                   (M21), (M22)})

#define BST_MAT3D(M11, M12, M13, \
                  M21, M22, M23, \
                  M31, M32, M33) \
    ((bst_mat3d_t){(M11), (M12), (M13), \
                   (M21), (M22), (M23), \
                   (M31), (M32), (M33)})

#define BST_MAT4D(M11, M12, M13, M14, \
                  M21, M22, M23, M24, \
                  M31, M32, M33, M34, \
                  M41, M42, M43, M44) \
    ((bst_mat4d_t){(M11), (M12), (M13), (M14), \
                   (M21), (M22), (M23), (M24), \
                   (M31), (M32), (M33), (M34), \
                   (M41), (M42), (M43), (M44)})

#define BST_VEC2D_NULL BST_VEC2D(0, 0)

#define BST_VEC3D_NULL BST_VEC3D(0, 0, 0)

#define BST_VEC4D_NULL BST_VEC4D(0, 0, 0, 0)

#define BST_MAT2D_IDENTITY BST_MAT2D(1, 0, 1, 0)

#define BST_MAT3D_IDENTITY BST_MAT3D(1, 0, 0, 1, 0, 0, 1, 0, 0)

#define BST_MAT4D_IDENTITY BST_MAT4D(1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0)

#define BST_VEC2D_ARR(V) ((double[2])(V))

#define BST_VEC3D_ARR(V) ((double[3])(V))

#define BST_VEC4D_ARR(V) ((double[4])(V))

#define BST_MAT2D_ARR(V) ((double[4])(V))

#define BST_MAT3D_ARR(V) ((double[9])(V))

#define BST_MAT4D_ARR(V) ((double[16])(V))


typedef struct bst_vec2d {
    double x;
    double y;
} bst_vec2d_t;

typedef struct bst_vec3d {
    double x;
    double y;
    double z;
} bst_vec3d_t;

typedef struct bst_vec4d {
    double x;
    double y;
    double z;
    double w;
} bst_vec4d_t;

typedef struct bst_mat2d {
    double m11;
    double m12;
    double m21;
    double m22;
} bst_mat2d_t;

typedef struct bst_mat3d {
    double m11;
    double m12;
    double m13;
    double m21;
    double m22;
    double m23;
    double m31;
    double m32;
    double m33;
} bst_mat3d_t;

typedef struct bst_mat4d {
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
} bst_mat4d_t;


/* vec2 */

BST_API(bst_vec2d_t*)
bst_vec2d_add(bst_vec2d_t *a, bst_vec2d_t *b, bst_vec2d_t *r);

BST_API(bst_vec2d_t*)
bst_vec2d_sub(bst_vec2d_t *a, bst_vec2d_t *b, bst_vec2d_t *r);

BST_API(bst_vec2d_t*)
bst_vec2d_mul(bst_vec2d_t *a, bst_vec2d_t *b, bst_vec2d_t *r);

BST_API(bst_vec2d_t*)
bst_vec2d_scale(double s, bst_vec2d_t *v, bst_vec2d_t *r);

BST_API(double)
bst_vec2d_dot(bst_vec2d_t *a, bst_vec2d_t *b);

BST_API(double)
bst_vec2d_norm(bst_vec2d_t *v);


/* vec3 */

BST_API(bst_vec3d_t*)
bst_vec3d_add(bst_vec3d_t *a, bst_vec3d_t *b, bst_vec3d_t *r);

BST_API(bst_vec3d_t*)
bst_vec3d_sub(bst_vec3d_t *a, bst_vec3d_t *b, bst_vec3d_t *r);

BST_API(bst_vec3d_t*)
bst_vec3d_mul(bst_vec3d_t *a, bst_vec3d_t *b, bst_vec3d_t *r);

BST_API(bst_vec3d_t*)
bst_vec3d_scale(double s, bst_vec3d_t *v, bst_vec3d_t *r);

BST_API(bst_vec3d_t*)
bst_vec3d_cross(bst_vec3d_t *a, bst_vec3d_t *b, bst_vec3d_t *r);

BST_API(double)
bst_vec3d_dot(bst_vec3d_t *a, bst_vec3d_t *b);

BST_API(double)
bst_vec3d_norm(bst_vec3d_t *v);


/* vec4 */

BST_API(bst_vec4d_t*)
bst_vec4d_add(bst_vec4d_t *a, bst_vec4d_t *b, bst_vec4d_t *r);

BST_API(bst_vec4d_t*)
bst_vec4d_sub(bst_vec4d_t *a, bst_vec4d_t *b, bst_vec4d_t *r);

BST_API(bst_vec4d_t*)
bst_vec4d_mul(bst_vec4d_t *a, bst_vec4d_t *b, bst_vec4d_t *r);

BST_API(bst_vec4d_t*)
bst_vec4d_scale(double s, bst_vec4d_t *v, bst_vec4d_t *r);

BST_API(double)
bst_vec4d_dot(bst_vec4d_t *a, bst_vec4d_t *b);

BST_API(double)
bst_vec4d_norm(bst_vec4d_t *v);


/* mat2 */

BST_API(bst_mat2d_t*)
bst_mat2d_add(bst_mat2d_t *a, bst_mat2d_t *b, bst_mat2d_t *r);

BST_API(bst_mat2d_t*)
bst_mat2d_sub(bst_mat2d_t *a, bst_mat2d_t *b, bst_mat2d_t *r);

BST_API(bst_mat2d_t*)
bst_mat2d_mul(bst_mat2d_t *a, bst_mat2d_t *b, bst_mat2d_t *r);

BST_API(bst_mat2d_t*)
bst_mat2d_dot(bst_mat2d_t *a, bst_mat2d_t *b, bst_mat2d_t *r);

BST_API(bst_mat2d_t*)
bst_mat2d_scale(double s, bst_mat2d_t *m, bst_mat2d_t *r);

BST_API(bst_mat2d_t*)
bst_mat2d_transpose(bst_mat2d_t *m, bst_mat2d_t *r);

BST_API(bst_vec2d_t*)
bst_mat2d_map(bst_mat2d_t *m, bst_vec2d_t *v, bst_vec2d_t *r);

BST_API(bst_vec2d_t*)
bst_mat2d_lmap(bst_mat2d_t *m, bst_vec2d_t *v, bst_vec2d_t *r);


/* mat3 */

BST_API(bst_mat3d_t*)
bst_mat3d_add(bst_mat3d_t *a, bst_mat3d_t *b, bst_mat3d_t *r);

BST_API(bst_mat3d_t*)
bst_mat3d_sub(bst_mat3d_t *a, bst_mat3d_t *b, bst_mat3d_t *r);

BST_API(bst_mat3d_t*)
bst_mat3d_mul(bst_mat3d_t *a, bst_mat3d_t *b, bst_mat3d_t *r);

BST_API(bst_mat3d_t*)
bst_mat3d_dot(bst_mat3d_t *a, bst_mat3d_t *b, bst_mat3d_t *r);

BST_API(bst_mat3d_t*)
bst_mat3d_scale(double s, bst_mat3d_t *m, bst_mat3d_t *r);

BST_API(bst_mat3d_t*)
bst_mat3d_transpose(bst_mat3d_t *m, bst_mat3d_t *r);

BST_API(bst_vec3d_t*)
bst_mat3d_map(bst_mat3d_t *m, bst_vec3d_t *v, bst_vec3d_t *r);

BST_API(bst_vec3d_t*)
bst_mat3d_lmap(bst_mat3d_t *m, bst_vec3d_t *v, bst_vec3d_t *r);


/* mat4 */

BST_API(bst_mat4d_t*)
bst_mat4d_add(bst_mat4d_t *a, bst_mat4d_t *b, bst_mat4d_t *r);

BST_API(bst_mat4d_t*)
bst_mat4d_sub(bst_mat4d_t *a, bst_mat4d_t *b, bst_mat4d_t *r);

BST_API(bst_mat4d_t*)
bst_mat4d_mul(bst_mat4d_t *a, bst_mat4d_t *b, bst_mat4d_t *r);

BST_API(bst_mat4d_t*)
bst_mat4d_dot(bst_mat4d_t *a, bst_mat4d_t *b, bst_mat4d_t *r);

BST_API(bst_mat4d_t*)
bst_mat4d_scale(double s, bst_mat4d_t *m, bst_mat4d_t *r);

BST_API(bst_mat4d_t*)
bst_mat4d_transpose(bst_mat4d_t *m, bst_mat4d_t *r);

BST_API(bst_vec4d_t*)
bst_mat4d_map(bst_mat4d_t *m, bst_vec4d_t *v, bst_vec4d_t *r);

BST_API(bst_vec4d_t*)
bst_mat4d_lmap(bst_mat4d_t *m, bst_vec4d_t *v, bst_vec4d_t *r);

#endif
