#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "Bebida.h"
#include "Cliente.h"
#include "Empresa.h"


int main() {
    Empresa empresa = {"Bodega do Maneca", "12.345.678/0001-99"};
    Bebida *bebidas = NULL;
    Cliente *clientes = NULL;
    int opcao;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Cadastrar bebida\n");
        printf("2. Mostrar bebidas\n");
        printf("3. Comprar bebida\n");
        printf("4. Vender bebida\n");
        printf("5. Cadastrar cliente\n");
        printf("6. Mostrar clientes\n");
        printf("7. Sair do sistema\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarBebida(&bebidas);
                break;
            case 2:
                mostrarBebidas(bebidas);
                break;
            case 3:
                comprarBebida(bebidas);
                break;
            case 4: {
                char cpf[15];
                int codigo, quantidade, idade;
                printf("Digite o CPF do cliente: ");
                scanf("%s", cpf);

                Cliente *cliente = clientes;
                while (cliente && strcmp(cliente->cpf, cpf) != 0) {
                    cliente = cliente->proximo;
                }

                if (!cliente) {
                    printf("Cliente não encontrado.\n");
                    break;
                }

                idade = cliente->idade;
                printf("Digite o código da bebida: ");
                scanf("%d", &codigo);
                printf("Digite a quantidade: ");
                scanf("%d", &quantidade);

                venderBebida(bebidas, codigo, quantidade, idade);
                break;
            }
            case 5:
                cadastrarCliente(&clientes);
                break;
            case 6:
                mostrarClientes(clientes);
                break;
            case 7:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 7);

    return 0;
}
