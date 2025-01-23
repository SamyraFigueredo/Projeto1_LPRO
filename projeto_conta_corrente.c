#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void limpar_tela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pausar_tela() {
    printf("\nPressione Enter para continuar...");
    getchar();
}

void consultar_saldo() {
    limpar_tela();
    char nome[50];
    int numero_conta;
    float saldo;

    printf("=== Consultar Saldo ===\n\n");
    printf("Informe o nome do correntista: ");
    getchar();
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0;

    printf("Informe o numero da conta: ");
    scanf("%d", &numero_conta);

    limpar_tela();
    printf("=== Informacoes da Conta ===\n\n");
    printf("Correntista: %s\n", nome);
    printf("Numero da Conta: %d\n", numero_conta);
    printf("Saldo Disponivel: R$ %.2f\n", saldo);

    pausar_tela();
}

void depositar() {
    limpar_tela();
    char nome[50];
    int numero_conta;
    float saldo = 0, valor;

    printf("=== Depositar ===\n\n");
    printf("Informe o nome do correntista: ");
    getchar();
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0;

    printf("Informe o numero da conta: ");
    scanf("%d", &numero_conta);

    printf("Informe o valor para deposito: R$ ");
    scanf("%f", &valor);

    if (valor > 0) {
        saldo += valor;
        printf("\nDepósito concluído com sucesso!\n");
        printf("Novo saldo: R$ %.2f\n", saldo);
    } else {
        printf("\nValor inválido. O depósito deve ser maior que zero.\n");
    }

    pausar_tela();
}

void sacar() {
    limpar_tela();
    char nome[50];
    int numero_conta;
    float saldo, valor;

    printf("=== Sacar ===\n\n");
    printf("Informe o nome do correntista: ");
    getchar();
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0;

    printf("Informe o numero da conta: ");
    scanf("%d", &numero_conta);

    printf("Informe o valor para saque: R$ ");
    scanf("%f", &valor);

    if (valor > 0 && valor <= saldo) {
        saldo -= valor;
        printf("\nSaque realizado com sucesso! Novo saldo: R$ %.2f\n", saldo);
    } else if (valor > saldo) {
        printf("\nSaldo insuficiente para realizar o saque.\n");
    } else {
        printf("\nValor inválido. O saque deve ser maior que zero.\n");
    }

    pausar_tela();
}

void exibir_menu() {
    printf("=== Menu da Conta Corrente ===\n\n");
    printf("1 - Consultar Saldo\n");
    printf("2 - Depositar\n");
    printf("3 - Sacar\n");
    printf("4 - Sair\n");
    printf("\nEscolha uma opcao: ");
}

int main() {
    int opcao;

    do {
        limpar_tela();
        exibir_menu();

        if (scanf("%d", &opcao) != 1) {
            printf("\nEntrada inválida. Tente novamente!\n");
            while (getchar() != '\n'); // Limpa o buffer
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
                limpar_tela();
                printf("\nObrigado por utilizar o sistema. Até logo!\n");
                return 0;
            default:
                printf("\nOpção inválida. Tente novamente!\n");
                pausar_tela();
                break;
        }
    } while (1);

    return 0;
}