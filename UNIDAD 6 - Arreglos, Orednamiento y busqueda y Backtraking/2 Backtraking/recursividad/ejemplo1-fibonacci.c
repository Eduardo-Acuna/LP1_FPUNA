# include <stdio.h>

long fibonacci(int n);

int main(){
    int n, k;

    do{
        printf("Introdusca el numero de terminos: ");
        scanf("%d",&n);
    } while (n<=1);

    puts("Serie numeros de fibonacci: ");
    printf("0 1 ");

    for (k=2 ; k<=n ; k++){
        printf("%ld ", fibonacci(k) );
    }

    return 0;
}

long fibonacci( int n ){
    int resultado;

    if ( n==0 || n==1 ){
        resultado = n;
    } else {
        resultado = fibonacci(n-2) + fibonacci(n-1);
    }

    return resultado;
}


