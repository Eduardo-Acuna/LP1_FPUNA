#include <stdio.h>
#include <stdlib.h>

struct Libro {
  char titulo[20];
  char autor[20];
  int paginas;
  float precio;
};

int main() {
  // Declaramos un array de estructuras
  struct Libro libros[10];

  // Inicializamos el array
  for (int i = 0; i < 10; i++) {
    libros[i].titulo[0] = '\0';
    libros[i].autor[0] = '\0';
    libros[i].paginas = 0;
    libros[i].precio = 0.0;
  }

  // Creamos la función de menú
  int opcion;
  do {
    // Mostramos el menú
    printf("** Menú **\n");
    printf("1. Introducir libro\n");
    printf("2. Imprimir libros\n");
    printf("3. Salir\n");
    printf("Introduzca una opción: ");
    scanf("%d", &opcion);

    // Limpiar el búfer de entrada (eliminar el carácter de nueva línea)
    while (getchar() != '\n');

    // Procesamos la opción seleccionada
    switch (opcion) {
      case 1:
        // Introducimos un libro
        printf("Introduzca los datos del libro:\n");
        printf("Título: ");
        fgets(libros[0].titulo, sizeof(libros[0].titulo), stdin);
        printf("Autor: ");
        fgets(libros[0].autor, sizeof(libros[0].autor), stdin);
        printf("Número de páginas: ");
        scanf("%d", &libros[0].paginas);
        printf("Precio: ");
        scanf("%f", &libros[0].precio);
        break;
      case 2:
        // Imprimimos los libros
        printf("** Libros almacenados **\n");
        for (int i = 0; i < 10; i++) {
          if (libros[i].titulo[0] != '\0') {
            printf("Título: %s", libros[i].titulo);
            printf("Autor: %s", libros[i].autor);
            printf("Número de páginas: %d\n", libros[i].paginas);
            printf("Precio: %.2f\n", libros[i].precio);
          }
        }
        break;
      case 3:
        // Salimos del programa
        printf("Saliendo...\n");
        break;
      default:
        // Opción no válida
        printf("Opción inválida\n");
        break;
    }
  } while (opcion != 3);

  return 0;
}

