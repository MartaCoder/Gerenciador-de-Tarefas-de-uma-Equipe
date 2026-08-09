#include "menu.h"

#include <stdio.h>

void exibirMenu(void) {
    printf("\n========================================\n");
    printf("  GERENCIADOR DE TAREFAS DE UMA EQUIPE\n");
    printf("========================================\n");
    printf(" 1. Cadastrar tarefa\n");
    printf(" 2. Editar tarefa\n");
    printf(" 3. Remover tarefa\n");
    printf(" 4. Listar tarefas\n");
    printf(" 5. Adicionar tarefa a fila da semana\n");
    printf(" 6. Iniciar proxima tarefa da fila\n");
    printf(" 7. Alterar status de uma tarefa\n");
    printf(" 8. Reabrir ultima tarefa concluida\n");
    printf(" 9. Buscar tarefas\n");
    printf("10. Ordenar tarefas\n");
    printf("11. Exibir relatorio geral\n");
    printf("12. Exibir fila da semana\n");
    printf("13. Exibir concluidas recentemente\n");
    printf(" 0. Encerrar programa\n");
    printf("========================================\n");
}
