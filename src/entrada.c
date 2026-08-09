#include "entrada.h"

#include "tarefa.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void limparRestanteLinha(void) {
    int caractere;

    while ((caractere = getchar()) != '\n' && caractere != EOF) {
    }
}

void lerLinha(const char *mensagem, char *destino, size_t tamanho) {
    size_t comprimento;

    printf("%s", mensagem);
    if (fgets(destino, (int)tamanho, stdin) == NULL) {
        destino[0] = '\0';
        return;
    }

    comprimento = strlen(destino);
    if (comprimento > 0 && destino[comprimento - 1] == '\n') {
        destino[comprimento - 1] = '\0';
    } else {
        limparRestanteLinha();
    }
}

void lerTextoObrigatorio(const char *mensagem, char *destino, size_t tamanho) {
    do {
        lerLinha(mensagem, destino, tamanho);
        if (destino[0] == '\0') {
            printf("O campo nao pode ficar vazio. Tente novamente.\n");
        }
    } while (destino[0] == '\0');
}

int lerInteiroIntervalo(const char *mensagem, int minimo, int maximo) {
    char entrada[TAM_ENTRADA];
    char *fim;
    long valor;

    while (1) {
        lerLinha(mensagem, entrada, sizeof(entrada));
        valor = strtol(entrada, &fim, 10);

        while (isspace((unsigned char)*fim)) {
            fim++;
        }

        if (entrada[0] != '\0' && *fim == '\0' && valor >= minimo && valor <= maximo) {
            return (int)valor;
        }

        printf("Digite um numero entre %d e %d.\n", minimo, maximo);
    }
}

int lerCodigoPositivo(const char *mensagem) {
    char entrada[TAM_ENTRADA];
    char *fim;
    long valor;

    while (1) {
        lerLinha(mensagem, entrada, sizeof(entrada));
        valor = strtol(entrada, &fim, 10);

        while (isspace((unsigned char)*fim)) {
            fim++;
        }

        if (entrada[0] != '\0' && *fim == '\0' && valor > 0 && valor <= 2147483647L) {
            return (int)valor;
        }

        printf("Digite um codigo inteiro positivo.\n");
    }
}

int dataValida(const char *data) {
    int dia;
    int mes;
    int ano;
    char sobra;
    int diasMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (strlen(data) != 10 || data[2] != '/' || data[5] != '/') {
        return 0;
    }

    if (sscanf(data, "%2d/%2d/%4d%c", &dia, &mes, &ano, &sobra) != 3) {
        return 0;
    }

    if (ano < 1900 || mes < 1 || mes > 12) {
        return 0;
    }

    if ((ano % 400 == 0) || (ano % 4 == 0 && ano % 100 != 0)) {
        diasMes[2] = 29;
    }

    return dia >= 1 && dia <= diasMes[mes];
}

void lerPrazo(char *prazo) {
    do {
        lerTextoObrigatorio("Prazo (DD/MM/AAAA): ", prazo, TAM_PRAZO);
        if (!dataValida(prazo)) {
            printf("Data invalida. Use o formato DD/MM/AAAA.\n");
        }
    } while (!dataValida(prazo));
}
