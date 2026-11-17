#include <stdio.h>
#include <stdlib.h>
#include "atualizar.h"
#include "busca.h"

int atualizar_produto(Lista *l, int codigo, Produto *novo_produto) {
    Produto *produto = buscar_produto(l, codigo);
    
    if (produto == NULL) {
        return 0;
    };

    strcpy(produto->nome, novo_produto->nome);
    produto->quantidade = novo_produto->quantidade;
    produto->preco = novo_produto->preco;

    return 1;
};