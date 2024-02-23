/*
Un caballero está aburrido de ver otra vez los mismos cuadros de blanco y negro, y ha decido hacer un viaje alrededor del mundo.

Siempre que un caballero se mueve, este tiene dos opciones:
    moverse dos cuadros en una dirección y un cuadro en forma perpendicular a su movimiento anterior.

El mundo de un caballero es un tablero donde él vive.
Nuestro caballero en cambio vive en un tablero que tiene un área más pequeña que el regular de 8x8, pero es rectangular.
 ¿Puedes tu ayudar a éste caballero a realizar su viaje de aventura?

• Problema
Se solicita calcular mediante un programa en lenguaje C un camino tal que el caballero visite cada cuadro una sola vez.
El cabello puede iniciar y terminar el cualquier cuadro del tablero.

• Entrada
La entrada consiste de un archivo denominado “Mundos-Caballero.dat”.

El archivo inicia con un número entero n en la primera fila.
Ésta indica el número de filas siguientes que contienen a los n casos de prueba.

Cada caso consiste de una simple línea con dos enteros positivos p y q, tal que 1 ≤ p⋅q ≤ 26.
Esto representa a un tablero de p x q, donde p indica cuantos diferentes números 1,2,...,p se tienen mientras
que q indica cuantas letras del abecedario a, b,..., se tienen. Básicamente, p indica el número de filas y q
el número de columnas.
• Salida
Los resultados deben ser dados en un archivo denominado “Camino-Caballero.dat”. La salida para cada
escenario debe iniciar con una línea que contiene “Escenario #i:”, donde i es el número de escenario queinicia con 1. Luego en una siguiente línea imprimir el camino del caballero, y finalmente un tablero con el
movimiento del caballero ordenado por números. Si el camino no existe imprima “imposible”.
Entrada ejemplo
3
1 1
2 3
4 3
Salida ejemplo
Escenario #1:
a1
a
1 1
Escenario #2:
Imposible
Escenario #3:
a1 b3 c1 a2 b4 c2 a3 b1 c3 a4 b2 c4
a b c
4 10 5 12
3 7 2 9
2 4 11 6
1 1 8 3

*/

#include <stdio.h>

#define MAX 30 // Tamaño máximo del tablero

int p, q;
char tablero[MAX][MAX];
char camino[MAX * MAX];
int movX[8] = {2, 2, 1, 1, -2, -2, -1, -1};
int movY[8] = {1, -1, 2, -2, 1, -1, 2, -2};
int movimientos = 0;

int es_valido(int x, int y) {
    return (x >= 0 && x < p && y >= 0 && y < q && tablero[x][y] == 0);
}

int resolver(int x, int y) {
    int i, nuevo_x, nuevo_y;

    if (movimientos == p * q) {
        return 1; // Se visitaron todos los cuadros
    }

    for (i = 0; i < 8; i++) {
        nuevo_x = x + movX[i];
        nuevo_y = y + movY[i];

        if (es_valido(nuevo_x, nuevo_y)) {
            movimientos++;
            tablero[nuevo_x][nuevo_y] = movimientos;
            camino[movimientos - 1] = 'a' + nuevo_y;
            camino[movimientos] = nuevo_x + 1;

            if (resolver(nuevo_x, nuevo_y)) {
                return 1;
            } else {
                movimientos--;
                tablero[nuevo_x][nuevo_y] = 0;
            }
        }
    }

    return 0;
}

int main() {
    int casos, i;
    scanf("%d", &casos);

    for (i = 1; i <= casos; i++) {
        scanf("%d %d", &p, &q);

        movimientos = 0;
        int x_inicial = 0, y_inicial = 0;

        for (int j = 0; j < p; j++) {
            for (int k = 0; k < q; k++) {
                tablero[j][k] = 0;
            }
        }

        tablero[x_inicial][y_inicial] = 1;
        camino[0] = 'a' + y_inicial;
        camino[1] = x_inicial + 1;

        if (resolver(x_inicial, y_inicial)) {
            printf("Escenario #%d:\n", i);

            for (int j = 0; j < p * q; j += 2) {
                printf("%c%d ", camino[j], camino[j + 1]);
            }

            printf("\n");

            for (int j = 0; j < p; j++) {
                for (int k = 0; k < q; k++) {
                    printf("%d ", tablero[j][k]);
                }

                printf("\n");
            }
        } else {
            printf("Escenario #%d:\nImposible\n", i);
        }
    }

    return 0;
}
