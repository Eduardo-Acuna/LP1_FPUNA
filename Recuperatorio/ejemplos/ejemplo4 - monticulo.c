#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo* izquierda;
    struct Nodo* derecha;
};

typedef struct Nodo Nodo;

struct Monticulo {
    Nodo* raiz;
};

typedef struct Monticulo Monticulo;

void inicializarMonticulo(Monticulo* monticulo) {
    monticulo->raiz = NULL;
}

void insertarEnMonticulo(Monticulo* monticulo, int elemento) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    if (!nuevoNodo) {
        printf("Error: No se pudo asignar memoria\n");
        exit(1);
    }

    nuevoNodo->dato = elemento;
    nuevoNodo->izquierda = nuevoNodo->derecha = NULL;

    if (monticulo->raiz == NULL) {
        monticulo->raiz = nuevoNodo;
    } else {
        nuevoNodo->derecha = monticulo->raiz->derecha;
        monticulo->raiz->derecha = nuevoNodo;
    }
}

int quitarMinDelMonticulo(Monticulo* monticulo) {
    if (monticulo->raiz == NULL) {
        printf("Montículo vacío\n");
        exit(1);
    }

    int elementoMinimo = monticulo->raiz->dato;
    Nodo* temp = monticulo->raiz;

    monticulo->raiz = monticulo->raiz->izquierda;

    free(temp);
    return elementoMinimo;
}

void imprimirMonticuloRecursivo(Nodo* nodo) {
    if (nodo == NULL) {
        return;
    }

    printf("%d ", nodo->dato);
    imprimirMonticuloRecursivo(nodo->izquierda);
    imprimirMonticuloRecursivo(nodo->derecha);
}

void imprimirMonticulo(Monticulo* monticulo) {
    if (monticulo->raiz == NULL) {
        printf("Montículo vacío\n");
        return;
    }

    printf("Montículo: ");
    imprimirMonticuloRecursivo(monticulo->raiz);
    printf("\n");
}

int main() {
    Monticulo monticulo;
    inicializarMonticulo(&monticulo);

    int opcion, elemento;

    do {
        printf("\n--- Menú Montículo ---\n");
        printf("1. Insertar elemento en el montículo\n");
        printf("2. Quitar elemento mínimo del montículo\n");
        printf("3. Imprimir montículo\n");
        printf("0. Salir\n");
        printf("Ingrese su opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese el elemento a insertar: ");
                scanf("%d", &elemento);
                insertarEnMonticulo(&monticulo, elemento);
                break;
            case 2:
                printf("Elemento mínimo eliminado: %d\n", quitarMinDelMonticulo(&monticulo));
                break;
            case 3:
                imprimirMonticulo(&monticulo);
                break;
            case 0:
                printf("Saliendo del programa\n");
                break;
            default:
                printf("Opción no válida\n");
        }
    } while (opcion != 0);

    return 0;
}

