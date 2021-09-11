#include <string.h>

#include "init.h"
#include "platform/input.h"
#include "platform/interrupts.h"
#include "platform/video.h"

int main(void) {
    init_screen();
    init_sprites();
    init_backgrounds();

    while (1) {
        refresh_input_buffers();

        // TODO: Game logic

        obj_buff_to_oam(OBJ_BUFF_SIZE);
        vblank_inter_wait();
    }
}
