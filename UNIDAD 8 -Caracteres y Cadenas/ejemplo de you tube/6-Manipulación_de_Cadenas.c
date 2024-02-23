#include <stdio.h>
#include <string.h>

int main() {
    // Funciones para copiar cadenas
    char cadena1[100] = "Hola, ";
    char cadena2[] = "mundo!";
    char cadena3[100];

    // Usando punteros para copiar cadenas
    char *ptr1 = cadena1;
    char *ptr2 = cadena2;
    char *ptr3 = cadena3;

        // Imprimir las cadenas originales
    printf("cadena1: %s\n", cadena1);
    printf("cadena2: %s\n", cadena2);

    // Copiar cadena usando punteros
    while ((*ptr3++ = *ptr1++) != '\0');
    printf("strcpy (con punteros): %s\n", cadena3);

    // Reinicializar punteros
    ptr1 = cadena1;
    ptr2 = cadena2;
    ptr3 = cadena3;

    // Copiar una porción de cadena usando punteros
    while ((*ptr3++ = *ptr2++) != '\0' && ptr2 - cadena2 < 3);
    printf("strncpy (con punteros): %s\n", cadena3);

    // Reinicializar cadena1 y punteros
    strcpy(cadena1, "Hola, ");
    ptr1 = cadena1;
    ptr2 = cadena2;

    // Usar punteros para concatenar cadenas
    while (*ptr1 != '\0') {
        ptr1++;
    }
    while ((*ptr1++ = *ptr2++) != '\0');
    printf("strcat (con punteros): %s\n", cadena1);

    // Usar punteros para concatenar una porción de cadena
    strcpy(cadena1, "Hola, ");
    ptr1 = cadena1;
    ptr2 = cadena2;

    while (*ptr1 != '\0') {
        ptr1++;
    }
    while ((*ptr1++ = *ptr2++) != '\0' && ptr2 - cadena2 < 3);
    printf("strncat (con punteros): %s\n", cadena1);

    // Resto del código para cambiar caracteres y comparar cadenas...

    return 0;
}
