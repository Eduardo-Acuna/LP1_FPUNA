/*
EJERCICIO 2.
Crea un programa en lenguaje C que permita al usuario realizar un recorrido
preorden de un árbol binario existente. El programa debe mostrar los valores
de los nodos en el orden correcto y luego salir. (1P)
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definición de la estructura de un nodo de árbol binario
struct nodo {
    int dato;
    struct nodo *izq;
    struct nodo *der;
};

// Función para crear un nuevo nodo de árbol binario
struct nodo *crear_nodo( int dato ){
    struct nodo *nuevo ;
    nuevo = malloc(sizeof(struct nodo));

    nuevo->dato = dato;
    nuevo->izq = NULL;
    nuevo->der = NULL;

    return nuevo;
}

void agregar_nodo( struct nodo **arbol , int dato );
void recorrer_preorden( struct nodo *arbol );

int main() {
    struct nodo *arbol;
    arbol=NULL;

    int valores[100];
    int contador, valor, i;

    // Generamos valores aleatorios y los almacenamos en el vector
    contador = 0;
    srand(time(NULL));
    printf("Los valores generados: ");
    for( i=0 ; i<7 ; i++ ){
        valor = rand() % 100;
        printf("%d ",valor);
        valores[contador] = valor;
        contador++;
    }

    // Cargamos los valores del vector en el árbol binario
    for( i=0 ; i<contador ; i++ ){
        agregar_nodo(&arbol, valores[i]);
    }

    // Realizamos un recorrido preorden del árbol
    printf("\nRecorrido preorden del arbol binario es: [ ");
    recorrer_preorden(arbol);
    printf("]\n");

    return 0;
}



// Función para agregar un nodo al árbol binario
void agregar_nodo( struct nodo **arbol , int dato ){
    if( *arbol==NULL ){
        *arbol = crear_nodo(dato);
        return;
     }

    // Si el valor del nodo a agregar es menor que el valor del nodo raíz, lo agregamos al subárbol izquierdo
    if ( dato<(*arbol)->dato ) {
        agregar_nodo(&(*arbol)->izq, dato);
    } else {
        agregar_nodo(&(*arbol)->der, dato);
    }
}


// Función para realizar un recorrido preorden del árbol binario
void recorrer_preorden( struct nodo *arbol ){

    if ( arbol==NULL ){
        return;
    }

    printf("%d ", arbol->dato); // Se imprime el valor del nodo actual
    recorrer_preorden(arbol->izq);// Recorremos el subárbol izquierdo
    recorrer_preorden(arbol->der); // Recorremos el subárbol derecho
}

