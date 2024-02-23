#include <stdio.h>
#include <stdlib.h>

struct nodo {
    int dato;
    struct nodo* siguiente;
};

struct nodo* crear_nodo(int dato) {
    struct nodo* nuevo = malloc(sizeof(struct nodo));
    nuevo->dato = dato;
    nuevo->siguiente = NULL;
    return nuevo;
}

void insertar_principio(struct nodo** lista, int dato) {
    struct nodo* nuevo = crear_nodo(dato);
    nuevo->siguiente = *lista;
    *lista = nuevo;
}

void insertar_final(struct nodo** lista, int dato) {
    struct nodo* nuevo = crear_nodo(dato);
    if (*lista == NULL) {
        *lista = nuevo;
        return;
    }

    struct nodo* iterador = *lista;
    while (iterador->siguiente != NULL) {
        iterador = iterador->siguiente;
    }
    iterador->siguiente = nuevo;
}

struct nodo* buscar_nodo(struct nodo* lista, int dato) {
    struct nodo* iterador = lista;
    while (iterador != NULL && iterador->dato != dato) {
        iterador = iterador->siguiente;
    }

    return iterador;
}

void insertar_en_posicion(struct nodo** lista, int dato, int posicion) {
    if (posicion == 1) {
        insertar_principio(lista, dato);
        return;
    }

    struct nodo* nuevo = crear_nodo(dato);
    struct nodo* iterador = *lista;
    for (int i = 2; i <= posicion && iterador != NULL; i++) {
        iterador = iterador->siguiente;
    }

    if (iterador == NULL) {
        printf("La posición %d es mayor a la longitud de la lista.\n", posicion);
        return;
    }

    nuevo->siguiente = iterador->siguiente;
    iterador->siguiente = nuevo;
}

void cambiar_dato(struct nodo* nodo, int nuevo_dato) {
    nodo->dato = nuevo_dato;
}

void imprimir_lista(struct nodo* lista) {
    while (lista != NULL) {
        printf("%d ", lista->dato);
        lista = lista->siguiente;
    }
    printf("\n");
}

int main() {
    struct nodo* lista = NULL;

    int opcion;
    do {
        printf("** Menú de listas enlazadas **\n\n");
        printf("1. Insertar al principio\n");
        printf("2. Insertar al final\n");
        printf("3. Buscar\n");
        printf("4. Insertar en cualquier posición\n");
        printf("5. Cambiar\n");
        printf("6. Imprimir\n");
        printf("7. Salir\n");
        printf("\nIngrese una opción: ");
        scanf("%d", &opcion);

        int dato;  // Variable compartida por varios casos
        struct nodo* nodo;

        switch (opcion) {
            case 1:
                printf("Ingrese el dato a insertar: ");
                scanf("%d", &dato);
                insertar_principio(&lista, dato);
                break;
            case 2:
                printf("Ingrese el dato a insertar: ");
                scanf("%d", &dato);
                insertar_final(&lista, dato);
                break;
            case 3:
                printf("Ingrese el dato a buscar: ");
                scanf("%d", &dato);
                nodo = buscar_nodo(lista, dato);
                if (nodo != NULL) {
                    printf("El nodo con el dato %d fue encontrado.\n", dato);
                } else {
                    printf("El nodo con el dato %d no fue encontrado.\n", dato);
                }
                break;
            case 4:
                printf("Ingrese el dato a insertar: ");
                scanf("%d", &dato);
                printf("Ingrese la posición para insertar: ");
                int posicion;
                scanf("%d", &posicion);
                insertar_en_posicion(&lista, dato, posicion);
                break;
            case 5:
                printf("Ingrese el dato del nodo a cambiar: ");
                scanf("%d", &dato);
                nodo = buscar_nodo(lista, dato);
                if (nodo != NULL) {
                    printf("Ingrese el nuevo dato para el nodo: ");
                    int nuevo_dato;
                    scanf("%d", &nuevo_dato);
                    cambiar_dato(nodo, nuevo_dato);
                    printf("El dato del nodo fue cambiado a %d.\n", nuevo_dato);
                } else {
                    printf("El nodo con el dato %d no fue encontrado.\n", dato);
                }
                break;
            case 6:
                imprimir_lista(lista);
                break;
            case 7:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción inválida.\n");
        }
    } while (opcion != 7);

    return 0;
}
