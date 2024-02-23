/*
EJERCICIO 3.
Dise�a un programa en lenguaje C que utilice una cola para almacenar
n�meros primos. El programa debe permitir al usuario realizar las
siguientes operaciones: (1P)
a. Agregar un n�mero primo a la cola.
b. Eliminar el n�mero primo en la parte delantera de la cola.
c. Mostrar la cantidad total de n�meros primos en la cola.
El programa debe verificar que los n�meros ingresados sean primos y, en
caso contrario, rechazarlos. Puedes utilizar una funci�n para verificar si
un n�mero es primo.
*/

#include <stdio.h>
#include <stdlib.h>

// Definici�n de la estructura para el nodo de la cola
struct NodoCola {
    int dato;
    struct NodoCola *siguiente;
};

// Definici�n del tipo de dato para la cola
typedef struct {
    struct NodoCola *frente;
    struct NodoCola *final;
} Cola;




// Funci�n para crear una cola vac�a
Cola *crear_cola() {
    Cola *cola;
    cola = (Cola *)malloc(sizeof(Cola));

    if (cola == NULL) {
        printf("\n\t Error: No se pudo asignar memoria para la cola.\n");
        exit(1);
    }

    cola->frente = cola->final = NULL;
    return cola;
}

int es_primo(int numero);
void encolar(Cola *cola, int dato);
int desencolar(Cola *cola);
int cantidad_elementos(Cola *cola);


int main() {

    Cola *cola = crear_cola();
    int numero, opcion, numero_eliminado,cantidad;

    printf("\n\t +-----------------------------------------------------+");
    printf("\n\t |                      MENU                           |");
    printf("\n\t +-----------------------------------------------------+");
    printf("\n\t | 1. Agregar numero primos                            |");
    printf("\n\t | 2. Eliminar numero primos                           |");
    printf("\n\t | 3. Mostrar cantidad de numeros primos               |");
    printf("\n\t | 4. Salir                                            |");
    printf("\n\t +-----------------------------------------------------+\n");

    while (1) {
        printf("\t -------------------------------------------------------");
        printf("\n\t OPCION: ");
        scanf("%d", &opcion);
        printf("\t -------------------------------------------------------");
        switch (opcion) {
            case 1:
                // Agregar un n�mero primo a la cola
                printf("\n\t Ingrese un numero: ");
                scanf("%d", &numero);
                if (es_primo(numero)) {
                    encolar(cola, numero);
                } else {
                    printf("\n\t El numero ingresado no es primo.\n");
                }
                break;
            case 2:
                // Eliminar un n�mero primo de la cola
                numero_eliminado = desencolar(cola);
                if (numero_eliminado > 0) {
                  printf("\n\t Se elimino el numero primo %d.\n", numero_eliminado);
                } else {
                  printf("\n\t La cola esta vacia o no contiene numeros primos.\n");
                }
                break;
            case 3:
                // Mostrar la cantidad de n�meros primos en la cola
                cantidad = cantidad_elementos(cola);
                printf("\n\t Hay %d numeros primos\n", cantidad);
                break;
            case 4:
                // Salir del programa
                while (cola->frente != NULL) {
                  desencolar(cola);
                }
                free(cola);
                return 0;
            default:
                printf("\n\t Opcion no valida.\n");
                break;
        }
    }
    return 0;
}


// Funci�n para verificar si un n�mero es primo
int es_primo(int numero) {
    if (numero <= 1) {
        return 0;
    }

    if (numero <= 3) {
        return 1;
    }

    if (numero % 2 == 0 || numero % 3 == 0) {
        return 0;
    }

    for (int i = 5; i * i <= numero; i += 6) {
        if (numero % i == 0 || numero % (i + 2) == 0) {
            return 0;
        }
    }

    return 1;
}

// Funci�n para encolar un n�mero primo en la cola
void encolar(Cola *cola, int dato) {
    if (es_primo(dato)) {
        struct NodoCola *nuevo_nodo;
        nuevo_nodo = (struct NodoCola *)malloc(sizeof(struct NodoCola));

        nuevo_nodo->dato = dato;
        nuevo_nodo->siguiente = NULL;

        if (cola->final == NULL) {
            cola->frente = cola->final = nuevo_nodo;
        } else {
            cola->final->siguiente = nuevo_nodo;
            cola->final = nuevo_nodo;
        }
    } else {
        printf("\n\t El n�mero ingresado no es primo. No se agreg� a la cola.\n");
    }
}

// Funci�n para desencolar un n�mero primo de la cola
int desencolar(Cola *cola) {
    int numero;

    if (cola->frente == NULL) {
        return -1;
    }

    numero = cola->frente->dato;
    struct NodoCola *nodo_eliminado;
    nodo_eliminado = cola->frente;
    cola->frente = cola->frente->siguiente;

    free(nodo_eliminado);

    if (cola->frente == NULL) {
        cola->final = NULL;
    }

    return numero;
}

// Funci�n para contar la cantidad de elementos en la cola
int cantidad_elementos(Cola *cola) {
    int cantidad;
    cantidad = 0;

    struct NodoCola *nodo;
    nodo = cola->frente;

    while (nodo != NULL) {
        cantidad++;
        nodo = nodo->siguiente;
    }

    return cantidad;
}

