#include <stdio.h>
#include <string.h>

int main() {
    // Ejemplo de cadena para todas las funciones
    const char *cadena = "Hola, mundo!";

    // Función strchr
    char caracter1 = 'o';
    char *ptr1 = strchr(cadena, caracter1);
    if (ptr1 != NULL) {
        printf("strchr: La primera ocurrencia de '%c' en la cadena es: %s\n", caracter1, ptr1);
    } else {
        printf("strchr: '%c' no encontrado en la cadena.\n", caracter1);
    }

    // Función strcspn
    const char *caracteres2 = "xyz";
    size_t longitud2 = strcspn(cadena, caracteres2);
    printf("strcspn: Longitud del segmento inicial que no contiene caracteres de caracteres2: %zu\n", longitud2);

    // Función strspn
    const char *caracteres3 = "Hoa,l mnd!";
    size_t longitud3 = strspn(cadena, caracteres3);
    printf("strspn: Longitud del segmento inicial que contiene solo caracteres de caracteres3: %zu\n", longitud3);

    // Función strpbrk
    const char *caracteres4 = "xyz";
    char *ptr4 = strpbrk(cadena, caracteres4);
    if (ptr4 != NULL) {
        printf("strpbrk: La primera ocurrencia de un carácter de caracteres4 en cadena es: %c\n", *ptr4);
    } else {
        printf("strpbrk: Ningún carácter de caracteres4 encontrado en cadena.\n");
    }

    // Función strrchr
    char caracter5 = 'o';
    char *ptr5 = strrchr(cadena, caracter5);
    if (ptr5 != NULL) {
        printf("strrchr: La última ocurrencia de '%c' en la cadena es: %s\n", caracter5, ptr5);
    } else {
        printf("strrchr: '%c' no encontrado en la cadena.\n", caracter5);
    }

    // Función strstr
    const char *subcadena6 = "mundo";
    char *ptr6 = strstr(cadena, subcadena6);
    if (ptr6 != NULL) {
        printf("strstr: La primera ocurrencia de '%s' en la cadena es: %s\n", subcadena6, ptr6);
    } else {
        printf("strstr: '%s' no encontrado en la cadena.\n", subcadena6);
    }

    // Función strtok (no es una función de búsqueda, pero la incluyo por completitud)
    char cadena7[] = "Este es un ejemplo";
    const char *delimitadores7 = " ";
    char *token7 = strtok(cadena7, delimitadores7);
    while (token7 != NULL) {
        printf("strtok: Token: %s\n", token7);
        token7 = strtok(NULL, delimitadores7);
    }

    return 0;
}

