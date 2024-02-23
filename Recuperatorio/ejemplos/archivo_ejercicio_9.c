/*
EJERCICIO 9
Escribe un programa que cuente con una funci�n que solicite 2 (dos) n�meros n y
m entre 1 y 10, lea el archivo �tabla-n.txt� con la tabla de multiplicar de ese n�mero,
y muestre por pantalla la l�nea m del archivo. Si el archivo no existe debe mostrar
un mensaje por pantalla informando de ello.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
void buscar(const char nombreArchivo[], int n, int m);

// FUNCION PRINCIPAL DEL PROGRMA
int main() {
    int n, m;
    char nombreArchivo[20];

    // el usuario debe cargar los valores permiido de n y m de lo contrario vuelve a preguntar
    do {
        printf("Valor n (nombre del archivo): ");
        scanf("%d", &n);

        printf("Valor m (linea a buscar): ");
        scanf("%d", &m);
    } while ((n < 1 || n > 10) || (m < 1 || m > 10));

    //busca el archivo creado si existe o no
    sprintf(nombreArchivo, "tabla-%d.txt", n);
    // busca en el archivo el numero de linea
    buscar(nombreArchivo, n, m-1);

    return 0;
}

// FUNCION QUE REALIZA LA BUSQUEDAD DE ARCHIVO Y BUSCA LA LINEA M
void buscar(const char nombreArchivo[], int n, int m) {

    FILE *archivo = fopen(nombreArchivo, "r");

    if (archivo == NULL) {
        printf("El archivo '%s' no existe.\n", nombreArchivo);
        return;
    }

    char linea[100];
    int lineaActual = 0;

    // Leer la primera l�nea del archivo
    if (fgets(linea, sizeof(linea), archivo) == NULL) {
        printf("El archivo '%s' est� vac�o.\n", nombreArchivo);
        fclose(archivo);
        return;
    }

    do {
        if (lineaActual == m) {
            printf("%s", linea);
            break;
        }
        lineaActual++;
    } while (fgets(linea, sizeof(linea), archivo) != NULL);

    if (lineaActual < m) {
        printf("La l�nea %d no existe en '%s'.\n", m, nombreArchivo);
    }

    fclose(archivo);
}
