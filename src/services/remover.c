#include <stdio.h>
#include <stdlib.h>
#include "remover.h"

// Remove um produto pelo codigo
int remover(Lista *l, int codigo) {
    No *atual = l->inicio;
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
        l->inicio = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    free(atual);
    return 1;
}