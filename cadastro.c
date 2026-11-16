#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "projeto-lista-produtos/src/lista.h"

#define CADASTRO_OK            0
#define CADASTRO_NOME_INVALIDO 1
#define CADASTRO_SEM_MEMORIA   2

void iniciar_lista(Lista *l) {
    l->inicio = NULL;
}

/* confere se o nome e apenas texto */
static int nome_e_texto(const char *nome) {
    int tem_letra = 0;

    for (const char *c = nome; *c != '\0'; c++) {
        unsigned char ch = (unsigned char) *c;

        if (isalpha(ch) || ch >= 128) {     /* letra acentuada */
            tem_letra = 1;
        } else if (ch != ' ') {
            return 0;                       /* numero ou simbolo */
        }
    }
    return tem_letra;
}

/* cadastra um produto no fim da lista */
int cadastrar_produto(Lista *l, int codigo, const char *nome,
                      int quantidade, double preco) {

    /* o nome so aceita texto */
    if (!nome_e_texto(nome)) return CADASTRO_NOME_INVALIDO;

    /* percorre a lista e guarda o ultimo no */
    No *ultimo = NULL;
    No *atual = l->inicio;
    while (atual != NULL) {
        ultimo = atual;
        atual = atual->prox;
    }

    /* novo no */
    No *novo = (No *) malloc(sizeof(No));
    if (novo == NULL) return CADASTRO_SEM_MEMORIA;

    novo->produto.codigo = codigo;
    strncpy(novo->produto.nome, nome, TAM_NOME - 1);   /* copia no maximo 150 caracteres */
    novo->produto.nome[TAM_NOME - 1] = '\0';           /* garante o fim da string */
    novo->produto.quantidade = quantidade;
    novo->produto.preco = preco;
    novo->prox = NULL;

    /* liga o novo no na lista */
    if (ultimo == NULL) {
        l->inicio = novo;           /* o novo vira o primeiro */
    } else {
        ultimo->prox = novo;        /* o ultimo antigo aponta para o novo */
    }

    return CADASTRO_OK;
}

void liberar_lista(Lista *l) {
    No *atual = l->inicio;
    while (atual != NULL) {
        No *proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    l->inicio = NULL;
}

/* mostra todos os produtos da lista */
void listar_produtos(const Lista *l) {
    printf("\nProdutos cadastrados\n");

    if (l->inicio == NULL) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    No *atual = l->inicio;
    while (atual != NULL) {
        printf("\ncodigo: %d\n", atual->produto.codigo);
        printf("nome: %s\n", atual->produto.nome);
        printf("quantidade: %d\n", atual->produto.quantidade);
        printf("preco: %.2f\n", atual->produto.preco);
        
        atual = atual->prox;
    }
}

/* le uma linha inteira (aceita espacos) sem o '\n' */
static void ler_linha(const char *pergunta, char *destino, int tamanho) {
    printf("%s", pergunta);
    if (fgets(destino, tamanho, stdin) == NULL) {
        destino[0] = '\0';
        return;
    }
    size_t len = strlen(destino);
    if (len > 0 && destino[len - 1] == '\n') {
        destino[len - 1] = '\0';
    } else {
        int c;                    /* linha maior que o vetor descarta o resto */
        while ((c = getchar()) != '\n' && c != EOF) {
        }
    }
}

/* pede os dados ao usuario e cadastra */
static void cadastrar_pelo_teclado(Lista *l) {
    char linha[200];
    char nome[TAM_NOME];
    int codigo = 0, quantidade = 0;
    double preco = 0;

    printf("\nCadastrar produto \n");

    ler_linha("Codigo: ", linha, sizeof linha);
    sscanf(linha, "%d", &codigo);

    ler_linha("Nome: ", nome, sizeof nome);

    ler_linha("Quantidade: ", linha, sizeof linha);
    sscanf(linha, "%d", &quantidade);

    ler_linha("Preço: ", linha, sizeof linha);
    sscanf(linha, "%lf", &preco);

    switch (cadastrar_produto(l, codigo, nome, quantidade, preco)) {
        case CADASTRO_OK:
            printf("Produto cadastrado com sucesso!\n");
            break;
        case CADASTRO_NOME_INVALIDO:
            printf("Nome invalido: use apenas letras.\n");
            break;
        default:
            printf("Sem memoria para cadastrar.\n");
            break;
    }
}

int main(void) {
    Lista lista;
    char resposta[20];

    iniciar_lista(&lista);

    do {
        cadastrar_pelo_teclado(&lista);
        ler_linha("\nCadastrar outro produto? (s/n): ", resposta, sizeof resposta);
    } while (resposta[0] == 's' || resposta[0] == 'S');

    listar_produtos(&lista);

    liberar_lista(&lista);
    return 0;
}