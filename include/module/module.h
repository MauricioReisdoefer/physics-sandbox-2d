#ifndef MODULE_H
#define MODULE_H

typedef void (*UpdateFunction)(float);
typedef void (*DestroyFunction)(Module *);

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
    DestroyFunction destroy;
    ModuleType type;
} Module;

Module *Module_Create(ModuleType type, UpdateFunction update, DestroyFunction destroy);
void Module_Destroy(Module *self);

#endif