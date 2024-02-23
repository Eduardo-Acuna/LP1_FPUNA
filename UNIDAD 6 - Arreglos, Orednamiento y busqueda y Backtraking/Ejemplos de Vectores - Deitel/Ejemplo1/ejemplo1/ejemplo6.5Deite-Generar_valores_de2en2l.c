/* Figura 6.5: fig06_05.c
02 Inicializa los elementos del arreglo s a los enteros pares de 2 a 20 */
#include <stdio.h>
#define TAMANIO 10

/* la funci�n main comienza la ejecuci�n del programa */
int main()
{
    /* se puede utilizar la constante simb�lica TAMANIO para especificar el tama�o del arreglo */
    int s[TAMANIO]; /* el arreglo s contiene 10 elementos */
    int j; /* conntador */

    for ( j=0; j<TAMANIO; j++ ) { /* establece los valores */
        s[j] = 2 + 2 * j;
    } /* fin de for */

    printf( "%s%13s\n" , "Elemento", "Valor" );

    /* muestra el contenido del arreglo s en forma tabular */
    for ( j=0; j<TAMANIO; j++ ) {
        printf( "%7d%13d\n" , j , s[j] );
    } /* fin de for */

    return 0; /* indica terminaci�n exitosa */

} /* fin de main */



