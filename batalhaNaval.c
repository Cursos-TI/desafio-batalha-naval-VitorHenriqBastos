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
    int navio[3] = {3,3,3};


    // Posições iniciais
    int linhaH = 2, colunaH = 4;
    int linhaV = 6, colunaV = 1;
    int linhaD1 = 0, colunaD1 = 0;
    int linhaD2 = 0, colunaD2 = 9;

    // Coloca navio horizontal
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaH][colunaH + i] = navio[i];
    }

    // Coloca navio vertical
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaV + i][colunaV] = navio[i];
    }

    // Coloca navio Diagonal principal
    for (int i = 0; i < 3; i++)
    {
        tabuleiro[linhaD1 + i][colunaD1 + i] = navio[i];
    }
    
    // Coloca Navio Diagonal invertida
    for (int i = 0; i < 3; i++)
    {
        tabuleiro[linhaD2 + i][colunaD2 - i] = navio[i];
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
