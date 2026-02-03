#include <stdio.h>
#include <stdlib.h>

#include "transform.h"
#include "module.h"
#include "entity.h"
#include "vector.h"

const Vector NEUTRAL_VECTOR = {0, 0};

int main()
{
    Entity *firstEntity = Entity_Create();
    Transform *firstTransform = Transform_Create(NEUTRAL_VECTOR, NEUTRAL_VECTOR, 0);

    Entity_AddModule(firstEntity, (Module *)firstTransform);
    Transform *anotherTransfrom = (Transform *)Entity_GetModule(firstEntity, MODULE_TRANSFORM);

    Entity_Destroy(firstEntity);
    return 0;
}