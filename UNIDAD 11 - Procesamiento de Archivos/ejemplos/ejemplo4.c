#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para almacenar datos de estudiantes
struct Estudiante {
    char nombre[50];
    char apellido[50];
    char dni[20];
    int aprobado;
};

// Funci�n para mostrar el men�
void mostrarMenu() {
    printf("\n** Men� **\n");
    printf("1. Crear archivo de estudiantes\n");
    printf("2. Cargar archivo de estudiantes\n");
    printf("3. Agregar estudiante\n");
    printf("4. Eliminar estudiante\n");
    printf("5. Mostrar lista de estudiantes\n");
    printf("6. Eliminar archivo de estudiantes\n");
    printf("7. Salir\n");
}

// Funci�n para agregar un estudiante a un archivo
void agregarEstudiante(FILE *archivo) {
    struct Estudiante estudiante;

    printf("Ingrese el nombre del estudiante: ");
    scanf("%s", estudiante.nombre);
    printf("Ingrese el apellido del estudiante: ");
    scanf("%s", estudiante.apellido);
    printf("Ingrese el DNI del estudiante: ");
    scanf("%s", estudiante.dni);
    printf("�Est� aprobado? (1 para s�, 0 para no): ");
    scanf("%d", &estudiante.aprobado);

    // Escribir el estudiante en el archivo
    fwrite(&estudiante, sizeof(struct Estudiante), 1, archivo);
}

// Funci�n para eliminar un estudiante del archivo
void eliminarEstudiante(FILE *archivo, const char *dniAEliminar) {
    FILE *tempArchivo = fopen("temp.dat", "wb");

    if (tempArchivo == NULL) {
        perror("Error al abrir el archivo temporal");
        return;
    }

    struct Estudiante estudiante;

    while (fread(&estudiante, sizeof(struct Estudiante), 1, archivo) == 1) {
        if (strcmp(estudiante.dni, dniAEliminar) != 0) {
            fwrite(&estudiante, sizeof(struct Estudiante), 1, tempArchivo);
        }
    }

    fclose(archivo);
    fclose(tempArchivo);
    remove("estudiantes.dat");
    rename("temp.dat", "estudiantes.dat");
}

// Funci�n para mostrar la lista de estudiantes
void mostrarEstudiantes(FILE *archivo) {
    struct Estudiante estudiante;
    rewind(archivo);

    printf("\n** Lista de Estudiantes **\n");
    while (fread(&estudiante, sizeof(struct Estudiante), 1, archivo) == 1) {
        printf("Nombre: %s %s\nDNI: %s\nAprobado: %s\n", estudiante.nombre, estudiante.apellido, estudiante.dni, estudiante.aprobado ? "S�" : "No");
        printf("------------------------------------------------------\n");
    }
}

int main() {
    int opcion;
    FILE *archivo;

    while (1) {
        mostrarMenu();
        printf("Introduzca una opci�n: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                // Crear archivo de estudiantes
                archivo = fopen("estudiantes.dat", "ab");
                if (archivo == NULL) {
                    perror("Error al crear el archivo de estudiantes");
                } else {
                    printf("Archivo de estudiantes creado con �xito.\n");
                    fclose(archivo);
                }
                break;

            case 2:
                // Cargar archivo de estudiantes
                archivo = fopen("estudiantes.dat", "rb");
                if (archivo == NULL) {
                    perror("Error al abrir el archivo de estudiantes");
                } else {
                    printf("Archivo de estudiantes cargado con �xito.\n");
                }
                break;

            case 3:
                // Agregar estudiante
                if (archivo != NULL) {
                    agregarEstudiante(archivo);
                } else {
                    printf("Primero debe cargar un archivo de estudiantes.\n");
                }
                break;

            case 4:
                // Eliminar estudiante
                if (archivo != NULL) {
                    char dniAEliminar[20];
                    printf("Ingrese el DNI del estudiante a eliminar: ");
                    scanf("%s", dniAEliminar);
                    eliminarEstudiante(archivo, dniAEliminar);
                    printf("Estudiante eliminado con �xito.\n");
                } else {
                    printf("Primero debe cargar un archivo de estudiantes.\n");
                }
                break;

            case 5:
                // Mostrar lista de estudiantes
                if (archivo != NULL) {
                    mostrarEstudiantes(archivo);
                } else {
                    printf("Primero debe cargar un archivo de estudiantes.\n");
                }
                break;

            case 6:
                // Eliminar archivo de estudiantes
                if (remove("estudiantes.dat") == 0) {
                    printf("El archivo de estudiantes ha sido eliminado.\n");
                } else {
                    perror("Error al eliminar el archivo de estudiantes");
                }
                archivo = NULL;
                break;

            case 7:
                // Salir del programa
                if (archivo != NULL) {
                    fclose(archivo);
                }
                printf("Saliendo...\n");
                exit(0);

            default:
                printf("Opci�n no v�lida. Intente de nuevo.\n");
                break;
        }
    }

    return 0;
}
