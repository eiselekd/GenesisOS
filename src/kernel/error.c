// SPDX-License-Identifier: GPL-3.0-or-later 
// Copyright (C) 2021 TTG <prs.ttg+gos@pm.me> 

#include "include/error.h" 
#include "driver/include/terminal.h" 

const char* _gos_exception_messages[] = { "Divide By Zero Error", "Debug", "Non Maskable Interrupt", "Breakpoint", "Overflow", "Out of Bounds", "Invalid Opcode", "No Coprocessor", "Double Fault", "Coprocessor Segment Overrun", "Bad TSS", "Segment Not Present", "Stack Fault", "General Protection Fault", "Page Fault", "", "Floating Point", "Alignment Check", "Machine Check", "SIMD Floating Point", "", "Control Protection Exception", "", "", "", "", "", "", "Hypervisor Injection Exception", "VMM Communication", "Security Exception", "" }; 

void _gos_exception_handler(uint8_t ino, uint64_t rax) { 
    (void) rax; 
    gos_panic(_gos_exception_messages[ino]); 
} __attribute__((noreturn)) 

void gos_panic(const char* msg) { 
    gos_terminal_clear(GOS_VGA_COLOR_RED); 
    gos_terminal_setcursor((GOS_VGA_BUFF_WIDTH / 2) - 6, 0); 
    gos_terminal_puts("DON'T PANIC!\n"); 
    gos_terminal_setcursor((GOS_VGA_BUFF_WIDTH / 2) - 29, 2); 
    gos_terminal_puts("Actually, do panic. Even I'm panicking, and I'm the kernel!\n"); 
    gos_terminal_setcursor((GOS_VGA_BUFF_WIDTH / 2) - 23, 4); 
    gos_terminal_puts("This was triggered by the following exception:\n"); 
    int len = 0; 
    for(; msg[len]; len++); 
    gos_terminal_setcursor((GOS_VGA_BUFF_WIDTH / 2) - (len / 2), 5); 
    gos_terminal_puts(msg); 
    while(1) __asm__("hlt"); 
}
