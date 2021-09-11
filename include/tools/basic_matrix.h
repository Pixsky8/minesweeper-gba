#ifndef TOOLS_CHARMATRIX_H
#define TOOLS_CHARMATRIX_H

#define MATRIX_NAME matrix_char
#define MATRIX_TYPE char
#include "tools/matrix.h"
#undef MATRIX_NAME
#undef MATRIX_TYPE

#define MATRIX_NAME matrix_short
#define MATRIX_TYPE short
#include "tools/matrix.h"
#undef MATRIX_NAME
#undef MATRIX_TYPE

#endif
