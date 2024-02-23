/*
EJERCICIO 8:
Escribe un programa que cuente con una función que solicite un número entero
entre 1 y 10 y guarde en un archivo con el nombre “tabla-n.txt”, la tabla de multiplicar
de ese número, donde n es el número introducido.
*/

#include <stdio.h>
#include <stdlib.h>


void guardar(const char *nomArch, int num);
void imprimirArchivo(const char *nomArch);

// fUNCIO PRINCIPAL
int main() {
    int numero;
    char nombreArchivo[20];

    do {
        // Solicita un número al usuario
        printf("Ingrese un numero entre 1 y 10: ");
        scanf("%d", &numero);
    } while (numero < 1 || numero > 10);

    // se crea el archivo
    sprintf(nombreArchivo, "tabla-%d.txt", numero);
    FILE *archivo = fopen(nombreArchivo, "w");

    // se verifica si se guardo correctamente
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    // se guarda el archivo con los valores
    guardar(archivo, numero);
    fclose(archivo);
    // imprime el rchivo
    printf("\n\nEsto es loque se guardo dentro del archivo:");
    imprimirArchivo(nombreArchivo);
    return 0;
}


// FUNCIN QUE SE ENCARGA DE GUARDAR EN EL ARCHIVO LA TABLA DE MULTIPLICAR
void guardar(const char *nomArch, int num) {

    // Itera sobre los números del 1 al 10
    for (int i = 1; i <= 10; i++) {
        // Escribe la multiplicación
        fprintf(nomArch, "%d x %d = %d\n", num, i, num * i);
    }
    printf("\nSe cargo correctamente en el archivo...");
}


// FUNCION QUE SE ENCARGAR DE IMPRIMIR EL ARCHIVO
void imprimirArchivo(const char *nomArch) {

    printf("\nTabla de multiplicar\n");
    FILE *archivo = fopen(nomArch, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }
    char linea[100];
    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        printf("%s", linea);
    }
    fclose(archivo);
}
