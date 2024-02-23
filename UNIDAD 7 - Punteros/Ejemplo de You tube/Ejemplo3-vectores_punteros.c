# include <stdio.h>

int main(){
    int a[]={1,2,3,4,5,6};

    int i,tam;

    tam = sizeof(a)/sizeof(a[0]);
    printf("El tamño del vector es: %d \n\n",tam);

    printf("VEMOS EL VECTOR a : \n");
    for ( i=0 ; i<tam ; i++ ){
        printf( "Vector a[%d] esta en %p y tiene el valor: %d \n",i, &a[i], a[i]);
    }


    printf("\n\n\nVEMOS EL VECTOR a UTILIZANDO PUNTEROS: \n");
     printf("\nel valor de a es: %p\n",a);
    int *p=a;
    printf("el valor de p es: %p\n",p);
    for ( i=0 ; i<tam ; i++ ){
        printf( "*(p+%d) esta en %p y tiene el valor: %d \n",i, p+i, *(p+i));
    }


    return 0;
}
