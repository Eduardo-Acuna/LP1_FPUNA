#include <stdio.h>
#include <stdlib.h>

// Definici�n de la estructura del Nodo
typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;

// Funci�n para crear un nuevo nodo
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

// Funci�n para agregar un nodo al final de la lista
void agregarNodo(Nodo** cabeza, int valor) {
    Nodo* nuevo = crearNodo(valor);
    if (*cabeza == NULL) {
        *cabeza = nuevo;
    } else {
        Nodo* actual = *cabeza;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
    }
}

// Funci�n para eliminar un nodo con un valor espec�fico
void eliminarNodo(Nodo** cabeza, int valor) {
    Nodo* temp;
    Nodo* anterior = NULL;
    Nodo* actual = *cabeza;

    while (actual != NULL && actual->dato != valor) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == NULL) {
        printf("El valor %d no se encontr� en la lista.\n", valor);
        return;
    }

    if (anterior == NULL) {
        *cabeza = actual->siguiente;
    } else {
        anterior->siguiente = actual->siguiente;
    }

    free(actual);
}

// Funci�n para imprimir la lista
void imprimirLista(Nodo* cabeza) {
    Nodo* actual = cabeza;
    while (actual != NULL) {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

// Funci�n principal
int main() {
    Nodo* cabeza = NULL;
    int opcion;
    int valor;

    while (1) {
        printf("\nMen�:\n");
        printf("1. Agregar nodo\n");
        printf("2. Eliminar nodo\n");
        printf("3. Imprimir lista\n");
        printf("4. Salir\n");
        printf("Seleccione una opci�n: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese el valor a agregar: ");
                scanf("%d", &valor);
                agregarNodo(&cabeza, valor);
                break;
            case 2:
                printf("Ingrese el valor a eliminar: ");
                scanf("%d", &valor);
                eliminarNodo(&cabeza, valor);
                break;
            case 3:
                printf("Lista actual: ");
                imprimirLista(cabeza);
                break;
            case 4:
                // Liberar memoria antes de salir
                while (cabeza != NULL) {
                    Nodo* temp = cabeza;
                    cabeza = cabeza->siguiente;
                    free(temp);
                }
                exit(0);
            default:
                printf("Opci�n no v�lida. Por favor, seleccione una opci�n v�lida.\n");
        }
    }

    return 0;
}
