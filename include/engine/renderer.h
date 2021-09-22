#ifndef ENGINE_RENDERER_H
#define ENGINE_RENDERER_H

#include "engine/board.h"

/**
 * @brief Display new_type sprite on the screen at specified location
 */
void reveal_square(int x, int y, enum BOARD_TYPE new_type);

#endif
