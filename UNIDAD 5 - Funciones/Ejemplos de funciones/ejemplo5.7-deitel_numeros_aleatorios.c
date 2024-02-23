/* Figura 5.7: fig05_07.c
02 Escalamiento y cambio de enteros producidos por 1 + rand() % 6 */


#include <stdio.h>
#include <stdlib.h>

/* la funci�n main comienza la ejecuci�n del programa */
int main()
{
    int i; /* contador */

    /* repite 20 veces */
    for ( i = 1; i <= 20; i++ ) {

        /* obtiene y despliega un n�mero aleatorio entre 1 y 6 */
        printf( "%10d", 1 + ( rand() % 6 ) );

        /* si el contador es divisible entre 5, comienza una nueva l�nea de salida */
        if ( i % 5 == 0 ) {
            printf( "\n" );
        }
    }
    return 0; /* indica terminaci�n exitosa */
}


