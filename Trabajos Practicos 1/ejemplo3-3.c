#include <stdio.h>

void subconjuntos(char *s, int m, int n, int i, int j) {
  // Si n = 0, entonces hemos encontrado un subconjunto válido.
  if (n == 0) {
    printf("(%c)", s[i]);
    return;
  }

  // Si i = m, entonces no quedan más letras por considerar.
  if (i == m) {
    return;
  }

  // Considerar el subconjunto que incluye la letra s[i].
  subconjuntos(s, m, n - 1, i + 1, j);

  // Considerar el subconjunto que no incluye la letra s[i].
  if (j < n) {
    subconjuntos(s, m, n, i + 1, j + 1);
  }
}

int main() {
  char s[] = {'A','B','C','D'};
  int m = 4;
  int n = 2;

  subconjuntos(s, m, n, 0, 0);

  return 0;
}
