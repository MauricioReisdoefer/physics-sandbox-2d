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