#include <stdio.h>

// Funci�n recursiva para calcular la suma de los d�gitos de un n�mero entero
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

    cargar_suma(sumas,digito,n); // Se c�lculo la suma de los d�gitos de cada n�mero que se ingrese

    mayor = nro_mayor(sumas,n); // B�squeda del n�mero con la suma de d�gitos mayor

    printf("El numero con la mayor suma es el: %d \nSu suma es: %d\n", digito[mayor], sumas[mayor]); // Salida de resultados

    return 0;
}


int sumar_nro(int n) {
    int resultado;

    if (n < 10) {
        resultado = n;
    } else {
        resultado = sumar_nro(n/10)+n%10;
    }

    return resultado;
}


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


void cargar_suma(int S[], int D[], int n){
    int i;

    // Se c�lculo la suma de los d�gitos de cada n�mero que se ingrese
    for ( i=0 ; i<n ; i++) {
        S[i] = sumar_nro(D[i]);
    }
}



// Funcio que cargar los
void cargar_nro(int V[], int n){
    int i;

    // Lectura de los n�meros enteros
    for ( i=0 ; i<n ; i++ ){
        printf("D[%d]: ", i+1);
        scanf("%d", &V[i]);
    }
}


