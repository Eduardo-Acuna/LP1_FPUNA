#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMEROS 100

struct Monticulo {
    int numeros[MAX_NUMEROS];
    int cantidad;
};

void inicializarMonticulo(struct Monticulo* monticulo) {
    monticulo->cantidad = 0;
}

void agregarNumero(struct Monticulo* monticulo, int numero) {
    if (monticulo->cantidad >= MAX_NUMEROS) {
        printf("El montículo está lleno. No se puede agregar más números.\n");
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
        printf("Valor de k no válido.\n");
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
        printf("El montículo está vacío. No se puede eliminar ningún número.\n");
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

int main() {
    struct Monticulo monticulo;
    int n, opcion, numero, k;

    inicializarMonticulo(&monticulo);

    do {
        printf("1. Agregar número\n2. Encontrar k-ésimo elemento más pequeño\n3. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese un número: ");
                scanf("%d", &numero);
                agregarNumero(&monticulo, numero);
                break;

            case 2:
                printf("Ingrese el valor de k: ");
                scanf("%d", &k);
                if (k > 0 && k <= monticulo.cantidad) {
                    int kElemento = encontrarKesimoElemento(&monticulo, k);
                    printf("El %d-ésimo elemento más pequeño es: %d\n", k, kElemento);
                } else {
                    printf("Valor de k no válido.\n");
                }
                break;

            case 3:
                printf("Saliendo del programa.\n");
                break;

            default:
                printf("Opción no válida. Por favor, elija una opción válida.\n");
        }
    } while (opcion != 3);

    return 0;
}

