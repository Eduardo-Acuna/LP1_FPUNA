/*
EJERCICIO 1.
Dise�a un programa en lenguaje C que cree un �rbol binario b�sico y permita al usuario realizar las siguientes operaciones: (1P)
a. Agregar un nodo al �rbol.
b. Realizar un recorrido en orden (in-order) del �rbol.
c. Mostrar la altura del �rbol.
d. Salir del programa.
*/

# include <stdio.h>
# include <stdlib.h>
# include <math.h>

// Definimos la estryctura del arbol binario
struct nodo{
    int dato;
    struct nodo *izq;
    struct nodo *der;
};

// Funci�n para crear un nuevo nodo de �rbol binario
struct nodo *crear_nodo(int dato){
    struct nodo *nuevo;
    nuevo=malloc(sizeof(struct nodo));

    nuevo->dato=dato;
    nuevo->izq=NULL;
    nuevo->der=NULL;

    return nuevo;
}

// Constructor de las funciones
void agregar_nodo( struct nodo **arbol, int dato);
void recorrer_en_orden(struct nodo *arbol);
int calcular_altura( struct nodo * arbol );
int maximo(int a, int b);

// Funcion del programa principal
int main(){
    struct nodo *arbol;
    arbol=NULL;

    int opcion,valor,altura;

    printf("\n+------------------------------------------------------------------+");
    printf("\n|\t                      MENU                                 |");
    printf("\n+------------------------------------------------------------------+");
    printf("\n|\t 1. Agregar un nodo al arbol.                              |");
    printf("\n|\t 2. Realizar un recorrido en orden (in-order) del arbol.   |");
    printf("\n|\t 3. Mostrar la altura del arbol.                           |");
    printf("\n|\t 4. Salir del programa.                                    |");
    printf("\n+------------------------------------------------------------------+");

    while (1){
        printf("\n--------------------------------------------------------------------");
        printf("\nOPCION: ");
        scanf("%d",&opcion);

        switch(opcion){
            case 1:
                printf("\n\t 1. Agregar un nodo al arbol: ");
                scanf("%d",&valor);
                agregar_nodo(&arbol,valor);
                break;

            case 2:
                printf("\n\t 2. Recorrido del Arbol\n");
                recorrer_en_orden(arbol);
                break;
            case 3:
                printf("\n\t 3. Mostrar la altura del arbol");
                altura=calcular_altura(arbol);
                printf("\nLa altura del arbol es: %d", altura);
                break;

            case 4:
                printf("\nFin del programa...");
                return 0;

            default:
                printf("\nError... opcion no valida.");
                break;
        }
    }
    return 0;
}

// Funci�n para agregar un nodo al �rbol binario
void agregar_nodo( struct nodo **arbol, int dato){

    if( *arbol==NULL ){
        *arbol=crear_nodo(dato);
        return;
    }

    if( dato<(*arbol)->dato){
        agregar_nodo(&( *arbol)->izq , dato );
    } else {
        agregar_nodo(&( *arbol)->der , dato );
    }
}

// Funci�n para realizar un recorrido en orden del �rbol binario
void recorrer_en_orden( struct nodo *arbol ){

    if( arbol==NULL){
        return;
    }

    recorrer_en_orden(arbol->izq);
    printf("%d, ",arbol->dato);
    recorrer_en_orden(arbol->der);
}


// Funci�n para calcular la altura del �rbol binario
int calcular_altura( struct nodo * arbol ){
    int resultado;

    if( arbol==NULL){
        return 0;
    }

    resultado=1+maximo( calcular_altura(arbol->izq) , calcular_altura(arbol->der));

    return resultado;
}


// Funci�n auxiliar para calcular el m�ximo de dos n�meros
int maximo(int a, int b) {
    int resultado;

    if (a > b) {
        resultado = a;
    } else {
        resultado = b;
    }

    return  resultado;
}




