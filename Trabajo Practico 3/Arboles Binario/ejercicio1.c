/*
EJEJRCICIO 1:
Dise�a un programa en lenguaje C que cree un �rbol binario b�sico y permitaal usuario realizar las siguientes operaciones: (1P)
a. Agregar un nodo al �rbol.
b. Realizar un recorrido en orden (in-order) del �rbol.
c. Mostrar la altura del �rbol.
d. Salir del programa.
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Definici�n de la estructura de un nodo de �rbol binario
struct nodo {
  int info;
  struct nodo *izq;
  struct nodo *der;
};

// Funci�n para crear un nuevo nodo de �rbol binario
struct nodo *crear_nodo(int info) {
  struct nodo *nuevo = malloc(sizeof(struct nodo));
  nuevo->info = info;
  nuevo->izq = NULL;
  nuevo->der = NULL;
  return nuevo;
}

// Funci�n para agregar un nodo al �rbol binario
void agregar_nodo(struct nodo **raiz, int info) {
    // Si el �rbol est� vac�o, creamos el nodo ra�z
    if (*raiz == NULL) {
    *raiz = crear_nodo(info);
    return;
    }

    // Si el valor del nodo a agregar es menor que el valor del nodo ra�z, lo agregamos al sub�rbol izquierdo
    if (info < (*raiz)->info) {
        agregar_nodo(&(*raiz)->izq, info);
    } else {
    // Si el valor del nodo a agregar es mayor o igual que el valor del nodo ra�z, lo agregamos al sub�rbol derecho
        agregar_nodo(&(*raiz)->der, info);
    }
}

// Funci�n para realizar un recorrido en orden del �rbol binario
void recorrer_en_orden(struct nodo *raiz) {
  // Si el �rbol est� vac�o, no hacemos nada
  if (raiz == NULL) {
    return;
  }

  // Recorremos el sub�rbol izquierdo
  recorrer_en_orden(raiz->izq);

  // Imprimimos el valor del nodo actual
  printf("%d ", raiz->info);

  // Recorremos el sub�rbol derecho
  recorrer_en_orden(raiz->der);
}

// Funci�n para calcular la altura del �rbol binario
int calcular_altura(struct nodo *raiz) {
  // Si el �rbol est� vac�o, la altura es 0
  if (raiz == NULL) {
    return 0;
  }

  // La altura del �rbol es la mayor de la altura del sub�rbol izquierdo y la altura del sub�rbol derecho
  return 1 + fmax(calcular_altura(raiz->izq), calcular_altura(raiz->der));
}

// Funci�n principal
int main() {
  // Declaramos la ra�z del �rbol
  struct nodo *raiz = NULL;
  int info;


  // Bucle para permitir al usuario realizar operaciones sobre el �rbol
  while (1) {
    // Imprimimos el men� de opciones
    printf("1. Agregar nodo\n2. Recorrer en orden\n3. Mostrar altura\n4. Salir\n");

    // Obtenemos la opci�n del usuario
    int opcion;
    scanf("%d", &opcion);

    // Realizamos la operaci�n seleccionada por el usuario
    switch (opcion) {
      case 1:
        // Solicitamos el valor del nuevo nodo

        printf("Ingrese el valor del nuevo nodo: ");
        scanf("%d", &info);

        // Agregamos el nuevo nodo al �rbol
        agregar_nodo(&raiz, info);
        break;
      case 2:
        // Recorremos el �rbol en orden
        recorrer_en_orden(raiz);
        printf("\n");
        break;
      case 3:
        // Imprimimos la altura del �rbol
        printf("La altura del �rbol es: %d\n", calcular_altura(raiz));
        break;
      case 4:
        // Salimos del programa
        return 0;
      default:
        printf("Opci�n no v�lida.\n");
        break;
    }
  }

  return 0;
}

