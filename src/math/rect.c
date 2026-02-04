#include <stdio.h>
#include <stdlib.h>

#include "rect.h"

Rect Rect_Create(double x, double y, double scaleX, double scaleY)
{
    Rect v;
    v.x = x;
    v.y = y;
    v.scaleX = scaleX;
    v.scaleY = scaleY;
    return v;
}

Rect Rect_Zero()
{
    return (Rect){0, 0, 0, 0};
}

SDL_FRect Rect_ConvertToFRect(Rect rect)
{
    SDL_FRect out;
    out.x = (float)rect.x;
    out.y = (float)rect.y;
    out.w = (float)rect.scaleX;
    out.h = (float)rect.scaleY;
    return out;
}