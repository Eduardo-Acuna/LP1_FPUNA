/*          --- ESTRUCTURAS DE CONTROL ---
BOHM Y JACOPINI
– Todos los programas escritos en términos de 3 estructuras decontrol:
    - Estructura de la secuencia:
        Construida en C. Programas ejecutados secuencialmente por defecto.

    - Estructuras de selección:
        C tiene tres tipos
        - if, if/else, y switch.

    - Estructuras de repetición:
        C tiene tres tipos
        - while, do/while, y for.

 -------------------------------------------------------------------------------
*/

#include <stdio.h>

int main(){
    int cont, cal, total, prom;

    /* Fase de inicialización*/
    total=0;
    cont=1;

    /* Fase de Procesamiento*/
    while(cont<=10){
        printf("Ingrese calificacion: ");
        scanf("%d",&cal);
        total=total+cal;
        cont=cont+1;
    }

    /* Hallamos el promedio*/
    prom=total/10;
    printf("\nEl promedio de la clase es %d: \n",prom);

    return 0;
}
