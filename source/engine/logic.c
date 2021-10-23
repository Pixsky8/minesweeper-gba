#include "platform/input.h"
#include "platform/types.h"

#include "engine/board.h"
#include "engine/renderer.h"
#include "global.h"

void init_game(void) {
    setup_board();
    init_renderer();
}

void restart_game(void) {
    setup_board();
    reset_renderer();
}

void close_game(void) {
    close_renderer();
}

static inline void reveal_all_squares(void) {
    for (int i = 0; i < g_game_board_side; i++) {
        for (int j = 0; j < g_game_board_side; j++)
            reveal_square(i, j);
    }
}

static inline void cursor_update(void) {
    if (key_positive_edge(KEY_UP)) {
        if (g_cursor_y > 0)
            g_cursor_y--;
    }
    else if (key_positive_edge(KEY_DOWN)) {
        if (g_cursor_y < MAX_SQUARE_SIDE) // TODO Fix this value
            g_cursor_y++;
    }

    if (key_positive_edge(KEY_LEFT)) {
        if (g_cursor_x > 0)
            g_cursor_x--;
    }
    else if (key_positive_edge(KEY_RIGHT)) {
        if (g_cursor_x < MAX_SQUARE_SIDE) // TODO Fix this value
            g_cursor_x++;
    }

    set_cursor_position(g_cursor_x << 3, g_cursor_y << 3);
}

void game_update(void) {
    cursor_update();

    if (key_positive_edge(KEY_A) && can_reveal_square(g_cursor_x, g_cursor_y))
        reveal_square(g_cursor_x, g_cursor_y);

    else if (key_positive_edge(KEY_B))
        toggle_flag_square(g_cursor_x, g_cursor_y);

    else if (key_positive_edge(KEY_START))
        restart_game();

    else if (key_positive_edge(KEY_SELECT))
        reveal_all_squares();
}
