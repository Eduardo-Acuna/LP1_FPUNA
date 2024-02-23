/*
EJERCICIO 1.
Crea un programa en lenguaje C que utilice un mont�culo para encontrar
el elemento m�ximo en un conjunto de n�meros enteros. El programa
debe permitir al usuario realizar las siguientes operaciones: (1P)
a. Agregar un n�mero entero al mont�culo.
b. Encontrar y mostrar el elemento m�ximo del mont�culo.
c. Eliminar el elemento m�ximo del mont�culo.
d. Salir del programa.
El programa debe garantizar que el elemento m�ximo se actualiza
autom�ticamente cuando se agrega o elimina un elemento.
*/

#include <stdio.h>
#include <stdlib.h>

void intercambiar(int *a, int *b);
void mantenerMonticulo(int *monticulo, int n, int i);
void insertar(int *monticulo, int *n, int elemento);
int encontrarMaximo(int *monticulo, int n);
int eliminarMaximo(int *monticulo, int *n);

int main() {
    int *monticulo;
    int opcion, elemento, maximo, n = 0;


    monticulo = (int *)malloc(sizeof(int) * 100);

    if (monticulo == NULL) {
        printf("Error: No se pudo asignar memoria para el mont�culo.\n");
        return 1;
    }

    printf("\n\t +-----------------------------------------------------+");
    printf("\n\t |                      MENU                           |");
    printf("\n\t +-----------------------------------------------------+");
    printf("\n\t | 1. Agregar un numero entero al monticulo            |");
    printf("\n\t | 2. Encontrar el elemento maximo                     |");
    printf("\n\t | 3. Eliminar el elemento maximo                      |");
    printf("\n\t | 4. Salir                                            |");
    printf("\n\t +-----------------------------------------------------+\n");


    while (1) {
        printf("\t -------------------------------------------------------");
        printf("\n\t OPCION: ");
        scanf("%d", &opcion);
        printf("\t -------------------------------------------------------");

        switch (opcion) {
            case 1:
                printf("\n\t Ingrese un numero entero: ");
                scanf("%d", &elemento);
                insertar(monticulo, &n, elemento);
                break;
            case 2:
                printf("\n\t Elemento maximo: %d\n", encontrarMaximo(monticulo, n));
                break;
            case 3:
                maximo = eliminarMaximo(monticulo, &n);
                if (maximo != -1)
                    printf("\n\t Se elimino el elemento maximo: %d\n", maximo);
                else
                    printf("\n\t El monticulo esta vacio.\n");
                break;
            case 4:
                free(monticulo);
                return 0;
            default:
                printf("\n\t Opcion no valida.\n");
                break;
        }
    }

    return 0;
}


// Funci�n para intercambiar dos elementos en el mont�culo
void intercambiar(int *a, int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

// Funci�n para mantener la propiedad del mont�culo (heapify)
void mantenerMonticulo(int *monticulo, int n, int i) {
    int max = i;
    int izquierda = 2 * i + 1;
    int derecha = 2 * i + 2;

    if (izquierda < n && monticulo[izquierda] > monticulo[max])
        max = izquierda;

    if (derecha < n && monticulo[derecha] > monticulo[max])
        max = derecha;

    if (max != i) {
        intercambiar(&monticulo[i], &monticulo[max]);
        mantenerMonticulo(monticulo, n, max);
    }
}

// Funci�n para insertar un elemento en el mont�culo
void insertar(int *monticulo, int *n, int elemento) {
    (*n)++;
    int i = (*n) - 1;
    monticulo[i] = elemento;

    while (i > 0 && monticulo[(i - 1) / 2] < monticulo[i]) {
        intercambiar(&monticulo[i], &monticulo[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Funci�n para encontrar el elemento m�ximo del mont�culo
int encontrarMaximo(int *monticulo, int n) {
    if (n <= 0)
        return -1;
    return monticulo[0];
}

// Funci�n para eliminar el elemento m�ximo del mont�culo
int eliminarMaximo(int *monticulo, int *n){
    int raiz;

    if (*n <= 0)
        return -1;
    if (*n == 1) {
        (*n)--;
        return monticulo[0];
    }

    raiz = monticulo[0];
    monticulo[0] = monticulo[(*n) - 1];
    (*n)--;
    mantenerMonticulo(monticulo, *n, 0);

    return raiz;
}

