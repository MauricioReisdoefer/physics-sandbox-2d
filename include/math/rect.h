#ifndef RECT_H
#define RECT_H

#include <SDL3/SDL.h>

typedef struct Rect
{
    double x;
    double y;
    double scaleX;
    double scaleY;
} Rect;

Rect Rect_Create(double x, double y);
Rect Rect_Zero();
SDL_FRect Rect_ConvertToFRect(Rect rect);

#endif