#include <stdio.h>
#include <string.h>

int main() {
    char cadena1[100];
    char cadena2[200];
    int i, j = 0;

    printf("Ingrese la cadena de entrada: ");
    gets(cadena1);

    for (i = 0; cadena1[i] != '\0'; i++) {
        if (strchr("aeiouyAEIOUY", cadena1[i]) == NULL) {
            // Si el carácter no es una vocal, añade un punto y el carácter a cadena2
            cadena2[j++] = '.';
            cadena2[j++] = cadena1[i];
        }
    }

    cadena2[j] = '\0';

    // Convertir la cadena a minúsculas
    for (i = 0; cadena2[i] != '\0'; i++) {
        if (cadena2[i] >= 'A' && cadena2[i] <= 'Z') {
            cadena2[i] += 32;
        }
    }

    printf("La cadena resultante es: %s\n", cadena2);

    return 0;
}
