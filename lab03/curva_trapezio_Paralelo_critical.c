#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

// Função para calcular f(x) = sen(x)
double func(double x) {
    return sin(x);
}

// Função para calcular a área sob a curva usando a regra do trapézio
double area_sob_curva(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = (func(a) + func(b)) / 2.0;

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += func(x);
    }

    return h * sum;
}

int main() {
    double a = 0.0;
    double b = M_PI; 
    int n; 
    int num_threads; 

    printf("Digite o número de trapézios desejado: ");
    scanf("%d", &n);

    printf("Digite o número de threads desejado: ");
    scanf("%d", &num_threads);

    if (n <= 0 || num_threads <= 0) {
        printf("O número de trapézios e o número de threads devem ser positivos.\n");
        return 1;
    }

    double area = 0.0;

    #pragma omp parallel num_threads(num_threads) reduction(+:area)
    {
        int tid = omp_get_thread_num();
        double local_a = a + tid * (b - a) / num_threads;
        double local_b = local_a + (b - a) / num_threads;
        double local_area = area_sob_curva(local_a, local_b, n / num_threads);
        #pragma omp critical
        {
            area += local_area;
        }
    }

    // Imprime o resultado (fora da região crítica)
    printf("A área sob a curva é aproximadamente: %.6f\n", area);

    return 0;
}

