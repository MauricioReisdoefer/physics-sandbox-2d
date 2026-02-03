# `Entity`

A estrutura `Entity` é um componente fundamental no `physics-sandbox-2d`, representando um objeto no ambiente de simulação. Uma `Entity` pode agregar múltiplos `Modules`, que estendem sua funcionalidade, como transformação, propriedades físicas, etc.

## Definição da Estrutura

```c
typedef struct Entity
{
    Module *modules[MAX_MODULES];
    int module_count;
} Entity;
```

- `modules`: Um array de ponteiros para `Module`, representando os módulos anexados a esta entidade. O número máximo de módulos é definido por `MAX_MODULES` (atualmente 32).
- `module_count`: O número atual de módulos anexados à entidade.

## Funções

### `Entity_Create`

```c
Entity *Entity_Create();
```

**Descrição:** Aloca e inicializa uma nova estrutura `Entity`.

**Retorno:** Um ponteiro para a `Entity` recém-criada, ou `NULL` em caso de falha na alocação de memória.

### `Entity_Destroy`

```c
void Entity_Destroy(Entity *self);
```

**Descrição:** Libera a memória alocada para a `Entity` e todos os seus módulos anexados. Cada módulo é destruído individualmente através de sua função `destroy`.

**Parâmetros:**

- `self`: Um ponteiro para a `Entity` a ser destruída.

### `Entity_AddModule`

```c
void Entity_AddModule(Entity *self, Module *module);
```

**Descrição:** Adiciona um `Module` à `Entity`. Se o número máximo de módulos for atingido, o módulo não será adicionado.

**Parâmetros:**

- `self`: Um ponteiro para a `Entity` à qual o módulo será adicionado.
- `module`: Um ponteiro para o `Module` a ser adicionado.

### `Entity_RemoveModule`

```c
void Entity_RemoveModule(Entity *self, ModuleType type);
```

**Descrição:** Remove e destrói um `Module` da `Entity` com base no seu `ModuleType`. Se múltiplos módulos do mesmo tipo existirem, apenas o primeiro encontrado será removido.

**Parâmetros:**

- `self`: Um ponteiro para a `Entity` da qual o módulo será removido.
- `type`: O `ModuleType` do módulo a ser removido.

### `Entity_GetModule`

```c
Module *Entity_GetModule(Entity *self, ModuleType type);
```

**Descrição:** Retorna um ponteiro para um `Module` específico anexado à `Entity` com base no seu `ModuleType`.

**Parâmetros:**

- `self`: Um ponteiro para a `Entity` da qual o módulo será recuperado.
- `type`: O `ModuleType` do módulo a ser retornado.

**Retorno:** Um ponteiro para o `Module` encontrado, ou `NULL` se nenhum módulo do tipo especificado for encontrado ou se a entidade não tiver módulos.
