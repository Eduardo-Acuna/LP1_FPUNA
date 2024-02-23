/*
EJERCICIO 10
En un archivo se tiene los puntajes de los alumnos del curso. Elabora un programa
que lea el archivo e imprima la calificación obtenida de acuerdo a la siguiente escala:
100-95: 5, 80-94: 4, 70-79: 3, 60-69: 2, <60: 1.
Al final imprime el nombre del alumno que obtuvo el mejor puntaje (si hay varios,
imprime todos), el promedio general del curso en puntaje y el promedio en nota.
El formato de cada línea es (fijarse que cada campo está separado por el carácter:
(dos puntos)).
Apellido:Nombre:Puntaje
Se debe producir la lista (fijarse en el formato de salida ejemplo).
Apellido + “, ” + Nombre , Puntaje, Nota
*/

#include <stdio.h>
#include <string.h>

// ESTRUCTURA PARA GUARDAR LISTA DE ALUMNO
struct alumno {
    char apellido[50];
    char nombre[50];
    int puntaje;
    int nota;
};

// COSNTRUCTOR PARA CALCULAR LA NOTA
int calcular_nota(int puntaje);


// FUNCION PRINCIPAL DEL PROGRAMA
int main(){

    // Variables
    struct alumno alumnos[100];
    int i, total_alumnos = 0, mejor_puntaje = 0;
    float promedio_puntaje = 0, promedio_nota = 0;

    // Abrimos el archivo
    FILE *archivo = fopen("calificaciones.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    // Leemos el archivo y calculamos promedios
    while (fscanf(archivo, "%49[^:]:%49[^:]:%d", alumnos[total_alumnos].apellido, alumnos[total_alumnos].nombre, &alumnos[total_alumnos].puntaje) == 3) {
        // Calculamos la nota
        alumnos[total_alumnos].nota = calcular_nota(alumnos[total_alumnos].puntaje);

        // Actualizamos promedios y mejor puntaje
        promedio_puntaje += alumnos[total_alumnos].puntaje;
        promedio_nota += alumnos[total_alumnos].nota;

        if( alumnos[total_alumnos].puntaje>mejor_puntaje ){
            mejor_puntaje = alumnos[total_alumnos].puntaje;
        }

        total_alumnos++;
    }

    // Cerramos el archivo
    fclose(archivo);

    // Calculamos promedios finales
    if (total_alumnos > 0) {
        promedio_puntaje /= total_alumnos;
        promedio_nota /= total_alumnos;
    }

    // Imprimimos la tabla de resultados
    printf("-----------------------------------------------------+---------------+---------------\n");
    printf(" Apellido y Nombre                                   |     Puntaje   |       Nota    \n");
    printf("-------------------------------------------------------------------------------------");

    for (i = 0; i < total_alumnos; i++) {
        printf("\n%s, ", alumnos[i].apellido);
        printf("%s", alumnos[i].nombre);
        printf("%50d",alumnos[i].puntaje);
        printf("%15d",alumnos[i].nota);
    }

    printf("\n+------------------------------------------------------+--------------+--------------+\n");
    printf("Promedio Nota: %.2f                                    Promedio Puntaje: %.2f\n", promedio_nota, promedio_puntaje);
    printf("Alumno(s) con Mejor puntaje: ");
    for (i = 0; i < total_alumnos; i++) {
        if (alumnos[i].puntaje == mejor_puntaje) {
            printf("%s %s ", alumnos[i].apellido, alumnos[i].nombre);
        }
    }
    printf("\n");

    return 0;
}




// Función para calcular la nota de un alumno
int calcular_nota(int puntaje) {
    if (puntaje >= 95) {
        return 5;
    } else if (puntaje >= 80) {
        return 4;
    } else if (puntaje >= 70) {
        return 3;
    } else if (puntaje >= 60) {
        return 2;
    } else {
        return 1;
    }
}

