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


No* buscar_produto(No **inicio, int codigo) {
    No *atual = inicio;
    while (atual != NULL) {
        if (atual->produto.codigo == codigo) {
            return atual; // Encontrou o produto
        }
        atual = atual->prox;
    }
    return NULL;
}

void listar_produto(No *inicio, int codigo) {
    No *atual = inicio;

    if (atual == NULL) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    printf("\ncodigo: %d\n", atual->produto.codigo);
    printf("nome: %s\n", atual->produto.nome);
    printf("quantidade: %d\n", atual->produto.quantidade);
    printf("preco: %.2f\n", atual->produto.preco);      
};