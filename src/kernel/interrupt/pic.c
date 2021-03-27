// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (C) 2021 TTG <prs.ttg+gos@pm.me>

#include "include/pic.h"

void _gos_pic_install() {
    gos_io_port_out(_GOS_PIC_MASTER, 0x11);
    gos_io_wait();
    gos_io_port_out(_GOS_PIC_SLAVE, 0x11);
    gos_io_wait();
    gos_io_port_out(_GOS_PIC_DATA_SEL(_GOS_PIC_MASTER), 32);
    gos_io_wait();
    gos_io_port_out(_GOS_PIC_DATA_SEL(_GOS_PIC_SLAVE), 40);
    gos_io_wait();
    gos_io_port_out(_GOS_PIC_DATA_SEL(_GOS_PIC_MASTER), 4);
    gos_io_wait();
    gos_io_port_out(_GOS_PIC_DATA_SEL(_GOS_PIC_SLAVE), 2);
    gos_io_wait();
    gos_io_port_out(_GOS_PIC_DATA_SEL(_GOS_PIC_MASTER), 1);
    gos_io_wait();
    gos_io_port_out(_GOS_PIC_DATA_SEL(_GOS_PIC_SLAVE), 1);
    gos_io_wait();
    gos_io_port_out(_GOS_PIC_DATA_SEL(_GOS_PIC_MASTER), 0x0);
    gos_io_port_out(_GOS_PIC_DATA_SEL(_GOS_PIC_SLAVE), 0x0);
}

void gos_pic_eoi(uint8_t ino) {
    gos_io_port_out((ino - 32) > 0x7 ? _GOS_PIC_SLAVE : _GOS_PIC_MASTER, _GOS_EOI);
}
