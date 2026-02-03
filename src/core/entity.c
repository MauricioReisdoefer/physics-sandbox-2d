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

void Entity_AddModule(Entity *self, Module *module)
{
    if (self == NULL)
        return;

    if (module == NULL)
        return;

    if (self->module_count >= MAX_MODULES)
    {
        printf("Entity_AddModule: max modules reachead");
        return;
    }
    self->modules[self->module_count] = module;
    self->module_count++;
}

Module *Entity_GetModule(Entity *self, ModuleType type)
{
    if (self == NULL)
        return NULL;

    if (self->module_count <= 0)
    {
        printf("Entity_GetModule: no modules inside the entity");
        return NULL;
    }

    for (int i = 0; i < self->module_count; i++)
    {
        if (self->modules[i] != NULL && self->modules[i]->type == type)
        {
            return self->modules[i];
        }
    }
    return NULL;
}

void Entity_RemoveModule(Entity *self, ModuleType type)
{
    if (self == NULL || self->module_count == 0)
        return;

    for (int i = 0; i < self->module_count; i++)
    {
        Module *module = self->modules[i];

        if (module != NULL && module->type == type)
        {
            Module_Destroy(module);

            self->modules[i] = self->modules[self->module_count - 1];
            self->modules[self->module_count - 1] = NULL;

            self->module_count--;
            return;
        }
    }
}