#ifndef _GOS_ISR
#define _GOS_ISR

#include "../../../libc/include/stdint.h"

#define GOS_MAX_INO_CALLBACKS 16

#define gos_interrupt_callback(name) void (*name) (uint8_t, uint64_t)

void _gos_isr_install();
void gos_register_interrupt_callback(uint8_t ino, gos_interrupt_callback(callback));

#endif
