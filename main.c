#include <stdio.h>
#include <stdlib.h>
#include "src/include/cadastro.h"
#include "src/include/busca.h"
#include "src/include/remover.h"
#include "src/include/atualizar.h"

int main() {
    No *inicio = NULL;
    Produto produto;
    int codigo;
    int opcao;

    do {
        printf("Olá, Seja bem-vindo ao Controle de Estoque\n");
        printf("1 - Cadastrar Produto\n");
        printf("2 - Listar Produtos\n");
        printf("3 - Listar Produto\n");
        printf("4 - Atualizar Produto\n");
        printf("5 - Remover Produto\n");
        printf("6 - Sair do Sistema\n");
       
        printf("O que você gostaria de fazer? (digite um número correspondente a opção)\n");
        if(scanf("%d, &opcao") != 1) break;

        switch (opcao) {
        case 1:
            printf("Código do Produto: \n");
            if(scanf("%d", &produto.codigo) != 1) break;
            
            if(buscar_produto(inicio, produto.codigo) != NULL) {
                printf("Código do Produto já está cadastrado");
                break;
            }

            printf("Nome do Produto: \n");
            if(scanf(" %50[^\n]", produto.nome) != 1) break;
            
            printf("Preço do Produto: \n");
            if(scanf("%f", produto.preco) != 1) break;
            
            printf("Quantidade do Produto: \n");
            if(scanf("%d", produto.quantidade) != 1) break;
    
            if(cadastrar_produto(&inicio, produto)) {
                printf("Produto Cadastrado com Sucesso!\n");
            } else {
                printf("Erro na Memória!\n");
            }
        case 2:
            listar_produtos(inicio);
            break;
        case 3:
            printf("Qual Produto você Gostaria de Visualizar? (Digite o Código)\n");
            codigo = scanf("%f", produto.codigo);
            if(buscar_produto(inicio, codigo)) {
                listar_produto(inicio, codigo);
            } else {
                printf("Produto Não Encontrado!");
            };
        case 4:
            

        default:
            break;
        }

    } while (opcao != 6);



    // liberar_no(&inicio);
    return 0;
};
