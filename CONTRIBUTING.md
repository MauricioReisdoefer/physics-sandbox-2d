# Guia de Contribuição

Agradecemos o seu interesse em contribuir para o **physics-sandbox-2d**. Este documento estabelece as diretrizes para facilitar o processo de colaboração e garantir a integridade técnica do projeto. Como um ambiente de experimentação focado em matemática e física, prezamos pela clareza do código e pela precisão das simulações.

## Como Contribuir

Existem diversas formas de colaborar com este projeto, desde a correção de falhas até a implementação de novos modelos físicos. Abaixo, detalhamos os procedimentos recomendados para cada tipo de contribuição.

### Relatando Problemas (Bugs)

Caso encontre algum comportamento inesperado ou erro de cálculo nas simulações, encorajamos a abertura de uma **Issue** no GitHub. Ao relatar um problema, procure incluir as seguintes informações:

1. **Descrição detalhada** do erro observado.
2. **Passos para reprodução**, preferencialmente com um exemplo simplificado.
3. **Ambiente de execução** (sistema operacional e versão do compilador GCC).
4. **Comportamento esperado** versus o comportamento obtido.

### Sugestões de Melhorias

Propostas para novas funcionalidades ou otimizações matemáticas são sempre bem-vindas. Recomendamos que grandes mudanças sejam discutidas previamente através de uma Issue para garantir o alinhamento com os objetivos do projeto (foco em simulação 2D pura, sem depender de engines de jogos complexas).

## Padrões de Desenvolvimento

Para manter a consistência da base de código escrita em C, solicitamos que os colaboradores sigam os padrões estabelecidos.

### Estilo de Código

O projeto utiliza uma convenção de nomenclatura específica para facilitar a leitura e evitar conflitos de escopo:

| Elemento | Padrão | Exemplo |
| :--- | :--- | :--- |
| **Arquivos** | snake_case | `new_module.c` |
| **Funções** | PascalCase com prefixo | `Vector_Create()`, `Rigidbody_ApplyForce()` |
| **Tipos/Structs** | PascalCase | `Vector`, `Rigidbody` |
| **Variáveis Locais** | snake_case | `force_magnitude` |

Além disso, utilize **4 espaços** para indentação e mantenha o código modularizado, separando a lógica matemática (`src/math`) dos módulos de simulação (`src/module`).

### Configuração do Ambiente

O projeto depende da biblioteca **SDL3** para renderização e gerenciamento de janelas. Certifique-se de ter a biblioteca instalada e configurada em seu caminho de busca do compilador.

A compilação padrão é realizada via GCC. Um comando de exemplo para compilar o projeto principal é:

```bash
gcc main.c src/core/*.c src/math/*.c src/module/*.c -o sandbox -I include -lSDL3 -lm
```

## Processo de Pull Request

1. Realize o **Fork** do repositório.
2. Crie uma **Branch** para sua funcionalidade ou correção (`git checkout -b feature/nova-simulacao`).
3. Desenvolva sua contribuição seguindo os padrões de código.
4. Certifique-se de que o código compila sem avisos (*warnings*).
5. Envie um **Pull Request** detalhando as alterações realizadas e o motivo da mudança.

## Licença

Ao contribuir para este projeto, você concorda que seu código será licenciado sob a mesma [Licença MIT](LICENSE) que rege o repositório original.
