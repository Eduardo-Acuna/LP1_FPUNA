#include <stdio.h>

int main(){
    float promedio;
    int cont,nota,total;

    total=0;
    cont=0;

    printf("Ingrese nota, -1 para terminar: ");
    scanf("%d",&nota);

    while(nota!=-1){
        total=total+nota;
        cont=cont+1;
        printf("ingrese nota, -1 para terminar: ");
        scanf("%d",&nota);
    }

    if(cont!=0){
        promedio=(float)total/cont;
        printf("Promedio de la clase es: %.2f",promedio);
    }
    else
        printf("Ninguna nota fue ingresada\n");

    return 0;
}

