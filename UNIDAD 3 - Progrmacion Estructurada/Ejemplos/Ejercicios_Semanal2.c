#include <stdio.h>
#include <math.h>

int main()
{
    int opcion,control = 0;
    const PI = 3.141592;
    float area,radio,base_t,altura_t,base_r,altura_r,lado;

    printf("\t---- SELECIONE UNA OPCION PARA CALCULAR ----\n");
    printf("\t 1. Area de un circulo\n");
    printf("\t 2. Area de un triangulo\n");
    printf("\t 3. Area de un rectagulo\n");
    printf("\t 4. Area de un cuadrado\n");
    printf("\t--------------------------------------------");

    do
    {
        printf("\n\tOPCION: ");
        scanf("%d", &opcion);
        if (opcion >= 1 && opcion <= 4)
        {
            switch (opcion)
            {
                case ( 1 ):
                    printf("\n\t------------- AREA DE UN CIRCULO ------------\n");
                    printf("\n\tRadio :");
                    scanf("%f", &radio);
                    area = PI*radio*radio;
                    printf("\n\tEl area del circulo es: %.2f\n",area);
                    control = 1;
                    break;
                case ( 2 ):
                    printf("\n\t------------ AREA DE UN TRIANGILO ----------\n");
                    printf("\n\tBase :");
                    scanf("%f", &base_t);
                    printf("\n\tAltura :");
                    scanf("%f", &altura_t);
                    area = 0.5*base_t*altura_t;
                    printf("\n\tEl area del triangulo es: %.2f\n",area);
                    control = 1;
                    break;
                case ( 3 ):
                    printf("\n\t----------- AREA DE UN RECTAGULAR -----------\n");
                    printf("\n\t Base :");
                    scanf("%f", &base_r);
                    printf("\n\t Altura :");
                    scanf("%f", &altura_r);
                    area=base_r*altura_r;
                    printf("\n\t El area del rectangulo es: %.2f\n",area);
                    control=1;
                    break;
                case ( 4 ):
                    printf("\n\t------------ AREA DE UN CUADRADO ------------\n");
                    printf("\n\tLado :");
                    scanf("%f",&lado);
                    area=lado*lado;
                    printf("\n\tEl area del cuadrado es: %.2f\n",area);
                    control=1;
                    break;
            }
        }else{
            printf("\tOPCION INVALIDA... vuelva a intentar.\n");
        }
    } while (control!=1);

    printf("\n\t------------ FIN DEL PROGRAMA --------------\n");
    printf("\n\t--------------------------------------------");
    printf("\n\t-------EEEEE-----A-------GGGG---------------");
    printf("\n\t-------E---------AA-----G-------------------");
    printf("\n\t-------EEEEE----A--A----G--GGG--------------");
    printf("\n\t-------E-------AAAAAA---G----G--------------");
    printf("\n\t-------EEEEE--A------A---GGGG---------------");
    printf("\n\t--------------------------------------------\n");
    printf("\n\t-------EDUARDO--ACUNA--GONZALEZ-------------\n\n");
    return 0;
}
