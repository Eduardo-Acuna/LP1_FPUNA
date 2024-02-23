#include <stdio.h>
#include "header.h"


int main(){
    int n, k;

    printf("Ingrese el número de estudiantes y la razón k: ");
    scanf("%lld %lld", &n, &k);

    long long diplomas, certificados, noGanadores;

    calcularPremios(n, k, &diplomas, &certificados, &noGanadores);

    printf("Número de estudiantes con diplomas: %lld\n", diplomas);
    printf("Número de estudiantes con certificados: %lld\n", certificados);
    printf("Número de estudiantes que no son ganadores: %lld\n", noGanadores);

    return 0;
}

