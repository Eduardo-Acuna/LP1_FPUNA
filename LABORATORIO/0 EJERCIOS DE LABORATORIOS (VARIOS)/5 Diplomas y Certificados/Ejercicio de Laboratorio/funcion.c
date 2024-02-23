# include "header.h"


void calcularPremios(long long n, long long k, long long *diplomas, long long *certificados, long long *noGanadores) {
    // Calcula el número máximo posible de ganadores
    long long maxGanadores = n / 2;

    // Inicializa los valores de salida
    *diplomas = 0;
    *certificados = 0;
    *noGanadores = n;

    // Verifica si es posible tener ganadores
    if (k == 1 && maxGanadores > 0) {
        *diplomas = 1;
        *certificados = k;
        *noGanadores = n - (*diplomas + *certificados);
    }
}
