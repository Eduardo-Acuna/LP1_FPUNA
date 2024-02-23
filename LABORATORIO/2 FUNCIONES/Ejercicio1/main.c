#include <stdio.h>
#include "header1.h"

int main(){
    int n,i,resultado;
    int x,y,z;
    int ejeX,ejeY,ejeZ;

    scanf("%d",&n);

    ejeX=0;
    ejeY=0;
    ejeZ=0;

    for (i=0;i<n;i++){
        scanf("%d%d%d",&x,&y,&z);
        ejeX=ejeX+x;
        ejeY=ejeY+y;
        ejeZ=ejeZ+z;
    }

    resultado=equilibrio(ejeX,ejeY,ejeZ);
    imprimir_resp(resultado);

    return 0;
}
