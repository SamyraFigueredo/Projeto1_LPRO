#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct {
    char nome[50];
    int numero_conta;
    float saldo;
} Conta;
Conta conta;

void inicializar_conta() {
    printf("=== Inicializacao da Conta ===\n\n");

    printf("Informe o nome do correntista: ");
    fgets(conta.nome, sizeof(conta.nome), stdin);
    conta.nome[strcspn(conta.nome, "\n")] = 0;

    printf("Informe o numero da conta: ");
    scanf("%d", &conta.numero_conta);

    printf("Informe o valor inicial de deposito (pode ser zero): R$ ");
    scanf("%f", &conta.saldo);

    printf("\nConta criada com sucesso!\n");
    printf("Pressione qualquer tecla para continuar...");
    getch();
}

void exibir_menu() {
    printf("\n=== Menu da Conta Corrente ===\n\n");
    printf("1 - Consultar Saldo\n");
    printf("2 - Depositar\n");
    printf("3 - Sacar\n");
    printf("4 - Sair\n");
}

void consultar_saldo() {
    system("cls || clear");
    printf("=== Consultar Saldo ===\n\n");
    printf("Correntista: %s\n", conta.nome);
    printf("Numero da Conta: %d\n", conta.numero_conta);
    printf("Saldo Disponivel: R$ %.2f\n", conta.saldo);
    printf("\nPressione qualquer tecla para continuar...");
    getch();
}

void depositar() {
    system("cls || clear");
    float valor;

    printf("=== Depositar ===\n\n");
    printf("Informe o valor para deposito: R$ ");
    scanf("%f", &valor);

    if (valor > 0) {
        conta.saldo += valor;
        printf("\nDeposito realizado com sucesso!\n");
        printf("Novo saldo: R$ %.2f\n", conta.saldo);
    } else {
        printf("\nValor invalido. O deposito deve ser maior que zero.\n");
    }
    printf("\nPressione qualquer tecla para continuar...");
    getch();
}

void sacar() {
    system("cls || clear");
    float valor;

    printf("=== Sacar ===\n\n");
    printf("Informe o valor para saque: R$ ");
    scanf("%f", &valor);

    if (valor > 0 && valor <= conta.saldo) {
        conta.saldo -= valor;
        printf("\nSaque realizado com sucesso!\n");
        printf("Novo saldo: R$ %.2f\n", conta.saldo);
    } else if (valor > conta.saldo) {
        printf("\nSaldo insuficiente para realizar o saque.\n");
    } else {
        printf("\nValor invalido. O saque deve ser maior que zero.\n");
    }
    printf("\nPressione qualquer tecla para continuar...");
    getch();
}

int main() {
    int opcao;
    inicializar_conta();

    do {
        system("cls || clear");
        exibir_menu();
        printf("\nEscolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("\nEntrada invalida. Tente novamente!\n");
            while (getchar() != '\n');
            continue;
        }
        switch (opcao) {
            case 1:
                consultar_saldo();
                break;
            case 2:
                depositar();
                break;
            case 3:
                sacar();
                break;
            case 4:
                system("cls || clear");
                printf("\nObrigado por utilizar o sistema. Ate logo!\n");
                exit(0);
            default:
                printf("\nOpcao invalida. Tente novamente!\n");
                printf("\nPressione qualquer tecla para continuar...");
                getch();
                break;
        }
    } while (1);
    return 0;
}