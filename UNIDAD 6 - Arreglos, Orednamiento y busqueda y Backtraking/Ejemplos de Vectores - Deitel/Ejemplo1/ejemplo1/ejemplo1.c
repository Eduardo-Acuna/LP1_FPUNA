/* Figura 6.3: fig06_03.c
02 inicializar un arreglo */
#include <stdio.h>

/* la funci�n main comienza la ejecuci�n del programa */
int main()
{
    int n[10]; /* n es un arreglo de 10 enteros */
    int i; /* contador */

    /* inicializa los elementos del arreglo n a 0 del arreglo */
    for ( i=0; i<10; i++ ) {
        n[i] = 0; /* establece el elemento i a 0 */
    }

    printf( "%s%13s\n" , "Elemento" , "Valor" );

    /* muestra el contenido del arreglo n en forma tabular */
    for ( i = 0; i < 10; i++ ) {
        printf( "%7d%13d\n", i , n[i] );
    }

    return 0; /* indica terminaci�n exitosa */
}
