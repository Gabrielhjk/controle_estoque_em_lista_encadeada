#pragma once
#include "lista.h"

#define CADASTRO_OK            0
#define CADASTRO_NOME_INVALIDO 1
#define CADASTRO_SEM_MEMORIA   2

int nome_e_texto(const char *nome);
int cadastrar_produto(No **inicio, Produto produto);
void liberar_no(No **inicio);
void listar_produtos(No *inicio);
