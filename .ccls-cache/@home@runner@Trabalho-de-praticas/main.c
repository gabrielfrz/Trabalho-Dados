#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pesquisa.h"

#define resett "\033[0m"
#define vvermelho "\033[0;31m"
#define azzul "\033[0;34m"
#define amarello "\033[0;33m"
#define vverde "\033[0;38;2;0;255;0m"
#define roxxo "\033[0;35m"

void LimparTelan() {
    system("clear");
}

void cabeçalho() {
    printf("\n");
    printf("%s╔═══════════════════════════════╗%s\n", vvermelho, resett);
    printf("%s║   Bem-vindo(a) à Pesquisa     ║%s\n", vvermelho, resett);
    printf("%s╚═══════════════════════════════╝%s\n", vvermelho, resett);
    printf("\n");
}

void printMenu() {
    printf("Selecione uma das opções abaixo:\n\n");
    printf("%sa%s - Responder a pesquisa\n", azzul, resett);
    printf("%sb%s - Exibir dados dos entrevistados\n", amarello, resett);
    printf("%sc%s - Buscar dados individuais\n", vverde, resett);
    printf("%sd%s - Exibir estatísticas\n", roxxo, resett);
    printf("%se%s - Encerrar\n", vvermelho, resett);
    printf("\n");
    printf("Opção: ");
}

int main() {
    char opcao;
    int fim = 0;
    FILE *arquivo;

    cabeçalho();

    while (fim == 0) {
        printf("\n");
        printMenu();
        scanf(" %c", &opcao);
        LimparTelan();
        switch (opcao) {
            case 'a':
                LimparTelan();
                opcaoa(&arquivo, &fim);
                break;

            case 'b':
                LimparTelan();
                opcaob(&arquivo);
                break;

            case 'c':
                LimparTelan();
                opcaoc(&arquivo);
                break;

            case 'd':
                LimparTelan();
                opcaod(&arquivo);
                break;

            case 'e':
                fim = opcaoe(fim, &arquivo);
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    }

    return 0;
}
