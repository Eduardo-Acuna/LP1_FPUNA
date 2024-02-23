/*
EJERCICIO 3
Diseña un programa en lenguaje C que use un montículo para buscar el k-ésimo
elemento más pequeño en un conjunto de números enteros. El programa debe
permitir al usuario realizar las siguientes operaciones: (1P)

a. Agregar un número entero al montículo.
b. Encontrar y mostrar el k-ésimo elemento más pequeño del montículo.
c. Salir del programa.
El programa debe mantener el montículo con los k elementos más pequeños en
todo momento y mostrar el k-ésimo elemento más pequeño al usuario.

Ejemplo:
El "k-ésimo elemento más pequeño" se refiere al elemento que ocupa la posición
k en un conjunto de elementos ordenados en orden ascendente. En otras
palabras, es el k-ésimo elemento cuando los elementos se ordenan de menor a
mayor.
Por ejemplo, en un conjunto de números [3, 1, 4, 1, 5, 9, 2, 6] y se quiere
encontrar el tercer elemento más pequeño (k=3), se debe ordenar los números
de menor a mayor: [1, 1, 2, 3, 4, 5, 6, 9]
En este caso, el tercer elemento más pequeño es 2, ya que ocupa la tercera
posición después de ordenar la lista de manera ascendente.
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
int encontrarKesimoElemento(struct Monticulo* monticulo, int k);
void eliminarMaximo(struct Monticulo* monticulo);

int main() {
    struct Monticulo monticulo;
    int n, opcion, numero, k;

    inicializarMonticulo(&monticulo);

    printf("\n\t +-----------------------------------------------------+");
    printf("\n\t |                      MENU                           |");
    printf("\n\t +-----------------------------------------------------+");
    printf("\n\t | 1. Agregar numero                                   |");
    printf("\n\t | 2. Encontrar k-esimo elemento mas pequeño           |");
    printf("\n\t | 3. Salir                                            |");
    printf("\n\t +-----------------------------------------------------+\n");



    do {
        printf("\t -------------------------------------------------------");
        printf("\n\t OPCION: ");
        scanf("%d", &opcion);
        printf("\t -------------------------------------------------------");


        switch (opcion) {
            case 1:
                printf("\n\t Ingrese un numero: ");
                scanf("%d", &numero);
                agregarNumero(&monticulo, numero);
                break;

            case 2:
                printf("\n\t Ingrese el valor de k: ");
                scanf("%d", &k);
                if (k > 0 && k <= monticulo.cantidad) {
                    int kElemento = encontrarKesimoElemento(&monticulo, k);
                    printf("\n\t El %d-esimo elemento mas pequeno es: %d\n", k, kElemento);
                } else {
                    printf("\n\t Valor de k no valido.\n");
                }
                break;

            case 3:
                printf("\n\t Saliendo del programa.\n");
                break;

            default:
                printf("\n\t Opcion no valida.\n");
        }
    } while (opcion != 3);

    return 0;
}


void inicializarMonticulo(struct Monticulo* monticulo) {
    monticulo->cantidad = 0;
}

void agregarNumero(struct Monticulo* monticulo, int numero) {
    if (monticulo->cantidad >= MAX_NUMEROS) {
        printf("El monticulo esta lleno. No se puede agregar mas numeros.\n");
        return;
    }

    int indice = monticulo->cantidad;
    monticulo->numeros[indice] = numero;
    monticulo->cantidad++;

    while (indice > 0) {
        int indicePadre = (indice - 1) / 2;
        if (monticulo->numeros[indice] < monticulo->numeros[indicePadre]) {
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

int encontrarKesimoElemento(struct Monticulo* monticulo, int k) {
    if (k <= 0 || k > monticulo->cantidad) {
        printf("\n\t Valor de k no valido.\n");
        return -1;
    }

    // Crear un montículo temporal para encontrar el k-ésimo elemento
    struct Monticulo temporal;
    inicializarMonticulo(&temporal);

    for (int i = 0; i < k; i++) {
        agregarNumero(&temporal, monticulo->numeros[i]);
    }

    for (int i = k; i < monticulo->cantidad; i++) {
        if (monticulo->numeros[i] < temporal.numeros[0]) {
            eliminarMaximo(&temporal);
            agregarNumero(&temporal, monticulo->numeros[i]);
        }
    }

    return temporal.numeros[0];
}

void eliminarMaximo(struct Monticulo* monticulo) {
    if (monticulo->cantidad == 0) {
        printf("\n\t El monticulo esta vacio.\n");
        return;
    }

    // Mover el último número al principio
    monticulo->numeros[0] = monticulo->numeros[monticulo->cantidad - 1];
    monticulo->cantidad--;

    int indice = 0;
    while (2 * indice + 1 < monticulo->cantidad) {
        int indiceHijoIzquierdo = 2 * indice + 1;
        int indiceHijoDerecho = 2 * indice + 2;
        int indiceMenor = indiceHijoIzquierdo;

        if (indiceHijoDerecho < monticulo->cantidad && monticulo->numeros[indiceHijoDerecho] < monticulo->numeros[indiceMenor]) {
            indiceMenor = indiceHijoDerecho;
        }

        if (monticulo->numeros[indiceMenor] < monticulo->numeros[indice]) {
            // Intercambiar el número con su hijo
            int temp = monticulo->numeros[indice];
            monticulo->numeros[indice] = monticulo->numeros[indiceMenor];
            monticulo->numeros[indiceMenor] = temp;
            indice = indiceMenor;
        } else {
            break;
        }
    }
}
