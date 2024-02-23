/*
EJERCICIO 8:
Crea una matriz de números enteros de 3 filas y 5 columnas, que deberás cargarla
con la sucesión de Fibonacci a través de una función. Luego, imprime la matriz
utilizando punteros.
*/

#include <stdio.h>

// Constructor de las funciones que permite CARGAR, IMPRIMIR y calcular la Sucesion de fibonacci
void cargar_matriz(int *M, int *m, int *n);
void imprimir_matriz(int *M, int *m, int *n);
int fibonacci(int n);

// Funcion Principal del Programa
int main() {
    int M,N;

    M=5;
    N=3;

    int matriz[M][N];

    cargar_matriz(&matriz, &M, &N);
    imprimir_matriz(&matriz, &M, &N);

    return 0;
}

// Función Recursiva para calcular los número de la sucesión de Fibonacci.
int fibonacci(int n) {
    int respuesta;

    if ( n==0 || n==1) {
        respuesta = n;
    } else {
        respuesta = fibonacci(n-1) + fibonacci(n-2);
    }
    return respuesta;
}

// Función que se encargar de cargar la matriz con los números Fibonacci.
void cargar_matriz(int *M, int *m, int *n) {
    int contador, i, j;
    contador=0;

    for ( i=0; i<*m ; i++) {
        for ( j=0 ; j<*n ; j++) {
            M[i*(*n)+j] = fibonacci(contador);
            contador++;
        }
    }
}

// Función que imprime la matriz.
void imprimir_matriz(int *M, int *m, int *n) {
    int i, j;

    for ( i=0 ; i<*m ; i++) {
        for ( j=0; j<*n ; j++) {
            printf("%d\t", M[i*(*n)+j]);
        }
        printf("\n");
    }
}
