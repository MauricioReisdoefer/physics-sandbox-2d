#include <stdio.h>
#include <stdlib.h>

#include "transform.h"
#include "module.h"
#include "entity.h"
#include "vector.h"

const Vector NEUTRAL_VECTOR = {0, 0};

int main()
{
    printf("Oi");
    Entity *firstEntity = Entity_Create();
    printf("Oi2");
    Transform *firstTransform = Transform_Create(NEUTRAL_VECTOR, NEUTRAL_VECTOR, 0);
    printf("Oi3");

    Entity_AddModule(firstEntity, (Module *)firstTransform);
    printf("Oi4");
    Transform *anotherTransfrom = (Transform *)Entity_GetModule(firstEntity, MODULE_TRANSFORM);
    printf("Oi5");

    Entity_Destroy(firstEntity);
    printf("Oi6");
    printf("%d", firstTransform->position.x);
    printf("Oi7");
    return 0;
}