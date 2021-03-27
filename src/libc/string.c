// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (C) 2021 TTG <prs.ttg+gos@pm.me>

#include "include/string.h"

unsigned long strlen(const char* str) {
    int i = 0;
    while(str[i]) i++;
    return i;
}

int strncmp(const char* a, const char* b, unsigned long n) {
    unsigned long len_a = strlen(a);
    unsigned long len_b = strlen(b);
    if(len_a < n && len_a != len_b) return -1;
    if(len_b < n && len_b != len_a) return -1;
    if(len_a < n) n = len_a;
    if(len_b < n) n = len_b;
    for(unsigned long i = 0; i < n; i++)
        if(a[i] != b[i]) return 1; 
    return 0; 
} 

void strncpy(const char* src, char* dest, unsigned long n) {
    for(unsigned long i = 0; i < n; i++) {
        if(!src[i]) return;
        dest[i] = src[i];
    }
}
