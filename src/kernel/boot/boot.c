#include "include/boot.h"

static uint8_t stack[4096];
struct stivale2_header_tag_framebuffer framebuffer_hdr_tag = {
    .tag = {
        .identifier = STIVALE2_HEADER_TAG_FRAMEBUFFER_ID,
        .next = 0 
    },
    .framebuffer_width = GOS_VGA_BUFF_WIDTH,
    .framebuffer_height = GOS_VGA_BUFF_HEIGHT,
    .framebuffer_bpp = 0 
}; __attribute__((section(".stivale2hdr"), used)) 

struct stivale2_header stivale_hdr = {
    .entry_point = 0,
    .stack = (uintptr_t)stack + sizeof(stack),
    .flags = 0, 
};

void *stivale2_get_tag(struct stivale2_struct *stivale2_struct, uint64_t id) {
    struct stivale2_tag *current_tag = (struct stivale2_tag *) stivale2_struct->tags;
    for (;;) {
        if (!current_tag) return NULL; 
        else if (current_tag->identifier == id) return current_tag;
        current_tag = (struct stivale2_tag *) current_tag->next; } 
    }
