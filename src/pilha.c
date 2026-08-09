#include "pilha.h"

#include <stdio.h>
#include <stdlib.h>

void inicializarPilha(PilhaConcluidas *pilha) {
    pilha->topo = NULL;
    pilha->tamanho = 0;
}

int empilhar(PilhaConcluidas *pilha, int codigo) {
    NoPilha *novo = malloc(sizeof(NoPilha));

    if (novo == NULL) {
        printf("Erro ao reservar memoria para a pilha.\n");
        return 0;
    }

    novo->codigoTarefa = codigo;
    novo->proximo = pilha->topo;
    pilha->topo = novo;
    pilha->tamanho++;
    return 1;
}

int desempilhar(PilhaConcluidas *pilha, int *codigo) {
    NoPilha *removido;

    if (pilha->topo == NULL) {
        return 0;
    }

    removido = pilha->topo;
    *codigo = removido->codigoTarefa;
    pilha->topo = removido->proximo;
    free(removido);
    pilha->tamanho--;
    return 1;
}

void removerCodigoDaPilha(PilhaConcluidas *pilha, int codigo) {
    NoPilha *atual = pilha->topo;
    NoPilha *anterior = NULL;

    while (atual != NULL) {
        if (atual->codigoTarefa == codigo) {
            NoPilha *removido = atual;

            if (anterior == NULL) {
                pilha->topo = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }

            atual = atual->proximo;
            free(removido);
            pilha->tamanho--;
        } else {
            anterior = atual;
            atual = atual->proximo;
        }
    }
}

void liberarPilha(PilhaConcluidas *pilha) {
    int codigoIgnorado;

    while (desempilhar(pilha, &codigoIgnorado)) {
    }
}
