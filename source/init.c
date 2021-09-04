#include <string.h>

#include "platform/video.h"

#include "sprites/sprites.h"

void init_sprites(void) {
    // Copy sprite palette
    memcpy(PAL_SP, spritesPal, spritesPalLen);

    // Copy sprites
    memcpy(&TILE8_MEM[4][0], spritesTiles, spritesTilesLen);

    obj_buff_init();
}
