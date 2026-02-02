#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

Vector Vector_Create(double x, double y)
{
    Vector v;
    v.x = x;
    v.y = y;
    return v;
}

Vector Vector_Product(Vector a, Vector b)
{
    return (Vector){
        a.x * b.x,
        a.y * b.y};
}

Vector Vector_Sum(Vector a, Vector b)
{
    return (Vector){
        a.x + b.x,
        a.y + b.y};
}

Vector Vector_Subtraction(Vector a, Vector b)
{
    return (Vector){
        a.x - b.x,
        a.y - b.y};
}

Vector Vector_Division(Vector a, Vector b)
{
    if (b.x == 0 || b.y == 0)
    {
        printf("Vector_Division: division by zero\n");
        return (Vector){0, 0};
    }

    return (Vector){
        a.x / b.x,
        a.y / b.y};
}

Vector Vector_Product_Double(Vector v, double x)
{
    return (Vector){
        v.x * x,
        v.y * x};
}

Vector Vector_Divide_Double(Vector v, double x)
{
    if (x == 0)
    {
        printf("Vector_Divide_Double: division by zero\n");
        return (Vector){0, 0};
    }

    return (Vector){
        v.x / x,
        v.y / x};
}
