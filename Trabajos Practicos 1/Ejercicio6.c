/*
EJERCICIO 6:
Elabora un programa que cargue e imprima los datos de un vector de números
enteros, mediante funciones y punteros.
*/


#include <stdio.h>

// Constructor de la funcion que CARGAR E IMPRIMIR el vetor
void cargar_elemento(int *vector, int n);
void imprimir_elemento(int *vector, int n);


// Funcion Principal del Programa
int main() {
    int n;

    do {
        printf("Ingrese la cantidad de elementos del vector: "); scanf("%d", &n);

        if (n <= 0) {
            printf("ERROR... La cantidad de elementos debe ser mayor que cero.\n");
        }
    } while( n<=0 );

    int vector[n];

    cargar_elemento(&vector, n);
    imprimir_elemento(&vector, n);

    return 0;
}


// Función para cargar los datos en el vector
void cargar_elemento(int *V, int n) {
    int i;
    printf("Ingrese %d numeros enteros:\n", n);
    for ( i=0 ; i<n ; i++ ) {
        printf("V[%d]: ", i);
        scanf("%d", &V[i]);
    }
}

// Función para imprimir los datos del vector
void imprimir_elemento(int *V, int n) {
    int i;
    printf("Elemento del vector: ");
    for ( i=0 ; i<n ; i++){
        printf("%d ", V[i]);
    }
    printf("\n");
}



