/* Figura 6.11: fig06_11.c
02 Arreglos est�ticos que se inicializan a cero */
#include <stdio.h>

void iniciaArregloEstatico( void ); /* prototipo de la funci�n */
void iniciaArregloAutomatico( void ); /* prototipo de la funci�n */



/* la funci�n main comienza la ejecuci�n del programa */
int main()
{
    printf( "Primera llamada a cada funcion:\n" );
    iniciaArregloEstatico();
    iniciaArregloAutomatico();

    printf( "\n\nSegunda llamada a cada funcion:\n" );
    iniciaArregloEstatico();
    iniciaArregloAutomatico();

    return 0; /* indica terminaci�n exitosa */
}



/* funci�n para demostrar un arreglo est�tico local */
void iniciaArregloEstatico( void )
{
    /* inicializa los elementos a 0 la primera vez que se llama a la funci�n */
    static int arreglo1[ 3 ];
    int i; /* contador */

    printf( "\nValores al entrar a iniciaArregloEstatico:\n" );

    /* muestra el contenido del arreglo1 */
    for ( i=0; i<=2; i++ ) {
        printf( "arreglo1[%d] = %d ", i, arreglo1[i]);
    }

    printf( "\nValores al salir de iniciaArregloEstatico:\n" );

    /* modifica y muestra el contenido de arreglo1 */
    for ( i=0; i<=2; i++ ) {
        printf("arreglo1[%d] = %d ", i, arreglo1[i]+=5 );
    }
}





/* funci�n para demostrar un arreglo local autom�tico */
void iniciaArregloAutomatico( void )
{
    /* inicializa los elementos cada vez que se llama a la funci�n */
    int arreglo2[3]={ 1, 2, 3 };
    int i; /* contador */

    printf( "\n\nValores al entrar a iniciaArregloAutomatico:\n" );

    /* muestra el contenido de arreglo2 */
    for ( i=0; i<=2; i++ ) {
        printf("arreglo2[%d] = %d ", i, arreglo2[i]);
    }

    printf( "\nValores al salir de iniciaArregloAutomatico:\n" );

    /* modifica y muestra el contenido de arreglo2 */
    for ( i=0; i<=2; i++ ) {
        printf( "arreglo2[%d] = %d ", i, arreglo2[i]+=5);
    }
}
