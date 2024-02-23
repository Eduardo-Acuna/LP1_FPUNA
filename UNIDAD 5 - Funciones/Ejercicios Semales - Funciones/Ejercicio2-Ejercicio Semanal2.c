#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Función para lanzar un dado y devolver el resultado
int lanzarDado() {
    return rand() % 6 + 1;
}

// Función para simular el juego del Craps
void jugarCraps() {
    printf("El juego del Craps ha iniciado\n");
    printf("=======================\n");

    int lanzamiento = 1;
    int punto = 0;
    int suma = lanzarDado() + lanzarDado();
    printf("Lanzamiento %d: %d + %d = %d", lanzamiento, lanzarDado(), lanzarDado(), suma);

    if (suma == 7 || suma == 11) {
        printf("  <<Win>>\n");
        printf("El juego ha terminado\n");
        return;
    } else if (suma == 2 || suma == 3 || suma == 12) {
        printf("  <<Craps>>.\n");
        printf("El juego ha terminado\n");
        return;
    } else {
        punto = suma;
        printf("  Punto=%d, Ronda.\n", punto);
    }

    while (1) {
        lanzamiento++;
        suma = lanzarDado() + lanzarDado();
        printf("Lanzamiento %d: %d + %d = %d", lanzamiento, lanzarDado(), lanzarDado(), suma);

        if (suma == punto) {
            printf("  <<Win>>\n");
            printf("El juego ha terminado\n");
            return;
        } else if (suma == 7) {
            printf("  <<Seven out>>\n");
            printf("El juego ha terminado\n");
            return;
        } else {
            printf("  Ronda.\n");
        }
    }
}

int main() {
    srand(time(NULL)); // Inicializar la semilla para generar números aleatorios

    jugarCraps();

    return 0;
}
