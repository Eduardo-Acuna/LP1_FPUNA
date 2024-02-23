#include <stdio.h>

/* Definición de la estructura datosCliente */
struct datosCliente {
    int numCta;          // número de cuenta
    char apellido[15];   // apellido de la cuenta
    char nombre[10];     // nombre de la cuenta
    double saldo;        // saldo de la cuenta
};

int main() {
    int i; // contador utilizado para contar de 1 a 100

    // Crea datosCliente con información predeterminada
    struct datosCliente clienteEnBlanco = {0, "", "", 0.0};

    FILE *ptrCf; // apuntador al archivo credito.dat

    // fopen abre el archivo; si no se puede abrir, sale del programa
    if ((ptrCf = fopen("credito.dat", "wb")) == NULL) {
        printf("No pudo abrirse el archivo.\n");
    } else {
        // Escribe 100 registros en blanco en el archivo
        for (i = 1; i <= 100; i++) {
            fwrite(&clienteEnBlanco, sizeof(struct datosCliente), 1, ptrCf);
        }

        fclose(ptrCf); // fclose cierra el archivo
    }

    return 0; // Indica terminación exitosa
}
