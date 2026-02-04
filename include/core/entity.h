#ifndef ENTITY_H
#define ENTITY_H

#define MAX_MODULES 32

#include "module.h"

typedef struct Entity
{
    Module *modules[MAX_MODULES];
    int module_count;
} Entity;

Entity *Entity_Create();
void Entity_Destroy(Entity *self);
void Entity_AddModule(Entity *self, Module *module);
void Entity_RemoveModule(Entity *self, ModuleType type);
Module *Entity_GetModule(Entity *self, ModuleType type);

void Entity_Update(Entity *self);

#endif