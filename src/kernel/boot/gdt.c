// SPDX-License-Identifier: GPL-3.0-or-later 
// Copyright (C) 2021 TTG <prs.ttg+gos@pm.me> 
#include "include/gdt.h" 
gos_gdt_entry _gos_gdt[6]; 
gos_gdt_ptr_T _gos_gdt_ptr; 

void _gos_gdt_flush() {
    asm volatile( "lgdt %0\n" 
        "pushq %%rbp\n" 
        "movq %%rsp, %%rbp\n" 
        "pushq %1\n" 
        "pushq %%rbp\n" 
        "pushfq\n" 
        "pushq %2\n" 
        "pushq $1f\n" 
        "iretq\n" 
        "1:\n" 
        "popq %%rbp\n" 
        "mov %1, %%ds\n" 
        "mov %1, %%es\n" 
        "mov %1, %%fs\n" 
        "mov %1, %%gs\n" 
        "mov %1, %%ss":: "m"(_gos_gdt_ptr), "r"((long long) GOS_GDT_KERNEL_DATA_SELECTOR), "r"((long long) GOS_GDT_KERNEL_CODE_SELECTOR) :"memory" ); 
}

void _gos_gdt_set_gate(int num, uint8_t access, uint8_t gran) { _gos_gdt[num].entry.base_low = 0; 
    _gos_gdt[num].entry.base_middle = 0; 
    _gos_gdt[num].entry.base_high = 0; 
    _gos_gdt[num].entry.limit_low = 0; 
    _gos_gdt[num].entry.granularity = (gran & 0xF0); 
    _gos_gdt[num].entry.access = access; 
} 

void _gos_gdt_install() {
    _gos_gdt_ptr.limit = (sizeof(gos_gdt_entry) * 6) - 1;
    _gos_gdt_ptr.base = (unsigned long int)&_gos_gdt; 

    // Null 
    _gos_gdt_set_gate(0, 0x00, 0x00); 
    // Code 
    _gos_gdt_set_gate(1, 0x9A, 0xCF); 
    _gos_gdt[1].integer |= (1l << 53); 
    _gos_gdt[1].integer &= ~(1l << 54); 
    // Data 
    _gos_gdt_set_gate(2, 0x92, 0xCF); 
    _gos_gdt[2].integer |= (1l << 53); 
    // User Code 
    _gos_gdt_set_gate(3, 0xFA, 0xCF); 
    _gos_gdt[3].integer |= (1l << 53); 
    _gos_gdt[3].integer &= ~(1l << 54); 
    // User Data 
    _gos_gdt_set_gate(4, 0xFA, 0xCF); 
    _gos_gdt[4].integer |= (1l << 53); 
    
    // TODO: TSS 
    _gos_gdt_set_gate(5, 0xF2, 0xCF); 
    
    _gos_gdt_flush(); 
}
