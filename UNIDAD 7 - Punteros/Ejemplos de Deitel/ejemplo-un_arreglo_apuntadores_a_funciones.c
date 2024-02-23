#include <stdio.h>

/* prototipos */
void funcion1( int a );
void funcion2( int b );
void funcion3( int c );

int main(){
    /* inicializa el arreglo de 3 apuntadores con funciones que toman un argumento entero y devuelven void */
    void (*f[ 3 ])( int ) = { funcion1, funcion2, funcion3 };

    int eleccion; /* variable para almacenar la elección del usuario */

    printf("Introduzca un numero entre 0 y 2, 3 para terminar:");
    scanf( "%d", &eleccion );

    /* procesa la elección del usuario */
    while ( eleccion>=0 && eleccion< 3 ){

        ( *f[eleccion] ) (eleccion); /* invoca a la función en la ubicación de la elección en el arreglo f, y pasa la elección como argumento */

        printf( "Introduzca un numero entre 0 y 2, 3 para terminar: ");
        scanf( "%d", &eleccion );
    }

    printf( "Termina le ejecucion del programa.\n");

    return 0;
}


void funcion1( int a ){
    printf("Usted introdujo %d de manera que invoco a la funcion1\n\n", a );
}



void funcion2( int b ){
    printf("Usted introdujo %d de manera que invoco a la funcion2\n\n", b );
}



void funcion3( int c ){
    printf("Usted introdujo %d de manera que invoco a la funcion2\n\n", c );
}
