/*

El ordenamiento de matrices es una extensión del ordenamiento de vectores.
Normalmente se busca ordenar una fila, una columna o la matriz completa.
Sin embargo, en ciertas situaciones es necesario ordenar la matriz de forma diagonal.
En este ejercicio se le solicita que usted desarrolle una solución en lenguaje C que reciba una matriz A={aij}
cuadrada de dimensión n, cuyos valores se encuentran desordenamos, y que la misma retorne la misma matriz
pero ordenada ascendentemente en el sentido de la diagonal solicitada. Note que, i,j∈{0,1,2,...,n−1}
 y que además usted no puede utilizar un vector o matriz auxiliar para realizar el ordenamiento.

Entrada

La primera línea contiene dos números enteros n y k
n es la dimensión de la matriz en un rango de 3 a 20.
k  la dirección del ordenamiento.

Si k=1 entonces la dirección del ordenamiento es la diagonal principal y el menor elemento debe estar ubicado en la posición (i,j)=(n−1,0)
. En cada diagonal debe cumplirse que aij≥akl cuando i≤k y j≤l

Si k=2 entonces la dirección de ordenamiento es la diagonal secundaria y el menor elemento debe estar ubicado en la posición (i,j)=(n−1,n−1)
. En cada diagonal debe cumplirse que aij≥akl cuando i≤k y j≥l

En las siguientes n
 líneas se tienen las secuencias de n
 números enteros que corresponden a cada fila de la matriz.

Salida

Imprimir la matriz ordenada ascendentemente.

***************************

EJEMPLOS

Abajo podrá observar un ejemplo de cada caso.

*/

# include <stdio.h>
# define MAX 20

void     ordenar_matriz(int M[][MAX],int n){
    int i,j;


}

void imprimir_matriz( int M[][MAX], int n){
    int i,j;
    printf("\nLA MATRIZ: \n");
    for ( i=0 ; i<n ; i++ ){
        for ( j=0 ; j<n ; j++){
            printf("%4d",M[i][j]);
        }
        printf("\n");
    }

}

void cargar_matriz( int M[][MAX], int n){
    int A[3][3]={
            {40,20,30},
            {15,13,35},
            {100,1,3},
        };

    int i,j;

    for ( i=0 ; i<n ; i++ ){
        for ( j=0 ; j<n ; j++){
            M[i][j]=A[i][j];
            //printf("%d",M[i][j]);
        }
    }
    printf("Se cargo la matriz...\n");
    imprimir_matriz(M,n);
    //ordenar_matriz(M,n);

}


int main(){

    int n=3,k=1;
    /*
    printf("Ingrese la dimension de la matriz cuadrada: ");
    scanf("%d",n);
    if (n<3 && n>20){
        return 1;
    }

    printf("Ingrese la direccion del ordenamiento: ");
    scanf("%d",k);
    if (k!=1 || k!=2){
        return 1;
    }
*/

    int MAT[n][n];
    cargar_matriz(MAT,n);

    imprimir_matriz(MAT,n);




    return  0;
}




