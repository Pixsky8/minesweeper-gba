#ifndef ENGINE_BOARD_H
#define ENGINE_BOARD_H

#include "tools/basic_matrix.h"

// This enum matches the sprite sheet
enum BOARD_TYPE {
    EMPTY = 0,
    ONE_BOMB = 1,
    TWO_BOMB = 2,
    THREE_BOMB = 3,
    FOUR_BOMB = 4,
    FIVE_BOMB = 5,
    SIX_BOMB = 6,
    SEVEN_BOMB = 7,
    EIGHT_BOMB = 8,
    BOMB = 10,
};

void setup_board(void);

#endif
