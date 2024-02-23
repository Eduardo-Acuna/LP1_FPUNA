#include <stdio.h>
#include "header3.h"

int main(){
    int h1,a1,c1,h2,a2;
    int resultado;

    scanf("%d%d%d",&h1,&a1,&c1);
    scanf("%d %d", &h2, &a2);

    resultado=juego(h1,a1,c1,h2,a2);

    printf("%d\n",resultado);

    return 0;
}
