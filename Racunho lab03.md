Código matriz-veotr serial:

#include <stdio.h>

#define N 3

// Declaração das variáveis globais
int matriz[N][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
int vetor[N] = {1, 2, 3};
int resultado[N] = {0};

int main() {
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

Máquina com 4 processadores:

![Captura de tela de 2024-03-13 05-31-07](https://github.com/Gustavo-Aragao-Guedes/CP05G/assets/64610385/f59d2790-14d1-4f47-93b3-95a59d3130a9)

Tempo serial 4 processadores:

![Captura de tela de 2024-03-13 05-32-40](https://github.com/Gustavo-Aragao-Guedes/CP05G/assets/64610385/609ecde3-5bb6-4bec-81ee-c4041163a3c9)
