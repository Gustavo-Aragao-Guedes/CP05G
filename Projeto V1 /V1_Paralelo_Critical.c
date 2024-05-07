#include <stdio.h>
#include <math.h>
#include <omp.h>

#define NUM_THREADS 4 

double calcular_e(int n) {
    double e = 1.0;
    double termo = 1.0;

    for (int i = 1; i <= n; i++) {
        termo /= i;
        e += termo;
    }

    return e;
}

int main() {
    double epsilon = 1e-50; // Critério de parada
    double e_anterior = 0.0;
    double e_atual = 1.0;
    int n = 1;
    double tempo = 0.0;

    #pragma omp parallel num_threads(NUM_THREADS) private(n)
    {
        int tid = omp_get_thread_num();
        double local_e_anterior = 0.0;
        double local_e_atual = 1.0;
        double local_tempo = 0.0;
        int local_n = 1;

        while (1) {
            local_e_anterior = local_e_atual;
            local_e_atual = calcular_e(local_n);

            #pragma omp barrier 

            local_tempo += 1.0 / local_e_atual;
            local_n++;

            if (fabs(local_e_atual - local_e_anterior) <= epsilon)
                break;
        }

        #pragma omp critical
        {
            if (local_n > n) {
                n = local_n;
                e_atual = local_e_atual;
                tempo = local_tempo;
            }
        }
    }

    printf("Valor de 'e' final: %.50f\n", e_atual);
    printf("Tempo para atingir esse valor: %.50f segundos\n", tempo);

    return 0;
}
