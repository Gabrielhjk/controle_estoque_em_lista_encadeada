#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/lista.h"

#define CADASTRO_OK            0
#define CADASTRO_NOME_INVALIDO 1
#define CADASTRO_SEM_MEMORIA   2

/* confere se o nome e apenas texto */
static int nome_e_texto(char *nome) {
    int tem_letra = 0;

    for (char *c = nome; *c != '\0'; c++) {
        unsigned char ch = (unsigned char) *c;

        if (isalpha(ch) || ch >= 128) {     /* letra acentuada */
            tem_letra = 1;
        } else if (ch != ' ') {
            return 0;                       /* numero ou simbolo */
        }
    }
    return tem_letra;
}

/* cadastra um produto no fim da No */
int cadastrar_produto(No *inicio, Produto produto) {

    /* o nome so aceita texto */
    if (!nome_e_texto(produto.nome)) return CADASTRO_NOME_INVALIDO;

    /* percorre a No e guarda o ultimo no */
    No *ultimo = NULL;
    No *atual = inicio;
    while (atual != NULL) {
        ultimo = atual;
        atual = atual->prox;
    }

    /* novo no */
    No *novo = (No *) malloc(sizeof(No));
    if (novo == NULL) return CADASTRO_SEM_MEMORIA;

    novo->produto.codigo = produto.codigo;
    strncpy(novo->produto.nome, produto.nome, TAM_NOME - 1);   /* copia no maximo 150 caracteres */
    novo->produto.nome[TAM_NOME - 1] = '\0';           /* garante o fim da string */
    novo->produto.quantidade = produto.quantidade;
    novo->produto.preco = produto.preco;
    novo->prox = NULL;

    /* liga o novo no na No */
    if (ultimo == NULL) {
        inicio = novo;           /* o novo vira o primeiro */
    } else {
        ultimo->prox = novo;        /* o ultimo antigo aponta para o novo */
    }

    return CADASTRO_OK;
}

void liberar_no(No *inicio) {
    No *atual = inicio;
    while (atual != NULL) {
        No *proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    inicio = NULL;
}

/* mostra todos os produtos da No */
void listar_produtos(No **inicio) {
    No *atual = *inicio;
    printf("\nProdutos cadastrados\n");

    if (atual == NULL) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    while (atual != NULL) {
        printf("\ncodigo: %d\n", atual->produto.codigo);
        printf("nome: %s\n", atual->produto.nome);
        printf("quantidade: %d\n", atual->produto.quantidade);
        printf("preco: %.2f\n", atual->produto.preco);
        
        atual = atual->prox;
    }
};
