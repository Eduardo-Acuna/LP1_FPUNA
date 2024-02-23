#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int lanzarDado();
void juego();

int main(){
    srand(time(NULL));
    juego();
    return 0;
}


int lanzarDado(){
    int dado;
    dado=rand()%6+1;
    return dado;
}


void juego(){
    int lanzamiento,punto,suma;

    printf("---------- JUEGO DEL CRAPS ----------\n\n")

    lanzamiento=1;
    punto=0;
    suma=lanzarDado()+lanzarDado()
    printf("JUEGO %d: %d + %d = %d",lanzamiento,lanzarDado(),lanzarDado());

    if (suma==7 || suma ==11){
        printf("GANO \n");
        printf("El juego a terminado")
        return;
    } else if{
        printf("Craps... ")
        printf("El juego a terminado")
    }



}
