#include <stdio.h>
#include <stdlib.h>

#include "transform.h"
#include "module.h"
#include "vector.h"

Transform *Transform_Create(Vector position, Vector scale, double rotation)
{
    Transform *transform = (Transform *)malloc(sizeof(Transform));
    if (transform == NULL)
    {
        return NULL;
    }
    transform->base = Module_Create(MODULE_TRANSFORM, Transform_Update, Transform_Destroy);
    transform->position = position;
    transform->scale = scale;
    transform->rotation = rotation;

    return transform;
}

void Transform_Destroy(Transform *self)
{
    if (self == NULL)
        return;
    Module_Destroy(self->base);
    free(self);
}