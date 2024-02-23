# include <stdio.h>
# include <stdlib.h>

int main(){
    FILE *archivo;

    archivo = fopen("datos.txt","r");

    if ( archivo==NULL ){
        perror("Erorr al abrir el archivo");
        return 1;
    }

    char nombre[50];
    char apellido[50];
    int edad;

    while( fscanf(archivo,"%s %s %d",nombre, apellido, &edad)!= EOF ){
        printf("Nombre: %s %s, \tEdad:%d\n",nombre, apellido, edad);
    }

    fclose(archivo);

    return 0;
}

