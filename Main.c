// Trabalho final de Estruturas de Dados - 2024/02

// Alunas: Caroline de Quadros Piazza (20230000690) e Eduarda Lazzaretti da Silva (20230002925)

// Bodega do Maneca:
// Aqui foi feito o Menu

#include <stdio.h>
#include <string.h>
#include "Bodega.h"

int main(){

    Empresa empresa = {"Bodega do Maneca", "12.345.678/0001-90"};
    Bebida* firstBebida = NULL;
    Cliente* firstCliente = NULL;
    int opcao;

    printf("\n**************************************************\n");
    printf("\n--- Bem-Vindo(a) a %s! ---\n\n\tCNPJ: %s\n", empresa.nome_empresa, empresa.CNPJ);
    printf("\n**************************************************\n");

    do{
        printf("\n- MENU: \n\n");
        printf("1. Cadastrar bebida\n");
        printf("2. Mostrar bebidas\n");
        printf("3. Comprar bebida\n");
        printf("4. Vender bebida\n");
        printf("5. Cadastrar cliente\n");
        printf("6. Mostrar clientes\n");
        printf("7. Sair do sistema\n");
        printf("\n\nEscolha uma opção:\n");
        printf("-> ");
        scanf("%d", &opcao);

        switch (opcao){
            case 1:
                cadastrarBebida(&firstBebida);
                break;

            case 2:
                mostrarBebidas(firstBebida);
                break;

            case 3:
                comprarBebida(&firstBebida);
                break;

            case 4:
                venderBebida(&firstBebida, firstCliente);
                break;

            case 5:
                cadastrarCliente(&firstCliente);
                break;

            case 6:
                mostrarClientes(firstCliente);
                break;

            case 7:
                sairSistema(&firstBebida, &firstCliente);
                break;
        }
    } while (opcao != 7);

    return 0;
}
