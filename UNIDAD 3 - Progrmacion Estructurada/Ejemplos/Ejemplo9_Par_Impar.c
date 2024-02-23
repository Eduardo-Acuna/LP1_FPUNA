#include<stdio.h>
#include<conio.h>

int main()
{
    int numero;

    printf("Introduzca un numero entero: ");
    scanf("%d",&numero);

    if (numero%2==0)
        printf("ES PAR");
    else
        printf("ES IMPAR");

    getch();
    return 0;
}
