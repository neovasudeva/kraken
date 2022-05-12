#pragma once

#define UNUSED(expr)                ((void) expr)
#define ALIGN_DOWN(addr, align)     ((uintptr_t) ((addr) & ~(align - 1)))
#define ALIGN_UP(addr, align)       ((uintptr_t) ((addr + align - 1) & ~(align - 1)))
#define BITS2BYTES(bits)            ((bits / 8) + (bits % 8 ? 1 : 0))

#define MIN(a, b)   ((a < b) ? (a) : (b))
#define MAX(a, b)   ((a > b) ? (a) : (b))

#define KiB  (1 << 10)
#define MiB  (1 << 20)
#define GiB  (1 << 30)