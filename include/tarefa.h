#ifndef TAREFA_H
#define TAREFA_H

#define TAM_TITULO 81
#define TAM_DESCRICAO 201
#define TAM_RESPONSAVEL 81
#define TAM_PRAZO 11

enum Prioridade {
    PRIORIDADE_ALTA = 1,
    PRIORIDADE_MEDIA = 2,
    PRIORIDADE_BAIXA = 3
};

enum StatusTarefa {
    STATUS_PENDENTE = 1,
    STATUS_ANDAMENTO = 2,
    STATUS_CONCLUIDA = 3
};

typedef struct {
    int codigo;
    char titulo[TAM_TITULO];
    char descricao[TAM_DESCRICAO];
    char responsavel[TAM_RESPONSAVEL];
    int prioridade;
    char prazo[TAM_PRAZO];
    int status;
} Tarefa;

const char *nomePrioridade(int prioridade);
const char *nomeStatus(int status);
void exibirTarefa(const Tarefa *tarefa);
int textoContem(const char *texto, const char *termo);
int textosIguais(const char *texto1, const char *texto2);
int compararTarefas(const Tarefa *a, const Tarefa *b, int criterio);

#endif
