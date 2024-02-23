
#include <stdio.h>

int main() {
    long long n, k;
    scanf("%lld %lld", &n, &k);

    // Calculamos el número máximo de ganadores posible
    long long ganadores = n / (2 * (k + 1));

    // Calculamos el número de estudiantes con diplomas y certificados
    long long diplomas = ganadores;
    long long certificados = ganadores * k;

    // Calculamos el número de estudiantes que no son ganadores
    long long noGanadores = n - (diplomas + certificados);

    printf("%lld %lld %lld\n", diplomas, certificados, noGanadores);

    return 0;
}
