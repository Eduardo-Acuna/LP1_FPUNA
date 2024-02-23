#include <stdio.h>
#include "header.h"

int main() {
    int n, k, resultado;
    scanf("%d %d", &n, &k);

    resultado = decodificador(n, k);

    printf("%d\n", resultado);

    return 0;
}


