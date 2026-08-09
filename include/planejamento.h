#ifndef PLANEJAMENTO_H
#define PLANEJAMENTO_H

#include "fila.h"
#include "lista.h"
#include "pilha.h"

void adicionarTarefaNaSemana(ListaTarefas *lista, FilaSemana *fila);
void iniciarProximaTarefa(ListaTarefas *lista, FilaSemana *fila);
void alterarStatus(ListaTarefas *lista, FilaSemana *fila, PilhaConcluidas *pilha);
void reabrirUltimaConcluida(ListaTarefas *lista, PilhaConcluidas *pilha);
void exibirFilaSemana(const ListaTarefas *lista, const FilaSemana *fila);
void exibirPilhaConcluidas(const ListaTarefas *lista, const PilhaConcluidas *pilha);

#endif
