#include <stdio.h>
#include <stdlib.h>

// Estructura para el nodo de la pila
typedef struct NodoPila {
    int dato;
    struct NodoPila *siguiente;
} NodoPila;

// Estructura de la pila
typedef struct {
    NodoPila *cima;
} Pila;

// Función para crear una pila vacía
Pila* crearPila() {
    Pila *pila = (Pila*)malloc(sizeof(Pila));
    if (pila == NULL) {
        printf("Error: No se pudo asignar memoria para la pila.\n");
        exit(1);
    }
    pila->cima = NULL;
    return pila;
}

// Función para verificar si la pila está vacía
int estaVacia(Pila* pila) {
    return pila->cima == NULL;
}

// Función para verificar si la pila está llena (en una pila enlazada, generalmente no se llena)
int estaLlena(Pila* pila) {
    return 0;
}

// Función para insertar un elemento en la pila
void push(Pila* pila, int elemento) {
    NodoPila* nuevoNodo = (NodoPila*)malloc(sizeof(NodoPila));
    if (nuevoNodo == NULL) {
        printf("Error: No se pudo asignar memoria para el nuevo nodo.\n");
        exit(1);
    }
    nuevoNodo->dato = elemento;
    nuevoNodo->siguiente = pila->cima;
    pila->cima = nuevoNodo;
    printf("Elemento %d insertado en la pila.\n", elemento);
}

// Función para quitar un elemento de la pila (pop)
int pop(Pila* pila) {
    if (estaVacia(pila)) {
        printf("La pila está vacía. No se puede quitar un elemento.\n");
        return -1; // Valor especial para indicar error
    }

    NodoPila* nodoAQuitar = pila->cima;
    int elemento = nodoAQuitar->dato;
    pila->cima = nodoAQuitar->siguiente;
    free(nodoAQuitar);
    return elemento;
}

// Función para mostrar la cima de la pila
void mostrarCima(Pila* pila) {
    if (estaVacia(pila)) {
        printf("La pila está vacía. No hay elementos en la cima.\n");
    } else {
        printf("Cima de la pila: %d\n", pila->cima->dato);
    }
}

// Función para imprimir la pila
void imprimirPila(Pila* pila) {
    if (estaVacia(pila)) {
        printf("La pila está vacía.\n");
        return;
    }

    printf("Pila:\n");
    NodoPila* actual = pila->cima;
    while (actual != NULL) {
        printf("%d\n", actual->dato);
        actual = actual->siguiente;
    }
}

// Función para eliminar todos los elementos de la pila
void vaciarPila(Pila* pila) {
    while (!estaVacia(pila)) {
        pop(pila);
    }
    printf("La pila ha sido vaciada.\n");
}

int main() {
    Pila* pila = NULL;
    int opcion, elemento;

    while (1) {
        printf("\nMenú:\n");
        printf("1. Crear una pila\n");
        printf("2. Verificar si la pila está vacía\n");
        printf("3. Insertar elemento en la pila\n");
        printf("4. Quitar elemento de la pila\n");
        printf("5. Mostrar la cima de la pila\n");
        printf("6. Imprimir la pila\n");
        printf("7. Vaciar la pila\n");
        printf("8. Salir\n");
        printf("Elija una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                if (pila == NULL) {
                    pila = crearPila();
                    printf("Se ha creado una pila.\n");
                } else {
                    printf("La pila ya ha sido creada.\n");
                }
                break;
            case 2:
                if (estaVacia(pila)) {
                    printf("La pila está vacía.\n");
                } else {
                    printf("La pila no está vacía.\n");
                }
                break;
            case 3:
                if (pila == NULL) {
                    printf("Primero debe crear una pila.\n");
                } else {
                    printf("Ingrese el elemento a insertar: ");
                    scanf("%d", &elemento);
                    push(pila, elemento);
                }
                break;
            case 4:
                if (pila == NULL) {
                    printf("Primero debe crear una pila.\n");
                } else {
                    elemento = pop(pila);
                    if (elemento != -1) {
                        printf("Elemento %d ha sido quitado de la pila.\n", elemento);
                    }
                }
                break;
            case 5:
                if (pila == NULL) {
                    printf("Primero debe crear una pila.\n");
                } else {
                    mostrarCima(pila);
                }
                break;
            case 6:
                if (pila == NULL) {
                    printf("Primero debe crear una pila.\n");
                } else {
                    imprimirPila(pila);
                }
                break;
            case 7:
                if (pila == NULL) {
                    printf("Primero debe crear una pila.\n");
                } else {
                    vaciarPila(pila);
                }
                break;
            case 8:
                if (pila != NULL) {
                    vaciarPila(pila); // Liberar la memoria antes de salir
                }
                exit(0);
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }
    }

    return 0;
}

