#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cargar_mat(int matriz[][100], int f, int c);
void imprimir_mat(int matriz[][100], int f, int c);
//void ordenar_mat(int matriz[][100], int f, int c);
void ordenar_matriz_completa(int matriz[][100], int f, int c);

int main(){
    int f, c;

    printf("Nro de filas de la matriz: ");
    scanf("%d", &f);

    printf("Nro de columnas de la matriz: ");
    scanf("%d", &c);

    int matriz[f][100]; // Usamos 100 como tamaño máximo para las columnas

    cargar_mat(matriz,f,c);
    imprimir_mat(matriz,f,c);

    //ordenar_mat(matriz,f,c);
    ordenar_matriz_completa(matriz,f,c);
    imprimir_mat(matriz,f,c);
    return 0;
}

// funcion que cargar numeros aleatorios a la matriz
void cargar_mat(int matriz[][100], int f, int c){
    int i, j;

    srand(time(NULL));
    for ( i=0 ; i<f ; i++){
        for ( j=0; j<c ; j++){
            matriz[i][j]=1+(rand()%9); // Genera números aleatorios entre 1 y 9
        }
    }
    printf("\nMatriz generada:\n");
}

// Funcion que imprime la matriz
void imprimir_mat(int matriz[][100], int f, int c){
    int i, j;

    for ( i=0; i<f ; i++ ){
        for ( j=0; j<c ; j++ ){
            printf("%4d", matriz[i][j]);
        }
        printf("\n");
    }
}

// Funcion que oredena la matriz por metodo de burbuja
void ordenar_mat(int matriz[][100], int f, int c) {
    int i, j, k, aux;
    //Este bucle exterior recorre cada fila de la matriz. k es el índice de la fila actual.
    for ( k=0; k<f ; k++ ){ // Recorre cada fila de la matriz

        //Este bucle interno recorre cada elemento de la fila actual (k). i es el índice del elemento actual en la fila.
        for (i=0; i<c; i++ ){ // Recorre cada elemento de la fila
            for ( j=0; j<c-i-1 ; j++ ){ // Compara los elementos adyacentes
                if ( matriz[k][j]>matriz[k][j+1] ){ // Intercambiar elementos

                    aux = matriz[k][j];
                    matriz[k][j] = matriz[k][j+1];
                    matriz[k][j+1] = aux;
                }
            }
        }
    }
}


void ordenar_matriz_completa(int matriz[][100], int f, int c) {
    int i,j,k,l,aux;

    for ( i=0; i<f ; i++ ){ // Recorremos cada fila i en la matriz
        for ( j= 0 ; j<c ; j++ ){ // Recorremos cada columna j en la fila actual
            for ( k=0 ; k<f ; k++ ){ // Comparamos el elemento en matriz[i][j] con todos los elementos de la matriz
                for ( l=0 ; l<c ; l++){ // Si el elemento en matriz[i][j] es menor que el elemento en matriz[k][l]
                    if ( matriz[i][j]<matriz[k][l] ){ // Intercambiamos los elementos usando una variable temporal
                        aux = matriz[i][j];
                        matriz[i][j] = matriz[k][l];
                        matriz[k][l] = aux;
                    }
                }
            }
        }
    }
    printf("\nLa Matriz Totalmente ordenada:\n");
}


