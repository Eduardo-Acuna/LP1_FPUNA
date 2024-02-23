#include <stdio.h>

#define N 16
  // Tama�o de la matriz, puedes cambiarlo seg�n tus necesidades

int main() {
    int matriz[N][N];
    int m, n; // Variables para almacenar la posici�n ingresada por el usuario

    // Inicializa la matriz con ceros
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matriz[i][j] = 0;
        }
    }

    // Solicita al usuario las coordenadas m y n
    printf("Ingrese la posici�n (m, n) para cargar las diagonales (0 <= m, n < %d): ", N);
    scanf("%d %d", &m, &n);

    // Carga de 1 en la diagonal principal
    for (int i = 0; i < N; i++) {
        matriz[i][i] = 1;
    }

    // Carga de 1 en la diagonal secundaria
    for (int i = 0; i < N; i++) {
        matriz[i][N - 1 - i] = 1;
    }

    // Si la posici�n ingresada est� dentro de los l�mites de la matriz, carga 1 en esa posici�n
    if (m >= 0 && m < N && n >= 0 && n < N) {
        matriz[m][n] = 1;
    } else {
        printf("Posici�n fuera de los l�mites de la matriz.\n");
    }

    // Imprime la matriz resultante
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
