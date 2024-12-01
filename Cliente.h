#ifndef CLIENTE_H
#define CLIENTE_H

typedef struct Cliente {
    char nome[50];
    char cpf[15];
    int idade;
    int fiado; 
    struct Cliente *proximo;
} Cliente;

void cadastrarCliente(Cliente **lista);
void mostrarClientes(Cliente *lista);

#endif
