/*
EJERCICIO 5:
Escribe un programa que tenga como entrada una secuencia de números enteros
positivos (mediante una variable entera). El programa debe hallar la suma de los
dígitos de cada entero y encontrar cual es el entero cuya suma de dígitos es mayor.
La suma de dígitos se ha de realizar con una función recursiva.
*/

#include <stdio.h>

// Constructores de las funciones que suma los numero, Carga numeros el usuario, cargar la suma realiza de los digitos y calcula el indice con la mayor suma.
int sumar_nro(int n);
void cargar_nro(int V[], int n);
void cargar_suma(int S[], int D[], int n);
int nro_mayor(int S[], int n);


// Programa principal
int main() {
    int n, mayor, suma;

    // Entrada de numero n
    do{
        printf("Ingrese cuantos numero quiere cargar: ");
        scanf("%d", &n);
    } while( n<=0 );

    // Variables para almacenar los datos
    int digito[n];
    int sumas[n];

    cargar_nro(digito,n);

    cargar_suma(sumas,digito,n); // Se cálculo la suma de los dígitos de cada número que se ingrese

    mayor = nro_mayor(sumas,n); // Búsqueda del número con la suma de dígitos mayor

    printf("El numero con la mayor suma es el: %d \nSu suma es: %d\n", digito[mayor], sumas[mayor]); // Salida de resultados

    return 0;
}

// Función Recursiva que realiza la suma de los dígitos
int sumar_nro(int n) {
    int resultado;

    if (n < 10) {
        resultado = n;
    } else {
        resultado = sumar_nro(n/10)+n%10;
    }

    return resultado;
}

// Funcion que saca el indice con la mayor suma que se almaceno en el vector sumas
int nro_mayor(int S[], int n){
    int i, m;
    m = 0;
    for ( i=0 ; i<n ; i++) {
        if ( S[i]>S[m]) {
            m = i;
        }
    }
    return m;
}

// Funcion que se encargar de cagar la suma de todos los digitos que los numero que se almaceno
void cargar_suma(int S[], int D[], int n){
    int i;

    // Se cálculo la suma de los dígitos de cada número que se ingrese
    for ( i=0 ; i<n ; i++) {
        S[i] = sumar_nro(D[i]);// Función Recursiva que realiza la suma de los dígitos
    }
}



// Funcion que almacena los digitos que ingresa el usuario
void cargar_nro(int V[], int n){
    int i;

    // Lectura de los números enteros
    for ( i=0 ; i<n ; i++ ){
        printf("D[%d]: ", i+1);
        scanf("%d", &V[i]);
    }
}


