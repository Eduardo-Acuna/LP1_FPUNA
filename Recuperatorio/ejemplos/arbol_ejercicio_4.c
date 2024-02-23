/*
EJERCICIO 4
Diseña un programa en lenguaje C que permita al usuario realizar un recorrido
postorden de un árbol binario existente. El programa debe mostrar los valores
de los nodos en el orden correcto y luego salir. (1P)
*/

# include <stdio.h>
# include <stdlib.h>

// Definición de la estructura de un nodo de árbol binario
struct nodo{
    int dato;
    struct nodo *izq;
    struct nodo *der;
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
void recorrer_postorden( struct nodo *arbol );


int main() {

    struct nodo *arbol ;
    arbol = NULL;;

    int cantidad, valor, i;

    printf("Ingrese la cantidad de nodos del arbol: ");
    scanf("%d", &cantidad);

    for ( i=0 ; i<cantidad ; i++ ){
        printf("Ingrese el valor del nodo %d: ", i + 1);
        scanf("%d", &valor);
        agregar_nodo(&arbol, valor);
    }

    // Realizamos un recorrido postorden del árbol
    printf("Postorden del arbol: ");
    recorrer_postorden(arbol);
    printf("\n");

    return 0;
}


// Función para agregar un nodo al árbol binario
void agregar_nodo( struct nodo **arbol , int dato ){

    if( *arbol==NULL ){
        *arbol = crear_nodo( dato );
        return;
    }

    if( dato<(*arbol)->dato ){  // Si el valor del nodo a agregar es menor que el valor del nodo raíz, lo agregamos al subárbol izquierdo
        agregar_nodo( &(*arbol)->izq , dato );
    } else { // Si el valor del nodo a agregar es mayor o igual que el valor del nodo raíz, lo agregamos al subárbol derecho
        agregar_nodo( &(*arbol)->der , dato );
    }
}


// Función para realizar un recorrido postorden del árbol binario
void recorrer_postorden( struct nodo *arbol ){

    if ( arbol==NULL ){
        return;
    }

    recorrer_postorden(arbol->izq); // Recorremos el subárbol izquierdo
    recorrer_postorden(arbol->der);  // Recorremos el subárbol derecho
    printf("%d ", arbol->dato);  // Imprimimos el valor del nodo actual
}



