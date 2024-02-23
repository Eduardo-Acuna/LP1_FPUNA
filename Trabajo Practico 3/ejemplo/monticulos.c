#include <stdio.h>
#include <stdlib.h>

// Estructura de Mont�culo
struct Monticulo {
    int *arreglo;
    int capacidad;
    int tamano;
};

// Funci�n para intercambiar dos elementos en el mont�culo
void intercambiar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Funci�n para flotar (percolar hacia arriba) un elemento en el mont�culo
void flotar(struct Monticulo *monticulo, int indice) {
    int padre = (indice - 1) / 2;
    while (indice > 0 && monticulo->arreglo[indice] < monticulo->arreglo[padre]) {
        intercambiar(&monticulo->arreglo[indice], &monticulo->arreglo[padre]);
        indice = padre;
        padre = (indice - 1) / 2;
    }
}

// Funci�n para insertar un elemento en el mont�culo
void insertar(struct Monticulo *monticulo, int elemento) {
    if (monticulo->tamano == monticulo->capacidad) {
        printf("Mont�culo lleno. No se puede insertar.\n");
        return;
    }

    monticulo->arreglo[monticulo->tamano] = elemento;
    monticulo->tamano++;
    flotar(monticulo, monticulo->tamano - 1);
}

// Funci�n para buscar el m�nimo en el mont�culo
int buscarMinimo(struct Monticulo *monticulo) {
    if (monticulo->tamano == 0) {
        printf("Mont�culo vac�o. No se puede buscar el m�nimo.\n");
        return -1;
    }
    return monticulo->arreglo[0];
}

// Funci�n para hundir (percolar hacia abajo) un elemento en el mont�culo
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

// Funci�n para eliminar el m�nimo del mont�culo
int eliminarMinimo(struct Monticulo *monticulo) {
    if (monticulo->tamano == 0) {
        printf("Mont�culo vac�o. No se puede eliminar el m�nimo.\n");
        return -1;
    }

    int minimo = monticulo->arreglo[0];
    monticulo->arreglo[0] = monticulo->arreglo[monticulo->tamano - 1];
    monticulo->tamano--;
    hundir(monticulo, 0);

    return minimo;
}

// Funci�n para imprimir el contenido del mont�culo
void imprimirMonticulo(struct Monticulo *monticulo) {
    if (monticulo->tamano == 0) {
        printf("Mont�culo vac�o.\n");
        return;
    }

    printf("Contenido del mont�culo: ");
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
    printf("2. Buscar el m�nimo\n");
    printf("3. Eliminar el m�nimo\n");
    printf("4. Imprimir el mont�culo\n");
    printf("5. Salir\n");





    while (1) {

        printf("-------------------------------------------------------------------\nOPCION: ");

        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                // Insertar un elemento

                printf("Ingrese un n�mero entero: ");
                scanf("%d", &elemento);
                insertar(monticulo, elemento);
                break;
            case 2:
                // Buscar el m�nimo
                printf("Elemento m�nimo: %d\n", buscarMinimo(monticulo));
                break;
            case 3:
                // Eliminar el m�nimo
                minimo = eliminarMinimo(monticulo);
                if (minimo != -1)
                    printf("Se elimin� el elemento m�nimo: %d\n", minimo);
                break;
            case 4:
                // Imprimir el mont�culo
                imprimirMonticulo(monticulo);
                break;
            case 5:
                // Salir del programa
                free(monticulo->arreglo);
                free(monticulo);
                return 0;
            default:
                printf("Opci�n no v�lida.\n");
        }
    }
}
