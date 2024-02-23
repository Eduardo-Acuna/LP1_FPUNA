#include <stdio.h>
#include <string.h>

int main() {
    char s1[20] = "Feliz ";      // Inicializa el arreglo de caracteres s1
    char s2[] = "Anio Nuevo ";   // Inicializa el arreglo de caracteres s2
    char s3[40] = "";            // Inicializa como vacío el arreglo de caracteres s3

    printf("s1 = %s\ns2 = %s\n", s1, s2);

    // Concatena s2 y s1
    printf("strcat(s1, s2) = %s\n", strcat(s1, s2));

    // Concatena los primeros 6 caracteres de s1 a s3. Coloca '\0' después del último caracter
    printf("strncat(s3, s1, 6) = %s\n", strncat(s3, s1, 6));

    // Concatena s1 a s3
    printf("strcat(s3, s1) = %s\n", strcat(s3, s1));

    return 0; // Indica terminación exitosa
}
