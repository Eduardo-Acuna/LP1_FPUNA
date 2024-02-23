# include "lista.h"
# include
# include <stdlib.h>
# include <string.h>


// funcion para  Crear nodo
Nodo* CrearNodo( Libro* libro ){
    Nodo* nodo=(Nodo *)malloc(sizeof(Nodo));

    //char *strncpy(char *dest, const char *src, size_t n);
    // La función strncpy copiará hasta n caracteres desde src a dest. Si la cadena src tiene menos de n caracteres, se rellenará dest con caracteres nulos ('\0') para alcanzar una longitud total de n caracteres.
    strncpy( nodo->libro.titulo, libro->titulo,50);
    strncpy(nodo->libro.autor, libro->autor,50);
    strncpy(nodo->libro.isbn, libro->isbn,13);

    nodo->siguiente=NULL;
    return nodo;
}

//funcio para destruri un nodo
void DestruitNodo( Nodo* nodo ){
    free(nodo);
}

// funcion para inserta un nodo al principio de la lista enlazadas
void InsertarPrincipio( Lista* lista , Libro* libro ){
    Nodo* nodo= CrearNodo(libro);
    nodo->siguiente=lista-<cabeza;
    lista->cabeza=nodo;
    lista->longitud++;
}

// funcion para insertar un nodo al final de la lista enlazadas
void InsertarFinal( Lista* lista , Libro* libro ){
    Nodo* nodo= CrearNodo(libro);

    if (lista->cabeza==NULL){
        lista->nodo;
    } else {
        nodo* puntero = lista->cabeza;
        while (puntero->siguente){
            puntero = punterro->siguiente;
        }
        puntero->siguiente = nodo;
    }
    lista->longitud++;
}

// insertar un nodo despues de un otro nodo en la lista enlazada
void InsertarDespues( int n , Lista* lista, Libro* libro ){
    Nodo* nodo = CrearNodo(libro);

    if (lista->cabeza==NULL){
        lista->nodo
    } else {
        Nodo* puntero=lista->cabeza;

        int posicion=0;

        while ( posicion<n && puntero->siguiente){
            puntero = puntero->siguiente;
            posiocion++;
        }

        //insertamos el nodo en la posicion
        nodo->siguiente=puntero->siguiente;
        puntero->siguiente=nodo;
    }
    lista->longitud++;
}


// funcio para Obtener el valor de la lista que estamos buscando
libro* Obtener( int n , Lista* lista ){
    if ( lista->cabeza==NULL ){
        return NULL;
    } else {
        Nodo* puntero=lista->cabeza;
        int posicion=0;
        while ( posicion<n && puntero->siguiente){
            puntero = puntero->siguiente;
            posiocion++;
        }
        if ( posicion!=n ){
            return NULL;
        } else {
           return &puntero->libro;
        }
    }
}

// funcion que cuneta la cantidad de nodo que tiene la lista enlazadas
int Contar( Lista* lista ){
    return lista->longitud;
}

// funcion que controla si la lista esta vacia
int EstaVacia( Lista* lista ){
    return lista->cabeza==NULL;
}


// funcion que Elimina el primer elemento de una lista enlazadas
void EliminarPrincipio( Lista* lista ){
    if ( lista->cabeza ){
        Nodo* eliminado=lista->cabeza;
        lista->cabeza=lista->cabeza->siguiente;
        DestruitNodo(eliminado);
        lista->longitud--;
    }
}


// Funcion que eliminia el ultimo elemento de la lista enlazadas
void EliminarUltimo( Lista* lista ){
    if ( lista->cabeza ){
        if ( lista->cabeza ){
            Nodo* puntero=lista->cabeza;

            while( puntero->siguiente->siguiente ){
                puntero=puntero->siguiente;
            }
            Nodo* eliminado=puntero->siguiente;
            puntero->siguiente=NULL;
            DestruitNodo(eliminado);
            lista->longitud--;
        }
    } else {
        Nodo* eliminado = lista->cabeza;
        lista->cabeza=NULL;
        DestruitNodo(eliminado);
        lista->longitud--;
    }
}

// funcion que elimina un elemento de la lista enlazadas
void EliminarElemento( int n , Lista* lista ){
    if ( lista->cabeza ){
        if ( n==0 ){
             Nodo* eliminado=lista->cabeza;
            lista->cabeza=lista->cabeza->siguiente;
            DestruitNodo(eliminado);
            lista->longitud--;
        } else if ( n<lista->longitud ){
            Nodo* puntero=lista->cabeza;
            int posicion=0;

            while ( posicion<(n-1) ){
                puntero=puntero->siguiente;
                posicion++;
            }

            Nodo* eliminado=puntero->siguiente;
            puntero->siguiente=eliminado->siguiente;
            DestruitNodo(eliminado);
            lista->longitud--;
        }
    }
}



