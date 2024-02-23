/*
EJERCICIO 7:
Elabora un programa que pida al usuario las dimensiones de una matriz MxN y que
luego pida al usuario que introduzca los elementos de la matriz en orden
ascendente. A continuación, imprime la matriz (para todo utiliza punteros).
*/


#include <stdio.h>

// Constructor de la funcion que CARGAR de forma ascendente e IMPRIMIR la matriz
void cargar_matriz(int *M, int m, int n);
void imprimir_matriz(int *M, int m, int n);

// Funcion Principal del Programa
int main() {
    int M, N;

    do{
        printf("Ingrese las dimensiones para la matriz (MxN):\n");
        printf("Fila (M): "); scanf("%d", &M);
        printf("Columna (N): "); scanf("%d", &N);

        if ( M<=0 || N<=0 )
            printf("ERROR, Las dimensiones de la matriz deben ser mayores que cero.\n");

    } while( M<=0 || N<=0 );

    int matriz[M][N];

    printf("Ingrese los elementos de la matriz en orden ascendente:\n");
    cargar_matriz(&matriz[0][0], M, N);
    imprimir_matriz(&matriz[0][0], M, N);

    return 0;
}

// Función para cargar los datos la matriz
void cargar_matriz(int *M, int m, int n){
    int i, j;

    for ( i=0; i<m; i++) {
        for ( j=0 ; j<n ; j++) {
            printf("M[%d,%d]: ", i, j);
            scanf("%d", M);
            M++; // Mover el puntero al siguiente elemento
        }
    }
}


// Función para imprimir los datos de la matriz
void imprimir_matriz(int *M, int m, int n){
    int i, j;

    printf("Matriz %dx%d:\n", m, n);
    for ( i=0 ; i<m ; i++ ){
        for ( j=0; j<n ; j++ ){
            printf("%d ", *M);
            M++; // Mover el puntero al siguiente elemento
        }
        printf("\n"); // Nueva línea para cada fila
    }
}





