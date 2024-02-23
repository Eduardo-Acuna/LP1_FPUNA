/* Figura 7.26: fig07_26.c
02 Programa de ordenamiento multipropósito que utiliza apuntadores a funciones */
# include <stdio.h>
# define TAMANIO 10

/* prototipos */
void burbuja( int trabajo[], const int tamanio, int (*compara)( int a, int b ) );
int ascendente( int a, int b );
int descendente( int a, int b );

int main(){

    int orden;
    int contador;

    /* inicializa el arreglo a */
    int a[ TAMANIO ] = { 2, 6, 4, 8, 10, 12, 89, 68, 45, 37 };

    printf( "Introduzca\n");
    printf("1. para ordenar en forma ascendente\n");
    printf("2. para ordenar en forma descendente\n");
    scanf( "%d", &orden );

    printf( "\nElementos de datos en el orden original\n");


    /* muestra el arreglo original */
    for ( contador=0; contador<TAMANIO ; contador++ ){
        printf( "%5d", a[contador]);
    }

    /* clasifica el arreglo en orden ascendente; pasa la función ascendente como un
    31 argumento para especificar el orden ascendente */
    if ( orden == 1 ){
        burbuja( a, TAMANIO, ascendente );
        printf( "\nElementos de datos en orden ascendente\n");
    } else {
        burbuja( a, TAMANIO, descendente );
        printf("\nElementos de datos en orden descendente\n");
    }

    /* muestra el arreglo ordenado */
    for ( contador=0 ; contador<TAMANIO ; contador++ ){
        printf( "%5d", a[contador]);
    }

    printf( "\n" );

    return 0;
}



/* ordenamiento burbuja multipropósito; el parámetro compara es un apuntador a la función de comparación que determina el tipo de ordenamiento */
void burbuja( int trabajo[], const int tamanio, int (*compara)( int a, int b ) ){
    int pasada;
    int cuenta;

    void intercambia( int *ptrElemento1, int *ptrElemento2 );

    /* ciclo para controlar las pasadas */
    for ( pasada = 1; pasada < tamanio; pasada++ ) {
        for ( cuenta=0 ; cuenta<tamanio-1; cuenta++ ){ /* ciclo para controlar el número de comparaciones por pasada */
            if ( (*compara)(trabajo[cuenta],trabajo[cuenta+1])){ /* si los elementos adyacentes no se encuentran en orden,los intercambia */
                intercambia(&trabajo[cuenta],&trabajo[cuenta+1]);
            }
        }
    }
}



/* intercambia los valores en las ubicaciones de memoria a las que apunta ptrElemento1 y ptrElemento2 */
void intercambia( int *ptrElemento1, int *ptrElemento2 ){
    int almacena; /* variable de almacenamiento temporal */

    almacena = *ptrElemento1;
    *ptrElemento1 = *ptrElemento2;
    *ptrElemento2 = almacena;
}




/* determina si los elementos están en desorden para un ordenamiento ascendente */
int ascendente( int a, int b ){
    return b < a; /* intercambia si b es menor que a */
}




/* determina si los elementos están en desorden para un  ordenamiento descendente */
int descendente(int a, int b){
    return b > a; /* intercambia si b es mayor que a */
}


