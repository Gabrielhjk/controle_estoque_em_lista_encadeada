#include <stdio.h>
#include <stdlib.h>

// Estruturas necessárias para a função de busca reconhecer o tipo de dado
typedef struct {
    int codigo;
    char nome[151];
    int quantidade;
    double preco;
} Produto;

typedef struct No {
    Produto produto;
    struct No *prox;
} No;

typedef struct {
    No *inicio;     
} Lista;