/*
EJERCICIO 2
Diseña un programa en lenguaje C que ordene un arreglo de números enteros
utilizando un montículo. El programa debe permitir al usuario realizar las
siguientes operaciones: (1P)
a. Ingresar un arreglo de números enteros.
b. Ordenar el arreglo utilizando un montículo.
c. Mostrar el arreglo ordenado.
d. Salir del programa.
El programa debe utilizar un montículo para ordenar el arreglo en orden
ascendente.
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMEROS 100

struct Monticulo {
    int numeros[MAX_NUMEROS];
    int cantidad;
};

void inicializarMonticulo(struct Monticulo* monticulo);
void agregarNumero(struct Monticulo* monticulo, int numero);
int eliminarMaximo(struct Monticulo* monticulo);
void mostrarArreglo(int arreglo[], int n);

int main() {
    struct Monticulo monticulo;
    int arreglo[MAX_NUMEROS];
    int n, opcion, numero,i;

    inicializarMonticulo(&monticulo);


    printf("\n\t +-----------------------------------------------------+");
    printf("\n\t |                      MENU                           |");
    printf("\n\t +-----------------------------------------------------+");
    printf("\n\t | 1. Cargar elementos en el arreglo                   |");
    printf("\n\t | 2. Ordenar el arreglo utilizando un montículo       |");
    printf("\n\t | 3. Mostrar el arreglo ordenado                      |");
    printf("\n\t | 4. Salir                                            |");
    printf("\n\t +-----------------------------------------------------+\n");

    while (1) {
        printf("\t -------------------------------------------------------");
        printf("\n\t OPCION: ");
        scanf("%d", &opcion);
        printf("\t -------------------------------------------------------");


        switch (opcion) {
            case 1:
                printf("\n\t Ingrese la cantidad de elementos en el arreglo: ");
                scanf("%d", &n);

                printf("\n\t Ingrese los elementos del arreglo:\n");
                for( i=0 ; i<n ; i++ ){
                    printf("\t arreglo[%d]: ",i);
                    scanf("%d", &arreglo[i]);
                }
                printf("\n\t Los elementos se han cargado en el arreglo.\n");
                break;
            case 2:
                for ( i=0 ; i<n ; i++){
                    agregarNumero(&monticulo, arreglo[i]);
                }
                printf("\n\t El arreglo ha sido ordenado con montículo.\n");
                break;
            case 3:
                printf("\n\t Arreglo ordenado: ");
                while (monticulo.cantidad > 0) {
                    int maximo = eliminarMaximo(&monticulo);
                    printf("\t %d ", maximo);
                }
                printf("\n");
                break;
            case 4:
                printf("\n\t Saliendo del programa.\n");
                break;
            default:
                printf("\n\t Opción no válida.\n");

        }
    }
}


void inicializarMonticulo(struct Monticulo* monticulo) {
    monticulo->cantidad = 0;
}

void agregarNumero(struct Monticulo* monticulo, int numero) {
    if (monticulo->cantidad >= MAX_NUMEROS) {
        printf("\n\t El montículo está lleno.\n");
        return;
    }

    int indice = monticulo->cantidad;
    monticulo->numeros[indice] = numero;
    monticulo->cantidad++;

    while (indice > 0) {
        int indicePadre = (indice - 1) / 2;
        if (monticulo->numeros[indice] > monticulo->numeros[indicePadre]) {
            // Intercambiar el número con su padre
            int temp = monticulo->numeros[indice];
            monticulo->numeros[indice] = monticulo->numeros[indicePadre];
            monticulo->numeros[indicePadre] = temp;
            indice = indicePadre;
        } else {
            break;
        }
    }
}

int eliminarMaximo(struct Monticulo* monticulo) {
    if (monticulo->cantidad == 0) {
        printf("El montículo está vacío. No se puede eliminar ningún número.\n");
        return -1;
    }

    int maximo = monticulo->numeros[0];

    // Mover el último número al principio
    monticulo->numeros[0] = monticulo->numeros[monticulo->cantidad - 1];
    monticulo->cantidad--;

    int indice = 0;
    while (2 * indice + 1 < monticulo->cantidad) {
        int indiceHijoIzquierdo = 2 * indice + 1;
        int indiceHijoDerecho = 2 * indice + 2;
        int indiceMayor = indiceHijoIzquierdo;

        if (indiceHijoDerecho < monticulo->cantidad && monticulo->numeros[indiceHijoDerecho] > monticulo->numeros[indiceMayor]) {
            indiceMayor = indiceHijoDerecho;
        }

        if (monticulo->numeros[indiceMayor] > monticulo->numeros[indice]) {
            // Intercambiar el número con su hijo
            int temp = monticulo->numeros[indice];
            monticulo->numeros[indice] = monticulo->numeros[indiceMayor];
            monticulo->numeros[indiceMayor] = temp;
            indice = indiceMayor;
        } else {
            break;
        }
    }

    return maximo;
}

void mostrarArreglo(int arreglo[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arreglo[i]);
    }
    printf("\n");
}
