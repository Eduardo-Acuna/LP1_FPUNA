/*
EJERCICIO 4
Escribe un programa que lea 2 (dos) números N y M en base hexadecimal e
imprima la suma de ambos números, también en hexadecimal.
Los números N y M son 2 (dos) cadenas.
Ten en cuenta los valores decimales: A=10, B=11, C=12, D=13, E=14, F=15.

*/

#include <stdio.h>
#include <string.h>

//CONSTRUCTORES PARA REALIZAR LA SUMA
int esHex(char c);
void sumaHex(char N[], char M[], char resp[]);
void verificarNumero(char num[]);
void impHex(char h[]);
int hexaDec(char c);


//FUNCION PRINCIPAL DEL PROGRAMA
int main() {
    char N[100], M[100];
    char suma[100];

    printf("Valor N:");
    scanf("%s", N);
    verificarNumero(N);

    printf("Valor M:");
    scanf("%s", M);
    verificarNumero(M);

    sumaHex(N, M, suma);

    printf("La suma hexagesimal de N+M: %s\n", suma);

    return 0;
}


//Funcion que verifica si es un numero hexagesimal
void verificarNumero(char num[]) {
    int i;

    for (i = 0; num[i] != '\0'; i++) {
        if (esHex(num[i]) == 0) {
            printf("Error. no es un numero Hexagesimal.\n");
            exit(0);
        }
    }
}


// Funcion que imprime el numero hexadecimal
void impHex(char h[]) {
    int i, tam;
    tam = strlen(h);

    for (i = tam - 1; i >= 0; i--) {
        printf("%c", h[i]);
    }
}
int esHex(char c) {
    int resp;

    if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F')) {
        resp = 1;
    } else {
        resp = 0;
    }
    return resp;
}

int hexaDec(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else if (c >= 'A' && c <= 'F') {
        return c - 'A' + 10;
    }
}


// funcio que realiza la suma de los dos valores ingresados
void sumaHex(char N[], char M[], char *resp) {
    int tamN, tamM, maxTam, acarreo, suma;
    int i,k,digito1, digito2;;

    tamN = strlen(N);
    tamM = strlen(M);
    acarreo = 0;

    if (tamN > tamM) {
        maxTam = tamN;
    } else {
        maxTam = tamM;
    }

    i = maxTam - 1;
    k = 0;
    while (i >= 0) {

        if (i >= tamN) {
            digito1 = 0;
        } else {
            digito1 = hexaDec(N[i]);
        }

        if (i >= tamM) {
            digito2 = 0;
        } else {
            digito2 = hexaDec(M[i]);
        }
/*
        if (digito1 == -1 || digito2 == -1) {
            printf("Error: no es un número Hexagesimal.\n");
            return;
        }
*/
        suma = digito1 + digito2 + acarreo;

        if (suma >= 16) {
            acarreo = 1;
            suma -= 16;
        } else {
            acarreo = 0;
        }

        if (suma < 10) {
            resp[k] = suma + '0';
        } else {
            resp[k] = suma - 10 + 'A';
        }

        i--;
        k++;
    }

    if (acarreo > 0) {
        resp[k] = acarreo + '0';
        k++;
    }

    resp[k] = '\0';

    int inicio, fin;
    char aux;

    // Invertir el resultado para obtener el orden correcto
    for (inicio = 0, fin = k - 1; inicio < fin; inicio++, fin--) {
        aux = resp[inicio];
        resp[inicio] = resp[fin];
        resp[fin] = aux;
    }
}

