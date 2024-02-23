
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define MAX_PAC 100
enum URGENCIA{
    ROJA,
    AMARILLA,
    VERDE
};

struct PACIENTE{
    enum URGENCIA urgencia;
    char nombre[300];
};

struct COLA_PRIORIDAD{
    struct PACIENTE paciente[MAX_PAC];
    int cantidad;
};

void inicioCola( struct COLA_PRIORIDAD *cola );

int main(){
    struct COLA_PRIORIDAD cola;
    int opcion, urgencia;
    inicioCola( &cola );
    printf("\n\t +-----------------------------------------------------+");
    printf("\n\t |                      MENU                           |");
    printf("\n\t +-----------------------------------------------------+");
    printf("\n\t | 1. Agregar paciente                                 |");
    printf("\n\t | 2. Atender paciente con mayor urgencia              |");
    printf("\n\t | 3. Mostrar pacientes en espera                       |");
    printf("\n\t | 4. Salir                                            |");
    printf("\n\t +-----------------------------------------------------+");

    do{
        printf("\n\t -------------------------------------------------------");
        printf("\n\t OPCION: ");
        scanf("%d", &opcion);
        printf("\t -------------------------------------------------------");

        if( opcion==1 ){
            printf("ingrese prioridad: ");
            scanf("%d",&urgencia);

            printf("ingrese nombre: ");
            scanf("%d",&nombre);
            agregarPaciente(&cola, (enum URGENCIA)urgencia , nombre)

        } else if( opcion==2 ){
            atenderPAciente( &cola )

        } else if( opcion==3 ){

        } else if( opcion==4){
            printf("Fin del progrma")
        } else {

        }
    }

    return 0;
}

void inicioCola( struct COLA_PRIORIDAD *cola ){
    cola -> cantidad = 0;
}
