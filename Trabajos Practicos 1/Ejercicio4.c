/*
Escribe un programa en el que un número natural N pueda ser expresado utilizando
ceros y unos solamente mediante el denominado sistema binario. Para obtener la
representación binaria de N, deben calcularse los restos de dividir sucesivamente N
por 2 hasta que el dividendo sea 0 (cero). Los restos obtenidos (listados en orden
inverso) son la representación binaria de N.
Ejemplo:
Para calcular la representación binaria de N=28, se deben calcular los siguientes restos:

28 dividido 2 da 14 y resto 0.
14 dividido 2 da 7 y resto 0.
7 dividido 2 da 3 y resto 1.
3 dividido 2 da 1 y resto 1.
1 dividido 2 da 0 y resto 1.

Por lo tanto, la representación binaria de 28 es 11100.
*/


#include <stdio.h>

// Constructor de la funcion recursiva
void nro_binario(int N);


// Funcion Principal del Programa
int main(){
    int N;

    do{
        printf("Ingrese un número natural para N: ");
        scanf("%d", &N);

        if ( N<0 ){
            printf("ERROR... N no es un numero natural.\n");
        }
    } while( N<0 );


    if ( N==0){
        printf("La representacion binaria de [%d] es: 0.\n", N);
    } else {
        printf("La representacion binaria de [%d] es: ", N);
        nro_binario( N );
    }

    return 0;
}


// Funcion recursiva que realiza la conversion a binario
void nro_binario(  int N ){

    if ( N>0 ){
        nro_binario( N/2 );
        printf("%d", N%2);
    }
}
