#ifndef _GOS_BOOTSTRAP
#define _GOS_BOOTSTRAP

#include "../../../libc/include/stdint.h"
#include "../../../libc/include/stddef.h"
#include "stivale2.h"
#include "../../driver/include/terminal.h"

void *stivale2_get_tag(struct stivale2_struct *stivale2_struct, uint64_t id);

#endif
