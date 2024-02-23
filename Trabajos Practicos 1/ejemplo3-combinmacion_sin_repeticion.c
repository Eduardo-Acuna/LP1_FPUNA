#include <stdio.h>

void generarSubconjuntos(char conjunto[], char subconjunto[], int m, int n, int inicio, int subconjuntoSize) {
    if (subconjuntoSize == n) {
        // El subconjunto está completo, se imprime.
        for (int i = 0; i < n; i++) {
            printf("%c ", subconjunto[i]);
        }
        printf("\n");
        return;
    }

    for (int i = inicio; i < m; i++) {
        subconjunto[subconjuntoSize] = conjunto[i];
        generarSubconjuntos(conjunto, subconjunto, m, n, i + 1, subconjuntoSize + 1);
    }
}

int main() {
    int m, n;

    printf("Cantidad total de letras (m): ");
    scanf("%d", &m);

    printf("Cantidad de letras en el subconjunto (n): ");
    scanf("%d", &n);

    char conjunto[m];
    char subconjunto[n];

    printf("\nCargar elementos: \n");

    for (int i = 0; i < m; i++) {
        printf("P[%d]: ", i);
        scanf(" %c", &conjunto[i]);
    }

    printf("\nLista de elementos: ");
    for (int i = 0; i < m; i++) {
        printf("%c", conjunto[i]);
    }

    printf("\n\nSubconjuntos:\n");
    generarSubconjuntos(conjunto, subconjunto, m, n, 0, 0);

    return 0;
}
