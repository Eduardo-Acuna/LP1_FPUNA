#include <stdio.h>

void permutaion( char aux, char palabra[], int n, int r){
    char resp = aux;
    int x;

    if ( r>0 ){
        for ( x=0 ; x<n ; x++){
            permutaion(aux+palabra[x],n,r-1);
        } else {
            printf("\n %c", resp);
        }
    }
}

int main() {
    int n, r, i;

    printf("Cant. total de letras (n): ");
    scanf("%d", &n);

    printf("Cant de letras en los Subconjuntos (r): ");
    scanf("%d", &r);

    char palabra[n];
    printf("\nCargar elementos: ");

    // Agregar espacio en blanco antes de %c para evitar problemas de lectura
    for (i = 0; i < n; i++) {
        printf("P[%d]: ", i);
        scanf(" %c", &palabra[i]);
    }

    printf("Lista de elementos: ");

    for (i = 0; i < n; i++) {
        printf("%c", palabra[i]);
    }

    permutaion("",palabra,n,t);

    return 0;
}

