/*
EJERCICIO 5
Crea un programa en lenguaje C que realice un recorrido por niveles (nivel por
nivel) de un árbol binario. El programa debe mostrar los valores de los nodos
en el orden correcto y luego salir. (1P)
*/

#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura de un nodo de árbol binario
struct nodo{
    int dato;
    struct nodo *izq;
    struct nodo *der;
};

// Definición de la estructura de un nodo en una cola
struct cola_nodo {
    struct nodo *nodo;
    struct cola_nodo *siguiente;
};

// Función para crear un nuevo nodo de árbol binario
struct nodo *crear_nodo(int dato) {
    struct nodo *nuevo;
    nuevo = malloc(sizeof(struct nodo));

    nuevo->dato = dato;
    nuevo->izq = NULL;
    nuevo->der = NULL;

    return nuevo;
}

void agregar_nodo( struct nodo **arbol , int dato );
void encolar(struct cola_nodo **cola, struct nodo *nodo);
struct nodo *desencolar(struct cola_nodo **cola);
void recorrer_por_niveles(struct nodo *arbol);


int main() {
    struct nodo *arbol;
    arbol = NULL;

    int cantidad, valor,i ;

    printf("Ingrese la cantidad de nodo del arbol: ");
    scanf("%d", &cantidad);

    for ( i=0 ; i<cantidad ; i++ ){
        printf("Ingrese el valor del nodo %d: ", i + 1);
        scanf("%d", &valor);
        agregar_nodo(&arbol, valor);
    }

    // Realizamos un recorrido por niveles del árbol
    printf("Recorrido por niveles del arbol: ");
    recorrer_por_niveles(arbol);
    printf("\n");

    return 0;
}


// Función para agregar un nodo al árbol binario
void agregar_nodo( struct nodo **arbol , int dato ){

    if( *arbol==NULL ){
        *arbol = crear_nodo( dato );
        return;
    }

    if( dato<(*arbol)->dato ){
        agregar_nodo( &(*arbol)->izq , dato );
    } else {
        agregar_nodo( &(*arbol)->der , dato );
    }
}

// Función para encolar un nodo en la cola
void encolar(struct cola_nodo **cola, struct nodo *nodo) {
    struct cola_nodo *nuevo;
    nuevo = malloc(sizeof(struct cola_nodo));

    nuevo->nodo = nodo;
    nuevo->siguiente = NULL;

    if (*cola == NULL) {
        *cola = nuevo;
    } else {
        struct cola_nodo *aux;
        aux = *cola;
        while( aux->siguiente!=NULL ){
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
    }
}

// Función para desencolar un nodo de la cola
struct nodo *desencolar(struct cola_nodo **cola) {
    if (*cola == NULL) {
        return NULL;
    }

    struct cola_nodo *aux;
    aux = *cola;
    *cola = aux->siguiente;

    struct nodo *nodo;
    nodo = aux->nodo;
    free(aux);

    return nodo;
}

// Función para realizar un recorrido por niveles del árbol binario
void recorrer_por_niveles(struct nodo *arbol) {
    if( arbol==NULL ){
        return;
    }

    struct cola_nodo *cola;
    cola = NULL;
    encolar(&cola, arbol);

    while( cola!=NULL ){
        struct nodo *nodo_actual;
        nodo_actual = desencolar(&cola);
        printf("%d, ", nodo_actual->dato);

        if( nodo_actual->izq!=NULL ){
            encolar(&cola, nodo_actual->izq);
        }

        if( nodo_actual->der!=NULL ){
            encolar(&cola, nodo_actual->der);
        }
    }
}

