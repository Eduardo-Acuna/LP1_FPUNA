#include <stdio.h>

// Definición de la estructura llamada "Persona"
struct Persona {
    char nombre[50];  // Miembro para almacenar el nombre
    int edad;         // Miembro para almacenar la edad
    float altura;     // Miembro para almacenar la altura
};

int main() {
    // Declaración de una variable de tipo "Persona"
    struct Persona persona1;

    // Asignación de valores a los miembros de la estructura
    strcpy(persona1.nombre, "Juan");  // Copiamos el nombre "Juan" al miembro "nombre"
    persona1.edad = 30;              // Asignamos la edad 30 al miembro "edad"
    persona1.altura = 1.75;          // Asignamos la altura 1.75 al miembro "altura"

    // Acceso e impresión de los valores almacenados en la estructura
    printf("Nombre: %s\n", persona1.nombre);  // Imprimimos el nombre
    printf("Edad: %d\n", persona1.edad);      // Imprimimos la edad
    printf("Altura: %.2f\n", persona1.altura); // Imprimimos la altura

    return 0;
}
