#include <stdio.h>
#include <stdlib.h>

// Función para calcular el siguiente número de la sucesión de Fibonacci.
int fibonacci(int n) {
    if (n == 0 || n == 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// Función para cargar la matriz con la sucesión de Fibonacci.
void cargarMatriz(int *matriz, int nFilas, int nColunas) {
    int i, j;

    // Iniciar la matriz con 0.
    for (i = 0; i < nFilas; i++) {
        for (j = 0; j < nColunas; j++) {
            matriz[i * nColunas + j] = 0;
        }
    }

    // Cargar la matriz con la sucesión de Fibonacci.
    for (i = 0; i < nFilas; i++) {
        for (j = 0; j < nColunas; j++) {
            matriz[i * nColunas + j] = fibonacci(i + j);
        }
    }
}

// Función para imprimir la matriz utilizando punteros.
void imprimirMatriz(int *matriz, int nFilas, int nColunas) {
    int i, j;

    for (i = 0; i < nFilas; i++) {
        for (j = 0; j < nColunas; j++) {
            printf("%d ", matriz[i * nColunas + j]);
        }
        printf("\n");
    }
}

int main() {
    // Declarar variables.
    int matriz[3][5];
    int nFilas = 3;
    int nColunas = 5;

    // Cargar la matriz con la sucesión de Fibonacci.
    cargarMatriz(matriz, nFilas, nColunas);

    // Imprimir la matriz utilizando punteros.
    imprimirMatriz(matriz, nFilas, nColunas);

    return 0;
}
