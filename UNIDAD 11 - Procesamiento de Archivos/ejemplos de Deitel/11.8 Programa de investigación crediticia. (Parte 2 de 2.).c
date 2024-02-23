#include <stdio.h>

int main(){
    int consulta;        // número de solicitud
    int cuenta;          // número de cuenta
    double saldo;        // saldo de la cuenta
    char nombre[30];     // nombre de la cuenta

    FILE *ptrCf;         // apuntador al archivo clientes.dat

    // fopen abre el archivo; si no se puede abrir el archivo, abandona el programa
    if ((ptrCf = fopen("clientes.txt", "r")) == NULL){
        printf("El archivo no pudo abrirse\n");
    } else {
        // Despliega las opciones de consulta
        printf("Introduzca la consulta\n"
               " 1 - Lista las cuentas con saldo cero\n"
               " 2 - Lista las cuentas con saldo a favor\n"
               " 3 - Lista las cuentas con saldo en contra\n"
               " 4 - Fin del programa\n? ");
        scanf("%d", &consulta);

        // Procesa la consulta del usuario
        while (consulta != 4){
            // Lee la cuenta, el nombre y el saldo del archivo
            fscanf(ptrCf, "%d %29s %lf", &cuenta, nombre, &saldo);

            switch (consulta){
                case 1:
                    printf("\nCuentas con saldo cero:\n");

                    // Lee el contenido del archivo (hasta eof)
                    while (!feof(ptrCf)){
                        if (saldo == 0){
                            printf("%-10d%-13s%7.2f\n", cuenta, nombre, saldo);
                        }

                        // Lee la cuenta, el nombre y el saldo del archivo
                        fscanf(ptrCf, "%d %29s %lf", &cuenta, nombre, &saldo);
                    }
                    break;

                case 2:
                    printf("\nCuentas con saldos a favor:\n");

                    // Lee el contenido del archivo (hasta eof)
                    while (!feof(ptrCf)){
                        if (saldo < 0){
                            printf("%-10d%-13s%7.2f\n", cuenta, nombre, saldo);
                        }

                        // Lee la cuenta, el nombre y el saldo del archivo
                        fscanf(ptrCf, "%d %29s %lf", &cuenta, nombre, &saldo);
                    }
                    break;

                case 3:
                    printf("\nCuentas con saldo en contra:\n");

                    // Lee el contenido del archivo (hasta eof)
                    while (!feof(ptrCf)){
                        if (saldo > 0){
                            printf("%-10d%-13s%7.2f\n", cuenta, nombre, saldo);
                        }

                        // Lee la cuenta, el nombre y el saldo del archivo
                        fscanf(ptrCf, "%d %29s %lf", &cuenta, nombre, &saldo);
                    }
                    break;
            }

            rewind(ptrCf); // Devuelve ptrCf al principio del archivo

            printf("? ");
            scanf("%d", &consulta);
        }

        printf("Fin de la ejecución.\n");
        fclose(ptrCf); // fclose cierra el archivo
    }

    return 0; // Indica terminación exitosa
}
