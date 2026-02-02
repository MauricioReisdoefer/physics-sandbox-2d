#ifndef MODULE_H
#define MODULE_H

typedef void (*UpdateFunction)(int deltaTime);

typedef enum ModuleType
{
    MODULE_DEFAULT,
    MODULE_TRANSFORM,
    MODULE_RIGIDBODY
} ModuleType;

typedef struct Entity Entity;

typedef struct Module
{
    Entity *owner;
    UpdateFunction update;
    ModuleType type;
} Module;

Module *Module_Create(ModuleType type, UpdateFunction update, Entity *owner);
void Module_Destroy(Module *self);

#endif