/* Figura 8.13: fig08_13.c
   Uso de gets y putchar */

#include <stdio.h>

void inverso(const char * const ptrS); /* prototipo */

int main() {

    char enunciado[80]; /* crea un arreglo de caracteres */

    printf("Introduzca una línea de texto:\n");

    gets(enunciado); /* utiliza gets para leer una línea de texto */

    printf("\nLa línea impresa al revés es:\n");
    inverso(enunciado);

    return 0; /* indica terminación exitosa */
}




/* imprime recursivamente los caracteres de una cadena en orden inverso */
void inverso(const char * const ptrS) {
    /* si es el final de la cadena */
    if (ptrS[0] == '\0') { /* caso base */
        return;
    } else { /* si no es el final de la cadena */
        inverso(&ptrS[1]); /* paso recursivo */
        putchar(ptrS[0]); /* utiliza putchar para desplegar los caracteres */
    }

}
