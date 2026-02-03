#include <stdio.h>
#include <stdlib.h>

#include "transform.h"
#include "module.h"
#include "vector.h"

void Transform_Update(float deltaTime)
{
    printf("fodase");
}

void Transform_Destroy(Module *self)
{
    Transform *transform = (Transform *)self;
    if (self == NULL)
        return;
    free(transform);

    transform = NULL;
    self = NULL;
}

Transform *Transform_Create(Vector position, Vector scale, double rotation)
{
    Transform *transform = (Transform *)malloc(sizeof(Transform));
    if (transform == NULL)
    {
        return NULL;
    }
    transform->base.type = MODULE_TRANSFORM;
    transform->base.update = Transform_Update;
    transform->base.destroy = Transform_Destroy;
    transform->base.owner = NULL;

    transform->position = position;
    transform->scale = scale;
    transform->rotation = rotation;

    return transform;
}