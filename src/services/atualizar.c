#include <stdio.h>
#include <stdlib.h>
#include "./src/include/atualizar.h"
#include "./src/include/busca.h"

int atualizar_produto(No *inicio, int codigo, Produto *novo_produto) {
    Produto *produto = buscar_produto(inicio, codigo);
    
    if (produto == NULL) {
        return 0;
    };

    strcpy(produto->nome, novo_produto->nome);
    produto->quantidade = novo_produto->quantidade;
    produto->preco = novo_produto->preco;

    return 1;
};