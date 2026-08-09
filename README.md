# Gerenciador de Tarefas de uma Equipe

Projeto final da disciplina de Estrutura de Dados I, desenvolvido em Linguagem C e executado pelo terminal.

## Equipe

- Thailton Veloso da Silva Luz
- Marcos Vinícius Soares da Costa
- Marcos Renan Costa Paiva
- Júlio Henrique Marta de Lima

Professor: Rogerio Figueredo de Sousa  
Instituição: IFPI - Campus Picos

## Organização dos módulos

O programa não está concentrado em um único arquivo. Cada parte possui uma responsabilidade:

```text
gerenciador_tarefas/
├── Relatorio_SBC/
├── include/
│   ├── cadastro.h
│   ├── consultas.h
│   ├── entrada.h
│   ├── fila.h
│   ├── lista.h
│   ├── menu.h
│   ├── pilha.h
│   ├── planejamento.h
│   └── tarefa.h
├── src/
│   ├── cadastro.c       # cadastro, edição, remoção e listagem
│   ├── consultas.c      # busca, ordenação e relatório
│   ├── entrada.c        # leitura e validação
│   ├── fila.c           # implementação da fila
│   ├── lista.c          # implementação da lista duplamente encadeada
│   ├── main.c           # inicialização e chamada das opções do menu
│   ├── menu.c           # impressão do menu
│   ├── pilha.c          # implementação da pilha
│   ├── planejamento.c   # fila semanal, status e reabertura
│   └── tarefa.c         # modelo e funções auxiliares da tarefa
├── .gitignore
├── Makefile
└── README.md
```

## Estruturas utilizadas

- Lista duplamente encadeada para armazenar as tarefas;
- Fila encadeada para organizar as tarefas da semana;
- Pilha encadeada para registrar as tarefas concluídas recentemente;
- Busca sequencial;
- Bubble Sort;
- Alocação dinâmica com `malloc` e liberação com `free`.

## Sobre os arquivos executáveis

O arquivo `gerenciador_tarefas.exe` é gerado no Windows e funciona somente nesse sistema. No Linux e no macOS, não se utiliza esse arquivo.

Nesses sistemas, o mesmo código-fonte deve ser compilado novamente. O executável gerado recebe o nome `gerenciador_tarefas`, sem a extensão `.exe`.

```text
gerenciador_tarefas.exe   # executável do Windows
gerenciador_tarefas       # executável do Linux ou macOS
```

Portanto, o código das pastas `src` e `include` é o mesmo nos três sistemas. O que muda é apenas o executável gerado em cada sistema operacional.

## Compilação e execução

Os comandos devem ser executados no terminal aberto na pasta principal do projeto, onde estão as pastas `src` e `include`.

### Windows

Como o projeto está dividido em módulos, não utilize a opção **C/C++: gcc.exe arquivo de build ativo**, pois ela compila somente o arquivo que está aberto.

Para compilar todos os módulos pelo PowerShell, execute:

```powershell
& "C:\msys64\ucrt64\bin\gcc.exe" -Iinclude -std=c11 -Wall -Wextra -Wpedantic (Get-ChildItem .\src\*.c).FullName -o .\gerenciador_tarefas.exe
```

Depois execute o programa:

```powershell
.\gerenciador_tarefas.exe
```

Se o arquivo `gerenciador_tarefas.exe` já tiver sido gerado anteriormente, basta executar o segundo comando.

### Linux

Para compilar todos os módulos, execute:

```bash
gcc -Iinclude -std=c11 -Wall -Wextra -Wpedantic src/*.c -o gerenciador_tarefas
```

Depois execute o programa:

```bash
./gerenciador_tarefas
```

Após a primeira compilação, enquanto o código não for modificado, basta utilizar `./gerenciador_tarefas` para abrir o programa novamente.

### macOS

Para compilar todos os módulos, execute:

```bash
clang -Iinclude -std=c11 -Wall -Wextra -Wpedantic src/*.c -o gerenciador_tarefas
```

Depois execute o programa:

```bash
./gerenciador_tarefas
```

Após a primeira compilação, enquanto o código não for modificado, basta utilizar `./gerenciador_tarefas` para abrir o programa novamente.

Ao escolher a opção `0`, o programa libera os nós restantes da lista, da fila e da pilha antes de encerrar.
