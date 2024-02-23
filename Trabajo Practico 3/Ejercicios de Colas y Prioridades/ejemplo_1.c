/*
EJERCICIO 1.
Crea un programa en lenguaje C que simule una cola de procesos para una
CPU. Cada proceso tiene una prioridad y un tiempo estimado de ejecución. El
programa debe permitir al usuario realizar las siguientes operaciones: (1P)
a. Agregar un proceso a la cola con su prioridad y tiempo de ejecución.
b. Ejecutar el proceso con la mayor prioridad en la cola.
c. Mostrar la lista de procesos en espera.
d. Salir del programa.
*/

#include <stdio.h>
#include <stdlib.h>

struct Proceso {
    int prioridad;
    int tiempo_estimado;
};

struct Nodo {
    struct Proceso proceso;
    struct Nodo* siguiente;
};

struct Cola {
    struct Nodo* frente;
    struct Nodo* fin;
};

struct Proceso desencolar(struct Cola* cola) {
    if (cola->frente == NULL) {
        struct Proceso procesoVacio;
        procesoVacio = {0, 0};
        return procesoVacio;
    }

    struct Nodo* nodoDesencolado;
    nodoDesencolado = cola->frente;

    struct Proceso proceso;
    proceso = nodoDesencolado->proceso;

    if( cola->frente==cola->fin ){
        cola->frente = NULL;
        cola->fin = NULL;
    } else {
        cola->frente = cola->frente->siguiente;
    }

    free(nodoDesencolado);
    return proceso;
}

void inicializarCola(struct Cola* cola);
void encolar(struct Cola* cola, struct Proceso proceso);
void mostrarCola(struct Cola* cola);


int main() {
    struct Cola cola;
    int opcion;

    inicializarCola(&cola);

    printf("\n\t +-----------------------------------------------------+");
    printf("\n\t |                      MENU                           |");
    printf("\n\t +-----------------------------------------------------+");
    printf("\n\t | 1. Agregar proceso                                  |");
    printf("\n\t | 2. Ejecutar proceso con mayor prioridad             |");
    printf("\n\t | 3. Mostrar proceso de espera                        |");
    printf("\n\t | 4. Salir                                            |");
    printf("\n\t +-----------------------------------------------------+");

    do {

        printf("\n\t OPCION: ");
        scanf("%d", &opcion);
        printf("\n\t -------------------------------------------------------");

        if( opcion==1 ){
            printf("\n\t                 1. AGREGAR PROCESO");
            struct Proceso nuevoProceso;
            printf("\n\t Prioridad del proceso: ");
            scanf("%d", &nuevoProceso.prioridad);
            printf("\n\t Tiempo estimado del proceso: ");
            scanf("%d", &nuevoProceso.tiempo_estimado);
            encolar(&cola, nuevoProceso);
            printf("\n\t -------------------------------------------------------");

        } else if( opcion==2 ){
            printf("\n\t         2. EJECUTAR PROCESO CON MAYOR PRIORIDAD ");
            struct Proceso procesoEjecutado = desencolar(&cola);
            if (procesoEjecutado.prioridad != 0) {
                printf("\n\t Proceso ejecutado: Prioridad: %d, Tiempo estimado: %d\n", procesoEjecutado.prioridad, procesoEjecutado.tiempo_estimado);
            } else {
                printf("\n\t No hay procesos en espera.\n");
            }
            printf("\n\t -------------------------------------------------------");
        } else if( opcion==3 ){
            printf("\n\t             3. MOSTRAR PROCESO DE ESPERA ");
            mostrarCola(&cola);

        } else if( opcion==4 ){
            printf("\n\t                    4. SALIR ");
            printf("\n\t Fin del programa... hasta pronto.\n");
            printf("\n\t -------------------------------------------------------");
            break;
        } else {
            printf("\n\t Opción no válida.\n");
            printf("\n\t -------------------------------------------------------");

        }

    } while (opcion != 4);

    // Libera la memoria asignada para los nodos de la cola
    while (cola.frente != NULL) {
        desencolar(&cola);
    }
    return 0;
}


void inicializarCola(struct Cola* cola) {
    cola->frente = NULL;
    cola->fin = NULL;
}

void encolar(struct Cola* cola, struct Proceso proceso) {
    struct Nodo* nuevoNodo;
    nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));

    nuevoNodo->proceso = proceso;
    nuevoNodo->siguiente = NULL;

    if( cola->fin==NULL ){
        cola->frente = nuevoNodo;
        cola->fin = nuevoNodo;
    } else {
        cola->fin->siguiente = nuevoNodo;
        cola->fin = nuevoNodo;
    }
}


void mostrarCola(struct Cola* cola) {
    struct Nodo* actual;
    actual = cola->frente;

    if( actual==NULL ){
        printf("\n\t La cola esta vacia.\n");
        return;
    }

    printf("\n\t Procesos en espera:\n");

    while (actual != NULL) {
        printf("\n\t Prioridad: %d, Tiempo estimado: %d\n", actual->proceso.prioridad, actual->proceso.tiempo_estimado);
        actual = actual->siguiente;
    }
}

