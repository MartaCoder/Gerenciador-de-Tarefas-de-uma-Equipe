#ifndef CONSULTAS_H
#define CONSULTAS_H

#include "fila.h"
#include "lista.h"

void buscarTarefas(ListaTarefas *lista);
void ordenarTarefas(ListaTarefas *lista);
void exibirRelatorio(const ListaTarefas *lista, const FilaSemana *fila);

#endif
