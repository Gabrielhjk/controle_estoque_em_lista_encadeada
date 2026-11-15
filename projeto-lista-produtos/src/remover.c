#include <stdio.h>
#include <stdlib.h>

// Remove um produto pelo codigo
int remover(No **inicio, int codigo) {
    No *atual = *inicio;
    No *anterior = NULL;

    while (atual != NULL &&
           atual->produto.codigo != codigo) {

        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        return 0;
    }

    if (anterior == NULL) {
        *inicio = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    free(atual);
    return 1;
}