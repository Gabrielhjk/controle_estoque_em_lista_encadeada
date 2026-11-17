#pragma once
#include "lista.h"

void iniciar_lista(Lista *l);
int nome_e_texto(const char *nome);
int cadastrar_produto(Lista *l, int codigo, const char *nome, int quantidade, double preco);
void liberar_lista(Lista *l);
void lista_produtos(const Lista *l);
