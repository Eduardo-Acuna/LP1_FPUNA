/*
EJEJRCICIO 3
Lee un número entero positivo, conviértelo a hexadecimal e imprime la mitad
derecha de sus dígitos hexadecimales seguido de la mitad izquierda.
Si al convertido a hexadecimal, el número tiene una cantidad impar de
dígitos, agregar un '0' (cero) como el primer dígito de la izquierda.

*/


# include <stdio.h>
# include <stdlib.h>

//CONSTRUCTOR DE LA FUNCION
void convHex(unsigned int n,char h[]);
void impHex(char h[]);
void intercambiarMitades(char h[]);

//FUNACION PRINCIPAL DEL PROGRAMA
int main(){
    unsigned int num;
    char hex[50];

    printf("\nCONVERSION A HEXADECIMAL");
    printf("\nIngresa un nUmero entero positivo. ");
    printf("\nNumero entero:");
    scanf("%u", &num);

    convHex(num,hex);
    printf("Numero hexadecimal normal: ");
    impHex(hex);

    intercambiarMitades(hex);
    printf("\nNumero hexadecimal cambiado: ");
    impHex(hex);

    //printf("\nNumero en hexagesimal: %s",numHex);

    return 0;
}


//FUNES QUE SE ENCARGA DE REALIZAR LA CONVERSION Y DE IMPRIMIR
void convHex(unsigned int n,char h[]){
    int resto, cont;
    cont=0;

    while( n>0 ){
        resto=n%16;
        if( resto<10 ){
            // Dígitos del '0' al '9'
            h[cont++] = resto+'0';
        } else {
            // Dígitos 'A' al 'F'
            h[cont++] = resto-10+'A';
        }
        n=n/16;
    }

    if (cont%2 != 0) {
        h[cont++]='0';
    }
}

void intercambiarMitades(char h[]){
    int mitad, tam, i,j;
    char aux;

    tam = strlen(h);
    mitad = tam/2;

    // si es impar
    if ( tam%2!=0 ){
        for (i=tam ; i>=0 ; i-- ){
            h[i+1]=h[i];
        }
        h[0]='0';
        tam++;
    }

    //intercambia
    for ( i=0 ; i<mitad ; i++ ){
        aux = h[i];
        h[i] = h[i + mitad];
        h[i + mitad] = aux;
    }

}

void impHex(char h[]){
    int i,tam;
    tam=strlen(h);

    for (i=tam-1 ; i>=0 ; i--) {
        printf("%c", h[i]);
    }
}










