#ifndef PILHA_H
#define PILHA_H

typedef struct NoPilha {
    int codigoTarefa;
    struct NoPilha *proximo;
} NoPilha;

typedef struct {
    NoPilha *topo;
    int tamanho;
} PilhaConcluidas;

void inicializarPilha(PilhaConcluidas *pilha);
int empilhar(PilhaConcluidas *pilha, int codigo);
int desempilhar(PilhaConcluidas *pilha, int *codigo);
void removerCodigoDaPilha(PilhaConcluidas *pilha, int codigo);
void liberarPilha(PilhaConcluidas *pilha);

#endif
