#ifndef FILA_H
#define FILA_H

typedef struct NoFila {
    int codigoTarefa;
    struct NoFila *proximo;
} NoFila;

typedef struct {
    NoFila *inicio;
    NoFila *fim;
    int tamanho;
} FilaSemana;

void inicializarFila(FilaSemana *fila);
int filaContemCodigo(const FilaSemana *fila, int codigo);
int enfileirar(FilaSemana *fila, int codigo);
int desenfileirar(FilaSemana *fila, int *codigo);
void removerCodigoDaFila(FilaSemana *fila, int codigo);
void liberarFila(FilaSemana *fila);

#endif
