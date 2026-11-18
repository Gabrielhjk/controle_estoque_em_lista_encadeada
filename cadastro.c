#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int codigo;
    char nome[151];
    int quantidade;
    double preco;
    struct No *prox;
} No;

/* cadastra um produto no inicio da lista e devolve o novo inicio */
No *cadastrar(No *inicio) {
    No *novo = (No *) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Sem memoria para cadastrar.\n");
        return inicio;
    }

    printf("Codigo: ");
    scanf("%d", &novo->codigo);

    printf("Nome: ");
    scanf(" %150[^\n]", novo->nome);

    printf("Quantidade: ");
    scanf("%d", &novo->quantidade);

    printf("Preco: ");
    scanf("%lf", &novo->preco);

    /* o novo no aponta para o antigo o inicio da lista passa a apontar para o novo no */
    novo->prox = inicio;
    inicio = novo;

    printf("Produto cadastrado com sucesso!\n");
    return inicio;
}

int main(void) {
    No *inicio = NULL;      /* lista vazia */
    char outro = 's';

    while (outro == 's' || outro == 'S') {
        printf("\n");
        inicio = cadastrar(inicio);

        printf("Cadastrar outro? (s/n): ");
        scanf(" %c", &outro);
    }

    /* libera a memoria da lista */
    while (inicio != NULL) {
        No *proximo = inicio->prox;
        free(inicio);
        inicio = proximo;
    }
    return 0;
}
