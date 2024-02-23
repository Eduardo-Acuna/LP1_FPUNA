#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_T 10


void cargarMat(int MAT[MAX_T][MAX_T], int a, int b){
    int i,j;
    srand(time(NULL));

    for ( i=0 ; i<a ; i++ ){
        for ( j=0 ; j<b ; j++){
            MAT[i][j]=1+rand()%6;
        }
    }
}

void imprimirMat(int MAT[MAX_T][MAX_T], int a, int b){
    int i, j;

    for( i=0 ; i<a ; i++){
        for ( j=0 ; j<b ; j ++){
            printf("%4d",MAT[i][j]);
        }
        printf("\n");
    }
}

void suma_mat(int A[MAX_T][MAX_T],int B[MAX_T][MAX_T],int FA, int CA,int FB,int CB){
    int i,j;

    if (FA==FB && CA==CB){
        int S[MAX_T][MAX_T];
        for ( i=0 ; i<FA ; i++ ){
            for ( j=0 ; j<CA ; j++ ){
                S[i][j]=A[i][j]+B[i][j];
            }
        }
        printf("\nSUMA DE LA MATRIZ A Y B:\n");
        imprimirMat(S,FA,CA);
    } else {
        printf("\nNo se puede realizr la suma d ls matrices");
    }

}

void producto_mat(int A[MAX_T][MAX_T],int B[MAX_T][MAX_T],int FA, int CA,int FB,int CB){
    int i,j,k;
    int FP,CP;
    if (CA==FB){
        FP=FA;
        CP=CB;
        int P[MAX_T][MAX_T];
        for ( i=0 ; i<FP ; i++ ){
            for ( j=0 ; j<CP ; j++){
                P[i][j]=0;
                for ( k=0 ; k<CA ; k++){
                    P[i][j]+=A[i][k]*B[k][j];
                }
            }
        }
        printf("\nPRODUCTO DE LA MATRIZ A Y B:\n");
        imprimirMat(P,FP,CP);
    } else {
        printf("No se puede realizar el producto.");
    }
}


int main(void)
{
    float A[MAX_T][MAX_T], B[MAX_T][MAX_T];
    float S[MAX_T][MAX_T], P[MAX_T][MAX_T];

    int FA=5,CA=5,FB=5,CB=5;
    int FS,CS,FP,CP;

    int a,b;
    int i,j,k;

    printf("\nMATRIZ A: ");
    printf("\nFila: "); //scanf("%d",&FA);
    printf("Columna: \n"); //scanf("%d",&CA);
    cargarMat(A,FA,CA);
    imprimirMat(A,FA,CA);

    printf("\nMATRIZ B: ");
    printf("\nFila: "); //scanf("%d",&FB);
    printf("Columna: \n");// scanf("%d",&CB);
    cargarMat(B,FB,CB);
    imprimirMat(B,FB,CB);

    // SUMA DE LAS MATRICES
    suma_mat(A,B,FA,CA,FB,CB);
    producto_mat(A,B,FA,CA,FB,CB);

    return 0;

}



