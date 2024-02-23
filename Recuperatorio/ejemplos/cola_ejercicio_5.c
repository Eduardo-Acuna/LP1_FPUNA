/*
EJERCICIO 5.
Crea un programa en C que utilice una cola para almacenar palabras
ingresadas por el usuario en orden inverso. El programa debe permitir al
usuario realizar las siguientes operaciones: (1P)
a. Agregar una palabra a la cola.
b. Eliminar la palabra en la parte delantera de la cola.
c. Mostrar la cola de palabras en orden inverso.
d. Salir del programa.
El programa debe permitir al usuario agregar palabras y mostrarlas en el
orden inverso en el que se ingresaron.

Ejemplo:
Ingrese una palabra: Manzana
Palabra "Manzana" agregada a la cola.
Ingrese una palabra: Banana
Palabra "Banana" agregada a la cola.
Contenido de la cola de palabras en orden inverso:
Banana Manzana
Palabra "Banana" eliminada de la cola.
Contenido de la cola de palabras en orden inverso:
Manzana
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de la estructura para el nodo de la cola
struct NodoCola {
    char palabra[50];
    struct NodoCola *siguiente;
};

// Definición del tipo de dato para la cola
typedef struct {
    struct NodoCola *frente;
    struct NodoCola *final;
} Cola;

// Función para crear una cola vacía
Cola *crear_cola() {
    Cola *cola;
    cola = (Cola *)malloc(sizeof(Cola));

    if (cola == NULL) {
        printf("Error: No se pudo asignar memoria para la cola.\n");
        exit(1);
    }

    cola->frente = cola->final = NULL;

    return cola;
}

void encolar(Cola *cola, char palabra[]);
void desencolar(Cola *cola);
void mostrar_en_orden_inverso(Cola *cola);

int main(){
    Cola *cola = crear_cola();
    int opcion;
    char palabra[50];

    printf("\n\t +-----------------------------------------------------+");
    printf("\n\t |                      MENU                           |");
    printf("\n\t +-----------------------------------------------------+");
    printf("\n\t | 1. Agregar una palabra                              |");
    printf("\n\t | 2. Eliminar la palabra en la parte delantera        |");
    printf("\n\t | 3. Mostrar la cola de palabras en orden inverso.    |");
    printf("\n\t | 4. Salir                                            |");
    printf("\n\t +-----------------------------------------------------+\n");

    while (1){
        printf("\t -------------------------------------------------------");
        printf("\n\t OPCION: ");
        scanf("%d", &opcion);
        printf("\t -------------------------------------------------------");

        switch (opcion) {
            case 1:
                printf("\n\t Ingrese una palabra: ");
                scanf("%s", palabra);
                encolar(cola, palabra);
                printf("\t Palabra \"%s\" agregada a la cola.\n", palabra);
                break;
            case 2:
                desencolar(cola);
                printf("\n");
                break;
            case 3:
                mostrar_en_orden_inverso(cola);
                break;
            case 4:
                while (cola->frente != NULL) {
                    desencolar(cola);
                }
                free(cola);
                return 0;
            default:
                printf("\n\t Opción no válida.\n");
                break;
            }
      }
}




// Función para encolar una palabra en la cola
void encolar(Cola *cola, char palabra[]){
    struct NodoCola *nuevo_nodo;
    nuevo_nodo = (struct NodoCola *)malloc(sizeof(struct NodoCola));

    if( nuevo_nodo==NULL ){
        printf("\n\t Error: No se pudo asignar memoria para el nodo de la cola.\n");
        exit(1);
    }

    strcpy(nuevo_nodo->palabra, palabra);
    nuevo_nodo->siguiente = NULL;

    if( cola->final==NULL ){
        cola->frente = cola->final = nuevo_nodo;
    } else {
        cola->final->siguiente = nuevo_nodo;
        cola->final = nuevo_nodo;
    }
}


// Función para desencolar una palabra de la cola
void desencolar(Cola *cola){
    if( cola->frente==NULL ){
        printf("\n\t La cola esta vacia.\n");
        return;
    }

    struct NodoCola *nodo_eliminado;
    nodo_eliminado = cola->frente;

    cola->frente = cola->frente->siguiente;
    free(nodo_eliminado);

    if( cola->frente==NULL ){
        cola->final = NULL;
    }
}

// Función para mostrar la cola de palabras en orden inverso
void mostrar_en_orden_inverso(Cola *cola){
    char palabras[50][50];
    int contador = 0;

    if( cola->frente==NULL ){
        printf("\n\t La cola esta vacia.\n");
        return;
    }

    struct NodoCola *nodo;
    nodo = cola->frente;

    while (nodo != NULL) {
        strcpy(palabras[contador], nodo->palabra);
        nodo = nodo->siguiente;
        contador++;
    }

    printf("\n\t Contenido de la cola de palabras en orden inverso:\n\t ");
    for (int i = contador - 1; i >= 0; i--) {
        printf("%s ", palabras[i]);
    }
    printf("\n");
}
