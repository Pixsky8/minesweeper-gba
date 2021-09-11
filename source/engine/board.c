#include "engine/board.h"

#include "global.h"

void setup_board(void) {
    matrix_board_set(board, 0, 0, BOARD_WIDTH, BOMB);
}
