# include <stdio.h>
# include <stdlib.h>
# include <string.h>


// Defino la estructura para el nodo de la cola
struct NodoCola{
    char palabra[100];
    struct NodoCola *siguiente;
};


// Definicion del tipo de dato para la cola
typedef struct{
    struct NodoCola *frente;
    struct NodoCola *final;
} Cola;


// Funcion para crear un
a cola vacia
Cola *crear_cola(){
    Cola *cola;
    cola=(Cola*)malloc(sizeof(Cola));

    if( cola==NULL ){
        printf("ERROR... no se puede asignar memoria.\n");
        exit(1);
    }

    cola->frente = cola->final = NULL;
    return cola;
}


void encolar( Cola *cola, char palabra[] );// Función para encolar una palabra en la cola
void desencolar( Cola *cola );// Función para desencolar una palabra de la cola
void mostrar_en_orden_inverso( Cola *cola );// Función para mostrar la cola de palabras en orden inverso


// FUNCION PRINCIPAL DEL PROGRAMADOR
int main(){

    Cola *cola;
    cola = crear_cola();

    int opcion;
    char palabra[100];


    printf("\t+-----------------------------------------------------+\n");
    printf("\t|                        MENU                         |\n");
    printf("\t+-----------------------------------------------------+\n");
    printf("\t|  1. Agregar una palabra                             |\n");
    printf("\t|  2. Eliminar la palabra en la parte delantera       |\n");
    printf("\t|  3. Mostrar la cola de palabras en orden inverso    |\n");
    printf("\t|  4. Salir                                           |");

    while(1){
        printf("\n\t+-----------------------------------------------------+\nOPCION: ");
        scanf("%d",&opcion);

        switch(opcion){
            case 1:
                // Agregar una palabra a la cola
                printf("1. Ingrese una palabra: ");
                scanf("%s",palabra);
                encolar( cola,palabra );
                printf("Se agrego en la cola la palabra [%s]",palabra);
                break;

            case 2:
                // Eliminar la palabra en la parte delantera de la cola
                desencolar(cola);
                break;

            case 3:
                // Mostrar la cola de palabras en orden inverso
                mostrar_en_orden_inverso(cola);
                break;

            case 4:
                // Salir del programa y Liberar la memoria asignada a la cola
                while( cola->frente!=NULL ){
                    desencolar(cola);
                }
                free(cola);
                return 0;

            default:
                printf("ERROR... opcion no validad.");
                break;
        }
    }
    return 0;
}



// Función para encolar una palabra en la cola
void encolar( Cola *cola, char palabra[] ){
    struct NodoCola *nuevo_nodo;
    nuevo_nodo = (struct NodoCola *)malloc(sizeof(struct NodoCola));

    if( nuevo_nodo==NULL){
        printf("ERROR... no se pudo asignar a la memoria\n");
        exit(1);
    }

    strcpy( nuevo_nodo->palabra , palabra );
    nuevo_nodo->siguiente = NULL;

    if( cola->final==NULL ){
        cola->frente = cola->final = nuevo_nodo;
    } else {
        cola->final->siguiente = nuevo_nodo;
        cola->final = nuevo_nodo;
    }
}



// Función para desencolar una palabra de la cola
void desencolar( Cola *cola ){

    struct NodoCola *nodo_eliminado;

    if( cola->frente==NULL ){
        printf("La cola esta vacia\n");
        return;
    }

    nodo_eliminado = cola->frente;
    cola->frente = cola->frente->siguiente;

    free(nodo_eliminado);

    if( cola->frente==NULL ){
        cola->final = NULL;
    }
}


// Función para mostrar la cola de palabras en orden inverso
void mostrar_en_orden_inverso( Cola *cola ){
    struct NodoCola *nodo;
    nodo = cola->frente;

    char palabra[50][50];
    int contador, i;

    if( cola->frente==NULL ){
        printf("La cola esta vacia\n");
        return;
    }

    contador=0;
    while( nodo!=NULL ){
        strcpy( palabra[contador] , nodo->palabra );
        nodo = nodo->siguiente;
        contador++;
    }

    printf("3. Contenido de la cola inverso es:");
    for ( i=contador-1 ; i>=0 ; i-- ){
        printf("[%s] ",palabra[i]);
    }
    printf("\n");

}
