#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 500

// Declaração das variáveis globais
int matriz[N][N];
int vetor[N];
int resultado[N];

// Função para gerar números aleatórios entre 1 e 20
int rand_num() {
    return rand() % 20 + 1;
}

int main() {
    srand(time(NULL));

    // Preenchimento da matriz e do vetor com números aleatórios
    for (int i = 0; i < N; i++) {
        vetor[i] = rand_num();
        for (int j = 0; j < N; j++) {
            matriz[i][j] = rand_num();
        }
    }

    // Impressão da matriz e do vetor originais
    printf("Matriz:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("Vetor: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    // Cálculo do resultado da multiplicação matriz-vetor
    for (int i = 0; i < N; i++) {
        resultado[i] = 0;
        for (int j = 0; j < N; j++) {
            resultado[i] += matriz[i][j] * vetor[j];
        }
    }

    // Impressão do resultado
    printf("\nResultado da multiplicação matriz-vetor:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", resultado[i]);
    }
    printf("\n");

    return 0;
}
