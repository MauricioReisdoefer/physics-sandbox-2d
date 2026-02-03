# `Transform`

A estrutura `Transform` é um `Module` especializado no `physics-sandbox-2d` que gerencia a posição, escala e rotação de uma `Entity` no espaço 2D. É um componente essencial para definir a geometria e o estado espacial de qualquer objeto na simulação.

## Definição da Estrutura

```c
typedef struct Transform
{
    Module base;
    Vector position;
    Vector scale;
    double rotation;
} Transform;
```

- `base`: Uma estrutura `Module` aninhada, permitindo que `Transform` seja tratado como um `Module` genérico e se beneficie da gestão de módulos da `Entity`.
- `position`: Um `Vector` 2D que representa a posição da `Entity` no espaço global.
- `scale`: Um `Vector` 2D que define a escala da `Entity` ao longo dos eixos X e Y.
- `rotation`: Um valor `double` que indica a rotação da `Entity`, geralmente em radianos.

## Funções

### `Transform_Create`

```c
Transform *Transform_Create(Vector position, Vector scale, double rotation);
```

**Descrição:** Aloca e inicializa uma nova estrutura `Transform` com os valores de posição, escala e rotação fornecidos. Também configura os ponteiros de função `update` e `destroy` da `base` `Module`.

**Parâmetros:**

- `position`: Um `Vector` que define a posição inicial da transformação.
- `scale`: Um `Vector` que define a escala inicial da transformação.
- `rotation`: Um `double` que define a rotação inicial da transformação.

**Retorno:** Um ponteiro para a `Transform` recém-criada, ou `NULL` em caso de falha na alocação de memória.

### `Transform_Destroy`

```c
void Transform_Destroy(Module *self);
```

**Descrição:** Libera a memória alocada para a estrutura `Transform`. Esta função é projetada para ser usada como a função `destroy` do `Module` base.

**Parâmetros:**

- `self`: Um ponteiro para o `Module` base da `Transform` a ser destruída.

### `Transform_Update`

```c
void Transform_Update(float deltaTime);
```

**Descrição:** Uma função de atualização para a `Transform`. Atualmente, esta função não implementa nenhuma lógica de atualização específica, mas está presente para cumprir a interface `UpdateFunction` do `Module`.

**Parâmetros:**

- `deltaTime`: O tempo decorrido desde a última atualização (não utilizado na implementação atual).
