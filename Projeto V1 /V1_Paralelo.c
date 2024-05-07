#include <stdio.h>
#include <math.h>
#include <omp.h>

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
    int n;
    double tempo = 0.0;
    int terminar = 0;

    #pragma omp parallel reduction(+:tempo) private(n, e_anterior)
    {
        #pragma omp for schedule(static) cancellation(terminar)
        for (n = 1; ; n++) {
            e_anterior = e_atual;
            e_atual = calcular_e(n);
            tempo += 1.0 / e_atual;
            if (fabs(e_atual - e_anterior) <= epsilon) {
                #pragma omp cancel for
            }
        }
    }

    printf("Valor de 'e' final: %.50f\n", e_atual);
    printf("Tempo para atingir esse valor: %.50f segundos\n", tempo);

    return 0;
}
