#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Bebida.h"

void cadastrarBebida(Bebida **lista) {
    Bebida *nova = (Bebida *)malloc(sizeof(Bebida));
    printf("Código da bebida: ");
    scanf("%d", &nova->codigo);

    Bebida *aux = *lista;
    while (aux) {
        if (aux->codigo == nova->codigo) {
            printf("Código já cadastrado!\n");
            free(nova);
            return;
        }
        aux = aux->proxima;
    }

    printf("Nome: ");
    scanf("%s", nova->nome);
    printf("Conteúdo em ml: ");
    scanf("%d", &nova->conteudo_ml);
    printf("Preço de venda: ");
    scanf("%f", &nova->preco_venda);
    printf("Quantidade em estoque: ");
    scanf("%d", &nova->estoque);
    printf("É alcoólica? (1-Sim, 0-Não): ");
    scanf("%d", &nova->alcoolica);
    if (nova->alcoolica) {
        printf("Teor alcoólico: ");
        scanf("%f", &nova->teor_alcoolico);
    }
    nova->proxima = *lista;
    *lista = nova;

    printf("Bebida cadastrada com sucesso!\n");
}

void mostrarBebidas(Bebida *lista) {
    if (!lista) {
        printf("Nenhuma bebida cadastrada.\n");
        return;
    }

    printf("Lista de bebidas:\n");
    while (lista) {
        printf("Código: %d, Nome: %s, Estoque: %d, Preço: %.2f, %s\n",
               lista->codigo, lista->nome, lista->estoque, lista->preco_venda,
               lista->alcoolica ? "Alcoólica" : "Não Alcoólica");
        lista = lista->proxima;
    }
}

void comprarBebida(Bebida *lista) {
    int codigo, quantidade;
    printf("Digite o código da bebida: ");
    scanf("%d", &codigo);
    printf("Digite a quantidade a comprar: ");
    scanf("%d", &quantidade);

    Bebida *aux = lista;
    while (aux) {
        if (aux->codigo == codigo) {
            aux->estoque += quantidade;
            printf("Estoque atualizado com sucesso!\n");
            return;
        }
        aux = aux->proxima;
    }

    printf("Bebida não encontrada.\n");
}

int venderBebida(Bebida *lista, int codigo, int quantidade, int idade_cliente) {
    Bebida *aux = lista;
    while (aux) {
        if (aux->codigo == codigo) {
            if (aux->alcoolica && idade_cliente < 18) {
                printf("Venda não permitida para menores de idade.\n");
                return 0;
            }
            if (aux->estoque >= quantidade) {
                aux->estoque -= quantidade;
                printf("Venda realizada com sucesso!\n");
                return 1;
            } else {
                printf("Estoque insuficiente.\n");
                return 0;
            }
        }
        aux = aux->proxima;
    }

    printf("Bebida não encontrada.\n");
    return 0;
}
