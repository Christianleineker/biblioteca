# Biblioteca de Livros em C

Projeto de biblioteca de livros feito em C para a disciplina de Estrutura de Dados.

O sistema permite:
- Cadastro de livros (título, autor e ISBN)
- Busca rápida por ISBN usando tabela hash (complexidade média O(1))
- Busca rápida por título usando hash de strings (complexidade média O(1))
- Listagem de autores utilizando lista encadeada (complexidade O(n))

## Como compilar

No terminal, dentro da pasta do projeto, execute:

```bash
gcc main.c biblioteca.c -o biblioteca.exe
```

## Como executar

Após a compilação, execute o programa:

```bash
./biblioteca.exe
```

## Estrutura do projeto

- 'biblioteca.h' — Definições das estruturas e funções
- 'biblioteca.c' — Implementações das funções
- 'main.c' — Testes de cadastro, busca e listagem