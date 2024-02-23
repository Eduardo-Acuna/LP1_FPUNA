#include <stdio.h>
#include <math.h>

int N;
int exito = 0;

int Valido(int Solucion[], int etapa) {
    int i;
    for (i = 0; i < etapa; i++) {
        if (Solucion[i] == Solucion[etapa] || fabs(Solucion[etapa] - Solucion[i]) == fabs(etapa - i)) {
            return 0; // Verifica si es v�lido colocar una reina en la posici�n actual
        }
    }
    return 1; // Si es v�lido, devuelve 1
}

void ImprimirSolucion(int Solucion[]) {
    int i, j;
    puts("TABLERO");

    // Imprime el tablero con las reinas
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (Solucion[i] == j) {
                printf("%3d", j + 1);
            } else {
                printf("%3d", 0);
            }
        }
        puts("");
    }

    puts("POSICIONES");

    // Imprime las posiciones de las reinas
    for (i = 0; i < N; i++) {
        printf(" (%d,%d) ", i, Solucion[i]);
    }
}

int Reinas(int Solucion[], int etapa) {
    if (etapa == N) {
        return exito = 0;
    }
    Solucion[etapa] = -1;

    do {
        Solucion[etapa]++;
        if (Valido(Solucion, etapa)) {
            if (etapa != N - 1) {
                // Llama recursivamente a la funci�n Reinas para la siguiente etapa
                etapa++;
            } else {
                // Si se encontr� una soluci�n completa, marca exito como 1
                exito = 1;
                ImprimirSolucion(Solucion); // Imprime la soluci�n
                return 1; // Termina la funci�n Reinas
            }
        }
    } while (Solucion[etapa] < N - 1 && !exito);
    return 0;
}

int main() {
    printf("Introduzca el n�mero de Reinas: ");
    scanf("%d", &N);
    int Solucion[N];

    // Verifica si el n�mero de reinas es mayor que 3
    if (N > 3) {
        // Llama a la funci�n Reinas para resolver el problema de las N reinas
        if (!Reinas(Solucion, 0)) {
            puts("\aNo se encontro solucion");
        }
    } else {
        // Si el n�mero de reinas es menor o igual a 3, muestra un mensaje de error
        puts("\aNo existe solucion, N debe ser mayor a 3");
    }

    return 0;
}
