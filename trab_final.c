#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Empresa {
    char nome[50];
    char cnpj[15];
} Empresa;

typedef struct Bebida {
    int codigo;
    char nome[50];
    int conteudo_ml;
    float preco_venda;
    int quantidade;
    float teor_alcoolico; 
    struct Bebida* proximo;
} Bebida;

typedef struct Cliente {
    int codigo;
    char nome[50];
    char cpf[12];
    int idade;
    int pode_fiado; 
    struct Cliente* proximo;
} Cliente;

Bebida* lista_bebidas = NULL;
Cliente* lista_clientes = NULL;

Empresa empresa;

Bebida* buscarBebida(int codigo) {
    Bebida* atual = lista_bebidas;
    while (atual != NULL) {
        if (atual->codigo == codigo) return atual;
        atual = atual->proximo;
    }
    return NULL;
}

Cliente* buscarClienteCPF(const char* cpf) {
    Cliente* atual = lista_clientes;
    while (atual != NULL) {
        if (strcmp(atual->cpf, cpf) == 0) return atual;
        atual = atual->proximo;
    }
    return NULL;
}

int clienteExiste(int codigo) {
    Cliente* atual = lista_clientes;
    while (atual != NULL) {
        if (atual->codigo == codigo) return 1;
        atual = atual->proximo;
    }
    return 0;
}

void cadastrarBebida() {
    Bebida* nova_bebida = (Bebida*)malloc(sizeof(Bebida));
    printf("Digite o código da bebida: ");
    scanf("%d", &nova_bebida->codigo);

    if (buscarBebida(nova_bebida->codigo) != NULL) {
        printf("Código já existe! Cadastro cancelado.\n");
        free(nova_bebida);
        return;
    }

    printf("Digite o nome da bebida: ");
    scanf("%s", &nova_bebida->nome);
    printf("Digite o conteúdo líquido (ml): ");
    scanf("%d", &nova_bebida->conteudo_ml);
    printf("Digite o preço de venda: ");
    scanf("%f", &nova_bebida->preco_venda);
    printf("Digite a quantidade em estoque: ");
    scanf("%d", &nova_bebida->quantidade);
    printf("Digite o teor alcoólico (0.0 para não-alcoólicas): ");
    scanf("%f", &nova_bebida->teor_alcoolico);

    nova_bebida->proximo = lista_bebidas;
    lista_bebidas = nova_bebida;
    printf("Bebida cadastrada com sucesso!\n");
}

void mostrarBebidas() {
    Bebida* atual = lista_bebidas;
    if (atual == NULL) {
        printf("Nenhuma bebida cadastrada.\n");
        return;
    }
    printf("\nBebidas cadastradas\n");
    while (atual != NULL) {
        printf("Código: %d | Nome: %s | Conteúdo: %dml | Preço: R$%.2f | Estoque: %d | Teor: %.2f%%\n",
               atual->codigo, atual->nome, atual->conteudo_ml, atual->preco_venda,
               atual->quantidade, atual->teor_alcoolico);
        atual = atual->proximo;
    }
}

void comprarBebida() {
    int codigo, quantidade;
    printf("Digite o código da bebida: ");
    scanf("%d", &codigo);
    Bebida* bebida = buscarBebida(codigo);

    if (bebida == NULL) {
        printf("Bebida não encontrada!\n");
        return;
    }

    printf("Digite a quantidade a ser comprada: ");
    scanf("%d", &quantidade);
    bebida->quantidade += quantidade;
    printf("Estoque atualizado! Nova quantidade: %d\n", bebida->quantidade);
}

void venderBebida() {
    char cpf[12];
    int codigo, quantidade;

    printf("Digite o CPF do cliente: ");
    scanf("%s", cpf);
    Cliente* cliente = buscarClienteCPF(cpf);

    if (cliente == NULL) {
        printf("Cliente não encontrado!\n");
        return;
    }

    printf("Digite o código da bebida: ");
    scanf("%d", &codigo);
    Bebida* bebida = buscarBebida(codigo);

    if (bebida == NULL) {
        printf("Bebida não encontrada!\n");
        return;
    }

    printf("Digite a quantidade a ser vendida: ");
    scanf("%d", &quantidade);

    if (bebida->quantidade < quantidade) {
        printf("Estoque insuficiente!\n");
        return;
    }

    if (bebida->teor_alcoolico > 0.0 && cliente->idade < 18) {
        printf("Venda proibida! Cliente menor de idade.\n");
        return;
    }

    bebida->quantidade -= quantidade;
    printf("Venda realizada com sucesso! Estoque restante: %d\n", bebida->quantidade);
}

void cadastrarCliente() {
    Cliente* novo_cliente = (Cliente*)malloc(sizeof(Cliente));
    printf("Digite o código do cliente: ");
    scanf("%d", &novo_cliente->codigo);

    if (clienteExiste(novo_cliente->codigo)) {
        printf("Código já existe! Cadastro cancelado.\n");
        free(novo_cliente);
        return;
    }

    printf("Digite o nome do cliente: ");
    scanf("%s", &novo_cliente->nome);
    printf("Digite o CPF do cliente: ");
    scanf("%s", &novo_cliente->cpf);
    printf("Digite a idade do cliente: ");
    scanf("%d", &novo_cliente->idade);
    printf("Pode vender fiado? (1 - Sim, 0 - Não): ");
    scanf("%d", &novo_cliente->pode_fiado);

    novo_cliente->proximo = lista_clientes;
    lista_clientes = novo_cliente;
    printf("Cliente cadastrado com sucesso!\n");
}

void mostrarClientes() {
    Cliente* atual = lista_clientes;
    if (atual == NULL) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }
    printf("\n--- Clientes cadastrados ---\n");
    while (atual != NULL) {
        printf("Código: %d | Nome: %s | CPF: %s | Idade: %d | Fiado: %s\n",
               atual->codigo, atual->nome, atual->cpf, atual->idade,
               atual->pode_fiado ? "Sim" : "Não");
        atual = atual->proximo;
    }
}

void cadastrarEmpresa() {
    printf("\nCadastro da Empresa\n");
    printf("Digite o nome da empresa: ");
    scanf("%s", empresa.nome);
    printf("Digite o CNPJ da empresa: ");
    scanf("%s", empresa.cnpj);
    printf("Empresa cadastrada com sucesso! Nome: %s | CNPJ: %s\n", empresa.nome, empresa.cnpj);
}

void menu() {
    int opcao;
    do {
        printf("\nMenu\n");
        printf("1. Cadastrar bebida\n");
        printf("2. Mostrar bebidas\n");
        printf("3. Comprar bebida\n");
        printf("4. Vender bebida\n");
        printf("5. Cadastrar cliente\n");
        printf("6. Mostrar clientes\n");
        printf("7. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: cadastrarBebida(); break;
            case 2: mostrarBebidas(); break;
            case 3: comprarBebida(); break;
            case 4: venderBebida(); break;
            case 5: cadastrarCliente(); break;
            case 6: mostrarClientes(); break;
            case 7: printf("Encerrando o sistema!\n"); break;
            default: printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 7);
}

int main() {
    printf("Bem-vindo ao Sistema de gerenciamento da sua Bodega!\n");
    cadastrarEmpresa(); 
    menu();             
    return 0;
}
