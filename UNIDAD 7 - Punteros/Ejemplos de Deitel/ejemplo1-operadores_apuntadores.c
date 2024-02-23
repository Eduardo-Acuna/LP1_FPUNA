/* Figura 7.4: fig07_04.c
Uso de los operadores & y * */
#include <stdio.h>

int main()
{
    int a; /* a es un entero */
    int *ptrA; /* ptrA es un apuntador a un entero */

    a = 7;

    ptrA = &a; /* ptrA toma la dirección de a */

    printf( "La direccion de a es: %p",&a);
    printf( "\nEl valor de ptrA es: %p", ptrA );

    printf( "\n\nEl valor de a es: %d", a);
    printf( "\nEl valor de *ptrA es: %d", *ptrA );

    printf( "\n\nMuestra de que * y & son complementos ");
    printf( "uno del otro\n&*ptrA = %p", &*ptrA);
    printf( " \n*&ptrA = %p\n", *&ptrA );

    return 0; /* indica terminación exitosa */
}
