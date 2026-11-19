#include <stdio.h>
#include <stdlib.h>
#include "../include/remover.h"

// Remove um produto pelo codigo
int remover(No **inicio, int codigo) {
    No *atual = *inicio;
    No *anterior = NULL;

    while (atual != NULL &&
           atual->produto.codigo != codigo) {

        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        return 0;
    }

    if (anterior == NULL) {
        *inicio = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    free(atual);
    return 1;
}
