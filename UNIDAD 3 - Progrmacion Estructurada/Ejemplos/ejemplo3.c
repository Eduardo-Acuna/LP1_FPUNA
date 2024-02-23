/*Una universidad tiene una lista de los resultados de los ex�menes (1 = aprobado, 2 = reprobado) de 10 estudiantes.
� Escriba un programa que analice los resultados:
� Si m�s de 8 estudiantes pasan, imprime "Aumentar la matr�cula"

Note que
    � El programa debe procesar 10 resultados de pruebas
        � Ciclo controlado por contador ser� utilizado
    � Dos contadores pueden ser utilizados
        � Uno por el n�mero de pases, uno por el n�mero de fallas
    � Cada resultado de la prueba es un n�mero, ya sea un 1 o un 2
        � Si el n�mero no es un 1, asumimos que es un 2
*/

#include <stdio.h>
int main(){
    int aprobado=0,reprobado=0,estudiante=1,resultado;

    while(estudiante<=10){
        printf("Ingrese resultado (1=Aprobado,2=reprobado): ");
        scanf("%d",&resultado);
        if (resultado==1)
            aprobado=aprobado+1;
        else
            reprobado=reprobado+1;
        estudiante=estudiante+1;
    }

    printf("Aprobado: %d\n",aprobado);
    printf("Reprobado: %d\n",reprobado);

    if (aprobado>8)
        printf("Aumentar matricula\n");

    return 0;
}





