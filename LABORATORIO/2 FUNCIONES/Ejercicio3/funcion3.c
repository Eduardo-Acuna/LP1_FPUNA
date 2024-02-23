#include "header3.h"


int juego(int h1, int a1, int c1, int h2, int a2){
    int cont;
    cont=0;

    while (h2>0){
        if (h1<=a2 && h2>a1) {
            h1=h1+c1;
            printf("CURAR\n");
        } else if (h2<=a1) {
            h2=h2-a1;
            printf("ATACAR\n");
        } else {
            h2=h2-a1;
            printf("ATACAR\n");
        }

        h1=h1-a2;
        cont++;
    }

    return cont;
}


