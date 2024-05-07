#include <stdio.h>
#include <math.h>

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
    double epsilon = 1e-100; // Critério de parada
    double e_anterior = 0.0;
    double e_atual = 1.0;
    int n = 1;
    double tempo = 0.0;

    while (fabs(e_atual - e_anterior) > epsilon) {
        e_anterior = e_atual;
        e_atual = calcular_e(n);
        tempo += 1.0 / e_atual;
        n++;
    }

    printf("Valor de 'e' final: %.100f\n", e_atual);
    printf("Tempo para atingir esse valor: %.100f segundos\n", tempo);

    return 0;
}
