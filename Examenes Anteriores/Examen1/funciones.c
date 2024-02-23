#include <stdio.h>
#include <math.h>
#include <string.h>
#include "header.h"

// Declaración de constantes
#define PI 3.1428

// Función para calcular y mostrar áreas
void calcularYMostrarAreas() {
    double radio;
    printf("Ingrese el radio del circulo: ");
    scanf("%lf", &radio);

    double areaCirculo = PI * pow(radio, 2) / 2;
    double areaHexagono = (3 * sqrt(3) * pow(radio, 2)) / 2;

    printf("Area del circulo: %.2lf\n", areaCirculo);
    printf("Area del hexagono: %.2lf\n", areaHexagono);
}

// Función para encontrar consonantes y trozos de texto
void encontrarConsonantesYTrozos() {
    char texto[81];
    printf("Ingrese un texto (hasta 80 caracteres):\n");
    scanf(" %[^\n]", texto);

    char consonantes[] = "lmnrs";
    int len = strlen(texto);

    for (int i = 0; i < strlen(consonantes); i++) {
        char letra = consonantes[i];
        int primeraAparicion = -1;
        int ultimaAparicion = -1;

        for (int j = 0; j < len; j++) {
            if (texto[j] == letra) {
                if (primeraAparicion == -1) {
                    primeraAparicion = j;
                }
                ultimaAparicion = j;
            }
        }

        if (primeraAparicion != -1) {
            printf("Primera aparición de '%c': %d\n", letra, primeraAparicion);
            printf("Trozo de texto: ");
            for (int k = primeraAparicion; k <= ultimaAparicion; k++) {
                printf("%c", texto[k]);
            }
            printf("\n");
        } else {
            printf("Tal letra no existe o no tiene repetición: '%c'\n", letra);
        }
    }
}

// Función para verificar cuadrado mágico
void verificarCuadradoMagico() {
    int cuadrado[3][3];
    printf("Ingrese los valores del cuadrado 3x3:\n");

    // Leer valores del usuario y llenar el cuadrado
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &cuadrado[i][j]);
        }
    }

    // Verificar si es un cuadrado mágico
    int sumaFila = 0;
    int sumaColumna = 0;
    int sumaDiagonal1 = 0;
    int sumaDiagonal2 = 0;

    for (int i = 0; i < 3; i++) {
        sumaFila = sumaColumna = 0;

        for (int j = 0; j < 3; j++) {
            sumaFila += cuadrado[i][j];
            sumaColumna += cuadrado[j][i];

            if (i == j) {
                sumaDiagonal1 += cuadrado[i][j];
            }

            if (i + j == 2) {
                sumaDiagonal2 += cuadrado[i][j];
            }
        }

        if (sumaFila != sumaColumna || sumaFila != sumaDiagonal1 || sumaFila != sumaDiagonal2) {
            printf("No es un cuadrado mágico.\n");
            return;
        }
    }

    printf("Es un cuadrado mágico.\n");
}
