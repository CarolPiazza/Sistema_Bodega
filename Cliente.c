#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cliente.h"

void cadastrarCliente(Cliente **lista) {
    Cliente *novo = (Cliente *)malloc(sizeof(Cliente));
    printf("Nome: ");
    scanf("%s", novo->nome);
    printf("CPF: ");
    scanf("%s", novo->cpf);
    printf("Idade: ");
    scanf("%d", &novo->idade);
    printf("Pode comprar fiado? (1-Sim, 0-Não): ");
    scanf("%d", &novo->fiado);

    if (!*lista || (*lista)->idade > novo->idade) {
        novo->proximo = *lista;
        *lista = novo;
        return;
    }

    Cliente *aux = *lista;
    while (aux->proximo && aux->proximo->idade <= novo->idade) {
        aux = aux->proximo;
    }

    novo->proximo = aux->proximo;
    aux->proximo = novo;
}

void mostrarClientes(Cliente *lista) {
    if (!lista) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }

    printf("Lista de clientes:\n");
    while (lista) {
        printf("Nome: %s, CPF: %s, Idade: %d, Fiado: %s\n",
               lista->nome, lista->cpf, lista->idade,
               lista->fiado ? "Sim" : "Não");
        lista = lista->proximo;
    }
}
