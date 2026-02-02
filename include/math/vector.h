#ifndef VECTOR_H
#define VECTOR_H

typedef struct Vector
{
    double x;
    double y;
} Vector;

Vector *Vector_Create(double x, double y);
void Vector_Destroy();

Vector *Vector_Product(Vector *a, Vector *b);
Vector *Vector_Sum(Vector *a, Vector *b);
Vector *Vector_Subtraction(Vector *a, Vector *b);
Vector *Vector_Division(Vector *a, Vector *b);

Vector *Vector_Product_Double(Vector *vector, double x);
Vector *Vector_Product_Division(Vector *vector, double x);

#endif