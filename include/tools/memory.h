#ifndef TOOLS_MEMORY_H
#define TOOLS_MEMORY_H

#include <stddef.h>

/**
 * @brief Same as memet but considers ptr to be an array of shorts
 * @param ptr The array
 * @param new_value The new value of every element of the array
 * @param length The number of short in the array (/!\ NOT THE NUMBER OF BYTES)
 */
static inline void short_memset(void *ptr, short new_value, size_t length) {
    short *cast = ptr;
    for (size_t i = 0; i < length; i++) {
        cast[i] = new_value;
    }
}

#endif
