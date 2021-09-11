#include "engine/board.h"

#include <string.h>

#include "global.h"

void setup_board(void) {
    memset(&board, 0, BOARD_SIZE);

    matrix_char_set(board, 0, 0, BOARD_WIDTH, BOMB);
}
