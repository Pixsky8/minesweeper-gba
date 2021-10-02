#include "platform/input.h"
#include "platform/types.h"

#include "engine/board.h"
#include "engine/renderer.h"
#include "global.h"

void init_game(void) {
    setup_board();
    init_renderer();
}

static void cursor_update(void) {
    if (key_positive_edge(KEY_UP)) {
        if (cursor_y > 0)
            cursor_y--;
    }
    else if (key_positive_edge(KEY_DOWN)) {
        if (cursor_y < MAX_SQUARE_SIDE) // TODO Fix this value
            cursor_y++;
    }

    if (key_positive_edge(KEY_LEFT)) {
        if (cursor_x > 0)
            cursor_x--;
    }
    else if (key_positive_edge(KEY_RIGHT)) {
        if (cursor_x < MAX_SQUARE_SIDE) // TODO Fix this value
            cursor_x++;
    }

    set_cursor_position(cursor_x << 3, cursor_y << 3);
}

void update(void) {
    cursor_update();
}
