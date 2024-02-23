#include <stdio.h>
#include <stdlib.h>

// Estructura para representar a un estudiante
struct Estudiante {
    char nombre[50];
    int edad;
};

// Estructura para el nodo de la pila
struct Nodo {
    struct Estudiante estudiante;
    struct Nodo* siguiente;
};

// Funci�n para crear un nuevo nodo de la pila
struct Nodo* crearNodo(struct Estudiante estudiante) {
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->estudiante = estudiante;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

// Funci�n para insertar un estudiante en la pila
void push(struct Nodo** pila, struct Estudiante estudiante) {
    struct Nodo* nuevoNodo = crearNodo(estudiante);
    nuevoNodo->siguiente = *pila;
    *pila = nuevoNodo;
    printf("Estudiante %s agregado a la pila.\n", estudiante.nombre);
}

// Funci�n para eliminar un estudiante de la pila
struct Estudiante pop(struct Nodo** pila) {
    if (*pila == NULL) {
        struct Estudiante estudianteVacia;
        estudianteVacia.edad = -1;
        return estudianteVacia;
    }

    struct Nodo* nodoAEliminar = *pila;
    *pila = nodoAEliminar->siguiente;
    struct Estudiante estudianteEliminado = nodoAEliminar->estudiante;
    free(nodoAEliminar);
    return estudianteEliminado;
}

// Funci�n para imprimir la informaci�n de un estudiante
void imprimirEstudiante(struct Estudiante estudiante) {
    printf("Nombre: %s\nEdad: %d\n", estudiante.nombre, estudiante.edad);
}

int main() {
    struct Nodo* pila = NULL;
    int opcion;

    do {
        printf("\n** Men� de Estudiantes **\n");
        printf("1. Agregar Estudiante\n");
        printf("2. Eliminar Estudiante\n");
        printf("3. Salir\n");
        printf("Ingrese una opci�n: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: {
                struct Estudiante nuevoEstudiante;
                printf("Ingrese el nombre del estudiante: ");
                scanf("%s", nuevoEstudiante.nombre);
                printf("Ingrese la edad del estudiante: ");
                scanf("%d", &nuevoEstudiante.edad);
                push(&pila, nuevoEstudiante);
                break;
            }
            case 2: {
                struct Estudiante estudianteEliminado = pop(&pila);
                if (estudianteEliminado.edad != -1) {
                    printf("Estudiante eliminado de la pila:\n");
                    imprimirEstudiante(estudianteEliminado);
                } else {
                    printf("La pila est� vac�a.\n");
                }
                break;
            }
            case 3:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opci�n inv�lida.\n");
        }
    } while (opcion != 3);

    // Liberar memoria de la pila
    while (pila != NULL) {
        struct Estudiante estudiante = pop(&pila);
        // Aqu� podr�as realizar alguna acci�n adicional si es necesario
    }

    return 0;
}
