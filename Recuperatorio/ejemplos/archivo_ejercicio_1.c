/*EJERCICIO 1
Escribe un programa que lea 2 (dos) cadenas. Debe retornar cuantas veces la primera cadena se repite en la segunda cadena.
No debe utilizar ninguna función predefinida del lenguaje excepto el acceso a elementos y la obtención de subcadenas con los indices.

Ejemplos:
cad1    cad2                                                resultado
“uno”   “unodosunodosuno uno dos tres”                      4
“hola”  “hola esto es una prueba de como se repite hola”    2
“hola”  “una prueba”                                        0           */

# include <stdio.h>
# include <stdlib.h>
# include <string.h>


int contador(char *c1, char *c2);

// Funcion principal
int main(){
    char cad1[100];
    char cad2[100];
    int resp;

    printf("Cadena 1: ");
    scanf("%s",cad1);
    printf("Cadena 2: ");
    getchar();
    gets(cad2);

    resp=contador(cad1,cad2);

    printf("La cantidad de repeteciones: %d", resp);

    return 0;
}

// Funcion que busca la cadena
int contador(char *c1, char *c2){
    int cont,i,resp;
    resp=0;
    i=0;
    cont=0;
    while (c2[i] != '\0'){
        if (c1[cont] == c2[i]){
            if (cont == strlen(c1)-1){
                resp ++;
                cont = 0;
            }
            else{
                cont++;
            }
        }
        else{
            cont = 0;
        }
        i++;
    }
    return resp;
}
