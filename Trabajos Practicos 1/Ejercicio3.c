/*
EJEMPLO 3:
Diseña un programa y una función recursiva que liste todos los subconjuntos de n
letras para un conjunto dado de m letras.
Ejemplo:
Si m = 4 y n = 2
[A, C, E, K]
[A, C] ,
[A, E] ,
[A, K] ,
[C, E] ,
[C, K] ,
[E, K]
Nota: El número de subconjuntos es C 4 , 2.
*/

#include <stdio.h>

// Constructor de las funciones que permite combinar, cargar y mostrar
void conbinacion(char conj[], char sub[], int m, int n, int inicio, int sub_num);
void cargar( char conj[], int m, int i);
void mostrar( char conj[], int m, int i);


// Funcion Principal del Programa
int main() {
    int m, n, i;

    printf("Cantidad de letras que va tener el conjunto (m): "); scanf("%d", &m);
    printf("Cantidad de letra que forma el subconjunto (n): "); scanf("%d", &n);

    char conjunto[m];
    char subconjunto[n];

    cargar( conjunto, m, 0);
    mostrar( conjunto, m, 0);

    printf("\nLos Subconjuntos formado son:\n");
    combinacion( conjunto, subconjunto, m, n, 0, 0); //Funcion que resuelve e imprime la combinacion

    return 0;
}



// Funcion recursiva que realiza la combinacion sin repetir
void combinacion(char conj[], char sub[], int m, int n, int inicio, int sub_num) {
    int i;

    if (sub_num == n) { // Condicion de corte
        // Caso base: Cuando el subconjunto está completo se procede a imprimir.
        for ( i=0 ; i<n ; i++) {
            printf("%c ", sub[i]);
        }
        printf("\n");
    } else {
        for ( i=inicio ; i<m ; i++) {
            sub[sub_num] = conj[i];
            combinacion(conj, sub, m, n, i+1, sub_num+1);
        }
    }
}


// Funcion que se encarga de pedir al usuario que cargue las letras para el conjunto
void cargar( char conj[], int m, int i){
    printf("\nCARGAR ELEMENTO AL CONJUNTO: \n");
    for ( i=0 ; i<m ; i++ ) {
        printf("P[%d]: ", i);
        scanf(" %c", &conj[i]);
    }
}

// Funcion que muetra las combincaion del conjunto
void mostrar(char conj[], int m, int i){
    printf("\nLos elemento del conjunto: ");
    for ( i=0 ; i<m ; i++ ){
        printf("%c", conj[i]);
    }
}


