#include <stdio.h>

struct persona {
  char nombre[10];
  int edad;
};

struct libro {
  char titulo[20];
  int paginas;
};

int main() {
  struct persona p1;
  struct libro l1;

  // Asignar el nombre "Juan" a la variable p1

  strcpy(p1.nombre, "Juan");
  p1.edad = 30;

  // Asignar el título "El Quijote" a la variable l1

  strcpy(l1.titulo, "El Quijote");
  l1.paginas = 1000;

  // Imprimir el nombre de la persona

  printf("El nombre de la persona es: %s\n", p1.nombre);

  // Imprimir el título del libro

  printf("El título del libro es: %s\n", l1.titulo);

  return 0;
}
