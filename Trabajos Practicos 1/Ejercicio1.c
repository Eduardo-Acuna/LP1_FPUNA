/*
EJERCICIO 1:
Escribe un programa recursivo en lenguaje C que permita invertir un número.
Ejemplo:
Entrada: 123,
Salida: 321.
*/

# include <stdio.h>

// Constructor de la funcion recursiva
void invertir( int n);

// Funcion Principal del Programa
int main(){
    int nro;

    do{
        printf("\nIngrese un numero: ");
        scanf("%d", &nro);
        if ( nro<0 )    {
            printf("\nERROR... ingrese un numero entero positivo.");
        }
    } while ( nro<0 );

    // Se hace el llamado para la inversion del numero
    printf("\nEl nro invertido es: ");
    invertir( nro );

    return 0;
}


// Funcion recursiva que invierte el digito ingresado
void invertir( int n){
    printf("%d",n%10);
    if ( n>10 ){
        invertir( n/10 );
    }
}
