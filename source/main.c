#include <string.h>

#include "init.h"
#include "platform/input.h"
#include "platform/interrupts.h"
#include "platform/video.h"

int main(void) {
    // Init VSync
    register_vblank_isr();

    REG_DISPCNT = MODE_0 | BGMODE_0 | BGMODE_1 | ENABLE_OBJECTS | SP_MAPPING_1D;

    init_sprites();
    init_backgrounds();

    while (1) {
        vblank_inter_wait();
        refresh_input_buffers();

        // TODO: Game logic

        obj_buff_to_oam(OBJ_BUFF_SIZE);
    }
}
