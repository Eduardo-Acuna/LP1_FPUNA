/*
EJERCICIO 2.
Diseña un programa en lenguaje C que simule la gestión de tareas pendientes
utilizando una cola de prioridad. Cada tarea tiene una prioridad (alta, media o
baja) y una descripción. El programa debe permitir al usuario realizar las
siguientes operaciones: (2P)
a. Agregar una tarea pendiente a la cola de prioridad con su prioridad y
descripción.
b. Ejecutar la tarea con la mayor prioridad en la cola.
c. Mostrar la lista de tareas pendientes en orden de prioridad.
d. Salir del programa.
El programa debe garantizar que las tareas se ejecutan en orden de prioridad,
de modo que las tareas con prioridad alta se ejecuten antes que las de prioridad
media y baja.
*/

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define MAX_TAREAS 100

enum Prioridad {
    ALTA,
    MEDIA,
    BAJA
};

struct Tarea {
    enum Prioridad prioridad;
    char descripcion[256];
};

struct ColaPrioridad {
    struct Tarea tareas[MAX_TAREAS];
    int cantidad;
};

void mostrarCola(struct ColaPrioridad* cola);
void inicializarCola(struct ColaPrioridad* cola) ;
void intercambiarTareas(struct Tarea* a, struct Tarea* b) ;
void agregarTarea(struct ColaPrioridad* cola, enum Prioridad prioridad, const char* descripcion);

struct Tarea ejecutarTarea( struct ColaPrioridad* cola ){

    if (cola->cantidad == 0) {
        printf("\n\t No hay tareas pendientes para ejecutar.\n");
        struct Tarea tareaVacia = {BAJA, ""};
        return tareaVacia;
    }


    struct Tarea tareaEjecutada;
    tareaEjecutada = cola->tareas[0];


    cola->cantidad--;
    cola->tareas[0] = cola->tareas[cola->cantidad];
    int indice = 0;
    while (1) {
        int indiceIzquierdo, indiceDerecho, indiceMayor;
        indiceIzquierdo = 2 * indice + 1;
        indiceDerecho = 2 * indice + 2;
        indiceMayor = indice;

        if (indiceIzquierdo < cola->cantidad && cola->tareas[indiceIzquierdo].prioridad > cola->tareas[indiceMayor].prioridad) {
            indiceMayor = indiceIzquierdo;
        }

        if (indiceDerecho < cola->cantidad && cola->tareas[indiceDerecho].prioridad > cola->tareas[indiceMayor].prioridad) {
            indiceMayor = indiceDerecho;
        }

        if (indiceMayor != indice) {
            intercambiarTareas(&cola->tareas[indice], &cola->tareas[indiceMayor]);
            indice = indiceMayor;
        } else {
            break;
        }
    }

    printf("\n\t Tarea ejecutada: Prioridad %d, Descripción: %s\n", tareaEjecutada.prioridad, tareaEjecutada.descripcion);

    return tareaEjecutada;
}

int main() {
    struct ColaPrioridad cola;
    int opcion, prioridad;

    inicializarCola(&cola);

    printf("\n\t +-----------------------------------------------------+");
    printf("\n\t |                      MENU                           |");
    printf("\n\t +-----------------------------------------------------+");
    printf("\n\t | 1. Agregar tarea                                    |");
    printf("\n\t | 2. Ejecutar tarea con mayor prioridad               |");
    printf("\n\t | 3. Mostrar tareas pendientes                        |");
    printf("\n\t | 4. Salir                                            |");
    printf("\n\t +-----------------------------------------------------+");

    do {
        printf("\n\t -------------------------------------------------------");
        printf("\n\t OPCION: ");
        scanf("%d", &opcion);
        printf("\n\t -------------------------------------------------------");

        if( opcion==1 ){
                char descripcion[256];
                printf("\n\t            1. Agregar tarea                    ");
                printf("\n\t Prioridad: (ALTA:2 ,MEDIA:1 ,BAJA:0 )");
                printf("\n\t Ingrese la prioridad: ");
                scanf("%d", &prioridad);
                printf("\t Ingrese tarea: ");
                scanf(" %[^\n]", descripcion);
                agregarTarea(&cola, (enum Prioridad)prioridad, descripcion);

        } else if(opcion==2 ){
                ejecutarTarea(&cola);


        } else if(opcion==3 ){
                mostrarCola(&cola);


         } else if(opcion==4 ){
                printf("\n\t Saliendo del programa.\n");
                break;

         } else {
                printf("\n\t Opción no válida.\n");

        }

    } while (opcion != 4);

    return 0;
}



void inicializarCola(struct ColaPrioridad* cola) {
    cola->cantidad = 0;
}

void intercambiarTareas(struct Tarea* a, struct Tarea* b) {
    struct Tarea aux;
     aux = *a;
    *a = *b;
    *b = aux;
}

void agregarTarea(struct ColaPrioridad* cola, enum Prioridad prioridad, const char* descripcion) {
    if (cola->cantidad >= MAX_TAREAS) {
        printf("La cola de prioridad está llena. No se puede agregar más tareas.\n");
        return;
    }

    struct Tarea nuevaTarea;
    nuevaTarea.prioridad = prioridad;
    strncpy(nuevaTarea.descripcion, descripcion, sizeof(nuevaTarea.descripcion) - 1);
    cola->tareas[cola->cantidad] = nuevaTarea;
    cola->cantidad++;

    int indice;
    indice = cola->cantidad - 1;
    while (indice > 0) {
        int indicePadre = (indice - 1) / 2;
        if (cola->tareas[indice].prioridad > cola->tareas[indicePadre].prioridad) {
            intercambiarTareas(&cola->tareas[indice], &cola->tareas[indicePadre]);
            indice = indicePadre;
        } else {
            break;
        }
    }
}

void mostrarCola(struct ColaPrioridad* cola) {
    int i;
    printf("\n\t Tareas pendientes en orden de prioridad:\n");
    for ( i=0 ; i<cola->cantidad ; i++ ){
        printf("\n\t Prioridad %d, Descripción: %s\n", cola->tareas[i].prioridad, cola->tareas[i].descripcion);
    }
}


