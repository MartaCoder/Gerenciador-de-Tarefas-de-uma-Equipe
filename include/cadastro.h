#ifndef CADASTRO_H
#define CADASTRO_H

#include "fila.h"
#include "lista.h"
#include "pilha.h"

void cadastrarTarefa(ListaTarefas *lista, PilhaConcluidas *pilha);
void editarTarefa(ListaTarefas *lista);
void removerTarefa(ListaTarefas *lista, FilaSemana *fila, PilhaConcluidas *pilha);
void listarTarefas(const ListaTarefas *lista);

#endif
