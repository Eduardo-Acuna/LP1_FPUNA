#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMEROS 100

struct Monticulo {
    int numeros[MAX_NUMEROS];
    int cantidad;
};

void inicializarMonticulo(struct Monticulo* monticulo) {
    monticulo->cantidad = 0;
}

void agregarNumero(struct Monticulo* monticulo, int numero) {
    if (monticulo->cantidad >= MAX_NUMEROS) {
        printf("El mont�culo est� lleno. No se puede agregar m�s n�meros.\n");
        return;
    }

    int indice = monticulo->cantidad;
    monticulo->numeros[indice] = numero;
    monticulo->cantidad++;

    while (indice > 0) {
        int indicePadre = (indice - 1) / 2;
        if (monticulo->numeros[indice] > monticulo->numeros[indicePadre]) {
            // Intercambiar el n�mero con su padre
            int temp = monticulo->numeros[indice];
            monticulo->numeros[indice] = monticulo->numeros[indicePadre];
            monticulo->numeros[indicePadre] = temp;
            indice = indicePadre;
        } else {
            break;
        }
    }
}

int eliminarMaximo(struct Monticulo* monticulo) {
    if (monticulo->cantidad == 0) {
        printf("El mont�culo est� vac�o. No se puede eliminar ning�n n�mero.\n");
        return -1;
    }

    int maximo = monticulo->numeros[0];

    // Mover el �ltimo n�mero al principio
    monticulo->numeros[0] = monticulo->numeros[monticulo->cantidad - 1];
    monticulo->cantidad--;

    int indice = 0;
    while (2 * indice + 1 < monticulo->cantidad) {
        int indiceHijoIzquierdo = 2 * indice + 1;
        int indiceHijoDerecho = 2 * indice + 2;
        int indiceMayor = indiceHijoIzquierdo;

        if (indiceHijoDerecho < monticulo->cantidad && monticulo->numeros[indiceHijoDerecho] > monticulo->numeros[indiceMayor]) {
            indiceMayor = indiceHijoDerecho;
        }

        if (monticulo->numeros[indiceMayor] > monticulo->numeros[indice]) {
            // Intercambiar el n�mero con su hijo
            int temp = monticulo->numeros[indice];
            monticulo->numeros[indice] = monticulo->numeros[indiceMayor];
            monticulo->numeros[indiceMayor] = temp;
            indice = indiceMayor;
        } else {
            break;
        }
    }

    return maximo;
}

void mostrarArreglo(int arreglo[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arreglo[i]);
    }
    printf("\n");
}

int main() {
    struct Monticulo monticulo;
    int arreglo[MAX_NUMEROS];
    int n, opcion, numero;

    inicializarMonticulo(&monticulo);

    do {
        printf("1. Ingresar arreglo de n�meros\n2. Ordenar el arreglo con mont�culo\n3. Mostrar arreglo ordenado\n4. Salir\n");
        printf("Ingrese una opci�n: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese la cantidad de n�meros (no m�s de %d): ", MAX_NUMEROS);
                scanf("%d", &n);
                printf("Ingrese los n�meros uno por uno:\n");
                for (int i = 0; i < n; i++) {
                    scanf("%d", &arreglo[i]);
                }
                break;

            case 2:
                for (int i = 0; i < n; i++) {
                    agregarNumero(&monticulo, arreglo[i]);
                }
                printf("El arreglo ha sido ordenado con mont�culo.\n");
                break;

            case 3:
                printf("Arreglo ordenado: ");
                while (monticulo.cantidad > 0) {
                    int maximo = eliminarMaximo(&monticulo);
                    printf("%d ", maximo);
                }
                printf("\n");
                break;

            case 4:
                printf("Saliendo del programa.\n");
                break;

            default:
                printf("Opci�n no v�lida. Por favor, elija una opci�n v�lida.\n");
        }
    } while (opcion != 4);

    return 0;
}

