/*
EJERCIICO 2:
Escribe un programa que retorne la cantidad de dígitos pares de un número entero
positivo N. El dígito 0 (cero) debe considerarse como par.
Ejemplo: Si N = 23025,
el resultado es 3.

*/

# include <stdio.h>

// Constructor de la funcion recursiva
int cant_pares( int num );

// Funcion Principal del Programa
int main(){
    int N;
    int respuesta ;

    // Controla si N es un numero entero positivo
    do{
        printf("\nIngrese un numero: ");
        scanf("%d",&N);
        if ( N<0 ){
            printf("\nERROR... ingrese un numero entero positivo.");
        }
    } while ( N<0 );

    respuesta = cant_pares(N);

    printf("La cantidad de numero pares de (%d) es: %d", N, respuesta );

    return 0;
}

// Funcion recursiva que cuenta la cantidad de numero pares en N
int cant_pares( int num ){
    int cont, dig;

    if ( num==0 ){    // Condicion de corte
        cont = 0;   // Caso base
    } else {
        dig = num%10;     // Sacamos el un digito y guaradmos en la variable
        if ( dig%2==0 ){
            cont = 1+cant_pares( num/10 );
        } else {
            cont = cant_pares(num/10);
        }
    }

    return cont;
}
