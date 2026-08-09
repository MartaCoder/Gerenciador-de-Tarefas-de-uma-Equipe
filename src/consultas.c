#include "consultas.h"

#include "entrada.h"
#include "tarefa.h"

#include <stdio.h>

void buscarTarefas(ListaTarefas *lista) {
    int opcao = lerInteiroIntervalo(
        "Buscar por (1 - Codigo, 2 - Titulo, 3 - Responsavel, 4 - Palavra-chave): ",
        1,
        4);
    NoTarefa *atual;
    int encontrados = 0;

    if (opcao == 1) {
        int codigo = lerCodigoPositivo("Codigo: ");
        NoTarefa *no = buscarNoPorCodigo(lista, codigo);

        if (no == NULL) {
            printf("Tarefa nao encontrada.\n");
        } else {
            exibirTarefa(&no->tarefa);
        }
        return;
    }

    {
        char termo[TAM_ENTRADA];

        lerTextoObrigatorio("Termo da busca: ", termo, sizeof(termo));
        atual = lista->inicio;

        while (atual != NULL) {
            int corresponde = 0;

            if (opcao == 2) {
                corresponde = textoContem(atual->tarefa.titulo, termo);
            } else if (opcao == 3) {
                corresponde = textoContem(atual->tarefa.responsavel, termo);
            } else {
                corresponde = textoContem(atual->tarefa.titulo, termo) ||
                               textoContem(atual->tarefa.descricao, termo) ||
                               textoContem(atual->tarefa.responsavel, termo);
            }

            if (corresponde) {
                exibirTarefa(&atual->tarefa);
                encontrados++;
            }

            atual = atual->proximo;
        }
    }

    printf("\n%d tarefa(s) encontrada(s).\n", encontrados);
}

void ordenarTarefas(ListaTarefas *lista) {
    int criterio;

    if (lista->tamanho < 2) {
        printf("Sao necessarias pelo menos duas tarefas para ordenar.\n");
        return;
    }

    criterio = lerInteiroIntervalo(
        "Ordenar por (1 - Prioridade, 2 - Prazo, 3 - Status): ", 1, 3);
    ordenarLista(lista, criterio);

    printf("Tarefas ordenadas com Bubble Sort.\n");
    if (criterio == 1) {
        printf("Ordem: prioridade alta, media e baixa.\n");
    } else if (criterio == 2) {
        printf("Ordem: prazo mais proximo ao mais distante.\n");
    } else {
        printf("Ordem: pendente, em andamento e concluida.\n");
    }
}

static int responsavelJaContado(const ListaTarefas *lista, const NoTarefa *limite) {
    NoTarefa *atual = lista->inicio;

    while (atual != limite) {
        if (textosIguais(atual->tarefa.responsavel, limite->tarefa.responsavel)) {
            return 1;
        }
        atual = atual->proximo;
    }

    return 0;
}

void exibirRelatorio(const ListaTarefas *lista, const FilaSemana *fila) {
    int pendentes = 0;
    int andamento = 0;
    int concluidas = 0;
    NoTarefa *atual = lista->inicio;

    while (atual != NULL) {
        if (atual->tarefa.status == STATUS_PENDENTE) {
            pendentes++;
        } else if (atual->tarefa.status == STATUS_ANDAMENTO) {
            andamento++;
        } else {
            concluidas++;
        }
        atual = atual->proximo;
    }

    printf("\n========================================\n");
    printf("       RELATORIO GERAL DE TAREFAS\n");
    printf("========================================\n");
    printf("Total de tarefas:  %d\n", lista->tamanho);
    printf("Pendentes:         %d\n", pendentes);
    printf("Em andamento:      %d\n", andamento);
    printf("Concluidas:        %d\n", concluidas);
    printf("Na fila da semana: %d\n", fila->tamanho);

    if (lista->tamanho == 0) {
        return;
    }

    printf("\n--- Quantidade por responsavel ---\n");
    atual = lista->inicio;

    while (atual != NULL) {
        if (!responsavelJaContado(lista, atual)) {
            int total = 0;
            NoTarefa *contador = lista->inicio;

            while (contador != NULL) {
                if (textosIguais(
                        contador->tarefa.responsavel, atual->tarefa.responsavel)) {
                    total++;
                }
                contador = contador->proximo;
            }

            printf("%s: %d tarefa(s)\n", atual->tarefa.responsavel, total);
        }
        atual = atual->proximo;
    }
}
