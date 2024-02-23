/*
EJERCICIO 9:
Crea un programa que requiera las dimensiones de una matriz MxN, que deberás
cargar con números aleatorios del 0 al 99. El programa debe imprimir la matriz y
luego enviarla a una función, donde los elementos de la matriz que son pares serán
divididos entre 2 y los impares serán multiplicados por 2. Para imprimir la matriz y
hacer la función utiliza punteros.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constructor de las funciones que permite CARGAR, IMPRIMIR y saber si los elementos son PARES 0 IMPARES
void cargar_valores(int *MT, int M, int N);
void imprimir_matriz(int *MT, int M, int N);
void par_impar(int *MT, int M, int N);

// Funcion Principal del Programa
int main() {
    int M, N;

    printf("Fila M: "); scanf("%d", &M);
    printf("Columna N: "); scanf("%d", &N);

    int MAT[M][N];

    cargar_valores(&MAT[0][0], M, N);
    imprimir_matriz(&MAT[0][0], M, N);


    par_impar(&MAT[0][0], M, N); // funcion que se encarga se resolver el problema

    printf("\nMatriz después de aplicar la funcion par_impar:\n");
    imprimir_matriz(&MAT[0][0], M, N);

    return 0;
}


// Funcion Principal del Programa
void par_impar(int *MT, int M, int N){
    int i, j;

    for ( i=0 ; i<M ; i++) {
        for ( j=0 ; j<N ; j++) {
            if ( MT[i*N+j]%2==0 ) {
                MT[i*N+j] = MT[i*N+j]/2;
            } else {
                MT[i*N+j] = MT[i*N+j]*2;
            }
        }
    }
}


// Funcion que genera elementos y carga en la matriz
void cargar_valores(int *MT, int M, int N) {
    int i, j;
    srand(time(NULL));

    for ( i=0; i<M ; i++ ) {
        for ( j=0 ; j<N ; j++ ) {
            MT[ i*N+j ] = 1+rand()%98;
        }
    }
}

// Función que imprime la matriz.
void imprimir_matriz(int *MT, int M, int N) {
    int i, j;

    for ( i=0 ; i<M ; i++) {
        for ( j=0; j<N ; j++) {
            printf("%d ", MT[ i*N+j]);
        }
        printf("\n");
    }
}
