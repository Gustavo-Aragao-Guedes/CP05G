#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define N 1000
#define MAX_THREADS 10

int matriz[N][N];
int vetor[N];
int resultado[N];
int num_threads;

// Função para gerar números aleatórios entre 1 e 20
int rand_num() {
    return rand() % 20 + 1;
}

// Função executada por cada thread
void *mult_matriz_vetor(void *arg) {
    long thread_id = (long)arg;
    int elementos_por_thread = N / num_threads;
    int inicio = thread_id * elementos_por_thread;
    int fim = (thread_id == num_threads - 1) ? N : inicio + elementos_por_thread;

    for (int i = inicio; i < fim; i++) {
        resultado[i] = 0; // Inicializa resultado[i] com 0
        for (int j = 0; j < N; j++) {
            resultado[i] += matriz[i][j] * vetor[j];
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
    for (long i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, mult_matriz_vetor, (void *)i);
    }

    for (long i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Impressão do resultado 
    printf("\nResultado da multiplicação matriz-vetor:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", resultado[i]);
    }
    printf("\n");

    return 0;
}
