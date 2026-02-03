# `Module`

A estrutura `Module` serve como a base para estender a funcionalidade de uma `Entity` no `physics-sandbox-2d`. Ela define uma interface comum para módulos que podem ser anexados, atualizados e destruídos.

## Definição da Estrutura

```c
typedef struct Module
{
    Entity *owner;
    UpdateFunction update;
    DestroyFunction destroy;
    ModuleType type;
} Module;
```

- `owner`: Um ponteiro para a `Entity` à qual este módulo pertence.
- `update`: Um ponteiro para uma função de atualização (`UpdateFunction`) que será chamada periodicamente para este módulo.
- `destroy`: Um ponteiro para uma função de destruição (`DestroyFunction`) responsável por liberar os recursos alocados pelo módulo.
- `type`: Um enumerador `ModuleType` que identifica o tipo específico do módulo.

## Tipos de Funções (Function Pointers)

### `UpdateFunction`

```c
typedef void (*UpdateFunction)(float);
```

**Descrição:** Define a assinatura de uma função de atualização. Módulos que precisam de lógica de atualização baseada no tempo devem implementar uma função com esta assinatura.

**Parâmetros:**

- `deltaTime`: O tempo decorrido desde a última atualização, geralmente em segundos.

### `DestroyFunction`

```c
typedef void (*DestroyFunction)(Module *);
```

**Descrição:** Define a assinatura de uma função de destruição. Cada módulo deve implementar uma função com esta assinatura para liberar corretamente seus recursos quando a `Entity` proprietária for destruída ou o módulo for removido.

**Parâmetros:**

- `self`: Um ponteiro para o `Module` a ser destruído.

## Enumeração `ModuleType`

```c
typedef enum ModuleType
{
    MODULE_DEFAULT,
    MODULE_TRANSFORM,
    MODULE_RIGIDBODY
} ModuleType;
```

**Descrição:** Esta enumeração fornece identificadores únicos para diferentes tipos de módulos. Isso permite que a `Entity` gerencie e recupere módulos específicos por tipo.

- `MODULE_DEFAULT`: Tipo padrão para módulos genéricos ou não especificados.
- `MODULE_TRANSFORM`: Identifica um módulo responsável por gerenciar a posição, escala e rotação de uma entidade.
- `MODULE_RIGIDBODY`: Identifica um módulo que lida com as propriedades físicas de um corpo rígido, como massa, velocidade e forças.
