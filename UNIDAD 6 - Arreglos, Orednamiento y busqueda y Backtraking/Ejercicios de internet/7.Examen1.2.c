#include <stdio.h>
#define MAX 20


void imprimir_matriz( int MAT[MAX][MAX], int n );
void ordenar_matriz( int MAT[MAX][MAX], int n,int k );
void orden_fila( int MAT[MAX][MAX], int n ,int k);
void orden_diagonal( int MAT[MAX][MAX], int n,int k );

int main() {
    int n=3,k=1;

    int MAT[MAX][MAX]={ {40, 20, 30},{15, 13, 35},{100, 1, 3},};

    /*
    n=5;
    k=2;
    {{50,14,15,17,21},
    {31,18,10,40,15},
    {35,46,47,18,44},
    {11,26,32,27,40},
    {30,30,22,14,44},};*/

    /*n=3, k=1 { {40, 20, 30},{15, 13, 35},{100, 1, 3},};*/

    imprimir_matriz(MAT, n);
    ordenar_matriz(MAT,n,k);

    return 0;
}


void ordenar_matriz(int MAT[MAX][MAX], int n,int k){
        orden_fila(MAT,n,k);
        orden_diagonal(MAT,n,k);
        orden_fila(MAT,n,k);

        imprimir_matriz(MAT,n);
}

void orden_diagonal( int MAT[MAX][MAX], int n,int k ){
    int i, j,aux,cambio,x;

    if (k==1){
        do{
            cambio=0;
            for ( i=0 ; i<n-1 ; i++){
                if (MAT[i][i]<MAT[i+1][i+1]){
                    aux=MAT[i][i];
                    MAT[i][i]=MAT[i+1][i+1];
                    MAT[i+1][i+1]=aux;
                    cambio=1;
                    x=x+1;
                }
            }
        }while(cambio);

    } else if (k==2){
        do{
            cambio=0;
                for ( i=0 ; i<n-1 ; i++){
                    if (MAT[i][n-1-i]<MAT[i+1][n-2-i]){
                        aux=MAT[i][n-1-i];
                        MAT[i][n-1-i]=MAT[i+1][n-2-i];
                        MAT[i+1][n-2-i]=aux;
                        cambio=1;
                }
            }
        }while(cambio);
    }

}


void orden_fila(int MAT[MAX][MAX], int n, int k){
    int i,j,m,aux;

    if (k==1){
        for ( m=0 ; m<n ; m++){
            for ( i=0 ; i<n ; i++ ){
                for ( j=0 ; j<n ; j++ ){
                    if ( MAT[m][j]>MAT[m][i]){
                        aux=MAT[m][i];
                        MAT[m][i]=MAT[m][j];
                        MAT[m][j]=aux;
                    }
                }
            }
        }
    } else if (k==2){
        for ( m=0 ; m<n ; m++){
            for ( i=0 ; i<n ; i++ ){
                for ( j=0 ; j<n ; j++ ){
                    if ( MAT[m][j]<MAT[m][i]){
                        aux=MAT[m][i];
                        MAT[m][i]=MAT[m][j];
                        MAT[m][j]=aux;
                    }
                }
            }
        }
    }
}

void imprimir_matriz(int MAT[MAX][MAX], int n) {
    int i, j;

    printf("\nLA MATRIZ:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%4d", MAT[i][j]);
        }
        printf("\n");
    }
}
