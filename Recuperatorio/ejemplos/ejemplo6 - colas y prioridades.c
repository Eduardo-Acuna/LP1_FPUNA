
#include <stdio.h>
#include <stdlib.h>

// Estructura para representar un proceso
struct Proceso {
    int prioridad;
    int tiempoEjecucion;
};

// Nodo de la cola
struct Nodo {
    struct Proceso proceso;
    struct Nodo* siguiente;
};

// Estructura para la cola de procesos
struct Cola {
    struct Nodo* frente;
    struct Nodo* final;
};

// Funciones para la cola
void inicializarCola(struct Cola* cola) {
    cola->frente = NULL;
    cola->final = NULL;
}

int estaVacia(struct Cola* cola) {
    return cola->frente == NULL;
}

void encolar(struct Cola* cola, struct Proceso proceso) {
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    if (nuevoNodo == NULL) {
        printf("Error: No se pudo asignar memoria para el nuevo proceso.\n");
        exit(EXIT_FAILURE);
    }

    nuevoNodo->proceso = proceso;
    nuevoNodo->siguiente = NULL;

    if (estaVacia(cola)) {
        cola->frente = nuevoNodo;
        cola->final = nuevoNodo;
    } else {
        cola->final->siguiente = nuevoNodo;
        cola->final = nuevoNodo;
    }
}

struct Proceso desencolar(struct Cola* cola) {
    if (estaVacia(cola)) {
        printf("Error: La cola está vacía. No se puede desencolar.\n");
        exit(EXIT_FAILURE);
    }

    struct Nodo* nodoEliminar = cola->frente;
    struct Proceso proceso = nodoEliminar->proceso;

    cola->frente = cola->frente->siguiente;
    free(nodoEliminar);

    if (cola->frente == NULL) {
        cola->final = NULL;
    }

    return proceso;
}

void mostrarCola(struct Cola* cola) {
    if (estaVacia(cola)) {
        printf("La cola está vacía.\n");
        return;
    }

    struct Nodo* actual = cola->frente;
    printf("Procesos en espera:\n");

    while (actual != NULL) {
        printf("Prioridad: %d, Tiempo de ejecución: %d\n", actual->proceso.prioridad, actual->proceso.tiempoEjecucion);
        actual = actual->siguiente;
    }
}

// Función principal
int main() {
    struct Cola colaProcesos;
    inicializarCola(&colaProcesos);

    int opcion;

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

        switch (opcion) {
            case 1: {
                struct Proceso nuevoProceso;
                printf("\nIngrese la prioridad del proceso: ");
                scanf("%d", &nuevoProceso.prioridad);
                printf("\nIngrese el tiempo de ejecución del proceso: ");
                scanf("%d", &nuevoProceso.tiempoEjecucion);

                encolar(&colaProcesos, nuevoProceso);
                printf("\nProceso agregado a la cola.\n");
                break;
            }
            case 2:
                if (!estaVacia(&colaProcesos)) {
                    struct Proceso procesoAEjecutar = desencolar(&colaProcesos);
                    printf("\nEjecutando proceso con prioridad %d y tiempo de ejecución %d.\n", procesoAEjecutar.prioridad, procesoAEjecutar.tiempoEjecucion);
                } else {
                    printf("\nLa cola está vacía. No hay procesos para ejecutar.\n");
                }
                break;
            case 3:
                mostrarCola(&colaProcesos);
                break;
            case 4:
                printf("\n¡Gracias por utilizar el programa!\n");
                break;
            default:
                printf("\nOpción no válida. Intente de nuevo.\n");
        }

    } while (opcion != 4);

    return 0;
}
