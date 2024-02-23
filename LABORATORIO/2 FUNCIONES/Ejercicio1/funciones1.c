#include "header1.h"

int equilibrio(int X, int Y, int Z) {
    int r;
    if(X==0 && Y==0 && Z==0){
        r=1;
    }else{
        r=0;
    }
    return r;
}

void imprimir_resp(int a){
   if (a==1) {
        printf("SI\n");
    } else {
        printf("NO\n");
    }
    return 0;
}

