#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define N 1000
#define MAX_THREADS 10
#define BLOCK_SIZE 10

int matriz[N][N];
int vetor[N];
int resultado[N];
int num_threads;

pthread_mutex_t mutex;
int next_block = 0;

// Função para gerar números aleatórios entre 1 e 20
int rand_num() {
    return rand() % 20 + 1;
}

// Função executada por cada thread
void *mult_matriz_vetor(void *arg) {
    int block;
    while (1) {
        pthread_mutex_lock(&mutex);
        if (next_block >= N) {
            pthread_mutex_unlock(&mutex);
            break;
        }
        block = next_block;
        next_block += BLOCK_SIZE;
        pthread_mutex_unlock(&mutex);

        for (int i = block; i < block + BLOCK_SIZE && i < N; i++) {
            resultado[i] = 0; 
            for (int j = 0; j < N; j++) {
                resultado[i] += matriz[i][j] * vetor[j];
            }
        }
    }

    pthread_exit(NULL);
}

int main() {
    srand(time(NULL)); // Inicialização da semente para números aleatórios

    printf("Digite o número de threads (1 a %d): ", MAX_THREADS);
    scanf("%d", &num_threads);
    if (num_threads < 1 || num_threads > MAX_THREADS) {
        printf("Número inválido de threads. Usando 1 thread.\n");
        num_threads = 1;
    }

    // Preenchimento da matriz e do vetor com números aleatórios
    for (int i = 0; i < N; i++) {
        vetor[i] = rand_num();
        for (int j = 0; j < N; j++) {
            matriz[i][j] = rand_num();
        }
    }

    pthread_t threads[MAX_THREADS];
    pthread_mutex_init(&mutex, NULL);

    for (long i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, mult_matriz_vetor, NULL);
    }

    for (long i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);

    // Impressão do resultado 
    printf("\nResultado da multiplicação matriz-vetor:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", resultado[i]);
    }
    printf("\n");

    return 0;
}
