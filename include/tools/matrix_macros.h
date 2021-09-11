#ifndef MATRIX_MACROS_H
#define MATRIX_MACROS_H

#define MATRIX_CONCAT_(A, B) A##_##B
#define MATRIX_CONCAT(A, B) MATRIX_CONCAT_(A, B)
#define M_FUNC_NAME(suffix) MATRIX_CONCAT(MATRIX_NAME, suffix)

#endif
