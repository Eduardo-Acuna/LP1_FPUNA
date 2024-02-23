#include "head.h"
#define PI 3.1428


void menu(){
    printf("\n    +----------------- Menu ------------------------+\n");
    printf("    | 1. Calcular area hexagono y circulo           |\n");
    printf("    | 2. Encontrar consonantes y trozos de texto    |\n");
    printf("    | 3. Verificar cuadrado magico 3x3              |\n");
    printf("    | 4. Salir                                      |\n");
    printf("    +-----------------------------------------------+\n");

}

void area(){
    double radio;
    double areaCir,areaHex;

    printf("Ingrese el radio: ");
    scanf("%lf",&radio);

    areaCir=PI*pow(radio,2)/2;
    areaHex=(3*aqrt(3)*pow(radio,2))/2;

    printf("Area del circulo: %.2lf \n",areaCir);
    printf("Area del hexagono: %.2lf \n",areaHex);

}
