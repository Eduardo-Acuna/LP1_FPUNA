/*
EJERCICIO 10:
Ingresa una matriz de orden MxN. Imprime la matriz y ordena los elementos en
orden ascendente desde la mitad superior de la matriz y en forma descendente la
mitad inferior. Si el número de filas es impar, la fila del medio de la matriz no se
ordena (se imprime tal como se cargó).
Obs: Puede ser utilizado cualquier método de ordenación.
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constructor de las funciones que permite CARGAR, IMPRIMIR y ORDENAR SUPERIOR E INFERIOR
void cargar_valores(int *MT, int *M, int *N);
void imprimir_matriz(int *MT, int *M, int *N);
void ordenar_sup_inf(int *MT, int M, int N);

// Funcion Principal del Programa
int main() {
    int M, N;

    printf("Valor de M: "); scanf("%d", &M);
    printf("Valor de N: "); scanf("%d", &N);

    int MAT[M][N];

    cargar_valores( &MAT[0][0], &M, &N);
    imprimir_matriz( &MAT[0][0], &M, &N);
    ordenar_sup_inf( &MAT[0][0], M, N);

    printf("\nMatriz despues de ser Ordenada:\n");
    imprimir_matriz(&MAT[0][0], &M, &N);

    return 0;
}


// Funcion que genera elementos y carga en la matriz
void cargar_valores(int *MT, int *M, int *N) {
    int i, j;
    srand(time(NULL));

    for ( i=0; i<*M ; i++ ) {
        for ( j=0 ; j<*N ; j++ ) {
            MT[ i*(*N)+j ] = 1+rand()%98;
        }
    }
}

// Función que imprime la matriz.
void imprimir_matriz(int *MT, int *M, int *N) {
    int i, j;

    for ( i=0 ; i<*M ; i++) {
        for ( j=0; j<*N ; j++) {
            printf("%d ", MT[ i*(*N)+j]);
        }
        printf("\n");
    }
}

// Funcion que ordena de forma  ascendente y descendente
void ordenar_sup_inf(int *MT, int M, int N){
    int medio1, medio2, i, j, l, k, aux;
    // se saca los medio
    medio1 = (M/2);
    medio2 = (M/2)+1;

    // Ordenamos los elementos de la mitad superior de forma ascendente
    for ( i=0; i<medio1 ; i++) {
        for ( j=0; j<N ; j++) {
            for ( l=0; l<medio1 ; l++ ) {
                for ( k=0 ; k<N ; k++ ) {
                    if ( MT[i*N+j]<MT[l*N+k] ) {
                        aux = MT[i*N+j];
                        MT[i*N+j] = MT[l*N+k];
                        MT[l*N+k] = aux;
                    }
                }
            }
        }
    }

    // Ordenamos los elementos de la mitad inferior de forma descendente
    for ( i=medio2 ; i<M ; i++){
        for ( j=0 ; j<N ; j++){
            for ( l=medio2 ; l<M ; l++ ){
                for ( k=0 ; k<N ; k++) {
                    if ( MT [i*N+j]>MT[l*N+k] ) {
                        aux = MT[i*N+j];
                        MT[i*N+j] = MT[l*N+k];
                        MT[l*N+k] = aux;
                    }
                }
            }
        }
    }

}
