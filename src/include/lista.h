#ifndef LISTA_H
#define LISTA_H

#define TAM_NOME 151

typedef struct {
    int codigo;
    char nome[TAM_NOME];
    int quantidade;
    double preco;
} Produto;

/* cada no guarda um produto e aponta para o proximo no */
typedef struct No {
    Produto produto;
    struct No *prox;
} No;

typedef struct {
    No *inicio;     /* lista vazia */
} Lista;

#endif