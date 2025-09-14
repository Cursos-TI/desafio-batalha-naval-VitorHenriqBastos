#include <stdio.h>

int main() {
    char linha[10] = {'A','B','C','D','E','F','G','H','I','J'};
    int tabuleiro[10][10];

    // Inicializa tabuleiro com 0
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Navios
    int navioHorizontal[3] = {3,3,3};
    int navioVertical[3]   = {3,3,3};

    // Posições iniciais
    int linhaH = 2, colunaH = 4;
    int linhaV = 6, colunaV = 1;

    // Coloca navio horizontal
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
    }

    // Coloca navio vertical
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaV + i][colunaV] = navioVertical[i];
    }

    // Exibe tabuleiro
    printf("   ");
    for (int j = 0; j < 10; j++) {
        printf("%d ", j);
    }
    printf("\n");

    for (int i = 0; i < 10; i++) {
        printf("%c: ", linha[i]);
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
