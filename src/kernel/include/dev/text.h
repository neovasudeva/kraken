#pragma once

#include <sys/sys.h>
#include <mm/mem.h>

#define TEXT_ADDR       (0xB8000 + VA_HHDM)
#define TEXT_WIDTH      80
#define TEXT_HEIGHT     25

#define TEXT_CMD_PORT   0x3D4
#define TEXT_DATA_PORT  0x3D5
#define HIGH_BYTE_CMD   14
#define LOW_BYTE_CMD    15

typedef enum {
    BLACK = 0,
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    LIGHT_GREY,
    DARK_GREY,
    LIGHT_BLUE,
    LIGHT_GREEN,
    LIGHT_CYAN,
    LIGHT_RED,
    LIGHT_MAGENTA,
    LIGHT_BROWN,
    WHITE
} text_color_t;

void text_write(uint16_t loc, uint8_t c, uint8_t fg, uint8_t bg);

void move_cursor(uint16_t loc);

