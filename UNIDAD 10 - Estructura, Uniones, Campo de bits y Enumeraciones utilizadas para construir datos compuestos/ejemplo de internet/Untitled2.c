#include <stdio.h>

// Definición de la estructura
struct Persona {
    char nombre[50];
    int edad;
    long telefono;
};

int main() {
    // Declaración e inicialización de una instancia de la estructura
    struct Persona persona1;

    // Asignar valores a los campos de la estructura
    strcpy(persona1.nombre, "Juan Pérez");
    persona1.edad = 30;
    persona1.telefono = 1234567890;

    // Mostrar los datos de la persona
    printf("Nombre: %s\n", persona1.nombre);
    printf("Edad: %d años\n", persona1.edad);
    printf("Teléfono: %ld\n", persona1.telefono);

    return 0;
}
