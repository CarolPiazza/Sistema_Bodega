// Aqui foi feito o funcionamento do código:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Bodega.h"

void cadastrarBebida(Bebida **firstBebida){

    Bebida *novaBebida = (Bebida*)malloc(sizeof(Bebida));

    printf("Digite o código da bebida: ");
    scanf("%d", &novaBebida->codigo);

    if (novaBebida->codigo < 0){

        printf("Não pode ser negativo! Voltando ao menu.\n");

        free(novaBebida);
        return;
    }

    Bebida *aux = *firstBebida;

    while (aux != NULL){

        if (aux->codigo == novaBebida->codigo){

            printf("Código de bebida já existe!\n");

            free(novaBebida);
            return;
        }

        aux = aux->next;
    }

    printf("Digite o nome da bebida: ");
    scanf("%s", novaBebida->nome);

    printf("Digite o conteúdo em ml: ");
    scanf("%d", &novaBebida->conteudo_ml);

    if (novaBebida->conteudo_ml < 0){

        printf("Conteúdo não pode ser negativo! Voltando ao menu.\n");

        free(novaBebida);
        return;
    }

    printf("Digite o preço de venda: ");
    scanf("%f", &novaBebida->preco_venda);

    if (novaBebida->preco_venda < 0){

        printf("Preço não pode ser negativo! Voltando ao menu.\n");

        free(novaBebida);
        return;
    }

    printf("Digite a quantidade em estoque: ");
    scanf("%d", &novaBebida->qtd_estoque);

    if (novaBebida->qtd_estoque < 0){

        printf("Quantidade em estoque não pode ser negativa! Voltando ao menu.\n");

        free(novaBebida);
        return;
    }

    printf("Digite o teor alcoólico (0 se não for alcoólica): ");
    scanf("%f", &novaBebida->teor_alcoolico);

    if (novaBebida->teor_alcoolico < 0){

        printf("Teor alcoólico não pode ser negativo! Voltando ao menu.\n");

        free(novaBebida);
        return;
    }

    novaBebida->next = *firstBebida;
    *firstBebida = novaBebida;

    printf("Bebida cadastrada com sucesso!\n");
}

void comprarBebida(Bebida **firstBebida){

    int codigo, qtd;

    printf("Digite o código da bebida: ");
    scanf("%d", &codigo);

    Bebida *aux = *firstBebida;

    while (aux != NULL){

        if (aux->codigo == codigo) 
        break;

        aux = aux->next;
    }

    if (aux == NULL){

        printf("Código de bebida não encontrado! Voltando ao menu.\n");

        return;
    }

    printf("Digite a quantidade a ser comprada: ");
    scanf("%d", &qtd);

    if (qtd <= 0){

        printf("A quantidade não pode ser 0 ou negativa! Voltando ao menu.\n");

        return;
    }

    aux->qtd_estoque += qtd;

    printf("Compra realizada com sucesso! Novo estoque: %d\n", aux->qtd_estoque);
}

void venderBebida(Bebida **firstBebida, Cliente *firstCliente){

    int codigo, qtd;
    char CPF[15];

    printf("Digite o CPF do cliente: ");
    scanf("%s", CPF);

    Cliente* cliente = firstCliente;

    while (cliente != NULL){

        if (strcmp(cliente->CPF, CPF) == 0) 
        break;

        cliente = cliente->next;
    }

    if (cliente == NULL){

        printf("Cliente não encontrado! Voltando ao menu.\n");

        return;
    }

    printf("Digite o código da bebida: ");
    scanf("%d", &codigo);

    Bebida *aux = *firstBebida;
    Bebida *prev = NULL;

    while (aux != NULL){

        if (aux->codigo == codigo) 
        break;

        prev = aux;
        aux = aux->next;
    }

    if (aux == NULL){

        printf("Código de bebida não encontrado! Voltando ao menu.\n");

        return;
    }

    printf("Digite a quantidade a ser vendida: ");
    scanf("%d", &qtd);

    if (qtd <= 0){

        printf("A quantidade não pode ser 0 ou negativa! Voltando ao menu.\n");

        return;
    }

    if (aux->qtd_estoque < qtd){

        printf("Estoque insuficiente para a venda. Voltando ao menu.\n");

        return;
    }

    if (aux->teor_alcoolico > 0 && cliente->idade < 18){

        printf("Venda não permitida! O cliente não é maior de idade. Voltando ao menu.\n");

        return;
    }

    aux->qtd_estoque -= qtd;

    printf("Venda realizada com sucesso! Estoque restante: %d\n", aux->qtd_estoque);

    if (aux->qtd_estoque == 0){

        if (prev == NULL){

            *firstBebida = aux->next;

        } else{

            prev->next = aux->next;
        }

        free(aux);
    }
}

