#include "engine/board.h"

#include <stdbool.h>
#include <string.h>

#include "engine/renderer.h"
#include "global.h"

void setup_board(void) {
    memset(&g_board, 0, BOARD_SIZE);

    matrix_char_set(g_board, 0, 0, g_game_board_side, BOMB);
    matrix_char_set(g_board, 0, 1, g_game_board_side, ONE_BOMB);
    matrix_char_set(g_board, 1, 0, g_game_board_side, ONE_BOMB);
    matrix_char_set(g_board, 1, 1, g_game_board_side, ONE_BOMB);
}

static inline enum BOARD_TYPE get_square(int x, int y) {
    if (x < 0 || x >= g_game_board_side)
        return OUT_OF_BOUND;
    if (y < 0 || y >= g_game_board_side)
        return OUT_OF_BOUND;
    return matrix_char_get(g_board, x, y, g_game_board_side);
}

bool can_reveal_square(int x, int y) {
    if (is_revealed(x, y))
        return false;

    if (get_square(x, y) == OUT_OF_BOUND)
        return false;

    if (is_flagged(x, y))
        return false;

    return true;
}

bool reveal_square(int x, int y) {
    if (is_revealed(x, y))
        return false;

    enum BOARD_TYPE revealed = get_square(x, y);

    if (revealed == OUT_OF_BOUND)
        return false;

    display_square(x, y, revealed);

    if (revealed == NO_BOMB) {
        reveal_square(x - 1, y);
        reveal_square(x + 1, y);
        reveal_square(x, y - 1);
        reveal_square(x, y + 1);
    }

    if (revealed == BOMB)
        return true;

    return false;
}

void toggle_flag_square(int x, int y) {
    if (is_revealed(x, y))
        return;

    bool should_put_flag = !is_flagged(x, y);
    display_flag_square(x, y, should_put_flag);
}
