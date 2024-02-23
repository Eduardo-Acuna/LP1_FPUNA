#include <stdio.h>
#include <stdlib.h>

// Estructura de un nodo de la cola
typedef struct NodoCola {
    int dato;
    struct NodoCola* siguiente;
} NodoCola;

// Estructura de la cola
typedef struct {
    NodoCola* frente;
    NodoCola* final;
} Cola;

// Función para crear una cola vacía
Cola* crearCola() {
    Cola* cola = (Cola*)malloc(sizeof(Cola));
    if (cola == NULL) {
        printf("Error: No se pudo asignar memoria para la cola.\n");
        exit(1);
    }
    cola->frente = cola->final = NULL;
    return cola;
}

// Función para verificar si la cola está vacía
int colaVacia(Cola* cola) {
    return cola->frente == NULL;
}

// Función para insertar un elemento en la cola (al final)
void encolar(Cola* cola, int elemento) {
    NodoCola* nuevoNodo = (NodoCola*)malloc(sizeof(NodoCola));
    if (nuevoNodo == NULL) {
        printf("Error: No se pudo asignar memoria para el nuevo nodo.\n");
        exit(1);
    }
    nuevoNodo->dato = elemento;
    nuevoNodo->siguiente = NULL;
    if (cola->final == NULL) {
        cola->frente = cola->final = nuevoNodo;
    } else {
        cola->final->siguiente = nuevoNodo;
        cola->final = nuevoNodo;
    }
    printf("Elemento %d encolado en la cola.\n", elemento);
}

// Función para quitar un elemento de la cola (del frente)
int desencolar(Cola* cola) {
    if (colaVacia(cola)) {
        printf("La cola está vacía. No se puede desencolar.\n");
        return -1; // Valor especial para indicar error
    }
    NodoCola* nodoAQuitar = cola->frente;
    int elemento = nodoAQuitar->dato;
    cola->frente = nodoAQuitar->siguiente;
    if (cola->frente == NULL) {
        cola->final = NULL;
    }
    free(nodoAQuitar);
    return elemento;
}

// Función para poner un elemento en frente de la cola
void ponerEnFrente(Cola* cola, int elemento) {
    NodoCola* nuevoNodo = (NodoCola*)malloc(sizeof(NodoCola));
    if (nuevoNodo == NULL) {
        printf("Error: No se pudo asignar memoria para el nuevo nodo.\n");
        exit(1);
    }
    nuevoNodo->dato = elemento;
    nuevoNodo->siguiente = cola->frente;
    cola->frente = nuevoNodo;
    if (cola->final == NULL) {
        cola->final = nuevoNodo;
    }
    printf("Elemento %d colocado en frente de la cola.\n", elemento);
}

// Función para imprimir la cola
void imprimirCola(Cola* cola) {
    if (colaVacia(cola)) {
        printf("La cola está vacía.\n");
        return;
    }
    NodoCola* actual = cola->frente;
    printf("Cola:\n");
    while (actual != NULL) {
        printf("%d\n", actual->dato);
        actual = actual->siguiente;
    }
}

// Función para borrar la cola y liberar memoria
void borrarCola(Cola* cola) {
    while (!colaVacia(cola)) {
        desencolar(cola);
    }
    free(cola);
    printf("La cola ha sido borrada.\n");
}

int main() {
    Cola* cola = NULL;
    int opcion, elemento;

    while (1) {
        printf("\nMenú:\n");
        printf("1. Crear una cola\n");
        printf("2. Verificar si la cola está vacía\n");
        printf("3. Encolar elemento\n");
        printf("4. Desencolar elemento\n");
        printf("5. Poner elemento en frente de la cola\n");
        printf("6. Imprimir la cola\n");
        printf("7. Borrar la cola\n");
        printf("8. Salir\n");
        printf("Elija una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                if (cola == NULL) {
                    cola = crearCola();
                    printf("Se ha creado una cola.\n");
                } else {
                    printf("La cola ya ha sido creada.\n");
                }
                break;
            case 2:
                if (colaVacia(cola)) {
                    printf("La cola está vacía.\n");
                } else {
                    printf("La cola no está vacía.\n");
                }
                break;
            case 3:
                if (cola == NULL) {
                    printf("Primero debe crear una cola.\n");
                } else {
                    printf("Ingrese el elemento a encolar: ");
                    scanf("%d", &elemento);
                    encolar(cola, elemento);
                }
                break;
            case 4:
                if (cola == NULL) {
                    printf("Primero debe crear una cola.\n");
                } else {
                    elemento = desencolar(cola);
                    if (elemento != -1) {
                        printf("Elemento %d ha sido desencolado de la cola.\n", elemento);
                    }
                }
                break;
            case 5:
                if (cola == NULL) {
                    printf("Primero debe crear una cola.\n");
                } else {
                    printf("Ingrese el elemento a poner en frente de la cola: ");
                    scanf("%d", &elemento);
                    ponerEnFrente(cola, elemento);
                }
                break;
            case 6:
                if (cola == NULL) {
                    printf("Primero debe crear una cola.\n");
                } else {
                    imprimirCola(cola);
                }
                break;
            case 7:
                if (cola == NULL) {
                    printf("Primero debe crear una cola.\n");
                } else {
                    borrarCola(cola);
                    cola = NULL;
                }
                break;
            case 8:
                if (cola != NULL) {
                    borrarCola(cola); // Liberar la memoria antes de salir
                }
                exit(0);
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }
    }

    return 0;
}
