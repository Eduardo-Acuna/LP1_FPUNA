#include <stdio.h>
#include <stdlib.h>

// Estructura de un nodo de lista enlazada
typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;

// Función para crear un nuevo nodo
Nodo* crearNodo(int valor) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevoNodo == NULL) {
        printf("Error: No se pudo asignar memoria para el nuevo nodo.\n");
        exit(1);
    }
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

// Función para agregar un valor a la lista
void agregarValor(Nodo** cabeza, int valor) {
    Nodo* nuevoNodo = crearNodo(valor);
    nuevoNodo->siguiente = *cabeza;
    *cabeza = nuevoNodo;
    printf("Valor %d agregado a la lista.\n", valor);
}

// Función para eliminar un valor de la lista
void eliminarValor(Nodo** cabeza, int valor) {
    Nodo* actual = *cabeza;
    Nodo* anterior = NULL;

    while (actual != NULL && actual->dato != valor) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == NULL) {
        printf("Valor %d no encontrado en la lista.\n", valor);
        return;
    }

    if (anterior == NULL) {
        *cabeza = actual->siguiente;
    } else {
        anterior->siguiente = actual->siguiente;
    }

    free(actual);
    printf("Valor %d eliminado de la lista.\n", valor);
}

// Función para mostrar la lista de valores
void mostrarValores(Nodo* cabeza) {
    if (cabeza == NULL) {
        printf("La lista está vacía.\n");
        return;
    }

    printf("Lista de valores: ");
    while (cabeza != NULL) {
        printf("%d -> ", cabeza->dato);
        cabeza = cabeza->siguiente;
    }
    printf("NULL\n");
}

// Función para liberar la memoria de la lista
void liberarLista(Nodo* cabeza) {
    while (cabeza != NULL) {
        Nodo* temp = cabeza;
        cabeza = cabeza->siguiente;
        free(temp);
    }
}

int main() {
    Nodo* cabeza = NULL;
    int opcion, valor;

    while (1) {
        printf("\nMenú:\n");
        printf("1. Agregar valor\n");
        printf("2. Eliminar valor\n");
        printf("3. Mostrar valores\n");
        printf("4. Salir\n");
        printf("Elija una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese el valor a agregar: ");
                scanf("%d", &valor);
                agregarValor(&cabeza, valor);
                break;
            case 2:
                printf("Ingrese el valor a eliminar: ");
                scanf("%d", &valor);
                eliminarValor(&cabeza, valor);
                break;
            case 3:
                mostrarValores(cabeza);
                break;
            case 4:
                liberarLista(cabeza);
                exit(0);
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }
    }

    return 0;
}
