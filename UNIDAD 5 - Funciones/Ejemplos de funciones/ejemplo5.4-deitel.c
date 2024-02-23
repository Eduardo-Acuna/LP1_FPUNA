/* Figura 5.4: fig05_04.c
2 Encuentra el máximo de tres enteros */

#include <stdio.h>

/* prototipo de la función */
int maximo( int x, int y, int z );

/* la función main comienza la ejecución del programa */
int main()
{
    int numero1,numero2,numero3; /* primer, segundo y tercer entero */

    printf( "Introduzca tres enteros: " );
    scanf( "%d%d%d", &numero1, &numero2, &numero3 );

    /* numero1, numero2 y numero3 son argumentos para la llamada a la función maximo */
    printf( "El maximo es: %d\n", maximo( numero1, numero2, numero3 ) );

    return 0;
}


/* Definición de la función maximo */
/* x, y, y z son parámetros */
int maximo( int x, int y, int z )
{
    /* asume que x es el mayor */
    int max = x;

    /* si y es mayor que max, asigna y a max */
    if ( y > max ) {
        max = y;
    }

    /* si z es mayor que max, asigna z a max */
    if ( z > max ) {
        max = z;
    }

    return max; /* max es el valor más grande */
}
