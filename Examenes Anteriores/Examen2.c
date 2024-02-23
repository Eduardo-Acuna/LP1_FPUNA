/*
En el clasico problema de las 8 reinas se tierne un tabla como se observa en la figura

Básicamente una reina amenaza a todas las casillas que se encuentran sobre las casillas de la
columna, fila, diagonal derecha e izquierda que contengan a su posición, Una solución válida para este
problema es que las 8 reinas sean ubicadas en el tablero sin que ninguna amenace a otra como puede
observarse en la siguiente figura 3.


En este trabajo se propone el caso general:
Dado un tablero de tamaño MxM (1<=M<=16) y "n reinas" (piezas ), proponga una solución en lenguaje C para resolver el problema de las n reinas de forma iterativa.

Básicamente, el programa debe solicitar al usuario que ingrese el número de reinas "n" y calcular la soluión.
Ante la primera solución válida imprime en pantalla la ubicación de las reinas sobre un
tablero de MxM, donde "*" indica reina y espacio ausencia de reina, luego el proceso termina.

El tablero a imprimir debe ser similar al de la figura 1.
Si el programa no encuentra solución válida debe imprimir en pantalla "no hay solución válida".

Consideraciones:
1) Código con errores de sintaxis (0 pts.)
2) Sin errores de sintaxis: Modularidad (15 pts.) + producción (85 pts.)

*/
#include <stdio.h>

int n;
int tablero[16][16];

// Función para imprimir el tablero
void imprimirTablero() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (tablero[i][j] == 1) {
                printf("* ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Función para verificar si es seguro colocar una reina en la posición (fila, col)
int esSeguro(int fila, int col) {
    // Verificar la fila en la izquierda
    for (int i = 0; i < col; i++) {
        if (tablero[fila][i] == 1) {
            return 0;
        }
    }
    // Verificar la diagonal superior izquierda
    for (int i = fila, j = col; i >= 0 && j >= 0; i--, j--) {
        if (tablero[i][j] == 1) {
            return 0;
        }
    }
    // Verificar la diagonal inferior izquierda
    for (int i = fila, j = col; i < n && j >= 0; i++, j--) {
        if (tablero[i][j] == 1) {
            return 0;
        }
    }
    return 1;
}

// Función para resolver el problema de las N reinas
int resolverNReinas(int col) {
    if (col >= n) {
        imprimirTablero();
        return 1;
    }

    int soluciones = 0;

    for (int i = 0; i < n; i++) {
        if (esSeguro(i, col)) {
            tablero[i][col] = 1;

            soluciones += resolverNReinas(col + 1);

            tablero[i][col] = 0;
        }
    }

    return soluciones;
}

int main() {
    printf("Ingrese la cantidad de reinas (1 <= n <= 16): ");
    scanf("%d", &n);

    if (n < 1 || n > 16) {
        printf("El valor de n debe estar entre 1 y 16.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tablero[i][j] = 0;
        }
    }

    int soluciones = resolverNReinas(0);

    if (soluciones == 0) {
        printf("No hay solución válida para %d reinas.\n", n);
    }

    return 0;
}
