#include <stdio.h>
#include <stdlib.h>

// Estructura de un nodo de lista enlazada
struct nodo {
  int dato;
  struct nodo *siguiente;
};

// Estructura para la pila
struct pila {
  struct nodo *tope;
};

// Función para crear una nueva pila
struct pila *crear_pila() {
  struct pila *pila = (struct pila *)malloc(sizeof(struct pila));
  pila->tope = NULL;
  return pila;
}

// Función para insertar un nodo en la pila






// Función para eliminar un nodo de la pila
struct nodo *eliminar_pila(struct pila *pila) {
  if (pila->tope == NULL) {
    return NULL;
  }

  struct nodo *nodo = pila->tope;
  pila->tope = nodo->siguiente;
  return nodo;
}

// Función para imprimir una lista enlazada
void imprimir_pila(struct pila *pila) {
  struct nodo *iterador = pila->tope;
  while (iterador != NULL) {
    printf("%d ", iterador->dato);
    iterador = iterador->siguiente;
  }
  printf("\n");
}

// Función principal
int main() {
  // Creación de una pila
  struct pila *pila = crear_pila();

  // Menú
  int opcion;
  do {
    printf("** Menú de pilas **\n\n");
    printf("1. Insertar\n");
    printf("2. Eliminar\n");
    printf("3. Imprimir\n");
    printf("4. Salir\n");
    printf("\nIngrese una opción: ");
    scanf("%d", &opcion);

    switch (opcion) {
      case 1:
        printf("Ingrese el dato a insertar: ");
        int dato;
        scanf("%d", &dato);
        struct nodo *nodo = (struct nodo *)malloc(sizeof(struct nodo));
        nodo->dato = dato;
        nodo->siguiente = NULL;
        insertar_pila(pila, nodo);
        break;
      case 2:
        struct nodo *nodo_eliminado = eliminar_pila(pila);
        if (nodo_eliminado != NULL) {
          printf("El nodo eliminado tiene el dato %d.\n", nodo_eliminado->dato);
          free(nodo_eliminado);
        }
        break;
      case 3:
        imprimir_pila(pila);
        break;
      case 4:
        printf("Saliendo...\n");
        break;
      default:
        printf("Opción inválida.\n");
    }
  } while (opcion != 4);

  return 0;
}
