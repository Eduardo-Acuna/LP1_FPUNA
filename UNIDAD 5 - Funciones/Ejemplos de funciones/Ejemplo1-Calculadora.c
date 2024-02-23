#include <stdio.h>

// Declaración de funciones
float sumar(float a, float b) {
    return a + b;
}

float restar(float a, float b) {
    return a - b;
}

float multiplicar(float a, float b) {
    return a * b;
}

float dividir(float a, float b) {
    if (b != 0) {
        return a / b;
    } else {
        printf("Error: No se puede dividir por cero.\n");
        return 0.0;
    }
}

int main() {
    float num1, num2, resultado;
    char operador;
    int opcion;

    do {
        printf("Calculadora:\n");
        printf("1. Sumar\n");
        printf("2. Restar\n");
        printf("3. Multiplicar\n");
        printf("4. Dividir\n");
        printf("5. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        if (opcion >= 1 && opcion <= 4) {
            printf("Ingrese el primer número: ");
            scanf("%f", &num1);

            printf("Ingrese el segundo número: ");
            scanf("%f", &num2);

            switch (opcion) {
                case 1:
                    operador = '+';
                    resultado = sumar(num1, num2);
                    break;
                case 2:
                    operador = '-';
                    resultado = restar(num1, num2);
                    break;
                case 3:
                    operador = '*';
                    resultado = multiplicar(num1, num2);
                    break;
                case 4:
                    operador = '/';
                    resultado = dividir(num1, num2);
                    break;
            }

            printf("Resultado: %.2f %c %.2f = %.2f\n", num1, operador, num2, resultado);
        } else if (opcion != 5) {
            printf("Opción inválida. Intente de nuevo.\n");
        }

    } while (opcion != 5);

    printf("Gracias por usar la calculadora.\n");

    return 0;
}

