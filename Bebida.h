#ifndef BEBIDA_H
#define BEBIDA_H

typedef struct Bebida {
    int codigo;
    char nome[50];
    int conteudo_ml;
    float preco_venda;
    int estoque;
    int alcoolica;  
    float teor_alcoolico; 
    struct Bebida *proxima;
} Bebida;

void cadastrarBebida(Bebida **lista);
void mostrarBebidas(Bebida *lista);
void comprarBebida(Bebida *lista);
int venderBebida(Bebida *lista, int codigo, int quantidade, int idade_cliente);

#endif
