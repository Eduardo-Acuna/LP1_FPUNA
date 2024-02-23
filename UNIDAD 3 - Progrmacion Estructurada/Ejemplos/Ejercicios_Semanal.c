#include <stdio.h>
#include <math.h>

int main() {
    int opcion;

    printf("Seleccione una opción:\n");
    printf("1. Calcular el área de un círculo.\n");
    printf("2. Calcular el área de un triángulo.\n");
    printf("3. Calcular el área de un rectángulo.\n");
    printf("4. Calcular el área de un cuadrado.\n");
    printf("Ingrese el número de opción: ");
    scanf("%d", &opcion);

    if (opcion >= 1 && opcion <= 4) {
        float area;
        switch (opcion)
        {
            case 1:
                float radio;
                printf("Ingrese el radio del círculo: ");
                scanf("%f", &radio);
                area = M_PI * radio * radio;
                printf("El área del círculo es: %.2f\n", area);
                break;

            case 2:
                float base, altura;
                printf("Ingrese la base del triángulo: ");
                scanf("%f", &base);
                printf("Ingrese la altura del triángulo: ");
                scanf("%f", &altura);
                area = 0.5 * base * altura;
                printf("El área del triángulo es: %.2f\n", area);
                break;

            case 3:
                float base_r, altura_r;
                printf("Ingrese la base del rectángulo: ");
                scanf("%f", &base_r);
                printf("Ingrese la altura del rectángulo: ");
                scanf("%f", &altura_r);
                area = base_r * altura_r;
                printf("El área del rectángulo es: %.2f\n", area);
                break;

            case 4:
                float lado;
                printf("Ingrese el lado del cuadrado: ");
                scanf("%f", &lado);
                area = lado * lado;
                printf("El área del cuadrado es: %.2f\n", area);
                break;
        }
    } else {
        printf("Opción no válida. Gracias por usar el programa.\n");
    }

    printf("Firma: G.R. (Gerardo Riveros)\n");

    return 0;
}
