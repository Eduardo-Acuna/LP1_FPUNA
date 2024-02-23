#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Función para ordenar un arreglo utilizando el algoritmo de ordenamiento de burbuja
void ordenarArreglo(int arr[], int n) {
    int temp;
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Intercambiar los elementos si están en el orden incorrecto
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Función para realizar una búsqueda binaria en un arreglo ordenado
int busquedaBinaria(int arr[], int n, int elemento) {
    int izquierda = 0, derecha = n - 1;
    while (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;
        if (arr[medio] == elemento) {
            return medio; // Se encontró el elemento, devuelve su posición
        }
        if (arr[medio] < elemento) {
            izquierda = medio + 1;
        } else {
            derecha = medio - 1;
        }
    }
    return -1; // El elemento no se encuentra en el arreglo
}

int main() {
    int n, elemento;

    printf("Ingrese el tamaño del arreglo: ");
    scanf("%d", &n);

    int arreglo[n];

    // Inicializar el generador de números aleatorios con la hora actual
    srand(time(NULL));

    printf("Generando valores aleatorios para el arreglo:\n");
    for (int i = 0; i < n; i++) {
        arreglo[i] = rand() % 100; // Genera números aleatorios entre 0 y 99
        printf("%d ", arreglo[i]);
    }

    printf("\nIngrese el elemento a buscar: ");
    scanf("%d", &elemento);

    // Ordenar el arreglo
    ordenarArreglo(arreglo, n);

    // Realizar la búsqueda binaria
    int resultado = busquedaBinaria(arreglo, n, elemento);

    if (resultado != -1) {
        printf("El elemento %d se encuentra en la posición %d del arreglo.\n", elemento, resultado);
    } else {
        printf("El elemento %d no se encuentra en el arreglo.\n", elemento);
    }

    return 0;
}
