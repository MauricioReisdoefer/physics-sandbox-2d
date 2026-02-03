#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "module.h"
#include "vector.h"

typedef struct Transform
{
    Module base;
    Vector position;
    Vector scale;
    double rotation;
} Transform;

Transform *Transform_Create(Vector position, Vector scale, double rotation);
void Transform_Destroy(Module *self);
void Transform_Update(float deltaTime);

#endif