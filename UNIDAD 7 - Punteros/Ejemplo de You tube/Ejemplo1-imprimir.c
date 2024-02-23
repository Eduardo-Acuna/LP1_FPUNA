# include <stdio.h>

void jugar( int* n ){
    int y;
    y = *n;
    y = (y+3)*2-1;
    *n = y;
}


int main(){
    int x;

    x = 10;

    jugar ( &x );

    printf("%d\n", x);

    return 0;
}
