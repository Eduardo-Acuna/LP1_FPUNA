# include <stdio.h>

void sumar_V1(int b[], int n){
    int i;

    for ( i=0 ; i<n ; i++ ){
        b[i] += 10;
    }
}

void sumar_V2( int *b, int n ){
    int i;

    for ( i=0  ; i<n ; i++ ){
        b[i] += 10;
    }
}

void imprimir_V( int *b, int n){
    int i;
    printf("\nEl vector es: ");
    for ( i=0  ; i<n ; i++ ){
        printf(" %d", b[i]);
    }
}


int main(){
    int A[] = {1,2,3,4,5,6};
    int tam;

    tam=sizeof(A)/sizeof(A[0]);

    printf("\nEl tamaño del vector: %d",tam);

    imprimir_V(A,tam);
    sumar_V1(A,tam);
    imprimir_V(A,tam);
    sumar_V2(A,tam);
    imprimir_V(A,tam);

    return 0;
}
