/*
EJERCICIO 1.
Escribe un programa en lenguaje C que implemente una cola simple de
números enteros. El programa debe permitir al usuario realizar las
siguientes operaciones:

a. Encolar un elemento en la cola.
b. Desencolar un elemento de la cola.
c. Mostrar el contenido actual de la cola.

Obs: Se deben de implementar las funciones necesarias para realizar
estas operaciones en la cola y de manejar casos como cola llena o cola
vacía de manera adecuada.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_TAMANO 100

// Estructura de la cola
struct Cola {
    int elementos[MAX_TAMANO];
    int frente;
    int final;
};

// Función para crear una cola vacía
struct Cola* crearCola() {
    struct Cola* cola = (struct Cola*)malloc(sizeof(struct Cola));
    cola->frente = -1;
    cola->final = -1;
    return cola;
}

int estaVacia(struct Cola* cola) ;
int estaLlena(struct Cola* cola);
void encolar(struct Cola* cola, int elemento);
int desencolar(struct Cola* cola);
void mostrar(struct Cola* cola) ;

int main() {
    struct Cola* cola = crearCola();
    int opcion, elemento;


    printf("\n\t +-----------------------------------------------------+");
    printf("\n\t |                      MENU                           |");
    printf("\n\t +-----------------------------------------------------+");
    printf("\n\t | 1. Encolar un elemento                              |");
    printf("\n\t | 2. Desencolar un elemento                           |");
    printf("\n\t | 3. Mostrar la cola                                  |");
    printf("\n\t | 4. Salir                                            |");
    printf("\n\t +-----------------------------------------------------+\n");



    while (1) {
        printf("\t -------------------------------------------------------");
        printf("\n\t OPCION: ");
        scanf("%d", &opcion);
        printf("\t -------------------------------------------------------");

        switch (opcion) {
            case 1:
                printf("\n\t Ingrese el elemento a encolar: ");
                scanf("%d", &elemento);
                encolar(cola, elemento);
                break;
            case 2:
                elemento = desencolar(cola);
                if (elemento != -1) {
                    printf("\n\t Elemento desencolado: %d\n", elemento);
                }
                break;
            case 3:
                mostrar(cola);
                break;
            case 4:
                exit(0);
            default:
                printf("\n\t Opción no válida. Intente de nuevo.");
        }
    }

    return 0;
}


// Función para verificar si la cola está vacía
int estaVacia(struct Cola* cola) {
    return (cola->frente == -1);
}

// Función para verificar si la cola está llena
int estaLlena(struct Cola* cola) {
    return (cola->final == MAX_TAMANO - 1);
}

// Función para encolar un elemento en la cola
void encolar(struct Cola* cola, int elemento) {
    if (estaLlena(cola)) {
        printf("\n\t La cola esta llena. No se puede encolar mas elementos.");
    } else {
        if (estaVacia(cola)) {
            cola->frente = 0;
        }
        cola->final++;
        cola->elementos[cola->final] = elemento;
        //printf("\n\t Elemento encolado: %d\n", elemento);
    }
}

// Función para desencolar un elemento de la cola
int desencolar(struct Cola* cola) {
    int elemento;
    if (estaVacia(cola)) {
        printf("\n\t La cola esta vacia. No se puede desencolar.\n");
        return -1;
    } else {
        elemento = cola->elementos[cola->frente];
        if (cola->frente == cola->final) {
            cola->frente = cola->final = -1;
        } else {
            cola->frente++;
        }
        return elemento;
    }
}

// Función para mostrar el contenido actual de la cola
void mostrar(struct Cola* cola) {
    if (estaVacia(cola)) {
        printf("\n\t La cola esta vacia.\n");
    } else {
        printf("\n\t Contenido de la cola: ");
        for (int i = cola->frente; i <= cola->final; i++) {
            printf("%d ", cola->elementos[i]);
        }
        printf("\n");
    }
}

