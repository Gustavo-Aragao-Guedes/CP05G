#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

    printf("Digite o número de trapézios desejado: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("O número de trapézios deve ser positivo.\n");
        return 1;
    }

    double area = area_sob_curva(a, b, n);

    printf("A área sob a curva é aproximadamente: %.6f\n", area);

    return 0;
}
