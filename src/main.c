#include "cadastro.h"
#include "consultas.h"
#include "entrada.h"
#include "fila.h"
#include "lista.h"
#include "menu.h"
#include "pilha.h"
#include "planejamento.h"

#include <stdio.h>

int main(void) {
    ListaTarefas lista;
    FilaSemana fila;
    PilhaConcluidas pilha;
    int opcao;

    inicializarLista(&lista);
    inicializarFila(&fila);
    inicializarPilha(&pilha);

    do {
        exibirMenu();
        opcao = lerInteiroIntervalo("Escolha uma opcao: ", 0, 13);

        switch (opcao) {
            case 1:
                cadastrarTarefa(&lista, &pilha);
                break;
            case 2:
                editarTarefa(&lista);
                break;
            case 3:
                removerTarefa(&lista, &fila, &pilha);
                break;
            case 4:
                listarTarefas(&lista);
                break;
            case 5:
                adicionarTarefaNaSemana(&lista, &fila);
                break;
            case 6:
                iniciarProximaTarefa(&lista, &fila);
                break;
            case 7:
                alterarStatus(&lista, &fila, &pilha);
                break;
            case 8:
                reabrirUltimaConcluida(&lista, &pilha);
                break;
            case 9:
                buscarTarefas(&lista);
                break;
            case 10:
                ordenarTarefas(&lista);
                break;
            case 11:
                exibirRelatorio(&lista, &fila);
                break;
            case 12:
                exibirFilaSemana(&lista, &fila);
                break;
            case 13:
                exibirPilhaConcluidas(&lista, &pilha);
                break;
            case 0:
                printf("Encerrando o programa...\n");
                break;
        }
    } while (opcao != 0);

    liberarFila(&fila);
    liberarPilha(&pilha);
    liberarLista(&lista);
    printf("Toda a memoria dinamica foi liberada.\n");
    return 0;
}
