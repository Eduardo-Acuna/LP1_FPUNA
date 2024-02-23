#include<stdio.h>
#include<conio.h>

int main()
{
    int cantiad;
    float precio,importe;

    printf("Ingrese el precio del articulo: ");
    scanf("%f",&precio);

    printf("Cantidad que va llevar: ");
    scanf("%i",&cantiad);

    importe=precio*cantiad;

    printf("El toatal a pagar es: %f",importe);

    getch();
    return 0;
}
