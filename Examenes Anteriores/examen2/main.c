#include <stdio.h>
#include "head.h"


int main()
{
    int opcion;
    char enter;
    do
    {
            menu();

            printf("\n opcion: ");
            scanf("%d",opcion);
            switch (opcion){
                case 1:
                    area();
                case 2:

                case 3:

                case 4:

                default:
                    printf("Opcion no valida, seleccione una opcion valida");
            }

    } while (1);

}
