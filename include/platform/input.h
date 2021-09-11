//----------------------------------------------
// Game input

#ifndef __INPUT_H__
#define __INPUT_H__

#include "platform/types.h"

//GBA Key definition
#define KEYS (int *) 0x04000130

#define KEY_A      1
#define KEY_B      2
#define KEY_SELECT 4
#define KEY_START  8
#define KEY_RIGHT  16
#define KEY_LEFT   32
#define KEY_UP     64
#define KEY_DOWN   128
#define KEY_R      256
#define KEY_L      512
#define KEY_MASK   0x3FF

//Input Buffers
extern u16 current_key_pressed;
extern u16 previous_key_pressed;

//Function for input handling

inline void refresh_input_buffers(void) {
    previous_key_pressed = current_key_pressed;
    current_key_pressed = (~(*KEYS)) & KEY_MASK;
}

inline int key_positive_edge(int key) {
    return (~(previous_key_pressed & key)) & (current_key_pressed & key);
}

inline int key_negative_edge(int key) {
    return (previous_key_pressed & key) & (~(current_key_pressed & key));
}

inline int key_held(int key) {
    return current_key_pressed & key;
}

#endif
