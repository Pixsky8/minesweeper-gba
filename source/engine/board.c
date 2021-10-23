#include "engine/board.h"

#include <stdbool.h>
#include <string.h>

#include "engine/renderer.h"
#include "global.h"
#include "tools/rng.h"

static inline enum BOARD_TYPE get_square(int x, int y) {
    if (x < 0 || x >= g_game_board_side)
        return OUT_OF_BOUND;
    if (y < 0 || y >= g_game_board_side)
        return OUT_OF_BOUND;
    return matrix_char_get(g_board, x, y, g_game_board_side);
}

static inline void plant_bomb(int x, int y) {
    matrix_char_set(g_board, x, y, g_game_board_side, BOMB);

    for (int curr_x = -1; curr_x <= 1; curr_x++) {
        for (int curr_y = -1; curr_y <= 1; curr_y++) {
            if (curr_x == 0 && curr_y == 0)
                continue;

            enum BOARD_TYPE curr = get_square(x + curr_x, y + curr_y);

            if (curr == BOMB || curr == OUT_OF_BOUND)
                continue;

            matrix_char_set(g_board,
                            x + curr_x,
                            y + curr_y,
                            g_game_board_side,
                            curr + 1);
        }
    }
}

void setup_board(void) {
    memset(&g_board, 0, BOARD_SIZE);

    for (int i = 0; i < g_bomb_number; i++) {
        random();
        random();
        random();
        bool bomb_planted = false;
        while (!bomb_planted) {
            int x = ((unsigned) random()) % g_game_board_side;
            int y = ((unsigned) random()) % g_game_board_side;

            if (get_square(x, y) == BOMB)
                continue;

            plant_bomb(x, y);
            bomb_planted = true;
        }
    }
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
        reveal_square(x + 1, y + 1);
        reveal_square(x + 1, y - 1);
        reveal_square(x - 1, y + 1);
        reveal_square(x - 1, y - 1);
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
