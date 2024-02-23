#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_AVIONES 100

// Estructura para representar un avión
struct Avion {
    char codigo[10];
};

// Estructura para representar una cola de aviones
struct Cola {
    struct Avion aviones[MAX_AVIONES];
    int frente, final;
};

// Funciones para la cola
void inicializarCola(struct Cola *cola) {
    cola->frente = -1;
    cola->final = -1;
}

int estaVacia(struct Cola *cola) {
    return cola->frente == -1;
}

int estaLlena(struct Cola *cola) {
    return (cola->final + 1) % MAX_AVIONES == cola->frente;
}

void encolar(struct Cola *cola, struct Avion avion) {
    if (!estaLlena(cola)) {
        if (estaVacia(cola)) {
            cola->frente = 0;
        }
        cola->final = (cola->final + 1) % MAX_AVIONES;
        cola->aviones[cola->final] = avion;
    } else {
        printf("La cola está llena. No se puede encolar más aviones.\n");
    }
}

struct Avion desencolar(struct Cola *cola) {
    struct Avion avion;
    if (!estaVacia(cola)) {
        avion = cola->aviones[cola->frente];
        if (cola->frente == cola->final) {
            inicializarCola(cola);
        } else {
            cola->frente = (cola->frente + 1) % MAX_AVIONES;
        }
    } else {
        printf("La cola está vacía. No se puede desencolar.\n");
    }
    return avion;
}

// Función para cargar aviones desde un archivo
void cargarAvionesDesdeArchivo(const char *nombreArchivo, struct Cola *cola) {
    FILE *archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo %s\n", nombreArchivo);
        exit(EXIT_FAILURE);
    }

    struct Avion avion;
    while (fscanf(archivo, "%s", avion.codigo) == 1) {
        encolar(cola, avion);
    }

    fclose(archivo);
}

// Función para mostrar el estado de la torre de control
void mostrarEstado(struct Cola *colaTierra, struct Cola *colaAire) {
    printf("\nVuelos esperando para aterrizar: ");
    while (!estaVacia(colaAire)) {
        struct Avion avion = desencolar(colaAire);
        printf("%s ", avion.codigo);
        encolar(colaTierra, avion);
    }

    printf("\nVuelos esperando para despegar: ");
    while (!estaVacia(colaTierra)) {
        struct Avion avion = desencolar(colaTierra);
        printf("%s ", avion.codigo);
        encolar(colaAire, avion);
    }

    printf("\n");
}

// Función principal
int main() {
    struct Cola colaTierra, colaAire;
    inicializarCola(&colaTierra);
    inicializarCola(&colaAire);

    cargarAvionesDesdeArchivo("avion_en_tierra.txt", &colaTierra);
    cargarAvionesDesdeArchivo("avion_en_aire.txt", &colaAire);

    int opcion;
    do {
        printf("\nMenú de Opciones:\n");
        printf("1. Ver Estado\n");
        printf("2. Asignar Pista\n");
        printf("3. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                mostrarEstado(&colaTierra, &colaAire);
                break;
            case 2:
                if (!estaVacia(&colaAire)) {
                    struct Avion avionAterrizaje = desencolar(&colaAire);
                    printf("El vuelo %s aterrizó con éxito\n", avionAterrizaje.codigo);
                } else if (!estaVacia(&colaTierra)) {
                    struct Avion avionDespegue = desencolar(&colaTierra);
                    printf("El vuelo %s despegó con éxito\n", avionDespegue.codigo);
                } else {
                    printf("No hay aviones en espera.\n");
                }
                break;
            case 3:
                printf("¡Gracias por utilizar el programa!\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }

    } while (opcion != 3);

    return 0;
}
