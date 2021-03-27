// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (C) 2021 TTG <prs.ttg+gos@pm.me>

#include "include/kio.h"

void gos_io_port_out(uint16_t port, uint8_t value) {
    asm("outb %1, %0"::"Nd"(port),"a"(value):"memory");
}

uint8_t gos_io_port_in(uint16_t port) {
    uint8_t ret;
    asm("inb %1, %0":"=a"(ret):"Nd"(port));
    return ret;
}

uint16_t gos_io_port_in_16(uint16_t port) {
    uint16_t ret;
    asm("inw %1, %0":"=a"(ret):"Nd"(port));
    return ret;
}
