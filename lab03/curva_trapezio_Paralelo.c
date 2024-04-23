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
    int n = 9; 

    int num_threads;
    printf("Digite o número de threads desejado: ");
    scanf("%d", &num_threads);

    double area = 0.0;

    #pragma omp parallel num_threads(num_threads) reduction(+:area)
    {
        int tid = omp_get_thread_num();
        double local_a = a + tid * (b - a) / num_threads;
        double local_b = local_a + (b - a) / num_threads;
        double local_area = area_sob_curva(local_a, local_b, n / num_threads);
        area += local_area;
    }

    // Imprime o resultado
    printf("A área sob a curva é aproximadamente: %.6f\n", area);

    return 0;
}

