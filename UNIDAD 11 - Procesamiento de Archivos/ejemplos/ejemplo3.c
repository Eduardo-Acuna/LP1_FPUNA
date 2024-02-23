#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void mostrarMenu() {
    printf("\n** Menú **\n");
    printf("1. Crear un archivo nuevo\n");
    printf("2. Cargar un archivo existente\n");
    printf("3. Leer y mostrar los datos\n");
    printf("4. Mostrar lista de archivos creados\n");
    printf("5. Eliminar un archivo\n");
    printf("6. Salir\n");
}

void mostrarArchivosCreados() {
    struct dirent *entrada;
    DIR *directorio = opendir(".");
    if (directorio) {
        printf("** Archivos Creados **\n");
        while ((entrada = readdir(directorio)) != NULL) {
            if (entrada->d_name[0] != '.') {
                printf("%s\n", entrada->d_name);
            }
        }
        closedir(directorio);
    } else {
        perror("Error al abrir el directorio");
    }
}

void eliminarArchivo(char *nombreArchivo) {
    if (remove(nombreArchivo) == 0) {
        printf("El archivo %s ha sido eliminado.\n", nombreArchivo);
    } else {
        perror("Error al eliminar el archivo");
    }
}

int main() {
    int opcion;
    char nombreArchivo[50];
    FILE *archivo;

    while (1) {
        mostrarMenu();
        printf("Introduzca una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                // Crear un archivo nuevo
                printf("Introduzca el nombre del archivo a crear: ");
                scanf("%s", nombreArchivo);
                archivo = fopen(nombreArchivo, "w");
                if (archivo == NULL) {
                    perror("Error al crear el archivo");
                } else {
                    printf("Archivo creado con éxito.\n");
                    fclose(archivo);
                }
                break;

            case 2:
                // Cargar un archivo existente
                printf("Introduzca el nombre del archivo a cargar: ");
                scanf("%s", nombreArchivo);
                archivo = fopen(nombreArchivo, "r");
                if (archivo == NULL) {
                    perror("Error al abrir el archivo");
                } else {
                    printf("Archivo cargado con éxito.\n");
                    fclose(archivo);
                }
                break;

            case 3:
                // Leer y mostrar los datos
                archivo = fopen(nombreArchivo, "r");
                if (archivo != NULL) {
                    printf("** Datos de estudiantes **\n");
                    char linea[100];
                    while (fgets(linea, sizeof(linea), archivo) != NULL) {
                        printf("%s", linea);
                    }
                    fclose(archivo);
                } else {
                    printf("No se ha cargado ningún archivo.\n");
                }
                break;

            case 4:
                // Mostrar lista de archivos creados
                mostrarArchivosCreados();
                break;

            case 5:
                // Eliminar un archivo
                printf("Introduzca el nombre del archivo a eliminar: ");
                scanf("%s", nombreArchivo);
                eliminarArchivo(nombreArchivo);
                break;

            case 6:
                // Salir del programa
                printf("Saliendo...\n");
                exit(0);

            default:
                printf("Opción no válida. Intente de nuevo.\n");
                break;
        }
    }

    return 0;
}
