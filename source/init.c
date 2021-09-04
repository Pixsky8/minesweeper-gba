#include <string.h>

#include "platform/video.h"

#include "backgrounds/background.h"
#include "sprites/sprites.h"

#define CHARACTER_BASE_BLOCK 0

void init_sprites(void) {
    // Copy sprite palette
    memcpy(PAL_SP, spritesPal, spritesPalLen);

    // Copy sprites
    memcpy(&TILE8_MEM[4][0], spritesTiles, spritesTilesLen);

    obj_buff_init();
}

void init_backgrounds(void) {
    // Copy background palette
    memcpy(PAL_BG, backgroundPal, backgroundPalLen);

    // Copy background tiles
    memcpy(&TILE_MEM[CHARACTER_BASE_BLOCK][0],
           backgroundTiles,
           backgroundTilesLen);
}
