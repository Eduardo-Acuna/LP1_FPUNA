#include <stdio.h>
#include <math.h>

int main()
{
    int opcion,control = 1;
    float PI,area,radio,base_t,altura_t,base_r,altura_r,lado;
    PI = 3.141592;
    /*Menu del programa*/
    printf("\t---- SELECIONE UNA OPCION PARA CALCULAR ----\n");
    printf("\t 1. Area de un circulo\n");
    printf("\t 2. Area de un triangulo\n");
    printf("\t 3. Area de un rectagulo\n");
    printf("\t 4. Area de un cuadrado\n");

    do
    {
        printf("\t--------------------------------------------");
        printf("\n\tOPCION: ");
        scanf("%d", &opcion);

        if(opcion >= 1 && opcion <= 4)
        {
            if( opcion == 1 )
            {
                printf("\n\t------------- AREA DE UN CIRCULO ------------\n");
                printf("\n\tRadio :"); scanf("%f", &radio);
                area = PI*radio*radio;
            }
            else if( opcion == 2 )
            {
                printf("\n\t------------ AREA DE UN TRIANGILO ----------\n");
                printf("\n\tBase :"); scanf("%f", &base_t);
                printf("\n\tAltura :"); scanf("%f", &altura_t);
                area = base_t*altura_t*0.5;
            }
            else if( opcion == 3 )
            {
                printf("\n\t----------- AREA DE UN RECTAGULAR -----------\n");
                printf("\n\t Base :"); scanf("%f", &base_r);
                printf("\n\t Altura :"); scanf("%f", &altura_r);
                area = base_r*altura_r;
            }
            else if( opcion == 4 )
            {
                printf("\n\t------------ AREA DE UN CUADRADO ------------\n");
                printf("\n\tLado :"); scanf("%f", &lado);
                area=lado*lado;
            }
            printf("\n\tEl area es: %.2f\n", area);
        }
        else
        {
            printf("\tOPCION INVALIDA... Gracias.\n");
            control=0;
        }
    } while( control!=0);

    printf("\n\t------------ FIN DEL PROGRAMA --------------\n");
    printf("\n\t--------------------------------------------");
    printf("\n\t-------EEEEE-----A-------GGGG---------------");
    printf("\n\t-------E---------AA-----G-------------------");
    printf("\n\t-------EEEEE----A--A----G--GGG--------------");
    printf("\n\t-------E-------AAAAAA---G----G--------------");
    printf("\n\t-------EEEEE--A------A---GGGG---------------");
    printf("\n\t--------------------------------------------");
    printf("\n\t-------EDUARDO--ACUNA--GONZALEZ-------------\n\n");
    return 0;
}

