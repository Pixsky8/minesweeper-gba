#ifndef __TYPES_H__
#define __TYPES_H__

#include <stdbool.h>
#include <stdint.h>

// clang-format off
typedef uint8_t     u8;
typedef int8_t      s8;
typedef uint16_t    u16;
typedef int16_t     s16;
typedef uint32_t    u32;
typedef int32_t     s32;

typedef volatile uint8_t    v_u8;
typedef volatile int8_t     v_s8;
typedef volatile uint16_t   v_u16;
typedef volatile int16_t    v_s16;
typedef volatile uint32_t   v_u32;
typedef volatile int32_t    v_s32;
// clang-format on

typedef void (*fnptr)(void);

#endif
