#include "planejamento.h"

#include "entrada.h"
#include "tarefa.h"

#include <stdio.h>

void adicionarTarefaNaSemana(ListaTarefas *lista, FilaSemana *fila) {
    int codigo = lerCodigoPositivo("Codigo da tarefa pendente: ");
    NoTarefa *no = buscarNoPorCodigo(lista, codigo);

    if (no == NULL) {
        printf("Tarefa nao encontrada.\n");
        return;
    }
    if (no->tarefa.status != STATUS_PENDENTE) {
        printf("Somente tarefas pendentes podem entrar na fila da semana.\n");
        return;
    }
    if (filaContemCodigo(fila, codigo)) {
        printf("A tarefa ja esta na fila da semana.\n");
        return;
    }

    if (enfileirar(fila, codigo)) {
        printf("Tarefa adicionada ao final da fila da semana.\n");
    }
}

void iniciarProximaTarefa(ListaTarefas *lista, FilaSemana *fila) {
    int codigo;
    NoTarefa *no;

    while (desenfileirar(fila, &codigo)) {
        no = buscarNoPorCodigo(lista, codigo);
        if (no != NULL && no->tarefa.status == STATUS_PENDENTE) {
            no->tarefa.status = STATUS_ANDAMENTO;
            printf("Proxima tarefa iniciada:\n");
            exibirTarefa(&no->tarefa);
            return;
        }
    }

    printf("A fila de execucao da semana esta vazia.\n");
}

void alterarStatus(
    ListaTarefas *lista, FilaSemana *fila, PilhaConcluidas *pilha) {
    int codigo = lerCodigoPositivo("Codigo da tarefa: ");
    NoTarefa *no = buscarNoPorCodigo(lista, codigo);
    int novoStatus;
    int statusAnterior;

    if (no == NULL) {
        printf("Tarefa nao encontrada.\n");
        return;
    }

    printf("Status atual: %s\n", nomeStatus(no->tarefa.status));
    novoStatus = lerInteiroIntervalo(
        "Novo status (1 - Pendente, 2 - Em andamento, 3 - Concluida): ", 1, 3);
    statusAnterior = no->tarefa.status;

    if (novoStatus == statusAnterior) {
        printf("A tarefa ja possui esse status.\n");
        return;
    }

    if (statusAnterior == STATUS_CONCLUIDA) {
        removerCodigoDaPilha(pilha, codigo);
    }

    no->tarefa.status = novoStatus;

    if (novoStatus != STATUS_PENDENTE) {
        removerCodigoDaFila(fila, codigo);
    }

    if (novoStatus == STATUS_CONCLUIDA) {
        empilhar(pilha, codigo);
        printf("Tarefa concluida e registrada na pilha.\n");
    } else {
        printf("Status atualizado para %s.\n", nomeStatus(novoStatus));
    }
}

void reabrirUltimaConcluida(ListaTarefas *lista, PilhaConcluidas *pilha) {
    int codigo;
    NoTarefa *no;

    while (desempilhar(pilha, &codigo)) {
        no = buscarNoPorCodigo(lista, codigo);
        if (no != NULL && no->tarefa.status == STATUS_CONCLUIDA) {
            no->tarefa.status = STATUS_PENDENTE;
            printf("A ultima tarefa concluida foi reaberta:\n");
            exibirTarefa(&no->tarefa);
            return;
        }
    }

    printf("Nao ha tarefas concluidas recentemente para reabrir.\n");
}

void exibirFilaSemana(const ListaTarefas *lista, const FilaSemana *fila) {
    NoFila *atual = fila->inicio;
    int posicao = 1;

    if (atual == NULL) {
        printf("A fila da semana esta vazia.\n");
        return;
    }

    printf("\n=== FILA DE EXECUCAO DA SEMANA ===\n");
    while (atual != NULL) {
        NoTarefa *no = buscarNoPorCodigo(lista, atual->codigoTarefa);
        if (no != NULL) {
            printf(
                "%d. [%d] %s - %s - prazo %s\n",
                posicao++,
                no->tarefa.codigo,
                no->tarefa.titulo,
                no->tarefa.responsavel,
                no->tarefa.prazo);
        }
        atual = atual->proximo;
    }
}

void exibirPilhaConcluidas(
    const ListaTarefas *lista, const PilhaConcluidas *pilha) {
    NoPilha *atual = pilha->topo;
    int posicao = 1;

    if (atual == NULL) {
        printf("A pilha de tarefas concluidas esta vazia.\n");
        return;
    }

    printf("\n=== CONCLUIDAS RECENTEMENTE ===\n");
    printf("O primeiro item representa o topo da pilha.\n");
    while (atual != NULL) {
        NoTarefa *no = buscarNoPorCodigo(lista, atual->codigoTarefa);
        if (no != NULL) {
            printf(
                "%d. [%d] %s - %s\n",
                posicao++,
                no->tarefa.codigo,
                no->tarefa.titulo,
                no->tarefa.responsavel);
        }
        atual = atual->proximo;
    }
}
