#include <stdio.h>
#include <stdlib.h>

// Función para intercambiar dos elementos en el montículo
void intercambiar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Función para mantener la propiedad del montículo (heapify)
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

// Función para insertar un elemento en el montículo
void insertar(int *monticulo, int *n, int elemento) {
    (*n)++;
    int i = (*n) - 1;
    monticulo[i] = elemento;

    while (i > 0 && monticulo[(i - 1) / 2] < monticulo[i]) {
        intercambiar(&monticulo[i], &monticulo[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Función para encontrar el elemento máximo del montículo
int encontrarMaximo(int *monticulo, int n) {
    if (n <= 0)
        return -1;
    return monticulo[0];
}

// Función para eliminar el elemento máximo del montículo
int eliminarMaximo(int *monticulo, int *n) {
    if (*n <= 0)
        return -1;
    if (*n == 1) {
        (*n)--;
        return monticulo[0];
    }

    int raiz = monticulo[0];
    monticulo[0] = monticulo[(*n) - 1];
    (*n)--;
    mantenerMonticulo(monticulo, *n, 0);

    return raiz;
}

int main() {
    int *monticulo;
    int n = 0;

    while (1) {
        printf("1. Agregar un número entero al montículo\n");
        printf("2. Encontrar el elemento máximo\n");
        printf("3. Eliminar el elemento máximo\n");
        printf("4. Salir\n");

        int opcion;
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                // Agregar un número entero al montículo
                int elemento;
                printf("Ingrese un número entero: ");
                scanf("%d", &elemento);
                insertar(monticulo, &n, elemento);
                break;
            case 2:
                // Encontrar y mostrar el elemento máximo
                printf("Elemento máximo: %d\n", encontrarMaximo(monticulo, n));
                break;
            case 3:
                // Eliminar el elemento máximo
                int maximo = eliminarMaximo(monticulo, &n);
                if (maximo != -1)
                    printf("Se eliminó el elemento máximo: %d\n", maximo);
                else
                    printf("El montículo está vacío.\n");
                break;
            case 4:
                // Salir del programa
                free(monticulo);
                return 0;
            default:
                printf("Opción no válida.\n");
                break;
        }
    }

    return 0;
}
