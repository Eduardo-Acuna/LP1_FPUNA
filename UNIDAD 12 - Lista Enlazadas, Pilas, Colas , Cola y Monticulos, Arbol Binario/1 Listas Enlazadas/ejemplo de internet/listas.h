# ifndef lista_h
# define lista_h

# include <stdio.h>
# include "lista.h"

typedef struct Nodo{
    Libro libro;
    struct Nodo* siguiente;


} Nodo;

typedef struct Lista{
    Nodo* cabeza;
    int longitud;
};




Nodo* CrearNodo( Libro* libro );
void DestruitNodo( Nodo* nodo );
void InsertarPrincipio( Lista* lista , Libro* libro );
void InsertarFinal( Lista* lista , Libro* libro );
void InsertarDespues( int n , Lista* lista, Libro* libro );
libro* Obtener( int n , Lista* lista );
int Contar( Lista* lista );
int EstaVacia( Lista* lista );
void EliminarUltimo( Lista* lista );
void EliminarElemento( int n , Lista* lista );


# endif // lista_h





