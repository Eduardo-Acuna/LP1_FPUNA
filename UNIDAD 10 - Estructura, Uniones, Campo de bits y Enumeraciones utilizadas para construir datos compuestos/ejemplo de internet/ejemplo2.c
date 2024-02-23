#include <stdio.h>
#include <string.h>

// Definición de la estructura Persona
struct Persona {
    char nombre[50];
    int edad;
    float altura;
};

// Función que modifica una estructura a través de un puntero
void modificarPersona(struct Persona *persona, const char *nuevoNombre, int nuevaEdad, float nuevaAltura) {
    strcpy(persona->nombre, nuevoNombre);
    persona->edad = nuevaEdad;
    persona->altura = nuevaAltura;
}

int main() {
    struct Persona persona1;
    struct Persona *ptrPersona = &persona1;

    // Inicializamos la estructura usando la función modificarPersona
    modificarPersona(ptrPersona, "Juan", 30, 1.75);

    // Accedemos a los miembros de la estructura a través del puntero
    printf("Nombre: %s\n", ptrPersona->nombre);
    printf("Edad: %d\n", ptrPersona->edad);
    printf("Altura: %.2f\n", ptrPersona->altura);

    return 0;
}
