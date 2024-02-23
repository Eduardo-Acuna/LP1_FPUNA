/*
EJERCICIO 6
Crea un programa que abra un archivo llamado “prueba.txt” (previamente creado
con el block de notas y guardado en la misma carpeta donde este el programa) y
que muestre el contenido del mismo por pantalla carácter a carácter.
*/

#include <stdio.h>

int main() {
    int caracter;
    // Abre el archivo "prueba.txt"
    FILE *archivo = fopen("prueba.txt", "r");


    // Verifica si el archivo se abrio correctamente
    if ( archivo==NULL ){
        printf("ERROR... no se puede abrir el archivo.\n");
        return 1;
    }


    // Lee y muestra el contenido
    while( caracter!=EOF ){

        // Imprime el carácter
        printf("\n%c", caracter);

        // Lee el siguiente carácter del archivo
        caracter = fgetc(archivo);
    }

    // Cierra el archivo
    fclose(archivo);

    return 0;
}
