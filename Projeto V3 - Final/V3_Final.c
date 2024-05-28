#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <gmp.h>

// Função para calcular o fatorial de um número usando memoização
void calculate_factorials(int n, mpf_t *factorial_cache) {
    mpf_set_ui(factorial_cache[0], 1); // 0! = 1
    for (int i = 1; i <= n; i++) {
        mpf_mul_ui(factorial_cache[i], factorial_cache[i-1], i);
    }
}

int main() {
    int n = 20000; // Número de termos para a série de Taylor
    mpf_set_default_prec(4096); // Define precisão para 4096 bits
    mpf_t e;
    mpf_init(e);
    mpf_set_ui(e, 0);

    int num_threads;

    // Solicita o número de threads ao usuário 
    printf("Digite o número de threads a serem usadas: ");
    scanf("%d", &num_threads);

    if (num_threads <= 0) {
        printf("Número de threads inválido. Por favor, insira um valor maior que 0.\n");
        return 1;
    }

    // Aloca memória para o cache dos fatoriais
    mpf_t *factorial_cache = (mpf_t *)malloc((n + 1) * sizeof(mpf_t));
    for (int i = 0; i <= n; i++) {
        mpf_init(factorial_cache[i]);
    }

    // Calcula os fatoriais antes do loop paralelo
    calculate_factorials(n, factorial_cache);

    // Começa a contagem do tempo
    double start_time = omp_get_wtime();

    // Configura o número de threads
    omp_set_num_threads(num_threads);

    // Uso de uma variável de redução privada para evitar a diretiva critical
    #pragma omp parallel
    {
        mpf_t local_e;
        mpf_init(local_e);
        mpf_set_ui(local_e, 0);

        #pragma omp for schedule(dynamic)
        for (int i = 0; i <= n; i++) {
            mpf_t term;
            mpf_init(term);
            mpf_ui_div(term, 1, factorial_cache[i]);
            mpf_add(local_e, local_e, term);
            mpf_clear(term);
        }

        #pragma omp critical
        {
            mpf_add(e, e, local_e);
        }

        mpf_clear(local_e);
    }

    // Para a contagem do tempo
    double end_time = omp_get_wtime();
    double elapsed_time = end_time - start_time;

    // Imprime os resultados
    gmp_printf("O valor final de e calculado: %.5000Ff\n", e); // Imprime com até 5000 casas decimais
    printf("Tempo total: %f segundos\n", elapsed_time);

    // Libera a memória alocada para o cache dos fatoriais
    for (int i = 0; i <= n; i++) {
        mpf_clear(factorial_cache[i]);
    }
    free(factorial_cache);
    mpf_clear(e);

    return 0;
}

