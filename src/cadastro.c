#include "cadastro.h"

#include "entrada.h"
#include "tarefa.h"

#include <stdio.h>

void cadastrarTarefa(ListaTarefas *lista, PilhaConcluidas *pilha) {
    Tarefa tarefa;

    printf("\n=== CADASTRAR TAREFA ===\n");
    do {
        tarefa.codigo = lerCodigoPositivo("Codigo: ");
        if (buscarNoPorCodigo(lista, tarefa.codigo) != NULL) {
            printf("Ja existe uma tarefa com esse codigo.\n");
        }
    } while (buscarNoPorCodigo(lista, tarefa.codigo) != NULL);

    lerTextoObrigatorio("Titulo: ", tarefa.titulo, sizeof(tarefa.titulo));
    lerTextoObrigatorio("Descricao: ", tarefa.descricao, sizeof(tarefa.descricao));
    lerTextoObrigatorio("Responsavel: ", tarefa.responsavel, sizeof(tarefa.responsavel));
    tarefa.prioridade = lerInteiroIntervalo(
        "Prioridade (1 - Alta, 2 - Media, 3 - Baixa): ", 1, 3);
    lerPrazo(tarefa.prazo);
    tarefa.status = lerInteiroIntervalo(
        "Status (1 - Pendente, 2 - Em andamento, 3 - Concluida): ", 1, 3);

    if (inserirNoFim(lista, tarefa)) {
        if (tarefa.status == STATUS_CONCLUIDA) {
            empilhar(pilha, tarefa.codigo);
        }
        printf("Tarefa cadastrada com sucesso.\n");
    }
}

void editarTarefa(ListaTarefas *lista) {
    int codigo = lerCodigoPositivo("Codigo da tarefa que deseja editar: ");
    NoTarefa *no = buscarNoPorCodigo(lista, codigo);

    if (no == NULL) {
        printf("Tarefa nao encontrada.\n");
        return;
    }

    printf("\nDados atuais:");
    exibirTarefa(&no->tarefa);
    printf("\nInforme os novos dados. O codigo e o status serao mantidos.\n");
    lerTextoObrigatorio("Novo titulo: ", no->tarefa.titulo, sizeof(no->tarefa.titulo));
    lerTextoObrigatorio(
        "Nova descricao: ", no->tarefa.descricao, sizeof(no->tarefa.descricao));
    lerTextoObrigatorio(
        "Novo responsavel: ", no->tarefa.responsavel, sizeof(no->tarefa.responsavel));
    no->tarefa.prioridade = lerInteiroIntervalo(
        "Nova prioridade (1 - Alta, 2 - Media, 3 - Baixa): ", 1, 3);
    lerPrazo(no->tarefa.prazo);
    printf("Tarefa editada com sucesso.\n");
}

void removerTarefa(
    ListaTarefas *lista, FilaSemana *fila, PilhaConcluidas *pilha) {
    int codigo = lerCodigoPositivo("Codigo da tarefa que deseja remover: ");
    NoTarefa *no = buscarNoPorCodigo(lista, codigo);
    int confirmar;

    if (no == NULL) {
        printf("Tarefa nao encontrada.\n");
        return;
    }

    exibirTarefa(&no->tarefa);
    confirmar = lerInteiroIntervalo("Confirmar remocao? (1 - Sim, 2 - Nao): ", 1, 2);
    if (confirmar == 2) {
        printf("Remocao cancelada.\n");
        return;
    }

    removerCodigoDaFila(fila, codigo);
    removerCodigoDaPilha(pilha, codigo);
    removerNoDaLista(lista, no);
    printf("Tarefa removida com sucesso.\n");
}

void listarTarefas(const ListaTarefas *lista) {
    int sentido;
    int posicao = 1;

    if (lista->inicio == NULL) {
        printf("Nao ha tarefas cadastradas.\n");
        return;
    }

    sentido = lerInteiroIntervalo(
        "Sentido da listagem (1 - Inicio ao fim, 2 - Fim ao inicio): ", 1, 2);
    printf("\n=== LISTA DE TAREFAS (%d tarefa(s)) ===\n", lista->tamanho);

    if (sentido == 1) {
        NoTarefa *atual = lista->inicio;
        while (atual != NULL) {
            printf("\nTarefa %d:", posicao++);
            exibirTarefa(&atual->tarefa);
            atual = atual->proximo;
        }
    } else {
        NoTarefa *atual = lista->fim;
        while (atual != NULL) {
            printf("\nTarefa %d:", posicao++);
            exibirTarefa(&atual->tarefa);
            atual = atual->anterior;
        }
    }
}
