#ifndef ENGINE_BOARD_H
#define ENGINE_BOARD_H

#include <stdbool.h>

#include "tools/basic_matrix.h"

#define MAX_SQUARE_SIDE 32

// This enum matches the sprite sheet
enum BOARD_TYPE {
    OUT_OF_BOUND = -1,
    NO_BOMB = 0,
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

enum BOARD_DISPLAY_TYPE {
    HIDDEN = 0,
    REVEALED = 1,
    FLAGGED = 2,
};

void setup_board(void);

/**
 * @brief Reveal a square
 * @return True if there is a bomb at the location
 */
bool reveal_square(int x, int y);

#endif
