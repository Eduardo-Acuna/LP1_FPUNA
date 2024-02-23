/*
EJERCICIO 7
Crea un programa que vaya leyendo las frases que el usuario teclea y las guarde
en un archivo de texto llamado “registrodeusuario.txt”. Terminará cuando la frase
introducida sea "fin" (la última frase “fin” no deberá guardarse en el archivo).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// FUNCION PRINCIPAL
int main(){

    // Crea un archivo con el nombre "entrada.txt"
    FILE *archivo = fopen("registrodeusuario.txt","w");

    // Verifica que el archivo se haya creado correctamente
    if( archivo==NULL ) {
        printf("Error.. no se creo correctamente el archivo.\n");
        return 1;
    }

    // Variable para almacenar la entrada del usuario
    char frase[100];

    printf(" Ingrese una frase\n(fin para terminar)\n");
    // Bucle para cargar la entrada del usuario
    while (1) {
        // Solicita la entrada del usuario
        printf("frase: ");
        gets(frase);
        frase[strcspn(frase,"\n")]='\0';

        // Verifica si es "fin"
        if( strcmp(frase,"fin")==0 ){
            break;
        }

        // Escribe la entrada del usuario en el archivo
        fprintf(archivo, "%s\n", frase);
    }

    fclose(archivo);

    printf("\n\nfin del programa... ");

    return 0;
}
