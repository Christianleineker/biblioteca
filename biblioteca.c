#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"

static unsigned long hash_inteiro(int chave) {
    return chave;
}

static unsigned long hash_string(const char *str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash;
}

TabelaHash* criar_tabela(int capacidade) {
    TabelaHash *t = malloc(sizeof(TabelaHash));
    if (!t) return NULL;
    t->capacidade = capacidade;
    t->tabela = malloc(sizeof(NodoHash*) * capacidade);
    if (!t->tabela) {
        free(t);
        return NULL;
    }
    for (int i = 0; i < capacidade; i++) {
        t->tabela[i] = NULL;
    }
    return t;
}

bool inserir_livro(TabelaHash *por_isbn, TabelaHash *por_titulo, Livro *livro) {
    unsigned long idx_isbn = hash_inteiro(livro->isbn) % por_isbn->capacidade;
    unsigned long idx_titulo = hash_string(livro->titulo) % por_titulo->capacidade;

    NodoHash *novo_isbn = malloc(sizeof(NodoHash));
    if (!novo_isbn) return false;
    novo_isbn->livro = livro;
    novo_isbn->prox = por_isbn->tabela[idx_isbn];
    por_isbn->tabela[idx_isbn] = novo_isbn;

    NodoHash *novo_titulo = malloc(sizeof(NodoHash));
    if (!novo_titulo) return false;
    novo_titulo->livro = livro;
    novo_titulo->prox = por_titulo->tabela[idx_titulo];
    por_titulo->tabela[idx_titulo] = novo_titulo;

    return true;
}

Livro* buscar_por_isbn(TabelaHash *tabela, int isbn) {
    unsigned long idx = hash_inteiro(isbn) % tabela->capacidade;
    NodoHash *nodo = tabela->tabela[idx];
    while (nodo) {
        if (nodo->livro->isbn == isbn)
            return nodo->livro;
        nodo = nodo->prox;
    }
    return NULL;
}

Livro* buscar_por_titulo(TabelaHash *tabela, const char *titulo) {
    unsigned long idx = hash_string(titulo) % tabela->capacidade;
    NodoHash *nodo = tabela->tabela[idx];
    while (nodo) {
        if (strcmp(nodo->livro->titulo, titulo) == 0)
            return nodo->livro;
        nodo = nodo->prox;
    }
    return NULL;
}

void listar_autores(TabelaHash *tabela) {
    for (int i = 0; i < tabela->capacidade; i++) {
        NodoHash *nodo = tabela->tabela[i];
        while (nodo) {
            printf("Autor: %s\n", nodo->livro->autor);
            nodo = nodo->prox;
        }
    }
}

void liberar_tabelas(TabelaHash *por_isbn, TabelaHash *por_titulo) {
    if (!por_isbn || !por_titulo) return;
    for (int i = 0; i < por_isbn->capacidade; i++) {
        NodoHash *nodo = por_isbn->tabela[i];
        while (nodo) {
            NodoHash *tmp = nodo;
            nodo = nodo->prox;
            free(tmp);
        }
    }
    free(por_isbn->tabela);
    free(por_isbn);

    for (int i = 0; i < por_titulo->capacidade; i++) {
        NodoHash *nodo = por_titulo->tabela[i];
        while (nodo) {
            NodoHash *tmp = nodo;
            nodo = nodo->prox;
            free(tmp);
        }
    }
    free(por_titulo->tabela);
    free(por_titulo);
}


