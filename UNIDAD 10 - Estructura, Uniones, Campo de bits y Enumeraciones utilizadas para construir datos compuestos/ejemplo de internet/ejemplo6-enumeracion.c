/*
Inclusión de bibliotecas:
stdio.h: Incluye las funciones de entrada y salida estándar, como printf, puts y getchar.
ctype.h: Proporciona funciones para el procesamiento de caracteres, como tolower*/
# include <stdio.h>
# include <ctype.h>

/*Declaración de una enumeración llamada Boolean:
Define una enumeración que tiene dos valores posibles, FALSE y TRUE, que representan valores booleanos.*/
enum Boolean{
    FALSE,
    TRUE
};

/*Declaración de una función llamada vocal:
Esta función toma un carácter como argumento (char c) y devuelve un valor de tipo enum Boolean. Su objetivo es determinar si el carácter es una vocal (a, e, i, o, u) y devolver TRUE en ese caso, o FALSE si no es una vocal.*/
enum Boolean vocal(char c);

void main(){
    char car;

    int numVocal=0;

    puts("\nIntroduce un texto (INTRO para terminar): ");


    while ( (car=getchar())!='\n' ){//la función getchar() se utiliza para leer un carácter del flujo de entrada estándar. El valor del carácter leído se asigna a la variable car.
        //La función vocal() se utiliza para comprobar si un carácter es una vocal. Esta función devuelve un valor 1 si el carácter es una vocal, o 0 si no lo es.
        //La función tolower() se utiliza para convertir un carácter a minúsculas.
        if ( vocal(tolower(car)) ){
            numVocal++;
        }
    }

    printf("\n Total de vocales leidas: %d\n",numVocal);
}


/*
Función vocal:
La función vocal toma un carácter c como argumento.
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
