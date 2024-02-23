# include <stdio.h>

void intercambiar(int *x, int *y);

int main(){
    int a,b;

    a=7;
    b=8;

    printf("\n    a=%d    b=%d",a,b);

    intercambiar(&a,&b);

    printf("\n    a=%d    b=%d",a,b);

    return 0;
}


void intercambiar(int *x, int *y){
    int z;

    z = *x;
    *x = *y;
    *y = z;
}
