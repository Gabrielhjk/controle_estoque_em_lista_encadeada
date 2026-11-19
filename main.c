#include <stdio.h>
#include <stdlib.h>
#include "src/include/cadastro.h"
#include "src/include/busca.h"
#include "src/include/remover.h"
#include "src/include/atualizar.h"
#ifdef _WIN32
#include <windows.h>
#endif

static void limpar_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/* lê um inteiro: 1 = ok, 0 = entrada inválida, EOF = fim da entrada */
static int ler_int(int *valor) {
    int r = scanf("%d", valor);
    if (r == 0) {
        printf("\nEntrada inválida! Digite um número válido entre as opções.\n");
        limpar_buffer();
    }
    return r;
}

/* lê um decimal: 1 = ok, 0 = entrada inválida, EOF = fim da entrada */
static int ler_double(double *valor) {
    int r = scanf("%lf", valor);
    if (r == 0) {
        printf("Entrada inválida! Digite um número.\n");
        limpar_buffer();
    }
    return r;
}

int main() {
    No *inicio = NULL;
    Produto produto;
    int codigo;
    int opcao = 0;
    int lido;
    int r;
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    #endif

    do {
        printf("\nOlá, Seja bem-vindo ao Controle de Estoque\n");
        printf("\n1 - Cadastrar Produto\n");
        printf("2 - Listar Produtos\n");
        printf("3 - Listar Produto específico\n");
        printf("4 - Atualizar Produto\n");
        printf("5 - Remover Produto\n");
        printf("6 - Sair do Sistema\n");
        printf("\nO que você gostaria de fazer? (digite um número correspondente a opção)\n");

        lido = ler_int(&opcao);
        if (lido == EOF) break;
        if (lido == 0) continue;

        switch (opcao) {
        case 1:
            printf("Código do Produto: \n");
            if(ler_int(&produto.codigo) != 1) break;
            
            if(buscar_produto(inicio, produto.codigo) != NULL) {
                printf("Código do Produto já está cadastrado\n");
                break;
            }

            printf("Nome do Produto: \n");
            if(scanf(" %150[^\n]", produto.nome) != 1) break;
            if(!nome_e_texto(produto.nome)) {
                printf("\nNome inválido (use apenas letras)!\n");
                break;
            }
            
            printf("Preço do Produto: \n");
            if(ler_double(&produto.preco) != 1) break;
            
            printf("Quantidade do Produto: \n");
            if(ler_int(&produto.quantidade) != 1) break;
    
            r = cadastrar_produto(&inicio, produto);
            if (r == CADASTRO_OK) {
                printf("Produto Cadastrado com Sucesso!\n");
            } else if (r == CADASTRO_NOME_INVALIDO) {
                printf("\nNome inválido (use apenas letras)!\n");
            } else {
                printf("Erro na Memória!\n");
            }
            break;
        case 2: 
            listar_produtos(inicio);
            break;
        case 3:
            printf("Qual Produto você Gostaria de Visualizar? (Digite o Código)\n");
            if(ler_int(&codigo) != 1) break;
            listar_produto(inicio, codigo);
            break;
        case 4:
            printf("Código do Produto a atualizar: \n");
            if(ler_int(&codigo) != 1) break;
            printf("Novo Nome: \n");
            if(scanf(" %150[^\n]", produto.nome) != 1) break;
            if(!nome_e_texto(produto.nome)) {
                printf("\nNome inválido (use apenas letras)!\n");
                break;
            }
            printf("Novo Preço: \n");
            if(ler_double(&produto.preco) != 1) break;
            printf("Nova Quantidade: \n");
            if(ler_int(&produto.quantidade) != 1) break;
            if(atualizar_produto(inicio, codigo, &produto)) {
                printf("Produto atualizado!\n");
            } else {
                printf("Produto não encontrado ou nome inválido!\n");
            }
            break;
        case 5:
            printf("Código do Produto a remover: \n");
            if(ler_int(&codigo) != 1) break;
            if(remover(&inicio, codigo)) {
                printf("Produto removido!\n");
            } else {
                printf("\nProduto não encontrado!\n");
            }
            break;
        case 6:
            printf("Saindo...\n");
            break;
            
        default:
            printf("Opção inválida!\n");
            break;
        }

    } while (opcao != 6);


     liberar_no(&inicio);
    return 0;
}
