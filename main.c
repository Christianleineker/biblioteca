#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"

int main() {
    TabelaHash *tabela_isbn = criar_tabela(100);
    TabelaHash *tabela_titulo = criar_tabela(100);

    if (!tabela_isbn || !tabela_titulo) {
        printf("Erro ao criar tabelas.\n");
        return 1;
    }

    Livro *livro1 = malloc(sizeof(Livro));
    strcpy(livro1->titulo, "Aprendendo C");
    strcpy(livro1->autor, "Jose Silva");
    livro1->isbn = 12345;
    livro1->prox_autor = NULL;
    inserir_livro(tabela_isbn, tabela_titulo, livro1);

    Livro *livro2 = malloc(sizeof(Livro));
    strcpy(livro2->titulo, "Estruturas de Dados");
    strcpy(livro2->autor, "Maria Souza");
    livro2->isbn = 67890;
    livro2->prox_autor = NULL;
    inserir_livro(tabela_isbn, tabela_titulo, livro2);

    Livro *encontrado = buscar_por_isbn(tabela_isbn, 12345);
    if (encontrado) {
        printf("Livro encontrado por ISBN: %s\n", encontrado->titulo);
    } else {
        printf("Livro não encontrado por ISBN.\n");
    }

    encontrado = buscar_por_titulo(tabela_titulo, "Estruturas de Dados");
    if (encontrado) {
        printf("Livro encontrado por Titulo: %s\n", encontrado->titulo);
    } else {
        printf("Livro não encontrado por Titulo.\n");
    }

    printf("\nLista de autores:\n");
    listar_autores(tabela_isbn);

    liberar_tabelas(tabela_isbn, tabela_titulo);

    free(livro1);
    free(livro2);

    return 0;
}

