/* Figura 5.14: fig05_14.c
Funci�n factorial recursiva */
#include <stdio.h>

long factorial( long numero ); /* prototipo de la funci�n */

/* la funci�n main comienza la ejecuci�n del programa */
int main()
{
    int i; /* contador */

    /* repite 11 veces; durante cada iteraci�n, calcula el factorial( i ) y despliega el resultado */
    for ( i = 0; i <= 10; i++ ) {
        printf( "%2d! = %ld\n", i, factorial( i ) );
    } /* fin de for */

    return 0; /* indica terminaci�n exitosa */
}


/* definici�n recursiva de la funci�n factorial */
long factorial( long numero )
{
    /* caso base */
    if ( numero <= 1 ) {
        return 1;
    } else { /* paso recursivo */
        return ( numero * factorial( numero - 1 ) );
    }
}
