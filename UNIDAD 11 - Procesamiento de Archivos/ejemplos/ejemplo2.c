#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void mMenu();
void mArchCreados();
void elimArch(char *nomArch );

int main(){
    int opcion;
    char nomArch[50];

    FILE *archivo;

    while (1){
        mMenu();
        printf("\n\tOpcion: ");
        scanf("%d",&opcion);

        switch (opcion){
            // 1 CREAR UN ARCHIVO NUEVO
            case 1:
                printf("\n1. CREAR UN ARCHIVO NUEVO");
                printf("\nNombre del archivo nuevo: ");
                scanf("%s",nomArch);

                archivo = fopen(nomArch, "w");

                if ( archivo==NULL ){
                    perror("ERROR al crear...");
                } else {
                    printf("El archivo se creo con exito.\n");
                    fclose( archivo );
                }
                break;

            // 2 CARGAR UN ARCHIVO EXISTENTE
            case 2:
                printf("\n2. CARGAR UN ARCHIVO EXISTENTE");
                printf("\nNombre del archivo a cargar: ");
                scanf("%s",nomArch);

                archivo = fopen(nomArch, "r");

                if ( archivo==NULL ){
                    perror("ERROR al abrir...");
                } else {
                    printf("El archivo se cargo con exito.\n");
                    fclose( archivo );
                }
                break;

            // 3 LEER Y MOSTRAR LOS DATOS
            case 3:
                printf("\n3. LEER Y MOSTRAR LOS DATOS");

                archivo = fopen( nomArch, "r");

                if ( archivo!=NULL ){
                    printf("\n           DATOS DE ESTUDIANTES         \n");
                    char linea[100];

                    while( fgets( linea, sizeof(linea), archivo)!=NULL){
                        printf("%s", linea);
                    }

                    fclose(archivo);
                } else {
                    printf("\nNo se cargo ningun archivo...");
                }
                break;

            // 4 MOSTRAR LISTA DE ARCHIVOS CREADOS
            case 4:
                printf("\n4. MOSTRAR LISTA DE ARCHIVOS CREADOS");

                mArchCreados();
                break;

            // 5 ELIMINAR UN ARCHIVO
            case 5:
                printf("\n5. ELIMINAR UN ARCHIVO");

                printf("\nNombre del archivo para eliminar: ");
                scanf("%s",nomArch);
                elimArch( nomArch );
                break;

            // 6 SALIR DEL PROGRAMA
            case 6:
                printf("\nFin del programa...");
                exit(0);

            default:
                printf("\nOpcion invalidad... Intente de nuevo");

        }
    }

    return 0;
}



void mMenu(){
    printf("\n\t+----------------------------------------+");
    printf("\n\t|               MENU                     |");
    printf("\n\t+----------------------------------------+");
    printf("\n\t| 1. Crear un archivo nuevo              |");
    printf("\n\t| 2. Cargar un archivo existente         |");
    printf("\n\t| 3. Leer y mostrar los datos            |");
    printf("\n\t| 4. Mostrar lista de archivos creados   |");
    printf("\n\t| 5. Eliminar un archivo                 |");
    printf("\n\t| 6. Salir                               |");
    printf("\n\t+----------------------------------------+");
}



void mArchCreados(){
    struct dirent *entrada;

    DIR * directorio = opendir(".");

    if ( directorio ){
        printf("\n           ARCHIVOS CREADOS         ");

        while( (entrada=readdir(directorio))!=NULL ){
            if ( entrada->d_name[0]!='.'){
                printf("\n%s",entrada->d_name);
            }
        }
        closedir(directorio);
    } else {
        perror("ERROR... no se puede abrir el directorio. ");
    }
}


void elimArch(char *nomArch ){

    if ( remove(nomArch)==0 ){
        printf("[%s] se ha sido eliminado.\n", nomArch);
    } else {
        perror("ERROR... no se puede eliminar el archivo.");
    }
}






