#include "tarefa.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>

const char *nomePrioridade(int prioridade) {
    switch (prioridade) {
        case PRIORIDADE_ALTA:
            return "Alta";
        case PRIORIDADE_MEDIA:
            return "Media";
        case PRIORIDADE_BAIXA:
            return "Baixa";
        default:
            return "Desconhecida";
    }
}

const char *nomeStatus(int status) {
    switch (status) {
        case STATUS_PENDENTE:
            return "Pendente";
        case STATUS_ANDAMENTO:
            return "Em andamento";
        case STATUS_CONCLUIDA:
            return "Concluida";
        default:
            return "Desconhecido";
    }
}

void exibirTarefa(const Tarefa *tarefa) {
    printf("\n----------------------------------------\n");
    printf("Codigo:      %d\n", tarefa->codigo);
    printf("Titulo:      %s\n", tarefa->titulo);
    printf("Descricao:   %s\n", tarefa->descricao);
    printf("Responsavel: %s\n", tarefa->responsavel);
    printf("Prioridade:  %s\n", nomePrioridade(tarefa->prioridade));
    printf("Prazo:       %s\n", tarefa->prazo);
    printf("Status:      %s\n", nomeStatus(tarefa->status));
}

int textoContem(const char *texto, const char *termo) {
    size_t tamanhoTexto = strlen(texto);
    size_t tamanhoTermo = strlen(termo);
    size_t i;
    size_t j;

    if (tamanhoTermo == 0) {
        return 1;
    }

    if (tamanhoTermo > tamanhoTexto) {
        return 0;
    }

    for (i = 0; i <= tamanhoTexto - tamanhoTermo; i++) {
        for (j = 0; j < tamanhoTermo; j++) {
            if (tolower((unsigned char)texto[i + j]) !=
                tolower((unsigned char)termo[j])) {
                break;
            }
        }

        if (j == tamanhoTermo) {
            return 1;
        }
    }

    return 0;
}

int textosIguais(const char *texto1, const char *texto2) {
    while (*texto1 != '\0' && *texto2 != '\0') {
        if (tolower((unsigned char)*texto1) != tolower((unsigned char)*texto2)) {
            return 0;
        }
        texto1++;
        texto2++;
    }

    return *texto1 == '\0' && *texto2 == '\0';
}

static int valorData(const char *data) {
    int dia;
    int mes;
    int ano;

    sscanf(data, "%2d/%2d/%4d", &dia, &mes, &ano);
    return ano * 10000 + mes * 100 + dia;
}

int compararTarefas(const Tarefa *a, const Tarefa *b, int criterio) {
    if (criterio == 1) {
        return a->prioridade - b->prioridade;
    }
    if (criterio == 2) {
        return valorData(a->prazo) - valorData(b->prazo);
    }
    return a->status - b->status;
}
