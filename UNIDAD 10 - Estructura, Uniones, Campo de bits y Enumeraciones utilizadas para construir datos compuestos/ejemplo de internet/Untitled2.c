#include <stdio.h>

// Definici�n de la estructura
struct Persona {
    char nombre[50];
    int edad;
    long telefono;
};

int main() {
    // Declaraci�n e inicializaci�n de una instancia de la estructura
    struct Persona persona1;

    // Asignar valores a los campos de la estructura
    strcpy(persona1.nombre, "Juan P�rez");
    persona1.edad = 30;
    persona1.telefono = 1234567890;

    // Mostrar los datos de la persona
    printf("Nombre: %s\n", persona1.nombre);
    printf("Edad: %d a�os\n", persona1.edad);
    printf("Tel�fono: %ld\n", persona1.telefono);

    return 0;
}
