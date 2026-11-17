#include <stdio.h>
#include <stdlib.h>
#include "cadastro.h"
#include "busca.h"
#include "remover.h"
#include "atualizar.h"

int main() {
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
};
