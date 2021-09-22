#include <string.h>

#include "init.h"
#include "platform/input.h"
#include "platform/interrupts.h"
#include "platform/video.h"
#include "engine/logic.h"

#include "engine/board.h"

int main(void) {
    init_screen();
    init_sprites();
    init_backgrounds();
    init_game();

    for (int i = 1; i <= 8; i++) {
        update_square(i - 1, 0, i);
    }

    while (1) {
        refresh_input_buffers();

        // TODO: Game logic

        obj_buff_to_oam(OBJ_BUFF_SIZE);
        vblank_inter_wait();
    }
}
