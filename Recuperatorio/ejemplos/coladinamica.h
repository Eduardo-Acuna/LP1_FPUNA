struct nodo{
    TipoDato elemento;
    struct nodo *siguiente;
}typedef struct nodo NODO;



struct cola{
    NODO *frente;
    NODO *final;
}typedef struct cola COLA;


void crearCola( COLA *cola );
void insertarCola( COLA *cola, TipoDato elemento );

TipoDato quitarCola( COLA *cola);

void borrarCola( COLA *cola );


int frenteCola( COLA cola );
int colaVacia( COLA pila);


/*Crea una cola nueva*/
void crearCola( COLA *cola ){
    cola -> frente = cola -> final = NULL;
}

/* Verifica si la cola está vacia */
int colaVacia( COLA cola ){
    return ( cola.frente == NULL );
}

/* Insertar en la cola */
void insertarCola( COLA *cola, TipoDato entrada ){
    NODO *aux;
    aux = crearNodo( entrada );

    if( colaVacia( *cola )){
        cola -> frente = aux;
    } else {
        cola -> final -> siguiente = aux;
    }

    cola -> final = aux;
}

/* Quitar de la cola*/
TipoDato quitarCola( COLA *cola ){
    TipoDato temp;

    if( !colaVacio( *cola )){
        NODO *aux;
        aux = cola -> frente;
        temp = cola -> frente -> elemento;
        cola -> frente = cola -> frente -> siguiente;
        free(aux)
    } else {
        puts("Coal Vacia");
        exit(1);
    }

    return temp;
}

/* Eliminar toda la Cola*/
void borrarCola( COLA *cola ){
    for( ;cola -> frente != NULL ; ){
        NODO *aux;
        aux = cola -> frente;
        cola -> frente = cola -> frente - siguiente;
        free( aux );
    }
}






