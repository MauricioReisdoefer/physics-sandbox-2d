#include <stdio.h>
#include <stdlib.h>

#include "module.h"

Module *Module_Create(ModuleType type, UpdateFunction update, DestroyFunction destroy)
{
    Module *newModule = (Module *)malloc(sizeof(Module));
    if (newModule == NULL)
    {
        printf("Module_Create: module could not created");
        return NULL;
    }
    newModule->type = type;
    newModule->update = update;
    newModule->destroy = destroy;
    return newModule;
}