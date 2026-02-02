#ifndef MODULE_H
#define MOUDLE_H

typedef void (*UpdateFunction)(int deltaTime);

typedef enum ModuleType
{
    MODULE_DEFAULT,
    MODULE_TRANSFORM,
    MODULE_RIGIDBODY
} ModuleType;

typedef struct Module
{
    UpdateFunction update;
    ModuleType type;
} Module;

Module *Module_Create(ModuleType type, UpdateFunction update);
void Module_Destroy(Module *self);

#endif