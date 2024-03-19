#include <stdio.h>
#include <pthread.h>

#define N 3
#define NUM_THREADS N

// Declaração das variáveis globais
int matriz[N][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
int vetor[N] = {1, 2, 3};
int resultado[N] = {0};

// Função executada por cada thread
void* multiplicarMatrizVetor(void* arg) {
    // Converte o argumento genérico para um inteiro
    int thread_id = *((int*)arg);
    // Cada thread calcula uma parte do vetor resultado
    for (int i = thread_id; i < N; i += NUM_THREADS) {
        for (int j = 0; j < N; j++) {
            resultado[i] += matriz[i][j] * vetor[j];
        }
    }
    // Termina a thread
    pthread_exit(NULL);
}

int main() {
    // Declaração de variáveis locais
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];

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
  
    // Criação das threads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_args[i] = i; // Argumento da thread
        pthread_create(&threads[i], NULL, multiplicarMatrizVetor, (void*)&thread_args[i]);
    }

    // Espera que todas as threads terminem
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    printf("\n");
  
    // Impressão do resultado
    printf("Resultado da multiplicação matriz-vetor:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", resultado[i]);
    }
    printf("\n");

    return 0;
}

