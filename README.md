# Gerenciador de Tarefas em C

Aplicação de linha de comando desenvolvida em linguagem C para gerenciamento de tarefas.

Este projeto foi desenvolvido como parte do meu portfólio de programação, com o objetivo de praticar fundamentos da linguagem C, organização de código, manipulação de arquivos e persistência de dados.

## Funcionalidades

* Adicionar tarefas
* Listar tarefas cadastradas
* Marcar tarefas como concluídas
* Excluir tarefas
* Validação de entradas
* Geração automática de IDs
* Salvamento das tarefas em arquivo
* Carregamento das tarefas ao iniciar o programa

## Tecnologias utilizadas

* Linguagem C
* GCC
* Dev-C++
* Git
* GitHub

## Estrutura do projeto

```text
gerenciador_de_tarefas_em_C/
│
├── src/
│   ├── Main.c
│   ├── tarefas.c
│   └── tarefas.h
│
├── README.md
├── .gitignore
└── LICENSE
```

## Como funciona

Ao iniciar o programa, as tarefas salvas anteriormente são carregadas automaticamente.

O usuário pode escolher uma das opções disponíveis no menu:

```text
===== GERENCIADOR DE TAREFAS =====
1 - Adicionar tarefa
2 - Listar tarefas
3 - Concluir tarefa
4 - Excluir tarefa
0 - Sair
```

As tarefas são armazenadas em memória durante a execução e salvas em um arquivo binário para que continuem disponíveis quando o programa for executado novamente.

## Exemplo

```text
===== LISTA DE TAREFAS =====
[ ] ID: 1 - Estudar C
[X] ID: 2 - Fazer exercicios
[ ] ID: 3 - Praticar Git
```

`[ ]` representa uma tarefa pendente.

`[X]` representa uma tarefa concluída.

## Como executar

### 1. Clone o repositório

```bash
git clone URL_DO_SEU_REPOSITORIO
```

### 2. Entre na pasta do projeto

```bash
cd gerenciador_de_tarefas_em_C
```

### 3. Compile o programa

Com o GCC instalado:

```bash
gcc src/Main.c src/tarefas.c -o gerenciador
```

### 4. Execute

No Windows:

```bash
gerenciador.exe
```

No Linux:

```bash
./gerenciador
```

## Conceitos praticados

Durante o desenvolvimento deste projeto foram praticados conceitos importantes da linguagem C:

* Variáveis e tipos de dados
* Estruturas (`struct`)
* Vetores
* Funções
* Ponteiros
* Condicionais
* Estruturas de repetição
* `switch`
* Manipulação de strings
* Entrada e saída de dados
* Manipulação de arquivos
* Modularização com arquivos `.c` e `.h`
* Persistência de dados
* Validação de entrada

## O que aprendi

Este projeto foi desenvolvido com foco no aprendizado prático de programação.

Além dos fundamentos da linguagem C, o projeto ajudou a compreender como dividir um programa em diferentes arquivos, organizar responsabilidades e utilizar arquivos para manter dados mesmo após o encerramento da aplicação.

Também foi uma oportunidade para praticar o uso do Git e do GitHub no desenvolvimento de software.

## Melhorias futuras

Algumas melhorias planejadas para versões futuras:

* Editar tarefas
* Pesquisar tarefas
* Filtrar tarefas concluídas e pendentes
* Adicionar prioridade
* Adicionar data de criação
* Adicionar prazo para conclusão
* Melhorar a interface do terminal
* Criar testes automatizados
* Evoluir o projeto para uma aplicação com interface gráfica

## Autor

**Flavio**

Estudante de Ciência da Computação, desenvolvendo projetos práticos para construir experiência em programação e desenvolvimento de software.
