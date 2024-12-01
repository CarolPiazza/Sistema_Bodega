#ifndef EMPRESA_H
#define EMPRESA_H

typedef struct {
    char nome[50];
    char cnpj[20];
} Empresa;

void inicializarEmpresa(Empresa *empresa, const char *nome, const char *cnpj);


void mostrarEmpresa(const Empresa *empresa);

#endif 