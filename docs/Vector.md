# `Vector`

A estrutura `Vector` no `physics-sandbox-2d` representa um vetor 2D simples, fundamental para operações matemáticas e físicas, como posição, velocidade, força e escala. Ela encapsula as coordenadas `x` e `y` de um ponto ou direção no espaço bidimensional.

## Definição da Estrutura

```c
typedef struct Vector
{
    double x;
    double y;
} Vector;
```

- `x`: Um valor `double` que representa a componente horizontal do vetor.
- `y`: Um valor `double` que representa a componente vertical do vetor.

## Funções

### `Vector_Create`

```c
Vector Vector_Create(double x, double y);
```

**Descrição:** Cria e retorna uma nova estrutura `Vector` com as coordenadas `x` e `y` especificadas.

**Parâmetros:**

- `x`: A componente horizontal do vetor.
- `y`: A componente vertical do vetor.

**Retorno:** Uma nova estrutura `Vector` inicializada.

### `Vector_Product`

```c
Vector Vector_Product(Vector a, Vector b);
```

**Descrição:** Realiza o produto componente a componente (Hadamard product) de dois vetores.

**Parâmetros:**

- `a`: O primeiro vetor.
- `b`: O segundo vetor.

**Retorno:** Um novo `Vector` resultante do produto componente a componente.

### `Vector_Sum`

```c
Vector Vector_Sum(Vector a, Vector b);
```

**Descrição:** Realiza a soma de dois vetores, somando suas respectivas componentes.

**Parâmetros:**

- `a`: O primeiro vetor.
- `b`: O segundo vetor.

**Retorno:** Um novo `Vector` resultante da soma.

### `Vector_Subtraction`

```c
Vector Vector_Subtraction(Vector a, Vector b);
```

**Descrição:** Realiza a subtração de dois vetores, subtraindo suas respectivas componentes.

**Parâmetros:**

- `a`: O vetor do qual subtrair.
- `b`: O vetor a ser subtraído.

**Retorno:** Um novo `Vector` resultante da subtração.

### `Vector_Division`

```c
Vector Vector_Division(Vector a, Vector b);
```

**Descrição:** Realiza a divisão componente a componente de dois vetores. Inclui verificação para evitar divisão por zero.

**Parâmetros:**

- `a`: O vetor dividendo.
- `b`: O vetor divisor.

**Retorno:** Um novo `Vector` resultante da divisão. Se ocorrer divisão por zero, um vetor `(0, 0)` é retornado e uma mensagem de erro é impressa.

### `Vector_Product_Double`

```c
Vector Vector_Product_Double(Vector v, double x);
```

**Descrição:** Multiplica um vetor por um escalar (`double`).

**Parâmetros:**

- `v`: O vetor a ser multiplicado.
- `x`: O valor escalar.

**Retorno:** Um novo `Vector` com suas componentes multiplicadas pelo escalar.

### `Vector_Divide_Double`

```c
Vector Vector_Divide_Double(Vector v, double x);
```

**Descrição:** Divide um vetor por um escalar (`double`). Inclui verificação para evitar divisão por zero.

**Parâmetros:**

- `v`: O vetor a ser dividido.
- `x`: O valor escalar.

**Retorno:** Um novo `Vector` com suas componentes divididas pelo escalar. Se ocorrer divisão por zero, um vetor `(0, 0)` é retornado e uma mensagem de erro é impressa.
