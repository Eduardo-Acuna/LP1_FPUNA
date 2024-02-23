#include <stdio.h>
#include <math.h>
#include <string.h>
#include "header.h"

int main() {
    int opcion;
    char enter;
    do {
        printf("\n--- Menu ---\n");
        printf("1. Calcular area hexagono y circulo\n");
        printf("2. Encontrar consonantes y trozos de texto\n");
        printf("3. Verificar cuadrado magico 3x3\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                calcularYMostrarAreas();
                break;
            case 2:
                encontrarConsonantesYTrozos();
                break;
            case 3:
                verificarCuadradoMagico();
                break;
            case 4:
                return 0;  // Salir del programa
            default:
                printf("Opción no válida. Por favor, seleccione una opción válida.\n");
        }

        printf("\nPresione Enter para volver al menú...");
        scanf("%c", &enter);  // Limpiar el buffer de entrada
        scanf("%c", &enter);  // Esperar Enter para continuar

    } while (1);  // Ciclo infinito para mostrar el menú continuamente

    return 0;
}
