#include <stdio.h>
#include <stdlib.h>

void insertarEnMonticulo(int* monticulo, int* tamano, int elemento) {
    (*tamano)++;
    int i = *tamano;

    while (i > 1 && elemento < monticulo[i / 2]) {
        monticulo[i] = monticulo[i / 2];
        i /= 2;
    }

    monticulo[i] = elemento;
}

int quitarMinDelMonticulo(int* monticulo, int* tamano) {
    if (*tamano == 0) {
        printf("Mont�culo vac�o\n");
        exit(1);
    }

    int elementoMinimo = monticulo[1];
    int ultimoElemento = monticulo[(*tamano)--];
    int i = 1, hijo;

    while (i * 2 <= *tamano) {
        hijo = i * 2;

        if (hijo + 1 <= *tamano && monticulo[hijo + 1] < monticulo[hijo]) {
            hijo++;
        }

        if (ultimoElemento > monticulo[hijo]) {
            monticulo[i] = monticulo[hijo];
        } else {
            break;
        }

        i = hijo;
    }

    monticulo[i] = ultimoElemento;
    return elementoMinimo;
}

void imprimirMonticulo(int* monticulo, int tamano) {
    printf("Mont�culo: ");
    for (int i = 1; i <= tamano; i++) {
        printf("%d ", monticulo[i]);
    }
    printf("\n");
}

int main() {
    int tamanoMonticulo = 0;
    int monticulo[100];  // Tama�o arbitrario para el mont�culo

    int opcion, elemento;

    do {
        printf("\n--- Men� ---\n");
        printf("1. Insertar elemento en el mont�culo\n");
        printf("2. Quitar elemento m�nimo del mont�culo\n");
        printf("3. Imprimir mont�culo\n");
        printf("0. Salir\n");
        printf("Ingrese su opci�n: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese el elemento a insertar: ");
                scanf("%d", &elemento);
                insertarEnMonticulo(monticulo, &tamanoMonticulo, elemento);
                break;
            case 2:
                printf("Elemento m�nimo eliminado: %d\n", quitarMinDelMonticulo(monticulo, &tamanoMonticulo));
                break;
            case 3:
                imprimirMonticulo(monticulo, tamanoMonticulo);
                break;
            case 0:
                printf("Saliendo del programa\n");
                break;
            default:
                printf("Opci�n no v�lida\n");
        }
    } while (opcion != 0);

    return 0;
}
