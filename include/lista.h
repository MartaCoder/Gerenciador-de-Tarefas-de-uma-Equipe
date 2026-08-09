#ifndef LISTA_H
#define LISTA_H

#include "tarefa.h"

typedef struct NoTarefa {
    Tarefa tarefa;
    struct NoTarefa *anterior;
    struct NoTarefa *proximo;
} NoTarefa;

typedef struct {
    NoTarefa *inicio;
    NoTarefa *fim;
    int tamanho;
} ListaTarefas;

void inicializarLista(ListaTarefas *lista);
NoTarefa *buscarNoPorCodigo(const ListaTarefas *lista, int codigo);
int inserirNoFim(ListaTarefas *lista, Tarefa tarefa);
void removerNoDaLista(ListaTarefas *lista, NoTarefa *no);
void ordenarLista(ListaTarefas *lista, int criterio);
void liberarLista(ListaTarefas *lista);

#endif
