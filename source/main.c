#include <string.h>

#include "engine/logic.h"
#include "init.h"
#include "platform/input.h"
#include "platform/interrupts.h"
#include "platform/video.h"

// TMP include
#include "engine/board.h"
#include "engine/renderer.h"
#include <stddef.h>

int main(void) {
    init_screen();
    init_sprites();
    init_backgrounds();
    init_game();

    while (1) {
        refresh_input_buffers();

        update();

        obj_buff_to_oam(OBJ_BUFF_SIZE);
        vblank_inter_wait();
    }
}
