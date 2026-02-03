#include <stdio.h>
#include <stdlib.h>

#include "rigidbody.h"

void Rigidbody_Destroy(Module *self)
{
    Rigidbody *rigidbody = (Rigidbody *)self;
    if (self == NULL)
        return;
    free(rigidbody);

    rigidbody = NULL;
    self = NULL;
}
void Rigidbody_AddForce(Rigidbody *self, Vector vector)
{
    if (self == NULL)
    {
        return;
    }
    self->force = Vector_Sum(self->force, vector);
}
void Rigidbody_Update(float deltaTime);

Rigidbody *Rigidbody_Create(
    Module base,

    double mass,
    double damping)
{
    Rigidbody *newRigidbody = (Rigidbody *)malloc(sizeof(Rigidbody));
    if (newRigidbody == NULL)
    {
        printf("Rigidbody_Create: could not create Rigidbody");
        return NULL;
    }

    newRigidbody->base.type = MODULE_RIGIDBODY;
    newRigidbody->base.owner = NULL;
    newRigidbody->base.update = Rigidbody_Update;
    newRigidbody->base.destroy = Rigidbody_Destroy;

    newRigidbody->acceleration.x = 0;
    newRigidbody->acceleration.y = 0;

    newRigidbody->force.x = 0;
    newRigidbody->force.y = 0;

    newRigidbody->velocity.x = 0;
    newRigidbody->velocity.y = 0;

    newRigidbody->damping = damping;
    newRigidbody->mass = mass;
}
