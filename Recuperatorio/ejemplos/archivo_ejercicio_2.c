/*
EJERCICIO 2
Escribe un programa que reciba un número entre 1 y 3000 e imprima una
cadena que corresponde a su representación como número romano.
Recuerda que: I=1, V=5, X=10, L=50, C=100, D=500, M=1000.
*/

#include <stdio.h>
#include <string.h>

void numRoman(int n, char *resp);


// FUNCION PRINCIPAL DEL PROGRAMA
int main() {

    int num;
    char respuesta[20];

    printf("CONVERTIR UN NUMERO ENTERO A ROMANO\n");
    do {
        printf("Ingrese un numero entero entre 1 y 3000\nnumero: ");
        scanf("%d", &num);
    } while (num < 1 || num > 3000);

    numRoman(num, respuesta);

    printf("El numero en romano es: %s", respuesta);

    return 0;
}


// FUNCION QUE CONVIERTE EL NUMERO ENTERO A NUMERO ROMANO
void numRoman(int n, char *resp) {
    int i = 0;

    char *simbolos[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    int numero[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};

    resp[0]='\0'; // Inicializamos la cadena vacía

    while( n>0 ) {
        while ( n>=numero[i] ){
            strcat(resp,simbolos[i]);
            n=n-numero[i];
        }
        i++;
    }
}
