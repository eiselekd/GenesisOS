// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (C) 2021 TTG <prs.ttg+gos@pm.me> 
#include "include/isr.h"
#include "include/idt.h" 
#include "include/pic.h" 
#include "../boot/include/gdt.h" 
#include "../include/kio.h" 
uint64_t _gos_interrupt_callbacks[GOS_IDT_GATE_LIMIT][GOS_MAX_INO_CALLBACKS]; 
void gos_register_interrupt_callback(uint8_t ino, gos_interrupt_callback(callback)) { 
    for(int i = 0;;i++) if(!_gos_interrupt_callbacks[ino][i]) {
            _gos_interrupt_callbacks[ino][i] = (uint64_t) callback;
        return;
    }
}

void _gos_interrupt_handler(uint64_t ino, uint64_t rax) {
    for(int i = 0; _gos_interrupt_callbacks[ino][i]; i++) ((gos_interrupt_callback()) _gos_interrupt_callbacks[ino][i])(*(uint8_t*) &ino, rax);
    if(ino > 31 && ino < 48) gos_pic_eoi(ino); 
}

extern void _gos_isr_stub(); 
extern void _gos_isr_syscall(); 
extern void _gos_isr0(); 
extern void _gos_isr1(); 
extern void _gos_isr2(); 
extern void _gos_isr3(); 
extern void _gos_isr4(); 
extern void _gos_isr5(); 
extern void _gos_isr6(); 
extern void _gos_isr7(); 
extern void _gos_isr8(); 
extern void _gos_isr9(); 
extern void _gos_isr10(); 
extern void _gos_isr11(); 
extern void _gos_isr12(); 
extern void _gos_isr13(); 
extern void _gos_isr14(); 
extern void _gos_isr16(); 
extern void _gos_isr17(); 
extern void _gos_isr18(); 
extern void _gos_isr19(); 
extern void _gos_isr21(); 
extern void _gos_isr28(); 
extern void _gos_isr29(); 
extern void _gos_isr30(); 
extern void _gos_irq0(); 
extern void _gos_irq1(); 
extern void _gos_irq2(); 
extern void _gos_irq3(); 
extern void _gos_irq4(); 
extern void _gos_irq5(); 
extern void _gos_irq6(); 
extern void _gos_irq7(); 
extern void _gos_irq8(); 
extern void _gos_irq9(); 
extern void _gos_irq10(); 
extern void _gos_irq11(); 
extern void _gos_irq12(); 
extern void _gos_irq13(); 
extern void _gos_irq14(); 
extern void _gos_irq15(); 
void _gos_isr_install() { 
    for(int i = 0; i < GOS_IDT_GATE_LIMIT; i++) for(int j = 0; j < GOS_MAX_INO_CALLBACKS; j++) _gos_interrupt_callbacks[i][j] = 0; 
    _gos_idt_set_gate(80, (uint64_t) _gos_isr_syscall, GOS_GDT_KERNEL_CODE_SELECTOR, GOS_IDT_TYPE_INT32, true);
    _gos_idt_set_gate(0, (uint64_t) _gos_isr0, GOS_GDT_KERNEL_CODE_SELECTOR, GOS_IDT_TYPE_TRAP32, true);
    _gos_idt_set_gate(1, (uint64_t) _gos_isr1, GOS_GDT_KERNEL_CODE_SELECTOR, GOS_IDT_TYPE_TRAP32, true);
    _gos_idt_set_gate(2, (uint64_t) _gos_isr2, GOS_GDT_KERNEL_CODE_SELECTOR, GOS_IDT_TYPE_TRAP32, true);
    _gos_idt_set_gate(3, (uint64_t) _gos_isr3, GOS_GDT_KERNEL_CODE_SELECTOR, GOS_IDT_TYPE_TRAP32, true);
    _gos_idt_set_gate(4, (uint64_t) _gos_isr4, GOS_GDT_KERNEL_CODE_SELECTOR, GOS_IDT_TYPE_TRAP32, true); 
    _gos_idt_set_gate(5, (uint64_t) _gos_isr5, GOS_GDT_KERNEL_CODE_SELECTOR, GOS_IDT_TYPE_TRAP32, true); 
    _gos_idt_set_gate(6, (uint64_t) _gos_isr6, GOS_GDT_KERNEL_CODE_SELECTOR, GOS_IDT_TYPE_TRAP32, true); 
    _gos_idt_set_gate(7, (uint64_t) _gos_isr7, GOS_GDT_KERNEL_CODE_SELECTOR, GOS_IDT_TYPE_TRAP32, true); 
    _gos_idt_set_gate(8, (uint64_t) _gos_isr8, GOS_GDT_KERNEL_CODE_SELECTOR, GOS_IDT_TYPE_TRAP32, true); 
    _gos_idt_set_gate(9, (uint64_t) _gos_isr9, GOS_GDT_KERNEL_CODE_SELECTOR, GOS_IDT_TYPE_TRAP32, true); 
    _gos_idt_set_gate(10, (uint64_t) _gos_isr10, GOS_GDT_KERNEL_CODE_SELECTOR, GOS_IDT_TYPE_TRAP32, true); 
    _gos_idt_set_gate(11, (uint64_t) _gos_isr11, GOS_GDT_KERNEL_CODE_SELECTOR, GOS_IDT_TYPE_TRAP32, true); 
    _gos_idt_set_gate(12, (uint64_t) _gos_isr12, GOS_GDT_KERNEL_CODE_SELECTOR, GOS_IDT_TYPE_TRAP32, true); 
    _gos_idt_set_gate(13, (uint64_t) _gos_isr13, GOS_GDT_KERNEL_CODE_SELECTOR, GOS_IDT_TYPE_TRAP32, true); 
    _gos_idt_set_gate(14, (uint64_t) _gos_isr14, GOS_GDT_KERNEL_CODE_SELECTOR, GOS_IDT_TYPE_TRAP32, true); 
    _gos_idt_set_gate(15, (uint64_t) _gos_isr_stub, GOS_GDT_KERNEL_CODE_SELECTOR, GOS_IDT_TYPE_TRAP32, true); 
    _gos_idt_set_gate(16, (uint64_t) _gos_isr16, GOS_GDT_KERNEL_CODE_SELECTOR, GOS_IDT_TYPE_TRAP32, true); 
    _gos_idt_set_gate(17, (uint64_t) _gos_isr17, GOS_GDT_KERNEL_CODE_SELECTOR, GOS_IDT_TYPE_TRAP32, true); 
    _gos_idt_set_gate(18, (uint64_t) _gos_isr18, GOS_GDT_KERNEL_CODE_SELECTOR, GOS_IDT_TYPE_TRAP32, true); 
    _gos_idt_set_gate(19, (uint64_t) _gos_isr19, GOS_GDT_KERNEL_CODE_SELECTOR, GOS_IDT_TYPE_TRAP32, true); 
    _gos_idt_set_gate(20, (uint64_t) _gos_isr_stub, GOS_GDT_KERNEL_CODE_SELECTOR, GOS_IDT_TYPE_TRAP32, true); 
    _gos_idt_set_gate(21, (uint64_t) _gos_isr21, GOS_GDT_KERNEL_CODE_SELECTOR, GOS_IDT_TYPE_TRAP32, true); 
    _gos_idt_set_gate(22, (uint64_t) _gos_isr_stub, GOS_GDT_KERNEL_CODE_SELECTOR, GOS_IDT_TYPE_TRAP32, true); 
    _gos_idt_set_gate(23, (uint64_t) _gos_isr_stub, GOS_GDT_KERNEL_CODE_SELECTOR, GOS_IDT_TYPE_TRAP32, true); 
    _gos_idt_set_gate(24, (uint64_t) _gos_isr_stub, GOS_GDT_KERNEL_CODE_SELECTOR, GOS_IDT_TYPE_TRAP32, true); 
    _gos_idt_set_gate(25, (uint64_t) _gos_isr_stub, GOS_GDT_KERNEL_CODE_SELECTOR, GOS_IDT_TYPE_TRAP32, true); 
    _gos_idt_set_gate(26, (uint64_t) _gos_isr_stub, GOS_GDT_KERNEL_CODE_SELECTOR, GOS_IDT_TYPE_TRAP32, true); 
    _gos_idt_set_gate(27, (uint64_t) _gos_isr_stub, GOS_GDT_KERNEL_CODE_SELECTOR, GOS_IDT_TYPE_TRAP32, true); 
    _gos_idt_set_gate(28, (uint64_t) _gos_isr28, GOS_GDT_KERNEL_CODE_SELECTOR, GOS_IDT_TYPE_TRAP32, true); 
    _gos_idt_set_gate(29, (uint64_t) _gos_isr29, GOS_GDT_KERNEL_CODE_SELECTOR, GOS_IDT_TYPE_TRAP32, true); 
    _gos_idt_set_gate(30, (uint64_t) _gos_isr30, GOS_GDT_KERNEL_CODE_SELECTOR, GOS_IDT_TYPE_TRAP32, true); 
    _gos_idt_set_gate(31, (uint64_t) _gos_isr_stub, GOS_GDT_KERNEL_CODE_SELECTOR, GOS_IDT_TYPE_TRAP32, true); 
    _gos_idt_set_gate(32, (uint64_t)_gos_irq0, GOS_GDT_KERNEL_CODE_SELECTOR, GOS_IDT_TYPE_INT32, true); 
    _gos_idt_set_gate(33, (uint64_t)_gos_irq1, GOS_GDT_KERNEL_CODE_SELECTOR, GOS_IDT_TYPE_INT32, true); 
    _gos_idt_set_gate(34, (uint64_t)_gos_irq2, GOS_GDT_KERNEL_CODE_SELECTOR, GOS_IDT_TYPE_INT32, true); 
    _gos_idt_set_gate(35, (uint64_t)_gos_irq3, GOS_GDT_KERNEL_CODE_SELECTOR, GOS_IDT_TYPE_INT32, true); 
    _gos_idt_set_gate(36, (uint64_t)_gos_irq4, GOS_GDT_KERNEL_CODE_SELECTOR, GOS_IDT_TYPE_INT32, true); 
    _gos_idt_set_gate(37, (uint64_t)_gos_irq5, GOS_GDT_KERNEL_CODE_SELECTOR, GOS_IDT_TYPE_INT32, true); 
    _gos_idt_set_gate(38, (uint64_t)_gos_irq6, GOS_GDT_KERNEL_CODE_SELECTOR, GOS_IDT_TYPE_INT32, true); 
    _gos_idt_set_gate(39, (uint64_t)_gos_irq7, GOS_GDT_KERNEL_CODE_SELECTOR, GOS_IDT_TYPE_INT32, true); 
    _gos_idt_set_gate(40, (uint64_t)_gos_irq8, GOS_GDT_KERNEL_CODE_SELECTOR, GOS_IDT_TYPE_INT32, true); 
    _gos_idt_set_gate(41, (uint64_t)_gos_irq9, GOS_GDT_KERNEL_CODE_SELECTOR, GOS_IDT_TYPE_INT32, true); 
    _gos_idt_set_gate(42, (uint64_t)_gos_irq10, GOS_GDT_KERNEL_CODE_SELECTOR, GOS_IDT_TYPE_INT32, true); 
    _gos_idt_set_gate(43, (uint64_t)_gos_irq11, GOS_GDT_KERNEL_CODE_SELECTOR, GOS_IDT_TYPE_INT32, true); 
    _gos_idt_set_gate(44, (uint64_t)_gos_irq12, GOS_GDT_KERNEL_CODE_SELECTOR, GOS_IDT_TYPE_INT32, true); 
    _gos_idt_set_gate(45, (uint64_t)_gos_irq13, GOS_GDT_KERNEL_CODE_SELECTOR, GOS_IDT_TYPE_INT32, true); 
    _gos_idt_set_gate(46, (uint64_t)_gos_irq14, GOS_GDT_KERNEL_CODE_SELECTOR, GOS_IDT_TYPE_INT32, true); 
    _gos_idt_set_gate(47, (uint64_t)_gos_irq15, GOS_GDT_KERNEL_CODE_SELECTOR, GOS_IDT_TYPE_INT32, true); 
}
