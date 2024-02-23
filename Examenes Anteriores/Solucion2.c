#include <stdio.h>

#define N 16
  // Tamaño de la matriz, puedes cambiarlo según tus necesidades

int main() {
    int matriz[N][N];
    int m, n; // Variables para almacenar la posición ingresada por el usuario

    // Inicializa la matriz con ceros
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matriz[i][j] = 0;
        }
    }

    // Solicita al usuario las coordenadas m y n
    printf("Ingrese la posición (m, n) para cargar las diagonales (0 <= m, n < %d): ", N);
    scanf("%d %d", &m, &n);

    // Carga de 1 en la diagonal principal
    for (int i = 0; i < N; i++) {
        matriz[i][i] = 1;
    }

    // Carga de 1 en la diagonal secundaria
    for (int i = 0; i < N; i++) {
        matriz[i][N - 1 - i] = 1;
    }

    // Si la posición ingresada está dentro de los límites de la matriz, carga 1 en esa posición
    if (m >= 0 && m < N && n >= 0 && n < N) {
        matriz[m][n] = 1;
    } else {
        printf("Posición fuera de los límites de la matriz.\n");
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
