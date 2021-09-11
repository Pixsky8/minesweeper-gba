#include "tools/matrix_macros.h"

#ifndef MATRIX_NAME
#error MATRIX_NAME is undefined
#endif

#ifndef MATRIX_TYPE
#error MATRIX_TYPE is undefined
#endif

static inline MATRIX_TYPE M_FUNC_NAME(get) (MATRIX_TYPE *matrix,
                                            int i,
                                            int j,
                                            unsigned int width) {
    return matrix[i + j * width];
}

static inline void M_FUNC_NAME(set) (MATRIX_TYPE *matrix,
                                     int i,
                                     int j,
                                     unsigned int width,
                                     MATRIX_TYPE value) {
    matrix[i + j * width] = value;
}
