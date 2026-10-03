
#ifndef TAREFAS_H
#define TAREFAS_H

#define MAX_TAREFAS 100
#define TAM_DESCRICAO 100

typedef struct {
    int id;
    char descricao[TAM_DESCRICAO];
    int concluida;
} Tarefa;

/* Funções de entrada e tarefas */
void limparBuffer(void);
void adicionarTarefa(Tarefa tarefas[], int *quantidade, int *proximo_id);
void listarTarefas(Tarefa tarefas[], int quantidade);
void concluirTarefa(Tarefa tarefas[], int quantidade);
void excluirTarefa(Tarefa tarefas[], int *quantidade);
void exibirMenu(void);

/* Funções de persistência */
void salvarTarefas(Tarefa tarefas[], int quantidade, int proximo_id);
void carregarTarefas(Tarefa tarefas[], int *quantidade, int *proximo_id);

#endif


