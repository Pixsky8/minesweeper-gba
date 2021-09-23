#ifndef ENGINE_RENDERER_H
#define ENGINE_RENDERER_H

#include "engine/board.h"

#define MAX_SQUARE_SIDE 32

/**
 * @brief Display new_type sprite on the screen at specified location
 */
void reveal_square(int x, int y, enum BOARD_TYPE new_type);

/**
 * @brief Put a flag on the tile
 */
void flag_square(int x, int y, bool put_flag);

#endif
