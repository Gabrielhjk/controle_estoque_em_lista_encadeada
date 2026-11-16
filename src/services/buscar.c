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

No* buscar_produto(const Lista *l, int codigo) {
    No *atual = l->inicio;
    while (atual != NULL) {
        if (atual->produto.codigo == codigo) {
            return atual; // Encontrou o produto
        }
        atual = atual->prox;
    }
    return NULL;
}