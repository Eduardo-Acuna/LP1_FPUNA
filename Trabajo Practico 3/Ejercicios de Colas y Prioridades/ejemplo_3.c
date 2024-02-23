/*
EJERCICIO 3
Diseña un programa en lenguaje C que simule una cola de prioridad para
pacientes en una sala de emergencias.
Cada paciente tiene una categoría de urgencia (roja, amarilla, verde) y un nombre.
El programa debe permitir al usuario realizar las siguientes operaciones: (2P)

a. Agregar un paciente a la cola de prioridad con su categoría de urgencia y nombre.
b. Atender al paciente con la mayor urgencia en la cola.
c. Mostrar la lista de pacientes en espera en orden de urgencia.
d. Salir del programa.

El programa debe garantizar que los pacientes con categoría de urgencia "roja"
se atiendan antes que los de categoría "amarilla" y "verde".
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PACIENTES 100

enum Urgencia {
    ROJA,
    AMARILLA,
    VERDE
};

struct Paciente {
    enum Urgencia urgencia;
    char nombre[256];
};

struct ColaPrioridad {
    struct Paciente pacientes[MAX_PACIENTES];
    int cantidad;
};

void inicializarCola(struct ColaPrioridad* cola);
void intercambiarPacientes(struct Paciente* a, struct Paciente* b);
void agregarPaciente(struct ColaPrioridad* cola, enum Urgencia urgencia, const char* nombre);
void mostrarCola(struct ColaPrioridad* cola);

struct Paciente atenderPaciente(struct ColaPrioridad* cola) {
    int indice;

    if (cola->cantidad == 0) {
        printf("\n\t No hay pacientes en espera para atender.\n");
        struct Paciente pacienteVacio = {VERDE, ""};
        return pacienteVacio;
    }

    struct Paciente pacienteAtendido;
    pacienteAtendido = cola->pacientes[0];

    cola->cantidad--;
    cola->pacientes[0] = cola->pacientes[cola->cantidad];

    indice = 0;
    while (1) {
        int indiceIzquierdo, indiceDerecho, indiceMayor;

        indiceIzquierdo = 2 * indice + 1;
        indiceDerecho = 2 * indice + 2;
        indiceMayor = indice;

        if (indiceIzquierdo < cola->cantidad && cola->pacientes[indiceIzquierdo].urgencia > cola->pacientes[indiceMayor].urgencia) {
            indiceMayor = indiceIzquierdo;
        }
        if (indiceDerecho < cola->cantidad && cola->pacientes[indiceDerecho].urgencia > cola->pacientes[indiceMayor].urgencia) {
            indiceMayor = indiceDerecho;
        }
        if (indiceMayor != indice) {
            intercambiarPacientes(&cola->pacientes[indice], &cola->pacientes[indiceMayor]);
            indice = indiceMayor;
        } else {
            break;
        }
    }

    printf("\n\t Paciente atendido: Urgencia %d, Nombre: %s\n", pacienteAtendido.urgencia, pacienteAtendido.nombre);

    return pacienteAtendido;
}


int main() {
    struct ColaPrioridad cola;
    int opcion,urgencia;

    inicializarCola(&cola);

    printf("\n\t +-----------------------------------------------------+");
    printf("\n\t |                      MENU                           |");
    printf("\n\t +-----------------------------------------------------+");
    printf("\n\t | 1. Agregar paciente                                 |");
    printf("\n\t | 2. Atender paciente con mayor urgencia              |");
    printf("\n\t | 3. Mostrar pacientes en espera                       |");
    printf("\n\t | 4. Salir                                            |");
    printf("\n\t +-----------------------------------------------------+");


    do {

        printf("\n\t -------------------------------------------------------");
        printf("\n\t OPCION: ");
        scanf("%d", &opcion);
        printf("\t -------------------------------------------------------");


        if ( opcion==1 ){
             char nombre[256];
            printf("\n\t            1. Agregar paciente                ");
            printf("\n\t Tipo de urgencia: ( 2:ROJA, 1:AMARILLA, 1:VERDE )");
            printf("\n\t Ingrese la urgencia( 0, 1 o 2): ");
            scanf("%d", &urgencia);
            printf("\t Nombre del paciente: ");
            scanf(" %[^\n]", nombre);
            agregarPaciente(&cola, (enum Urgencia)urgencia, nombre);

        } else if( opcion==2 ){
            atenderPaciente(&cola);


        } else if( opcion==3 ){
            mostrarCola(&cola);

        } else if( opcion==4 ){
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

void intercambiarPacientes(struct Paciente* a, struct Paciente* b) {
    struct Paciente aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void agregarPaciente(struct ColaPrioridad* cola, enum Urgencia urgencia, const char* nombre) {

    if (cola->cantidad >= MAX_PACIENTES) {
        printf("\n\t La cola de prioridad está llena. No se pueden agregar más pacientes.\n");
        return;
    }

    struct Paciente nuevoPaciente;
    nuevoPaciente.urgencia = urgencia;
    strncpy(nuevoPaciente.nombre, nombre, sizeof(nuevoPaciente.nombre) - 1);
    cola->pacientes[cola->cantidad] = nuevoPaciente;
    cola->cantidad++;

    int indice = cola->cantidad - 1;
    while (indice > 0) {
        int indicePadre;
        indicePadre = (indice - 1) / 2;
        if (cola->pacientes[indice].urgencia > cola->pacientes[indicePadre].urgencia) {
            intercambiarPacientes(&cola->pacientes[indice], &cola->pacientes[indicePadre]);
            indice = indicePadre;
        } else {
            break;
        }
    }
}

void mostrarCola(struct ColaPrioridad* cola) {
    int i;

    printf("\n\t Pacientes en espera en orden de urgencia:\n");
    for( i=0 ; i<cola->cantidad ; i++ ){
        printf("\n\t Urgencia %d, Nombre: %s\n", cola->pacientes[i].urgencia, cola->pacientes[i].nombre);
    }
}

