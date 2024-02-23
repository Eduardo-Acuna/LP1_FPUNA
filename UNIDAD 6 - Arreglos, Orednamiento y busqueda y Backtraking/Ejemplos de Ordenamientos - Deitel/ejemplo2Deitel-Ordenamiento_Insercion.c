/* Figura 6.15: fig06_15.c
Este programa ordena los valores de un arreglo en orden ascendente */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    int tam;
    int j, i, alm, aux;
    // CARGAMOS LA DIMESION PARA EL VECTOR
    printf("Ingrese la dimension del vector: ");
    scanf("%d",&tam);

    int vector[tam];
    srand(time(NULL));
    // SE GENERA DE FORMA ALEATORIA LOS ELEMENTO PARA EL VECTOR
    for (i=0;i<tam;i++){
        vector[i]=1+(rand()%20);
    }

    //IMPRIMIR EL VECTOR
    printf("Los elementos del vector sin ordenar: \n" );
    for ( i=0 ; i<tam ; i++ ) {
        printf("%4d", vector[i]);
    }

    // ORDENAMIENTO POR INSERCION DEL VECTOR
    for (i=1 ; i<tam ; i++) {
        aux = vector[i];
        for ( j=i-1 ; j>=0 ; j--) {
            if ( aux<vector[j] ){
                vector[j+1] = vector[j];
                vector[j] = aux;
            } else {
                break;
            }
        }
    }

    //IMPRIME EL VECTOR ORDENADO POR BURBUJA
    printf("\n\nLos elementos del vector ordenado: \n" );
    for ( i=0 ; i<tam ; i++ ){
        printf("%4d", vector[i]);
    }

    return 0;
}

