#pragma once
#include "lista.h"

int nome_e_texto(char *nome);
int cadastrar_produto(No *inicio, Produto produto);
void liberar_no(No *inicio);
void listar_produtos(No **inicio);
