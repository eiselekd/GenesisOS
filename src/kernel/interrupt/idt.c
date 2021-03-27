// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (C) 2021 TTG <prs.ttg+gos@pm.me>
#include "include/idt.h" 
#include "../include/kio.h" 

gos_idt_entry_T _gos_idt[GOS_IDT_GATE_LIMIT]; 
gos_idt_ptr_T _gos_idt_ptr; 

void _gos_idt_set_gate(uint8_t num, uint64_t base, uint16_t sel, uint8_t type, bool active) { 
    _gos_idt[num].offset_low = (base >> 0) & 0xFFFF; 
    _gos_idt[num].offset_mid = (base >> 16) & 0xFFFF; 
    _gos_idt[num].offset_high = (base >> 32); 
    _gos_idt[num].zero = 0; 
    _gos_idt[num].selector = sel; 
    _gos_idt[num].ist = 0; 
    // FIXME: TSS 
    _gos_idt[num].type_attr = 0; 
    _gos_idt[num].type_attr = type | /* FIXME: DPL Rings boot/ src/*/ (active ? 1 << 7 : 0); 
} 

void _gos_idt_install() {
    _gos_idt_ptr.limit = (sizeof(gos_idt_entry_T) *GOS_IDT_GATE_LIMIT) - 1;
    _gos_idt_ptr.base = &_gos_idt[0]; 
    for(char* i = (char*) &_gos_idt[0]; ((unsigned long) i) < sizeof(gos_idt_entry_T) *GOS_IDT_GATE_LIMIT; i++) 
        i = 0; 

    asm("lidt %0"::"m"(_gos_idt_ptr):"memory"); __asm__("sti"); 
}
