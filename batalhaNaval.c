##include <stdio.h>

#define N 5 // tamanho do tabuleiro (5x5 como exemplo)

void imprimirMatriz(int matriz[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void habilidadeCone() {
    int matriz[N][N] = {0};

    for (int i = 0; i < N; i++) {
        for (int j = N/2 - i; j <= N/2 + i; j++) {
            if (j >= 0 && j < N) {
                matriz[i][j] = 1;
            }
        }
    }

    printf("Habilidade: Cone\n");
    imprimirMatriz(matriz);
}

void habilidadeCruz() {
    int matriz[N][N] = {0};

    for (int i = 0; i < N; i++) {
        matriz[i][N/2] = 1; // coluna central
        matriz[N/2][i] = 1; // linha central
    }

    printf("Habilidade: Cruz\n");
    imprimirMatriz(matriz);
}

void habilidadeOctaedro() {
    int matriz[N][N] = {0};

    int centro = N / 2;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (abs(i - centro) + abs(j - centro) <= centro) {
                matriz[i][j] = 1;
            }
        }
    }

    printf("Habilidade: Octaedro\n");
    imprimirMatriz(matriz);
}

int main() {
    habilidadeCone();
    habilidadeCruz();
    habilidadeOctaedro();
    return 0;
}
