/*
EJEJRCICIO 1:
Diseña un programa en lenguaje C que cree un árbol binario básico y permitaal usuario realizar las siguientes operaciones: (1P)
a. Agregar un nodo al árbol.
b. Realizar un recorrido en orden (in-order) del árbol.
c. Mostrar la altura del árbol.
d. Salir del programa.
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Definición de la estructura de un nodo de árbol binario
struct nodo {
  int info;
  struct nodo *izq;
  struct nodo *der;
};

// Función para crear un nuevo nodo de árbol binario
struct nodo *crear_nodo(int info) {
  struct nodo *nuevo = malloc(sizeof(struct nodo));
  nuevo->info = info;
  nuevo->izq = NULL;
  nuevo->der = NULL;
  return nuevo;
}

// Función para agregar un nodo al árbol binario
void agregar_nodo(struct nodo **raiz, int info) {
    // Si el árbol está vacío, creamos el nodo raíz
    if (*raiz == NULL) {
    *raiz = crear_nodo(info);
    return;
    }

    // Si el valor del nodo a agregar es menor que el valor del nodo raíz, lo agregamos al subárbol izquierdo
    if (info < (*raiz)->info) {
        agregar_nodo(&(*raiz)->izq, info);
    } else {
    // Si el valor del nodo a agregar es mayor o igual que el valor del nodo raíz, lo agregamos al subárbol derecho
        agregar_nodo(&(*raiz)->der, info);
    }
}

// Función para realizar un recorrido en orden del árbol binario
void recorrer_en_orden(struct nodo *raiz) {
  // Si el árbol está vacío, no hacemos nada
  if (raiz == NULL) {
    return;
  }

  // Recorremos el subárbol izquierdo
  recorrer_en_orden(raiz->izq);

  // Imprimimos el valor del nodo actual
  printf("%d ", raiz->info);

  // Recorremos el subárbol derecho
  recorrer_en_orden(raiz->der);
}

// Función para calcular la altura del árbol binario
int calcular_altura(struct nodo *raiz) {
  // Si el árbol está vacío, la altura es 0
  if (raiz == NULL) {
    return 0;
  }

  // La altura del árbol es la mayor de la altura del subárbol izquierdo y la altura del subárbol derecho
  return 1 + fmax(calcular_altura(raiz->izq), calcular_altura(raiz->der));
}

// Función principal
int main() {
  // Declaramos la raíz del árbol
  struct nodo *raiz = NULL;
  int info;


  // Bucle para permitir al usuario realizar operaciones sobre el árbol
  while (1) {
    // Imprimimos el menú de opciones
    printf("1. Agregar nodo\n2. Recorrer en orden\n3. Mostrar altura\n4. Salir\n");

    // Obtenemos la opción del usuario
    int opcion;
    scanf("%d", &opcion);

    // Realizamos la operación seleccionada por el usuario
    switch (opcion) {
      case 1:
        // Solicitamos el valor del nuevo nodo

        printf("Ingrese el valor del nuevo nodo: ");
        scanf("%d", &info);

        // Agregamos el nuevo nodo al árbol
        agregar_nodo(&raiz, info);
        break;
      case 2:
        // Recorremos el árbol en orden
        recorrer_en_orden(raiz);
        printf("\n");
        break;
      case 3:
        // Imprimimos la altura del árbol
        printf("La altura del árbol es: %d\n", calcular_altura(raiz));
        break;
      case 4:
        // Salimos del programa
        return 0;
      default:
        printf("Opción no válida.\n");
        break;
    }
  }

  return 0;
}

