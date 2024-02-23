# include <stdio.h>

int main(){

    int suma;
    int i=0;

    while ( i<=25){
        suma+=i*i;
        i++;
    }

    printf("sumatoria: %d",suma);
}
