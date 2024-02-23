/* Figura 6.8: fig06_08.c
02 Programa de impresión de un Histograma */
#include <stdio.h>
#include <stdlib.h>

/* la función main comienza la ejecución del programa */
int main()
{
    int i,j,tam;
    int vector[tam];
    srand(time(NULL));

    printf("Ingrese el tamaño del vector: ");
    scanf("%d", &tam);

    for ( i=0; i<tam; i++ ) { /* establece los valores */
        vector[i] = 1+(rand()%20);
    }

    /* para cada elemento del arreglo n, muestra una barra en el histograma */
    printf( "%s%13s%17s\n", "Elemento", "Valor", "Histograma" );
    for ( i=0; i<tam; i++ ) {
        printf( "%7d%13d ", i, vector[i]) ;
        for ( j=1; j<=vector[i] ; j++ ) { /* imprime una barra */
            printf( "%c", '*' );
        }
        printf( "\n" );
    }

    return 0;
}
