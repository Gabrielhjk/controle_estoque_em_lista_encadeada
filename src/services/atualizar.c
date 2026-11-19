#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/atualizar.h"
#include "../include/busca.h"
#include "../include/cadastro.h"

int atualizar_produto(No *inicio, int codigo, Produto *novo_produto) {
    No *no = buscar_produto(inicio, codigo);

    if (no == NULL) {
        return 0;
    }

    if (!nome_e_texto(novo_produto->nome)) {
        return 0;
    }

    strcpy(no->produto.nome, novo_produto->nome);
    no->produto.quantidade = novo_produto->quantidade;
    no->produto.preco = novo_produto->preco;

    return 1;
}
