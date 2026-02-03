#include <stdio.h>
#include <stdlib.h>

#include "entity.h"
#include "module.h"

Entity *Entity_Create()
{
    Entity *entity = (Entity *)malloc(sizeof(Entity));
    if (entity == NULL)
    {
        printf("Entity_Create: entity could not created");
        return NULL;
    }
    entity->module_count = 0;
    return entity;
}
void Entity_Destroy(Entity *self)
{
    if (self == NULL)
        return;
    if (self->module_count > 0)
    {
        for (int i = 0; i < self->module_count; i++)
        {
            Module_Destroy(self->modules[i]);
        }
    }
    free(self);
}