#include "lista.h"

#include <stdio.h>
#include <stdlib.h>

void inicializarLista(ListaTarefas *lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
}

NoTarefa *buscarNoPorCodigo(const ListaTarefas *lista, int codigo) {
    NoTarefa *atual = lista->inicio;

    while (atual != NULL) {
        if (atual->tarefa.codigo == codigo) {
            return atual;
        }
        atual = atual->proximo;
    }

    return NULL;
}

int inserirNoFim(ListaTarefas *lista, Tarefa tarefa) {
    NoTarefa *novo = malloc(sizeof(NoTarefa));

    if (novo == NULL) {
        printf("Erro ao reservar memoria para a tarefa.\n");
        return 0;
    }

    novo->tarefa = tarefa;
    novo->anterior = lista->fim;
    novo->proximo = NULL;

    if (lista->fim == NULL) {
        lista->inicio = novo;
    } else {
        lista->fim->proximo = novo;
    }

    lista->fim = novo;
    lista->tamanho++;
    return 1;
}

void removerNoDaLista(ListaTarefas *lista, NoTarefa *no) {
    if (no->anterior == NULL) {
        lista->inicio = no->proximo;
    } else {
        no->anterior->proximo = no->proximo;
    }

    if (no->proximo == NULL) {
        lista->fim = no->anterior;
    } else {
        no->proximo->anterior = no->anterior;
    }

    free(no);
    lista->tamanho--;
}

void ordenarLista(ListaTarefas *lista, int criterio) {
    int houveTroca;
    NoTarefa *limite = NULL;

    do {
        NoTarefa *atual = lista->inicio;
        houveTroca = 0;

        while (atual->proximo != limite) {
            if (compararTarefas(&atual->tarefa, &atual->proximo->tarefa, criterio) > 0) {
                Tarefa temporaria = atual->tarefa;
                atual->tarefa = atual->proximo->tarefa;
                atual->proximo->tarefa = temporaria;
                houveTroca = 1;
            }
            atual = atual->proximo;
        }

        limite = atual;
    } while (houveTroca);
}

void liberarLista(ListaTarefas *lista) {
    NoTarefa *atual = lista->inicio;

    while (atual != NULL) {
        NoTarefa *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    inicializarLista(lista);
}
