#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "module.h"
#include "vector.h"

typedef struct Rigidbody
{
    Module base;
    Vector velocity;
    Vector force;
    Vector acceleration;

    double speed;
} Rigidbody;

#endif