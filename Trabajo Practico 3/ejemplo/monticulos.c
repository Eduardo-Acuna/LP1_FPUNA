#include <stdio.h>
#include <stdlib.h>

// Estructura de Montículo
struct Monticulo {
    int *arreglo;
    int capacidad;
    int tamano;
};

// Función para intercambiar dos elementos en el montículo
void intercambiar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Función para flotar (percolar hacia arriba) un elemento en el montículo
void flotar(struct Monticulo *monticulo, int indice) {
    int padre = (indice - 1) / 2;
    while (indice > 0 && monticulo->arreglo[indice] < monticulo->arreglo[padre]) {
        intercambiar(&monticulo->arreglo[indice], &monticulo->arreglo[padre]);
        indice = padre;
        padre = (indice - 1) / 2;
    }
}

// Función para insertar un elemento en el montículo
void insertar(struct Monticulo *monticulo, int elemento) {
    if (monticulo->tamano == monticulo->capacidad) {
        printf("Montículo lleno. No se puede insertar.\n");
        return;
    }

    monticulo->arreglo[monticulo->tamano] = elemento;
    monticulo->tamano++;
    flotar(monticulo, monticulo->tamano - 1);
}

// Función para buscar el mínimo en el montículo
int buscarMinimo(struct Monticulo *monticulo) {
    if (monticulo->tamano == 0) {
        printf("Montículo vacío. No se puede buscar el mínimo.\n");
        return -1;
    }
    return monticulo->arreglo[0];
}

// Función para hundir (percolar hacia abajo) un elemento en el montículo
void hundir(struct Monticulo *monticulo, int indice) {
    int izquierda = 2 * indice + 1;
    int derecha = 2 * indice + 2;
    int minimo = indice;

    if (izquierda < monticulo->tamano && monticulo->arreglo[izquierda] < monticulo->arreglo[minimo]) {
        minimo = izquierda;
    }

    if (derecha < monticulo->tamano && monticulo->arreglo[derecha] < monticulo->arreglo[minimo]) {
        minimo = derecha;
    }

    if (minimo != indice) {
        intercambiar(&monticulo->arreglo[indice], &monticulo->arreglo[minimo]);
        hundir(monticulo, minimo);
    }
}

// Función para eliminar el mínimo del montículo
int eliminarMinimo(struct Monticulo *monticulo) {
    if (monticulo->tamano == 0) {
        printf("Montículo vacío. No se puede eliminar el mínimo.\n");
        return -1;
    }

    int minimo = monticulo->arreglo[0];
    monticulo->arreglo[0] = monticulo->arreglo[monticulo->tamano - 1];
    monticulo->tamano--;
    hundir(monticulo, 0);

    return minimo;
}

// Función para imprimir el contenido del montículo
void imprimirMonticulo(struct Monticulo *monticulo) {
    if (monticulo->tamano == 0) {
        printf("Montículo vacío.\n");
        return;
    }

    printf("Contenido del montículo: ");
    for (int i = 0; i < monticulo->tamano; i++) {
        printf("%d ", monticulo->arreglo[i]);
    }
    printf("\n");
}

int main() {
    int capacidad = 10;
    struct Monticulo *monticulo = (struct Monticulo *)malloc(sizeof(struct Monticulo));
    monticulo->capacidad = capacidad;
    monticulo->tamano = 0;
    monticulo->arreglo = (int *)malloc(capacidad * sizeof(int));

    int opcion,elemento,minimo;

    printf("1. Insertar un elemento\n");
    printf("2. Buscar el mínimo\n");
    printf("3. Eliminar el mínimo\n");
    printf("4. Imprimir el montículo\n");
    printf("5. Salir\n");





    while (1) {

        printf("-------------------------------------------------------------------\nOPCION: ");

        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                // Insertar un elemento

                printf("Ingrese un número entero: ");
                scanf("%d", &elemento);
                insertar(monticulo, elemento);
                break;
            case 2:
                // Buscar el mínimo
                printf("Elemento mínimo: %d\n", buscarMinimo(monticulo));
                break;
            case 3:
                // Eliminar el mínimo
                minimo = eliminarMinimo(monticulo);
                if (minimo != -1)
                    printf("Se eliminó el elemento mínimo: %d\n", minimo);
                break;
            case 4:
                // Imprimir el montículo
                imprimirMonticulo(monticulo);
                break;
            case 5:
                // Salir del programa
                free(monticulo->arreglo);
                free(monticulo);
                return 0;
            default:
                printf("Opción no válida.\n");
        }
    }
}
