/*
EJERCICIO 2
Dise�a un programa en lenguaje C que utilice una cola para almacenar
n�meros pares. El programa debe permitir al usuario realizar las
siguientes operaciones:

a. Agregar un n�mero par a la cola.
b. Eliminar el n�mero par en la parte delantera de la cola.
c. Mostrar la cantidad total de n�meros pares en la cola.
d. El programa debe verificar que los n�meros ingresados sean pares y, en caso contrario, rechazarlos.

*/


#include <stdio.h>
#include <stdlib.h>

// Definici�n de la estructura para la cola
struct cola {
    int dato;
    struct cola *siguiente;
};

// Funci�n para crear una cola vac�a
struct cola *crear_cola() {
    return NULL;
}

int es_par(int numero) ;
void encolar(struct cola **cola, int dato);
int desencolar(struct cola **cola) ;
int cantidad_elementos(struct cola *cola);

int main() {
    struct cola *cola = crear_cola();
    int numero, numero_eliminado,cantidad, opcion;;


    printf("\n\t +-----------------------------------------------------+");
    printf("\n\t |                      MENU                           |");
    printf("\n\t +-----------------------------------------------------+");
    printf("\n\t | 1. Agregar numero par                               |");
    printf("\n\t | 2. Eliminar numero par                              |");
    printf("\n\t | 3. Mostrar cantidad de numeros pares                |");
    printf("\n\t | 4. Salir                                            |");
    printf("\n\t +-----------------------------------------------------+\n");

    while (1) {
        printf("\t -------------------------------------------------------");
        printf("\n\t OPCION: ");
        scanf("%d", &opcion);
        printf("\t -------------------------------------------------------");
        switch (opcion) {
            case 1:
                // Agregar un n�mero par a la cola
                printf("\n\t Ingrese un numero par: ");
                scanf("%d", &numero);
                if (es_par(numero)) {
                  encolar(&cola, numero);
                } else {
                  printf("\t El numero ingresado no es par.\n");
                }
                break;
            case 2:
                // Eliminar un n�mero par de la cola
                numero_eliminado = desencolar(&cola);
                if (numero_eliminado > 0) {
                    printf("\n\t Se elimino el numero par: %d.\n", numero_eliminado);
                } else {
                    printf("\n\t La cola esta vacia.\n");
                }
                break;
            case 3:
                // Mostrar la cantidad de n�meros pares en la cola
                cantidad = cantidad_elementos(cola);
                printf("\n\t Hay %d numeros pares en la cola.\n", cantidad);
                break;
            case 4:
                while (cola != NULL) {
                    desencolar(&cola);
                }
                return 0;
            default:
                printf("Opcion no valida.\n");
                break;
        }
    }
    return 0;
}


// Funci�n para verificar si un n�mero es par
int es_par(int numero) {
    return numero % 2 == 0;
}


// Funci�n para encolar un n�mero en la cola
void encolar(struct cola **cola, int dato) {
    struct cola *nuevo_nodo;
    nuevo_nodo = malloc(sizeof(struct cola));

    nuevo_nodo->dato = dato;
    nuevo_nodo->siguiente = NULL;

    // Agregar el nuevo nodo al final de la cola
    if (*cola == NULL) {
        *cola = nuevo_nodo;
    } else {
        struct cola *ultimo_nodo;
        ultimo_nodo = *cola;
        while (ultimo_nodo->siguiente != NULL) {
            ultimo_nodo = ultimo_nodo->siguiente;
        }
        ultimo_nodo->siguiente = nuevo_nodo;
    }
}


// Funci�n para desencolar un n�mero de la cola
int desencolar(struct cola **cola) {
    int numero;

    if (*cola == NULL) {
        return -1;
    }

    // Obtener el n�mero a desencolar
    numero = (*cola)->dato;

    // Eliminar el nodo de la cola
    struct cola *nodo_eliminado;
    nodo_eliminado = *cola;
    *cola = (*cola)->siguiente;

    free(nodo_eliminado);

    return numero;
}


// Funci�n para contar la cantidad de elementos en la cola
int cantidad_elementos(struct cola *cola) {
    int cantidad;
    if (cola == NULL) {
        return 0;
    }

    cantidad = 1;
    struct cola *nodo;
    nodo = cola;

    while (nodo->siguiente != NULL) {
        cantidad++;
        nodo = nodo->siguiente;
    }

    return cantidad;
}

