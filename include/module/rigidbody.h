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

    double mass;
    double damping;
} Rigidbody;

Rigidbody *Rigidbody_Create(
    Module base,
    Vector velocity,
    Vector force,
    Vector acceleration,

    double mass,
    double damping);

void Rigidbody_Destroy(Rigidbody *self);
void Rigidbody_AddForce(Rigidbody *self, Vector vector);
void Rigidbody_Update(float deltaTime);

#endif