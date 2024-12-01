#include <stdio.h>
#include <string.h>
#include "Empresa.h"

void inicializarEmpresa(Empresa *empresa, const char *nome, const char *cnpj) {
    strncpy(empresa->nome, nome, sizeof(empresa->nome) - 1);
    empresa->nome[sizeof(empresa->nome) - 1] = '\0';

    strncpy(empresa->cnpj, cnpj, sizeof(empresa->cnpj) - 1);
    empresa->cnpj[sizeof(empresa->cnpj) - 1] = '\0';
}

void mostrarEmpresa(const Empresa *empresa) {
    printf("Nome da Bodega: %s\n", empresa->nome);
    printf("CNPJ: %s\n", empresa->cnpj);
}
