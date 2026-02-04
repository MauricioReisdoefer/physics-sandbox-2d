#ifndef COLOR_H
#define COLOR_H

#include <stdint.h>

typedef struct Color
{
    uint8_t r, g, b, a;
} Color;

static const Color COLOR_WHITE = {255, 255, 255, 255};
static const Color COLOR_BLACK = {0, 0, 0, 255};

#endif