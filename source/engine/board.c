#include "engine/board.h"

#include <string.h>
#include <stdbool.h>

#include "global.h"
#include "engine/renderer.h"

void setup_board(void) {
    memset(&g_board, 0, BOARD_SIZE);

    matrix_char_set(g_board, 0, 0, BOARD_WIDTH, BOMB);
}

static inline enum BOARD_TYPE get_square(int x, int y) {
    if (x < 0 || x >= g_game_board_side)
        return OUT_OF_BOUND;
    if (y < 0 || y >= g_game_board_side)
        return OUT_OF_BOUND;
    return matrix_char_get(g_board, x, y, g_game_board_side);
}

bool reveal_square(int x, int y) {
    enum BOARD_TYPE revealed = get_square(x, y);

    if (revealed == OUT_OF_BOUND)
        return false;

    display_square(x, y, revealed);

    if (revealed == BOMB)
        return true;

    return false;
}
