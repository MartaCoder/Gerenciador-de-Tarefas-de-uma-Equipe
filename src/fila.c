#include "fila.h"

#include <stdio.h>
#include <stdlib.h>

void inicializarFila(FilaSemana *fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
}

int filaContemCodigo(const FilaSemana *fila, int codigo) {
    NoFila *atual = fila->inicio;

    while (atual != NULL) {
        if (atual->codigoTarefa == codigo) {
            return 1;
        }
        atual = atual->proximo;
    }

    return 0;
}

int enfileirar(FilaSemana *fila, int codigo) {
    NoFila *novo = malloc(sizeof(NoFila));

    if (novo == NULL) {
        printf("Erro ao reservar memoria para a fila.\n");
        return 0;
    }

    novo->codigoTarefa = codigo;
    novo->proximo = NULL;

    if (fila->fim == NULL) {
        fila->inicio = novo;
    } else {
        fila->fim->proximo = novo;
    }

    fila->fim = novo;
    fila->tamanho++;
    return 1;
}

int desenfileirar(FilaSemana *fila, int *codigo) {
    NoFila *removido;

    if (fila->inicio == NULL) {
        return 0;
    }

    removido = fila->inicio;
    *codigo = removido->codigoTarefa;
    fila->inicio = removido->proximo;

    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    free(removido);
    fila->tamanho--;
    return 1;
}

void removerCodigoDaFila(FilaSemana *fila, int codigo) {
    NoFila *atual = fila->inicio;
    NoFila *anterior = NULL;

    while (atual != NULL) {
        if (atual->codigoTarefa == codigo) {
            NoFila *removido = atual;

            if (anterior == NULL) {
                fila->inicio = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }

            if (fila->fim == atual) {
                fila->fim = anterior;
            }

            atual = atual->proximo;
            free(removido);
            fila->tamanho--;
        } else {
            anterior = atual;
            atual = atual->proximo;
        }
    }
}

void liberarFila(FilaSemana *fila) {
    int codigoIgnorado;

    while (desenfileirar(fila, &codigoIgnorado)) {
    }
}
