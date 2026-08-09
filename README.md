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
├── docs/
├── .vscode/             # configuração para compilar o projeto completo
├── compilar_windows.bat
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

## Compilação

### No VS Code do Windows

Não use a opção **C/C++: gcc.exe arquivo de build ativo**, pois ela compila somente o arquivo aberto. Como este projeto possui vários módulos, faça assim:

1. Abra a pasta `gerenciador_tarefas` no VS Code;
2. Pressione `Ctrl + Shift + B`;
3. Escolha `Compilar projeto completo`;
4. Depois da compilação, abra o terminal e execute:

```powershell
.\gerenciador_tarefas.exe
```

Também é possível executar o arquivo `compilar_windows.bat`, que utiliza o GCC instalado em `C:\msys64\ucrt64\bin\gcc.exe`.

### No Linux

As instruções abaixo funcionam no Ubuntu, Debian, Linux Mint e outras distribuições baseadas no Debian.

1. Abra o terminal na pasta do projeto. Se o terminal estiver em outro local, entre na pasta com:

```bash
cd caminho/para/gerenciador_tarefas_modular
```

2. Instale o GCC e o Make, caso ainda não estejam instalados:

```bash
sudo apt update
sudo apt install build-essential
```

3. Verifique se as ferramentas estão disponíveis:

```bash
gcc --version
make --version
```

4. Compile todos os módulos:

```bash
make
```

5. Execute o programa:

```bash
./gerenciador_tarefas
```

Para apagar o executável e fazer uma nova compilação completa:

```bash
make clean
make
```

Se aparecer a mensagem `Permissão negada` ao executar, use:

```bash
chmod +x gerenciador_tarefas
./gerenciador_tarefas
```

### No macOS

1. Abra o aplicativo Terminal e entre na pasta do projeto:

```bash
cd caminho/para/gerenciador_tarefas_modular
```

2. Instale as ferramentas de linha de comando da Apple, caso ainda não estejam instaladas:

```bash
xcode-select --install
```

Uma janela do sistema será exibida. Confirme a instalação e aguarde a conclusão.

3. Verifique o compilador e o Make:

```bash
clang --version
make --version
```

4. Compile o projeto:

```bash
make
```

5. Execute o programa:

```bash
./gerenciador_tarefas
```

Para recompilar tudo:

```bash
make clean
make
```

### Compilação manual no Linux, macOS ou Windows

Se preferir não usar o Makefile, compile todos os arquivos diretamente:

```bash
gcc -Iinclude -std=c11 -Wall -Wextra -Wpedantic src/*.c -o gerenciador_tarefas
```

Depois execute:

```bash
./gerenciador_tarefas
```

## Execução no Windows

Depois de compilar pelo VS Code ou pelo arquivo `compilar_windows.bat`, execute:

```powershell
.\gerenciador_tarefas.exe
```

Ao escolher a opção `0`, o programa libera os nós restantes da lista, da fila e da pilha antes de encerrar.
