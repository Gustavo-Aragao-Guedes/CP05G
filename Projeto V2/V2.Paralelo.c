#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

// Função para calcular o fatorial de um número usando memoização
void calculate_factorials(int n, unsigned long long *factorial_cache) {
    factorial_cache[0] = 1;
    for (int i = 1; i <= n; i++) {
        factorial_cache[i] = factorial_cache[i - 1] * i;
    }
}

int main() {
    int n = 100; // Número de termos para a série de Taylor
    long double e = 0.0;
    int num_threads;

    // Solicita o número de threads ao usuário 
    printf("Digite o número de threads a serem usadas: ");
    scanf("%d", &num_threads);

    if (num_threads <= 0) {
        printf("Número de threads inválido. Por favor, insira um valor maior que 0.\n");
        return 1;
    }

    // Aloca memória para o cache dos fatoriais
    unsigned long long *factorial_cache = (unsigned long long *)calloc(n + 1, sizeof(unsigned long long));
    if (factorial_cache == NULL) {
        printf("Erro ao alocar memória para o cache dos fatoriais.\n");
        return 1;
    }

    // Calcula os fatoriais antes do loop paralelo
    calculate_factorials(n, factorial_cache);

    // Começa a contagem do tempo
    double start_time = omp_get_wtime();

    // Configura o número de threads
    omp_set_num_threads(num_threads);

    // Usa uma variável de redução privada para evitar a diretiva critical
    #pragma omp parallel for reduction(+:e)
    for (int i = 0; i <= n; i++) {
        e += 1.0L / factorial_cache[i];
    }

    // Para a contagem do tempo
    double end_time = omp_get_wtime();
    double elapsed_time = end_time - start_time;

    // Imprime os resultados
    printf("O valor final de e calculado: %.15Lf\n", e);
    printf("Tempo total: %f segundos\n", elapsed_time);

    // Libera a memória alocada para o cache dos fatoriais
    free(factorial_cache);

    return 0;
}

