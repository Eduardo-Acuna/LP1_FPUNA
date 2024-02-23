/*
EJERCICIO 4
Diseña un programa en lenguaje C que implemente una cola de prioridad
utilizando un montículo. La cola de prioridad debe almacenar elementos, cada
uno con un valor y una prioridad asociada. El programa debe permitir al usuario
realizar las siguientes operaciones: (2P)
a. Agregar un elemento con un valor y una prioridad a la cola de prioridad.
b. Obtener y mostrar el elemento con la mayor prioridad.
c. Eliminar el elemento con la mayor prioridad de la cola.
d. Salir del programa.
El programa debe utilizar un montículo para administrar los elementos en la cola
de prioridad, de modo que el elemento con la mayor prioridad esté siempre
disponible.

*/

#include <stdio.h>
#include <stdlib.h>

// Estructura para representar un elemento en la cola de prioridad
typedef struct {
    int valor;
    int prioridad;
} Elemento;

// Función para intercambiar dos elementos en el arreglo de elementos
void intercambiar(Elemento *a, Elemento *b) ;
void hundir(Elemento elementos[], int tamano, int indice);
void flotar(Elemento elementos[], int indice);
void agregar(Elemento elementos[], int *tamano, int valor, int prioridad) ;
void obtenerMayorPrioridad(Elemento elementos[], int *tamano);
void eliminarMayorPrioridad(Elemento elementos[], int *tamano);

int main() {
    int tamano = 0;
    Elemento *colaPrioridad = (Elemento *)malloc(100 * sizeof(Elemento)); // Tamaño máximo de la cola de prioridad

    int opcion,valor, prioridad;;


    printf("\n\t +-----------------------------------------------------+");
    printf("\n\t |                      MENU                           |");
    printf("\n\t +-----------------------------------------------------+");
    printf("\n\t | 1. Agregar elemento a la cola de prioridad          |");
    printf("\n\t | 2. Obtener elemento con mayor prioridad             |");
    printf("\n\t | 3. Eliminar elemento con mayor prioridad            |");
    printf("\n\t | 4. Salir                                            |");
    printf("\n\t +-----------------------------------------------------+\n");



    while (1) {
        printf("\t -------------------------------------------------------");
        printf("\n\t OPCION: ");
        scanf("%d", &opcion);
        printf("\t -------------------------------------------------------");


        switch (opcion) {
            case 1:

                printf("\n\t Ingrese el valor del elemento: ");
                scanf("%d", &valor);
                printf("\t Ingrese la prioridad del elemento: ");
                scanf("%d", &prioridad);
                agregar(colaPrioridad, &tamano, valor, prioridad);
                printf("\t Elemento agregado a la cola de prioridad.\n");
                break;
            case 2:
                obtenerMayorPrioridad(colaPrioridad, &tamano);
                break;
            case 3:
                eliminarMayorPrioridad(colaPrioridad, &tamano);
                break;
            case 4:
                free(colaPrioridad);
                return 0;
            default:
                printf("\n\t Opción no válida.\n");
        }
    }
}



// Función para intercambiar dos elementos en el arreglo de elementos
void intercambiar(Elemento *a, Elemento *b) {
    Elemento temp = *a;
    *a = *b;
    *b = temp;
}

// Función para hundir (percolar hacia abajo) un elemento en la cola de prioridad
void hundir(Elemento elementos[], int tamano, int indice) {
    int izquierda = 2 * indice + 1;
    int derecha = 2 * indice + 2;
    int mayor = indice;

    if (izquierda < tamano && elementos[izquierda].prioridad > elementos[mayor].prioridad) {
        mayor = izquierda;
    }

    if (derecha < tamano && elementos[derecha].prioridad > elementos[mayor].prioridad) {
        mayor = derecha;
    }

    if (mayor != indice) {
        intercambiar(&elementos[indice], &elementos[mayor]);
        hundir(elementos, tamano, mayor);
    }
}

// Función para flotar (percolar hacia arriba) un elemento en la cola de prioridad
void flotar(Elemento elementos[], int indice) {
    while (indice > 0 && elementos[(indice - 1) / 2].prioridad < elementos[indice].prioridad) {
        intercambiar(&elementos[indice], &elementos[(indice - 1) / 2]);
        indice = (indice - 1) / 2;
    }
}

// Función para agregar un elemento con valor y prioridad a la cola de prioridad
void agregar(Elemento elementos[], int *tamano, int valor, int prioridad) {
    elementos[*tamano].valor = valor;
    elementos[*tamano].prioridad = prioridad;
    (*tamano)++;
    flotar(elementos, *tamano - 1);
}

// Función para obtener y mostrar el elemento con la mayor prioridad
void obtenerMayorPrioridad(Elemento elementos[], int *tamano) {
    if (*tamano > 0) {
        printf("\n\t Elemento con mayor prioridad: Valor = %d, Prioridad = %d\n", elementos[0].valor, elementos[0].prioridad);
    } else {
        printf("\n\t La cola de prioridad está vacía.\n");
    }
}

// Función para eliminar el elemento con la mayor prioridad
void eliminarMayorPrioridad(Elemento elementos[], int *tamano) {
    if (*tamano > 0) {
        *tamano -= 1;
        elementos[0] = elementos[*tamano];
        hundir(elementos, *tamano, 0);
        printf("\n\t Elemento con mayor prioridad eliminado.\n");
    } else {
        printf("\n\t La cola de prioridad está vacía, no se puede eliminar ningún elemento.\n");
    }
}
