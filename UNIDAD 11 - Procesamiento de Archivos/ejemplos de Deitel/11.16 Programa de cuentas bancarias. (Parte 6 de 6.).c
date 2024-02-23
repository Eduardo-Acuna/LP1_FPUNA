
#include <stdio.h>

/* Definición de la estructura datosCliente */
struct datosCliente {
    int numCta;         // número de cuenta
    char apellido[15];  // apellido
    char nombre[10];    // nombre
    double saldo;       // saldo
};

/* Prototipos de funciones */
int intOpcion(void);
void archivoTexto(FILE *ptrLee);
void actualizaRegistro(FILE *ptrF);
void nuevoRegistro(FILE *ptrF);
void eliminaRegistro(FILE *ptrF);

int main() {
    FILE *ptrCf; // Apuntador al archivo credito.dat
    int eleccion; // Elección del usuario

    // fopen abre el archivo; si no se puede abrir, sale del programa
    if ((ptrCf = fopen("credito.dat", "rb+")) == NULL) {
        printf("El archivo no pudo abrirse.\n");
    } else {
        // Permite al usuario especificar una acción
        while ((eleccion = intOpcion()) != 5) {
            switch (eleccion) {
                case 1: // Crea el archivo desde el registro
                    archivoTexto(ptrCf);
                    break;
                case 2: // Actualiza registro
                    actualizaRegistro(ptrCf);
                    break;
                case 3: // Crea registro
                    nuevoRegistro(ptrCf);
                    break;
                case 4: // Elimina el registro existente
                    eliminaRegistro(ptrCf);
                    break;
                default: // Si el usuario no selecciona una opción válida, muestra un mensaje
                    printf("Opción incorrecta\n");
                    break;
            }
        }

        fclose(ptrCf); // fclose cierra el archivo
    }

    return 0; // Indica terminación exitosa
}

// Crea un archivo de texto con formato para impresión
void archivoTexto(FILE *ptrLee) {
    FILE *ptrEscribe; // Apuntador del archivo cuentas.txt

    // Crea datosCliente con información predeterminada
    struct datosCliente cliente = {0, "", "", 0.0};

    // fopen abre el archivo; si no se puede abrir, sale del programa
    if ((ptrEscribe = fopen("cuentas.txt", "w")) == NULL) {
        printf("No pudo abrirse el archivo.\n");
    } else {
        rewind(ptrLee); // Establece el apuntador en el principio del archivo
        fprintf(ptrEscribe, "%-6s%-16s%-11s%10s\n", "Cta", "Apellido", "Nombre", "Saldo");

        // Copia todos los registros del archivo de acceso aleatorio dentro del archivo de texto
        while (!feof(ptrLee)) {
            fread(&cliente, sizeof(struct datosCliente), 1, ptrLee);

            // Escribe un registro individual en el archivo de texto
            if (cliente.numCta != 0) {
                fprintf(ptrEscribe, "%-6d%-16s%-11s%10.2f\n", cliente.numCta, cliente.apellido, cliente.nombre, cliente.saldo);
            }
        }

        fclose(ptrEscribe); // fclose cierra el archivo
    }
}

// Actualiza el saldo en el registro
void actualizaRegistro(FILE *ptrF) {
    int cuenta; // Número de cuenta
    double transaccion; // Monto de la transacción

    // Crea datosCliente sin información
    struct datosCliente cliente = {0, "", "", 0.0};

    // Obtiene el número de cuenta para actualización
    printf("Introduzca cuenta para actualización (1 - 100): ");
    scanf("%d", &cuenta);

    // Mueve el apuntador de archivo para corregir el registro del archivo
    fseek(ptrF, (cuenta - 1) * sizeof(struct datosCliente), SEEK_SET);

    // Lee un registro del archivo
    fread(&cliente, sizeof(struct datosCliente), 1, ptrF);

    // Muestra un error si la cuenta no existe
    if (cliente.numCta == 0) {
        printf("La cuenta #%d no tiene información.\n", cuenta);
    } else { // Actualiza el registro
        printf("%-6d%-16s%-11s%10.2f\n\n", cliente.numCta, cliente.apellido, cliente.nombre, cliente.saldo);
        printf("Introduzca el cargo (+) o el pago (-): ");
        scanf("%lf", &transaccion);
        cliente.saldo += transaccion; // Actualiza el saldo del registro
        printf("%-6d%-16s%-11s%10.2f\n", cliente.numCta, cliente.apellido, cliente.nombre, cliente.saldo);
        fseek(ptrF, (cuenta - 1) * sizeof(struct datosCliente), SEEK_SET);
        fwrite(&cliente, sizeof(struct datosCliente), 1, ptrF);
    }
}

