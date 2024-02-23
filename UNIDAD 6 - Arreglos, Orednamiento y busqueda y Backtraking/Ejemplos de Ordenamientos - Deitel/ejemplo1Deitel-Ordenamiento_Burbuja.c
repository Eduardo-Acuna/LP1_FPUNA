/* Figura 6.15: fig06_15.c
Este programa ordena los valores de un arreglo en orden ascendente */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    int tam;
    int pas, i, alm;
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

    // ORDENAMIENTO POR BURBUJA DEL VECTOR
    for (pas=1 ; pas<tam ; pas++){ /* ciclo para controlar el número de pasos */
        for (i=0 ; i<tam-1 ; i++){ /* ciclo para controlar el número de comparaciones por pasada */
            if (vector[i] > vector[i+1]){ /* compara los elementos adyacentes y los intercambia si el primer elemento es mayor que el segundo */
                alm = vector[i];
                vector[i] = vector[i+1];
                vector[i+1] = alm;
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
