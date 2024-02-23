#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_AV 100

struct AVION {
    char codigo[10];
    char estado[15];  // Nuevo campo para el estado del avión
};

struct COLA {
    struct AVION aviones[MAX_AV];
    int FRENTE;
    int FINAL;
};

void inicioCola(struct COLA *cola);
int estaVacia(struct COLA *cola);
int estaLlena(struct COLA *cola);
void cargarArchivo(const char *nomArchivo, struct COLA *cola);
void mostrarEstado(struct COLA *colaT, struct COLA *colaA);

void encolar(struct COLA *cola, struct AVION avion);
struct AVION desencolar(struct COLA *cola);

int main() {
    struct COLA colaTierra;
    struct COLA colaAire;

    inicioCola(&colaTierra);
    inicioCola(&colaAire);

    cargarArchivo("avion_en_tierra.txt", &colaTierra);
    cargarArchivo("avion_en_aire.txt", &colaAire);

    int opcion;
    printf("\n\t +--------------------------------------+");
    printf("\n\t |               MENU                   |");
    printf("\n\t +--------------------------------------+");
    printf("\n\t | 1. Ver estado                        |");
    printf("\n\t | 2. Asignar pista                     |");
    printf("\n\t | 3. Salir                             |");
    printf("\n\t +--------------------------------------+");

    do {
        printf("OPCION: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                mostrarEstado(&colaTierra, &colaAire);
                break;
            case 2:
                if (!estaVacia(&colaAire)) {
                    struct AVION avionAterrizaje = desencolar(&colaAire);
                    strcpy(avionAterrizaje.estado, "Aterrizado");
                    printf("%s ATERRIZO con éxito.\n", avionAterrizaje.codigo);
                    encolar(&colaTierra, avionAterrizaje);
                } else if (!estaVacia(&colaTierra)) {
                    struct AVION avionDespegue = desencolar(&colaTierra);
                    strcpy(avionDespegue.estado, "Despegado");
                    printf("%s DESPEGO con éxito.\n", avionDespegue.codigo);
                    encolar(&colaAire, avionDespegue);
                } else {
                    printf("No hay aviones en espera.\n");
                }
                break;
            case 3:
                printf("Gracias por usar el programa HDP!\n");
                break;
            default:
                printf("Opción no válida.\n");
        }
    } while (opcion != 3);

    return 0;
}

void encolar(struct COLA *cola, struct AVION avion) {
    if (!estaLlena(cola)) {
        if (estaVacia(cola)) {
            cola->FRENTE = 0;
        }

        cola->FINAL = (cola->FINAL + 1) % MAX_AV;
        cola->aviones[cola->FINAL] = avion;
    } else {
        printf("La cola está llena. No se puede encolar más aviones.\n");
    }
}

struct AVION desencolar(struct COLA *cola) {
    struct AVION avion;

    if (!estaVacia(cola)) {
        avion = cola->aviones[cola->FRENTE];

        if (cola->FRENTE == cola->FINAL) {
            inicioCola(cola);
        } else {
            cola->FRENTE = (cola->FRENTE + 1) % MAX_AV;
        }
    } else {
        printf("La cola está vacía. No se puede desencolar.\n");
    }

    return avion;
}

void mostrarEstado(struct COLA *colaT, struct COLA *colaA) {
    printf("\nVUELOS ESPERANDO PARA ATERRIZAR:");
    while (!estaVacia(colaA)) {
        struct AVION avion1 = desencolar(colaA);
        printf("%s (%s) ", avion1.codigo, avion1.estado);
        encolar(colaT, avion1);
    }

    printf("\nVUELOS ESPERANDO PARA DESPEGAR:");
    while (!estaVacia(colaT)) {
        struct AVION avion2 = desencolar(colaT);
        printf("%s (%s) ", avion2.codigo, avion2.estado);
        encolar(colaA, avion2);
    }

    printf("\n");
}

void inicioCola(struct COLA *cola) {
    cola->FRENTE = -1;
    cola->FINAL = -1;
}

int estaVacia(struct COLA *cola) {
    return cola->FRENTE == -1;
}

int estaLlena(struct COLA *cola) {
    return (cola->FINAL + 1) % MAX_AV == cola->FRENTE;
}

void cargarArchivo(const char *nomArchivo, struct COLA *cola) {
    FILE *archivo;
    archivo = fopen(nomArchivo, "r");

    if (archivo == NULL) {
        printf("ERROR, no se puede abrir el archivo");
        exit(EXIT_FAILURE);
    }

    struct AVION avion;
    while (fscanf(archivo, "%s", avion.codigo) == 1) {
        strcpy(avion.estado, "");  // Inicializamos el estado como cadena vacía
        encolar(cola, avion);
    }

    fclose(archivo);
}