// Elimina el registro existente
void eliminaRegistro(FILE *ptrF) {
    struct datosCliente cliente; // Almacena los registros leídos en el archivo
    struct datosCliente clienteEnBlanco = {0, "", "", 0}; // Cliente en blanco
    int numCuenta; // Número de cuenta

    // Obtiene el número de cuenta para eliminarlo
    printf("Introduzca el número de cuenta a eliminar (1 - 100): ");
    scanf("%d", &numCuenta);

    // Mueve el apuntador de archivo al registro correcto en el archivo
    fseek(ptrF, (numCuenta - 1) * sizeof(struct datosCliente), SEEK_SET);

    // Lee el registro del archivo
    fread(&cliente, sizeof(struct datosCliente), 1, ptrF);

        // Si el registro no existe, muestra un error
    if (cliente.numCta == 0) {
        printf("La cuenta %d no existe.\n", numCuenta);
    } else { // Elimina el registro
        fseek(ptrF, (numCuenta - 1) * sizeof(struct datosCliente), SEEK_SET);
        fwrite(&clienteEnBlanco, sizeof(struct datosCliente), 1, ptrF);
    }
}

// Crea e inserta un nuevo registro
void nuevoRegistro(FILE *ptrF) {
    // Crea datosCliente con información predeterminada
    struct datosCliente cliente = {0, "", "", 0.0};
    int numCuenta; // Número de cuenta

    // Obtiene el número de cuenta a crear
    printf("Introduzca el nuevo número de cuenta (1 - 100): ");
    scanf("%d", &numCuenta);

    // Mueve el apuntador de archivo al registro correcto en el archivo
    fseek(ptrF, (numCuenta - 1) * sizeof(struct datosCliente), SEEK_SET);

    // Lee el registro desde el archivo
    fread(&cliente, sizeof(struct datosCliente), 1, ptrF);

    // Si la cuenta ya existe, muestra un error
    if (cliente.numCta != 0) {
        printf("La cuenta #%d ya contiene información.\n", cliente.numCta);
    } else { // Crea el registro
        // El usuario introduce el apellido, el nombre y el saldo
        printf("Introduzca el apellido, el nombre y el saldo: ");
        scanf("%s%s%lf", cliente.apellido, cliente.nombre, &cliente.saldo);
        cliente.numCta = numCuenta;

        // Mueve el apuntador de archivo al registro correcto en el archivo
        fseek(ptrF, (cliente.numCta - 1) * sizeof(struct datosCliente), SEEK_SET);

        // Inserta el registro en el archivo
        fwrite(&cliente, sizeof(struct datosCliente), 1, ptrF);
    }
}

// Habilita al usuario para introducir una opción de menú
int intOpcion(void) {
    int opcionMenu; // Variable para almacenar la opción del usuario

    // Muestra las opciones disponibles
    printf("\nIntroduzca su opción:\n");
    printf("1 - Almacena un archivo de texto con formato de las cuentas llamado \"cuentas.txt\" para impresión\n");
    printf("2 - Actualiza una cuenta\n");
    printf("3 - Agrega una nueva cuenta\n");
    printf("4 - Elimina una cuenta\n");
    printf("5 - Fin del programa\n? ");

    scanf("%d", &opcionMenu); // Recibe la opción del usuario

    return opcionMenu;
}

