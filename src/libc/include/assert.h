#ifndef _GOS_LIBC_ASSERT
#define _GOS_LIBC_ASSERT

#include "stdint.h"

#define __ASSERT_FUNCTION __func__

void __assert_fail(const char *assertion, const char *file, uint32_t line, const char *function);

#define assert(expr) ((expr) ? ((void) 0) : __assert_fail(# expr, __FILE__, __LINE__, __ASSERT_FUNCTION))

#endif

