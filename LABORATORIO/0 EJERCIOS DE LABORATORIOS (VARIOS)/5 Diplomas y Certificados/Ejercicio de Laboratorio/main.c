#include <stdio.h>
#include "header.h"


int main(){
    int n, k;

    printf("Ingrese el n�mero de estudiantes y la raz�n k: ");
    scanf("%lld %lld", &n, &k);

    long long diplomas, certificados, noGanadores;

    calcularPremios(n, k, &diplomas, &certificados, &noGanadores);

    printf("N�mero de estudiantes con diplomas: %lld\n", diplomas);
    printf("N�mero de estudiantes con certificados: %lld\n", certificados);
    printf("N�mero de estudiantes que no son ganadores: %lld\n", noGanadores);

    return 0;
}

