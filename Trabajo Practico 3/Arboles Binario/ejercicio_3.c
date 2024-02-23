/*
EJERCICIO 3.
Crea un programa en lenguaje C que cuente y muestre la cantidad de nodos
hoja (nodos sin hijos) en un �rbol binario dado. (1P)
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definici�n de la estructura de un nodo de �rbol binario
struct nodo{
    int dato;
    struct nodo *izq;
    struct nodo *der;
};

// Funci�n para crear un nuevo nodo de �rbol binario
struct nodo *crear_nodo(int dato) {
    struct nodo *nuevo;
    nuevo = malloc(sizeof(struct nodo));

    nuevo->dato = dato;
    nuevo->izq = NULL;
    nuevo->der = NULL;

    return nuevo;
}

void agregar_nodo( struct nodo **arbol , int dato );
void recorrer_preorden( struct nodo *arbol );
void recorrer_en_orden( struct nodo *arbol );
int contar_nodos_hoja( struct nodo *arbol );

// Funcion principal del progrma
int main() {
    // Declaramos el �rbol binario
    struct nodo *arbol;
    arbol = NULL;;

    int cantidad, valor,nodos_hoja, i;
    srand(time(NULL));

    // Solicitamos al usuario la cantidad de valores aleatorios a generar y cargar en el �rbol
    printf("Ingrese la cantidad de valores aleatorios a generar y cargar en el arbol: ");
    scanf("%d", &cantidad);

      // Generamos valores aleatorios y los almacenamos en el �rbol
    for( i=0 ; i<cantidad ; i++ ){
        valor = rand() % 100; // Generar valores entre 0 y 99
        agregar_nodo( &arbol , valor );
    }

    // Recorrido en orden del �rbol
    printf("Recorrido en orden del arbol: ");
    recorrer_en_orden(arbol);
    printf("\n");

    // Recorrido preorden del arbol
    printf("Recorrido preorden del arbol: ");
    recorrer_preorden(arbol);
    printf("\n");

    // Contamos y mostramos la cantidad de nodos hoja
    nodos_hoja = contar_nodos_hoja(arbol);
    printf("\nCantidad de nodos hoja en el arbol: %d\n", nodos_hoja);

    return 0;
}


// Funci�n para agregar un nodo al �rbol binario
void agregar_nodo( struct nodo **arbol , int dato ){

    if( *arbol==NULL ){
        *arbol = crear_nodo( dato );
        return;
    }

    if( dato<(*arbol)->dato ){  // Si el valor del nodo a agregar es menor que el valor del nodo ra�z, lo agregamos al sub�rbol izquierdo
        agregar_nodo( &(*arbol)->izq , dato );
    } else { // Si el valor del nodo a agregar es mayor o igual que el valor del nodo ra�z, lo agregamos al sub�rbol derecho
        agregar_nodo( &(*arbol)->der , dato );
    }
}

// Funci�n para realizar un recorrido preorden del �rbol binario
void recorrer_preorden( struct nodo *arbol ){

    if (arbol == NULL) {
        return;
    }

    printf("%d ", arbol->dato); // Imprimimos el valor del nodo actual
    recorrer_preorden(arbol->izq); // Recorremos el sub�rbol izquierdo
    recorrer_preorden(arbol->der); // Recorremos el sub�rbol derecho
}


// Funci�n para realizar un recorrido en orden del �rbol binario
void recorrer_en_orden( struct nodo *arbol ){

    if( arbol==NULL ){
        return;
    }

    recorrer_en_orden(arbol->izq); // Recorremos el sub�rbol izquierdo
    printf("%d ", arbol->dato); // Imprimimos el valor del nodo actual
    recorrer_en_orden(arbol->der); // Recorremos el sub�rbol derecho
}


// Funci�n para contar la cantidad de nodos hoja en el �rbol binario
int contar_nodos_hoja( struct nodo *arbol ){
    int contador;

    if( arbol==NULL ){
        return 0;
    }

    if( arbol->izq==NULL && arbol->der==NULL ){
        return 1;
    }

    contador = contar_nodos_hoja(arbol->izq) + contar_nodos_hoja(arbol->der);

    return contador;
}



