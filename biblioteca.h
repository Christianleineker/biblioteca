#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <stdbool.h>

typedef struct Livro {
    char titulo[100];
    char autor[100];
    int isbn;
    struct Livro *prox_autor;
} Livro;

typedef struct NodoHash {
    Livro *livro;
    struct NodoHash *prox;
} NodoHash;

typedef struct TabelaHash {
    NodoHash **tabela;
    int capacidade;
} TabelaHash;

TabelaHash* criar_tabela(int capacidade);
bool inserir_livro(TabelaHash *por_isbn, TabelaHash *por_titulo, Livro *livro);
Livro* buscar_por_isbn(TabelaHash *tabela, int isbn);
Livro* buscar_por_titulo(TabelaHash *tabela, const char *titulo);
void listar_autores(TabelaHash *tabela);
void liberar_tabelas(TabelaHash *por_isbn, TabelaHash *por_titulo);

#endif
