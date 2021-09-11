#ifndef ENGINE_BOARD_H
#define ENGINE_BOARD_H

enum BOARD_TYPE {
    EMPTY = 0,
    BOMB = -1,
    ONE_BOMB = 1,
    TWO_BOMB = 2,
    THREE_BOMB = 3,
    FOUR_BOMB = 4,
    FIVE_BOMB = 5,
    SIX_BOMB = 6,
    SEVEN_BOMB = 7,
    EIGHT_BOMB = 8,
};

#define MATRIX_NAME matrix_board
#define MATRIX_TYPE char
#include "tools/matrix.h"
#undef MATRIX_NAME
#undef MATRIX_TYPE

#endif
