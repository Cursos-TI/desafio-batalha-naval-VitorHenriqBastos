#include <stdio.h>

#define N 10 //Tamanho do Tabuleiro
#define H 5 // Tamanho das matrizes de habilidade

//Função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[N][N], char linha[10]){
    printf(" ");
    for (int j = 0; j < N; j++)
    {
        printf("%d ", j);
    }
    printf("\n");

    for (int i = 0; i < N; i++)
    {
        printf("%c: ", linha[i]);
        for (int j = 0; j < N; j++)
        {
            if (tabuleiro[i][j] == 0)
            {
                printf("~ "); //Água
            }
            else if (tabuleiro[i][j] == 3)
            {
                printf("N "); //Návio
            }
            else if (tabuleiro[i][j] == 5)
            {
                printf("* "); //Área de Habilidade
            }
            else{
                printf("%d ", tabuleiro[i][j]);
            }
        }
        printf("\n");
    }
    
}

//Matriz Cone
void gerarCone(int cone[H][H]) {
    int centro = H/2;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            if (j >= centro - i && j <= centro + i) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }
}

//Matriz Cruz
void gerarCruz(int cruz[H][H]){
    int centro = H/2;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < H; j++)
        {
            cruz[i][j] = (i == centro || j == centro) ? 1 : 0;
        }
        
    }
    
}

//Matriz Octaedro
void gerarOctaedro(int oct[H][H]){
    int centro = H/2;
    for (int i = 0; i < H; i++)
    {
        int distLinha = (i <= centro) ? i : H-1-i;
        int alcance = centro - distLinha;
        for (int j = 0; j < H; j++)
        {
            if (j >= centro - alcance && j <= centro + alcance)
            {
                oct[i][j] = 1;
            }
            else{
                oct[i][j] = 0;
            }
        }
        
    }
    
}

//Matriz de Habilidade
void aplicarHabilidade(int tabuleiro[N][N], int habilidade[H][H], int origemX, int origemY){
    int inicioX = origemX - H/2;
    int inicioY = origemY - H/2;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < H; j++)
        {
            if (habilidade[i][j] == 1)
            {
                int x = inicioX + i;
                int y = inicioY + j;
                if (x >= 0  && x < N && y >= 0 && y < N)
                {
                    if (tabuleiro[x][y] != 3)
                    {
                        tabuleiro[x][y] = 5;
                    }
                    
                }
                
            }
            
        }
        
    }
    

}


int main() {
    char linha[10] = {'A','B','C','D','E','F','G','H','I','J'};
    int tabuleiro[N][N] = {0};

    int navio[3] = {3,3,3};

    // Posicionamento dos navios
    int linhaH=2, colunaH=4, linhaV=6, colunaV=1, linhaD1=0, colunaD1=0, linhaD2=0, colunaD2=9;
    for(int i=0;i<3;i++){
        tabuleiro[linhaH][colunaH+i] = navio[i];
        tabuleiro[linhaV+i][colunaV] = navio[i];
        tabuleiro[linhaD1+i][colunaD1+i] = navio[i];
        tabuleiro[linhaD2+i][colunaD2-i] = navio[i];
    }

    // Matrizes de habilidades
    int cone[H][H], cruz[H][H], oct[H][H];
    gerarCone(cone);
    gerarCruz(cruz);
    gerarOctaedro(oct);

    // Pontos de origem
    aplicarHabilidade(tabuleiro, cone, 4, 4);
    aplicarHabilidade(tabuleiro, cruz, 7, 7);
    aplicarHabilidade(tabuleiro, oct, 5, 2);

    imprimirTabuleiro(tabuleiro, linha);

    return 0;
}
