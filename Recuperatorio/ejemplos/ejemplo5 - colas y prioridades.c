#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESOS 10

// Estructura para representar un proceso
typedef struct {
    int id;
    int prioridad;
} Proceso;

// Estructura para representar una cola de prioridad
typedef struct {
    Proceso procesos[MAX_PROCESOS];
    int frente;
    int final;
} ColaPrioridad;

// Función para inicializar una cola de prioridad
void inicializarCola(ColaPrioridad *cola) {
    cola->frente = -1;
    cola->final = -1;
}

// Función para verificar si la cola de prioridad está vacía
int colaVacia(ColaPrioridad *cola) {
    return cola->frente == -1;
}

// Función para insertar un proceso en la cola de prioridad
void insertarProceso(ColaPrioridad *cola, Proceso nuevoProceso) {
    int i;

    // Encuentra la posición adecuada para el nuevo proceso según su prioridad
    for (i = cola->final; i >= 0 && nuevoProceso.prioridad > cola->procesos[i].prioridad; i--) {
        cola->procesos[i + 1] = cola->procesos[i];
    }

    // Inserta el nuevo proceso en la posición encontrada
    cola->procesos[i + 1] = nuevoProceso;
    cola->final++;
}

// Función para eliminar un proceso de la cola de prioridad
void eliminarProceso(ColaPrioridad *cola, int id) {
    int i, encontrado = 0;

    for (i = cola->frente; i <= cola->final; i++) {
        if (cola->procesos[i].id == id) {
            encontrado = 1;
            break;
        }
    }

    if (encontrado) {
        // Elimina el proceso de la cola
        for (; i < cola->final; i++) {
            cola->procesos[i] = cola->procesos[i + 1];
        }

        cola->final--;

        printf("Proceso con ID %d eliminado\n", id);
    } else {
        printf("Proceso con ID %d no encontrado\n", id);
    }
}

// Función para imprimir los procesos en la cola de prioridad
void imprimirProcesos(ColaPrioridad *cola) {
    printf("Procesos en la cola de prioridad:\n");

    for (int i = cola->frente; i <= cola->final; i++) {
        printf("ID: %d, Prioridad: %d\n", cola->procesos[i].id, cola->procesos[i].prioridad);
    }
}

int main() {
    ColaPrioridad cola;
    inicializarCola(&cola);

    int opcion, id, prioridad;

    do {
        printf("\n1. Agregar proceso\n");
        printf("2. Eliminar proceso\n");
        printf("3. Imprimir procesos\n");
        printf("4. Salir\n");
        printf("Ingrese su opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese ID del proceso: ");
                scanf("%d", &id);
                printf("Ingrese prioridad del proceso: ");
                scanf("%d", &prioridad);

                Proceso nuevoProceso = {id, prioridad};
                insertarProceso(&cola, nuevoProceso);
                break;

            case 2:
                printf("Ingrese ID del proceso a eliminar: ");
                scanf("%d", &id);
                eliminarProceso(&cola, id);
                break;

            case 3:
                imprimirProcesos(&cola);
                break;

            case 4:
                printf("Saliendo del programa\n");
                break;

            default:
                printf("Opción no válida. Inténtelo de nuevo.\n");
        }
    } while (opcion != 4);

    return 0;
}
