#include <stdio.h>
#include "../include/busca.h"

No* buscar_produto(No *inicio, int codigo) {
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
    No *no = buscar_produto(inicio, codigo);

    if (no == NULL) {
        printf("Produto não encontrado!\n");
        return;
    }

    printf("\nCodigo: %d\n", no->produto.codigo);
    printf("Nome: %s\n", no->produto.nome);
    printf("Quantidade: %d\n", no->produto.quantidade);
    printf("Preço: %.2f\n", no->produto.preco);
} 