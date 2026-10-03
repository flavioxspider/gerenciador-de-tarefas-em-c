#include <stdio.h>
#include <string.h>

#include "tarefas.h"


#define NOME_ARQUIVO "tarefas.bin"


// ============================================================
// LIMPAR BUFFER
// ============================================================

void limparBuffer(void) {

    int c;

    while ((c = getchar()) != '\n' && c != EOF);
}


// ============================================================
// ADICIONAR TAREFA
// ============================================================

void adicionarTarefa(
    Tarefa tarefas[],
    int *quantidade,
    int *proximo_id
) {

    if (*quantidade >= MAX_TAREFAS) {

        printf("\nLimite de tarefas atingido!\n");

        return;
    }


    printf("\nDigite a descricao da tarefa: ");


    fgets(
        tarefas[*quantidade].descricao,
        TAM_DESCRICAO,
        stdin
    );


    // Remove o ENTER da descricao

    tarefas[*quantidade].descricao[
        strcspn(
            tarefas[*quantidade].descricao,
            "\n"
        )
    ] = '\0';


    // Verifica se a descricao esta vazia

    if (strlen(tarefas[*quantidade].descricao) == 0) {

        printf(
            "\nA descricao nao pode estar vazia.\n"
        );

        return;
    }


    // Define o ID

    tarefas[*quantidade].id = *proximo_id;


    // Nova tarefa começa pendente

    tarefas[*quantidade].concluida = 0;


    // Aumenta a quantidade de tarefas

    (*quantidade)++;


    // Prepara o proximo ID

    (*proximo_id)++;


    printf(
        "\nTarefa adicionada com sucesso!\n"
    );
}


// ============================================================
// LISTAR TAREFAS
// ============================================================

void listarTarefas(
    Tarefa tarefas[],
    int quantidade
) {

    int i;


    printf(
        "\n===== LISTA DE TAREFAS =====\n"
    );


    if (quantidade == 0) {

        printf(
            "Nenhuma tarefa cadastrada.\n"
        );

        return;
    }


    for (i = 0; i < quantidade; i++) {

        printf(
            "[%s] ID: %d - %s\n",
            tarefas[i].concluida ? "X" : " ",
            tarefas[i].id,
            tarefas[i].descricao
        );
    }
}


// ============================================================
// CONCLUIR TAREFA
// ============================================================

void concluirTarefa(
    Tarefa tarefas[],
    int quantidade
) {

    int i;
    int id_busca;


    if (quantidade == 0) {

        printf(
            "\nNenhuma tarefa cadastrada.\n"
        );

        return;
    }


    printf(
        "\nDigite o ID da tarefa que deseja concluir: "
    );


    if (scanf("%d", &id_busca) != 1) {

        printf(
            "\nID invalido! Digite apenas numeros.\n"
        );

        limparBuffer();

        return;
    }


    limparBuffer();


    for (i = 0; i < quantidade; i++) {

        if (tarefas[i].id == id_busca) {

            if (tarefas[i].concluida) {

                printf(
                    "\nEssa tarefa ja esta concluida.\n"
                );

            } else {

                tarefas[i].concluida = 1;

                printf(
                    "\nTarefa %d marcada como concluida!\n",
                    id_busca
                );
            }

            return;
        }
    }


    printf(
        "\nTarefa com ID %d nao encontrada.\n",
        id_busca
    );
}


// ============================================================
// EXCLUIR TAREFA
// ============================================================

void excluirTarefa(
    Tarefa tarefas[],
    int *quantidade
) {

    int i;
    int j;
    int id_busca;


    if (*quantidade == 0) {

        printf(
            "\nNenhuma tarefa cadastrada.\n"
        );

        return;
    }


    printf(
        "\nDigite o ID da tarefa que deseja excluir: "
    );


    if (scanf("%d", &id_busca) != 1) {

        printf(
            "\nID invalido! Digite apenas numeros.\n"
        );

        limparBuffer();

        return;
    }


    limparBuffer();


    for (i = 0; i < *quantidade; i++) {

        if (tarefas[i].id == id_busca) {


            // Move as tarefas seguintes uma posição para trás

            for (
                j = i;
                j < *quantidade - 1;
                j++
            ) {

                tarefas[j] = tarefas[j + 1];
            }


            (*quantidade)--;


            printf(
                "\nTarefa %d excluida com sucesso!\n",
                id_busca
            );


            return;
        }
    }


    printf(
        "\nTarefa com ID %d nao encontrada.\n",
        id_busca
    );
}


// ============================================================
// EXIBIR MENU
// ============================================================

void exibirMenu(void) {

    printf(
        "\n===== GERENCIADOR DE TAREFAS =====\n"
    );

    printf(
        "1 - Adicionar tarefa\n"
    );

    printf(
        "2 - Listar tarefas\n"
    );

    printf(
        "3 - Concluir tarefa\n"
    );

    printf(
        "4 - Excluir tarefa\n"
    );

    printf(
        "0 - Sair\n"
    );

    printf(
        "Escolha uma opcao: "
    );
}


// ============================================================
// SALVAR TAREFAS
// ============================================================

void salvarTarefas(
    Tarefa tarefas[],
    int quantidade,
    int proximo_id
) {

    FILE *arquivo;


    // Abre o arquivo em modo binario para escrita

    arquivo = fopen(
        NOME_ARQUIVO,
        "wb"
    );


    if (arquivo == NULL) {

        printf(
            "\nErro ao abrir o arquivo para salvar dados.\n"
        );

        return;
    }


    // Salva a quantidade de tarefas

    fwrite(
        &quantidade,
        sizeof(int),
        1,
        arquivo
    );


    // Salva o proximo ID

    fwrite(
        &proximo_id,
        sizeof(int),
        1,
        arquivo
    );


    // Salva as tarefas

    if (quantidade > 0) {

        fwrite(
            tarefas,
            sizeof(Tarefa),
            quantidade,
            arquivo
        );
    }


    // Fecha o arquivo

    fclose(arquivo);
}


// ============================================================
// CARREGAR TAREFAS
// ============================================================

void carregarTarefas(
    Tarefa tarefas[],
    int *quantidade,
    int *proximo_id
) {

    FILE *arquivo;


    // Tenta abrir o arquivo existente

    arquivo = fopen(
        NOME_ARQUIVO,
        "rb"
    );


    // Se ainda nao existe, inicia normalmente

    if (arquivo == NULL) {

        return;
    }


    // Carrega a quantidade de tarefas

    fread(
        quantidade,
        sizeof(int),
        1,
        arquivo
    );


    // Carrega o proximo ID

    fread(
        proximo_id,
        sizeof(int),
        1,
        arquivo
    );


    // Carrega as tarefas

    if (*quantidade > 0) {

        fread(
            tarefas,
            sizeof(Tarefa),
            *quantidade,
            arquivo
        );
    }


    // Fecha o arquivo

    fclose(arquivo);
}
