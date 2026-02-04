#ifndef RECT_H
#define RECT_H

typedef struct Rect
{
    double x;
    double y;
    double scaleX;
    double scaleY;
} Rect;

Rect Rect_Create(double x, double y);
Rect Rect_Zero();

#endif