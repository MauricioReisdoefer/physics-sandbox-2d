#include <stdio.h>
#include <stdlib.h>

#include "entity.h"
#include "module.h"

Entity *Entity_Create()
{
    Entity *entity = (Entity *)malloc(sizeof(Entity));
    if (entity == NULL)
    {
        printf("Entity_Create: could not allocate entity\n");
        return NULL;
    }

    entity->module_count = 0;

    for (int i = 0; i < MAX_MODULES; i++)
        entity->modules[i] = NULL;

    return entity;
}

void Entity_Destroy(Entity *self)
{
    if (self == NULL)
    {
        printf("Entity_Destroy: self is NULL\n");
        return;
    }
    for (int i = 0; i < self->module_count; i++)
    {
        if (self->modules[i] != NULL)
        {
            self->modules[i]->destroy(self->modules[i]);
        }
    }
    free(self);
    self = NULL;
}

void Entity_AddModule(Entity *self, Module *module)
{
    if (self == NULL)
    {
        printf("Entity_AddModule: self is NULL\n");
        return;
    }

    if (module == NULL)
    {
        printf("Entity_AddModule: module is NULL\n");
        return;
    }

    if (self->module_count >= MAX_MODULES)
    {
        printf("Entity_AddModule: max modules reached (%d)\n", MAX_MODULES);
        return;
    }

    self->modules[self->module_count++] = module;
}

Module *Entity_GetModule(Entity *self, ModuleType type)
{
    if (self == NULL)
    {
        printf("Entity_GetModule: self is NULL\n");
        return NULL;
    }

    if (self->module_count == 0)
    {
        printf("Entity_GetModule: entity has no modules\n");
        return NULL;
    }

    for (int i = 0; i < self->module_count; i++)
    {
        Module *module = self->modules[i];

        if (module != NULL && module->type == type)
            return module;
    }

    printf("Entity_GetModule: module of requested type not found\n");
    return NULL;
}

void Entity_RemoveModule(Entity *self, ModuleType type)
{
    if (self == NULL)
    {
        printf("Entity_RemoveModule: self is NULL\n");
        return;
    }

    if (self->module_count == 0)
    {
        printf("Entity_RemoveModule: entity has no modules\n");
        return;
    }

    for (int i = 0; i < self->module_count; i++)
    {
        Module *module = self->modules[i];

        if (module != NULL && module->type == type)
        {
            module->destroy(module);

            self->modules[i] = self->modules[self->module_count - 1];
            self->modules[self->module_count - 1] = NULL;
            self->module_count--;

            return;
        }
    }

    printf("Entity_RemoveModule: module of requested type not found\n");
}

void Entity_Update(Entity *self, float deltaTime)
{
    if (self == NULL)
        return;

    for (int i = 0; i < self->module_count; i++)
    {
        Module *module = self->modules[i];
        if (module != NULL)
            module->update(self, deltaTime);
    }
}