void mostrarBebidas(Bebida *firstBebida){

    if (firstBebida == NULL){

        printf("Nenhuma bebida cadastrada.\n");

        return;
    }

    Bebida *aux = firstBebida;

    while (aux != NULL){

        printf("\nCódigo: %d\nNome: %s\nConteúdo: %d ml\nPreço: R$ %.2f\nEstoque: %d\nTeor alcoólico: %.2f%%\n",
                aux->codigo, aux->nome, aux->conteudo_ml, aux->preco_venda, aux->qtd_estoque, aux->teor_alcoolico);

                aux = aux->next;
    }
}

void cadastrarCliente(Cliente **firstCliente){

    Cliente* novoCliente = (Cliente*)malloc(sizeof(Cliente));

    printf("Digite o código do cliente: ");
    scanf("%d", &novoCliente->codigo);

    Cliente *aux = *firstCliente;

    while (aux != NULL){

        if (aux->codigo == novoCliente->codigo){

            printf("Código já existente! Cadastro não realizado.\n");

            free(novoCliente);
            return;
        }
        aux = aux->next;
    }

    printf("Digite o nome do cliente: ");
    scanf("%s", novoCliente->nome);

    printf("Digite o CPF do cliente (apenas números, sem caracteres especiais): ");
    scanf("%s", novoCliente->CPF);

    aux = *firstCliente;

    while (aux != NULL){

        if (strcmp(aux->CPF, novoCliente->CPF) == 0){
            printf("CPF já cadastrado! Cadastro não realizado.\n");

            free(novoCliente);
            return;
        }

        aux = aux->next;
    }

    if (strlen(novoCliente->CPF) != 11){
        printf("CPF inválido!\n");

        free(novoCliente);
        return;
    }

    printf("Digite a idade do cliente: ");
    scanf("%d", &novoCliente->idade);

    printf("Pode vender fiado? (1 para sim, 0 para não): ");
    scanf("%d", &novoCliente->fiado);

    if (*firstCliente == NULL || novoCliente->idade <= (*firstCliente)->idade){
        novoCliente->next = *firstCliente;
        *firstCliente = novoCliente;

    } else {
        aux = *firstCliente;

        while (aux->next != NULL && aux->next->idade < novoCliente->idade){

            aux = aux->next;
        }

        novoCliente->next = aux->next;
        aux->next = novoCliente;
    }

    printf("Cliente cadastrado com sucesso!\n");
}

void mostrarClientes(Cliente *firstCliente){

    if (firstCliente == NULL){
        printf("Nenhum cliente cadastrado.\n");
        return;
    }

    Cliente *aux = firstCliente;
    
    while (aux != NULL){

        printf("\nCódigo: %d\nNome: %s\nCPF: %s\nIdade: %d\nFiado: %s\n", aux->codigo, aux->nome, aux->CPF, aux->idade, aux->fiado ? "Sim" : "Não");
        aux = aux->next;
    }
}

void sairSistema(Bebida **firstBebida, Cliente **firstCliente){

    Bebida *auxBebida;
    int contBebidas = 0; 
    Cliente *auxCliente;
    int contClientes = 0;

    while (*firstBebida != NULL){

        auxBebida = *firstBebida;
        *firstBebida = (*firstBebida)->next;

        free(auxBebida);
        contBebidas++; 
    }

    while (*firstCliente != NULL){

        auxCliente = *firstCliente;
        *firstCliente = (*firstCliente)->next;

        free(auxCliente);
        contClientes++;
    }

    int totalLiberados = contBebidas + contClientes;
    printf("Memória liberada com sucesso!\n %d elementos foram liberados\n(Bebidas: %d, Clientes: %d).\n", totalLiberados, contBebidas, contClientes);
}

