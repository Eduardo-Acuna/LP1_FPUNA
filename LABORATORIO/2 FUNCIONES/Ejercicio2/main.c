#include <stdio.h>
#include "header2.h"

int main() {
    int anio,nuevo_anio;

    scanf("%d", &anio);

    if (anio<1000 || anio>9000) {
        printf("El año debe estar en el rango 1000 <= año <= 9000.\n");
        return 1;
    }


    nuevo_anio=proximo_anio(anio);
    printf("%d\n",nuevo_anio);

    return 0;
}
