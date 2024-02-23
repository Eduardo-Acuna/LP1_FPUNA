# include <stdio.h>
# include <string.h>

int nro_par( int n );
int nro_impar( int n );

int main(){
    int n;
    char rslt[12];


    do{
        printf("Introduzca un numero: ");
        scanf("%d", &n);
    } while ( n<0 );


    if ( nro_par( n ) ){
        strcpy( rslt, " es par.");
    }else{
        strcpy( rslt, " es impar.");
    }


    printf("%d %s", n, rslt);

    return 0;
}

int nro_par( int n ){
    int resultado;

    if ( n==0 ){
        resultado = 1;
    } else {
        resultado = nro_impar( n-1 );
    }

    return resultado;
}

int nro_impar( int n ){
    int resultado;

    if ( n==0 ){
        resultado = 0;
    } else {
        resultado = nro_par( n-1 );
    }

    return resultado;
}
