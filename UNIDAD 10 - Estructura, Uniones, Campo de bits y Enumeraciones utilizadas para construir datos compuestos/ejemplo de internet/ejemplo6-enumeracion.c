/*
Inclusi�n de bibliotecas:
stdio.h: Incluye las funciones de entrada y salida est�ndar, como printf, puts y getchar.
ctype.h: Proporciona funciones para el procesamiento de caracteres, como tolower*/
# include <stdio.h>
# include <ctype.h>

/*Declaraci�n de una enumeraci�n llamada Boolean:
Define una enumeraci�n que tiene dos valores posibles, FALSE y TRUE, que representan valores booleanos.*/
enum Boolean{
    FALSE,
    TRUE
};

/*Declaraci�n de una funci�n llamada vocal:
Esta funci�n toma un car�cter como argumento (char c) y devuelve un valor de tipo enum Boolean. Su objetivo es determinar si el car�cter es una vocal (a, e, i, o, u) y devolver TRUE en ese caso, o FALSE si no es una vocal.*/
enum Boolean vocal(char c);

void main(){
    char car;

    int numVocal=0;

    puts("\nIntroduce un texto (INTRO para terminar): ");


    while ( (car=getchar())!='\n' ){//la funci�n getchar() se utiliza para leer un car�cter del flujo de entrada est�ndar. El valor del car�cter le�do se asigna a la variable car.
        //La funci�n vocal() se utiliza para comprobar si un car�cter es una vocal. Esta funci�n devuelve un valor 1 si el car�cter es una vocal, o 0 si no lo es.
        //La funci�n tolower() se utiliza para convertir un car�cter a min�sculas.
        if ( vocal(tolower(car)) ){
            numVocal++;
        }
    }

    printf("\n Total de vocales leidas: %d\n",numVocal);
}


/*
Funci�n vocal:
La funci�n vocal toma un car�cter c como argumento.
Utiliza una estructura de control switch para verificar si c es igual a alguna de las vocales 'a', 'e', 'i', 'o' o 'u'. Si es el caso, devuelve TRUE, indicando que es una vocal. De lo contrario, devuelve FALSE.*/
enum Boolean vocal (char c){
    switch(c){
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return TRUE;
        default:
            return FALSE;
    }
};
