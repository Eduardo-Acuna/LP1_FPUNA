#include <stdio.h>
#include <math.h>

int main() {
    int opcion;

    printf("Seleccione una opci�n:\n");
    printf("1. Calcular el �rea de un c�rculo.\n");
    printf("2. Calcular el �rea de un tri�ngulo.\n");
    printf("3. Calcular el �rea de un rect�ngulo.\n");
    printf("4. Calcular el �rea de un cuadrado.\n");
    printf("Ingrese el n�mero de opci�n: ");
    scanf("%d", &opcion);

    if (opcion >= 1 && opcion <= 4) {
        float area;
        switch (opcion)
        {
            case 1:
                float radio;
                printf("Ingrese el radio del c�rculo: ");
                scanf("%f", &radio);
                area = M_PI * radio * radio;
                printf("El �rea del c�rculo es: %.2f\n", area);
                break;

            case 2:
                float base, altura;
                printf("Ingrese la base del tri�ngulo: ");
                scanf("%f", &base);
                printf("Ingrese la altura del tri�ngulo: ");
                scanf("%f", &altura);
                area = 0.5 * base * altura;
                printf("El �rea del tri�ngulo es: %.2f\n", area);
                break;

            case 3:
                float base_r, altura_r;
                printf("Ingrese la base del rect�ngulo: ");
                scanf("%f", &base_r);
                printf("Ingrese la altura del rect�ngulo: ");
                scanf("%f", &altura_r);
                area = base_r * altura_r;
                printf("El �rea del rect�ngulo es: %.2f\n", area);
                break;

            case 4:
                float lado;
                printf("Ingrese el lado del cuadrado: ");
                scanf("%f", &lado);
                area = lado * lado;
                printf("El �rea del cuadrado es: %.2f\n", area);
                break;
        }
    } else {
        printf("Opci�n no v�lida. Gracias por usar el programa.\n");
    }

    printf("Firma: G.R. (Gerardo Riveros)\n");

    return 0;
}
