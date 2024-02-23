#include <stdio.h>

void ordenarDiagonalPrincipal(int matriz[][3], int n) {
    int temp;
    int intercambio;

    do {
        intercambio = 0;
        for (int i = 0; i < n - 1; i++) {
            if (matriz[i][i] > matriz[i + 1][i + 1]) {
                // Intercambiar los elementos de la diagonal principal
                temp = matriz[i][i];
                matriz[i][i] = matriz[i + 1][i + 1];
                matriz[i + 1][i + 1] = temp;
                intercambio = 1;
            }
        }
    } while (intercambio);
}

int main() {
    int matriz[3][3] = {{93, 20, 1},
                        {6, 53, 4},
                        {9, 8, 17}};
    int n = 3;

    printf("Matriz original:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    ordenarDiagonalPrincipal(matriz, n);

    printf("\nMatriz con diagonal principal ordenada:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
