#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimir_matriz(int matriz[][100], int n);
void cargar_mat(int matriz[][100], int n);
void ordenar(int matriz[][100], int n);


int main() {
    int n;

    printf("Ingrese el valor de N para la matriz NxN: ");
    scanf("%d", &n);

    int matriz[n][100];

    cargar_mat(matriz,n); // Inicializar el generador de números aleatorios

    printf("Matriz original:\n");
    imprimir_matriz(matriz, n);

    ordenar(matriz, n); // Ordenar la primera fila y la última columna

    printf("\nMatriz con la primera fila y última columna ordenadas:\n");
    imprimir_matriz(matriz, n);

    return 0;
}

void cargar_mat(int matriz[][100], int n){
    int i,j;

    srand(time(NULL));

    // Llenar la matriz con números aleatorios
    for ( i=0 ; i<n ; i++ ){
        for ( j=0 ; j<n ; j++ ){
            matriz[i][j] = 1+(rand()%100); // Genera números aleatorios entre 0 y 99
        }
    }

}

void imprimir_matriz(int matriz[][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", matriz[i][j]);
        }
        printf("\n");
    }
}

void ordenar(int matriz[][100], int n) {
    int i,j,aux1,aux2;

    // ORDENA LA FILA
    for ( i=0 ; i<n-1 ; i++ ){
        for ( j=i+1 ; j<n ; j++) {
            if (matriz[0][i] > matriz[0][j]) {
                aux1 = matriz[0][i];
                matriz[0][i] = matriz[0][j];
                matriz[0][j] = aux1;
            }
        }
    }

    // OREDENA LA ULTIMA COLUMNA
    for ( i=0 ; i<n-1 ; i++ ){
        for ( j=i+1 ; j<n ; j++ ){
            if ( matriz[i][n-1]>matriz[j][n-1]){
                aux2 = matriz[i][n-1];
                matriz[i][n-1] = matriz[j][n-1];
                matriz[j][n-1] = aux2;
            }
        }
    }
}
