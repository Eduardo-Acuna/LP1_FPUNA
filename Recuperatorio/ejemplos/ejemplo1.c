#include <stdio.h>

#define MAXNODOS 1001

struct monticulo {
    int V[MAXNODOS + 1];
    int maxNodos;
    int n;
} typedef Monticulo;

void flotar(Monticulo *mnlo, int i);
void insertarMonticulo(Monticulo *mnlo, int clave);
int buscarMinimo(Monticulo *mnlo);
int eliminarMinimo(Monticulo *mnlo);
void criba(int V[], int primero, int ultimo);

/* Crear Monticulo*/
void crearMonticulo(Monticulo *mnlo) {
    mnlo->n = 0;
    mnlo->maxNodos = MAXNODOS;
}

/*Insertar en el monticulo*/
void insertarMonticulo(Monticulo *mnlo, int clave) {
    if (mnlo->n == mnlo->maxNodos) {
        puts("Monticulo lleno\n");
        return;
    }

    (mnlo->n)++;
    mnlo->V[mnlo->n] = clave;

    flotar(mnlo, mnlo->n);
}

/*Lleva el menor en la raiz*/
void flotar(Monticulo *mnlo, int i) {
    int nuevaClave;

    nuevaClave = mnlo->V[i];

    while ((i > 1) && (mnlo->V[i / 2] > nuevaClave)) {
        mnlo->V[i] = mnlo->V[i / 2];
        i = i / 2;
    }

    mnlo->V[i] = nuevaClave;
}

/* buscar el minimo*/
int buscarMinimo(Monticulo *mnlo) {
    int aux = 0;

    if (mnlo->n > 0) {
        aux = mnlo->V[1];
    }

    return aux;
}

/* Eliminar el elemento de la raiz*/
int eliminarMinimo(Monticulo *mnlo) {
    int menor = -1;

    if (mnlo->n > 0) {
        menor = mnlo->V[1];
        mnlo->V[1] = mnlo->V[mnlo->n];
        (mnlo->n)--;

        criba(mnlo->V, 1, mnlo->n);
    }
    return menor;
}

/* Ordenar el monticulo*/
void criba(int V[], int primero, int ultimo) {
    int esMonticulo, hijo;
    esMonticulo = 0;

    while ((primero <= ultimo / 2) && !esMonticulo) {
        if (2 * primero == ultimo) {
            hijo = 2 * primero;
        } else {
            if (V[2 * primero] == V[2 * primero + 1]) {
                hijo = 2 * primero;
            } else {
                hijo = 2 * primero + 1;
            }

            if (V[hijo] < V[primero]) {
                // Deberías tener una función swap aquí si no la has definido
                int temp = V[primero];
                V[primero] = V[hijo];
                V[hijo] = temp;

                primero = hijo;
            } else {
                esMonticulo = 1;
            }
        }
    }
}









