#include "header2.h"


int proximo_anio(int a) {
    int nuevo_a;
    int d1,d2,d3,d4;
    int resultado;

    resultado=1;

    while (resultado==1) {
        a++;

        d1=a%10;
        d2=(a/10)%10;
        d3=(a/100)%10;
        d4=a/1000;

        if (d1!=d2 && d1!=d3 && d1!=d4 && d2!=d3 && d2!=d4 && d3!=d4){
            nuevo_a=a;
            resultado=0;
        }
    }

    return nuevo_a;
}

