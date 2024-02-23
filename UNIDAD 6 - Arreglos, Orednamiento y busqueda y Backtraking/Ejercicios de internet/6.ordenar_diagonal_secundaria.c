#include <stdio.h>

void ordenarDiagonalSecundaria(int matriz[][3], int n) {
    int temp;
    int intercambio;

    do {
        intercambio = 0;
        for (int i = 0; i < n - 1; i++) {
            if (matriz[i][n - 1 - i] > matriz[i + 1][n - 2 - i]) {
                // Intercambiar los elementos de la diagonal secundaria
                temp = matriz[i][n - 1 - i];
                matriz[i][n - 1 - i] = matriz[i + 1][n - 2 - i];
                matriz[i + 1][n - 2 - i] = temp;
                intercambio = 1;
            }
        }
    } while (intercambio);
}

int main() {
    int matriz[3][3] = {{10, 2, 63},
                        {4, 25, 6},
                        {97, 8, 9}};
    int n = 3;

    printf("Matriz original:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    ordenarDiagonalSecundaria(matriz, n);

    printf("\nMatriz con diagonal secundaria ordenada:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
