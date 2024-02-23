#include <stdio.h>

int main(){
    int cuenta;            // número de cuenta
    char nombre[30];       // nombre de cuenta
    double saldo;          // saldo de la cuenta

    int cont=1;

    FILE *ptrCf;           // ptrCf = apuntador al archivo clientes.dat

    // fopen abre el archivo.
    //Si no es capaz de crear el archivo, sale del programa
    if ((ptrCf = fopen("clientes.txt", "w")) == NULL){
        printf("El archivo no pudo abrirse\n");
    } else {
        printf("Introduzca la cuenta, el nombre, y el saldo.\n");
        printf("Introduzca EOF al final de la entrada.\n");
        printf("%d> ",cont++);
        scanf("%d %29s %lf", &cuenta, nombre, &saldo);

        // Escribe la cuenta, el nombre y el saldo dentro del archivo con fprintf
        while ( !feof(stdin) ){
            fprintf(ptrCf, "%d %s %.2f\n", cuenta, nombre, saldo);
            printf("%d> ",cont++);
            scanf("%d %29s %lf", &cuenta, nombre, &saldo);
        }

        fclose(ptrCf); // fclose cierra el archivo
    }

    return 0; // Indica terminación exitosa
}
