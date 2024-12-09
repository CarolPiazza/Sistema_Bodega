// Aqui foram feitas as estruturas Empresa, Bebida e Cliente:

#ifndef BODEGA_H
#define BODEGA_H

typedef struct{

    char nome_empresa[90];
    char CNPJ[20];
}Empresa;

typedef struct Bebida{

    int codigo;
    char nome[90];
    int conteudo_ml;
    float preco_venda;
    int qtd_estoque;
    float teor_alcoolico;
    struct Bebida *next;
}Bebida;

typedef struct Cliente{

    int codigo;
    char nome[90];
    char CPF[12];
    int idade;
    int fiado;
    struct Cliente *next;
}Cliente;

void mostrarMenu(Empresa empresa, Bebida *firstBebida, Cliente *firstCliente);
void cadastrarBebida(Bebida **firstBebida);
void mostrarBebidas(Bebida *firstBebida);
void comprarBebida(Bebida **firstBebida);
void venderBebida(Bebida **firstBebida, Cliente* firstCliente);
void cadastrarCliente(Cliente **firstCliente);
void mostrarClientes(Cliente *firstCliente);
void sairSistema(Bebida **firstBebida, Cliente **firstCliente);

#endif
