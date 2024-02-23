/*
4. Diseña y desarrolla un programa en lenguaje C que utilice una cola para
almacenar números impares. El programa debe permitir al usuario realizar
las siguientes operaciones:

a. Agregar un número impar a la cola.
b. Eliminar el número impar en la parte delantera de la cola.
c. Mostrar la cantidad total de números impares en la cola.
d. Salir del programa.

El programa debe verificar que los números ingresados sean impares y,
en caso contrario, rechazarlos.
e. Implementa una función adicional para verificar si un número es
impar o par. El programa debe funcionar de la siguiente manera:
- Cuando se agrega un nuevo número, se debe verificar que sea impar. Si no lo es, se debe mostrar un mensaje de error.
- Al eliminar un número, se debe mostrar el número eliminado.
- Mostrar la cantidad total de números impares en la cola en cualquier momento.

*/


#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura para el nodo de la cola
struct NodoCola{
    int dato;
    struct NodoCola *siguiente;
};

// Definición del tipo de dato para la cola
typedef struct{
    struct NodoCola *frente;
    struct NodoCola *final;
} Cola;

// Función para crear una cola vacía
Cola *crear_cola() {
    Cola *cola;
    cola = (Cola *)malloc(sizeof(Cola));

    if( cola==NULL ){
        printf("\n\t Error: No se pudo asignar memoria para la cola.\n");
        exit(1);
    }

    cola->frente = cola->final = NULL;
    return cola;
}

int es_impar(int numero) ;
void encolar(Cola *cola, int dato);
int desencolar(Cola *cola);
int cantidad_impares(Cola *cola);

int main() {
    Cola *cola = crear_cola();

    int numero,numero_eliminado,cantidad,opcion;


    printf("\n\t +-----------------------------------------------------+");
    printf("\n\t |                      MENU                           |");
    printf("\n\t +-----------------------------------------------------+");
    printf("\n\t | 1. Agregar numero impar                             |");
    printf("\n\t | 2. Eliminar numero impar                            |");
    printf("\n\t | 3. Mostrar cantidad de numeros impares              |");
    printf("\n\t | 4. Salir                                            |");
    printf("\n\t +-----------------------------------------------------+\n");

    while (1) {
        printf("\t -------------------------------------------------------");
        printf("\n\t OPCION: ");
        scanf("%d", &opcion);
        printf("\t -------------------------------------------------------");


        switch (opcion) {
            case 1:
                // Agregar un número impar a la cola

                printf("\n\t Ingrese un numero: ");
                scanf("%d", &numero);
                encolar(cola, numero);
                break;
            case 2:
                // Eliminar un número impar de la cola
                numero_eliminado = desencolar(cola);
                if (numero_eliminado > 0) {
                  printf("\n\t Se elimino el numero impar %d.\n", numero_eliminado);
                } else {
                  printf("\n\t La cola esta vacia o no contiene numeros impares.\n");
                }
                break;
            case 3:
                // Mostrar la cantidad de números impares en la cola
                cantidad = cantidad_impares(cola);
                printf("\n\t Hay %d numeros impares.\n", cantidad);
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


// Función para verificar si un número es impar
int es_impar(int numero) {
    int resultado;
    resultado = numero % 2 != 0;
    return resultado;
}



// Función para encolar un número impar en la cola
void encolar(Cola *cola, int dato) {

    if( es_impar(dato) ){
        struct NodoCola *nuevo_nodo;
        nuevo_nodo = (struct NodoCola *)malloc(sizeof(struct NodoCola));

        nuevo_nodo->dato = dato;
        nuevo_nodo->siguiente = NULL;

        if( cola->final == NULL ){
            cola->frente = cola->final = nuevo_nodo;
        } else {
            cola->final->siguiente = nuevo_nodo;
            cola->final = nuevo_nodo;
        }
    } else {
        printf("\n\t El numero ingresado no es impar.\n");
    }
}

// Función para desencolar un número impar de la cola
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

// Función para contar la cantidad de elementos impares en la cola
int cantidad_impares(Cola *cola) {
    int cantidad;
    cantidad = 0;

    struct NodoCola *nodo;
    nodo = cola->frente;

    while( nodo!=NULL ){
        if( es_impar(nodo->dato) ){
            cantidad++;
        }
        nodo = nodo->siguiente;
    }
    return cantidad;
}

