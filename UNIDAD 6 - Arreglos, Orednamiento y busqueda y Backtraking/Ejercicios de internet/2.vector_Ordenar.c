# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# define MAX 10

void imprimir_vector( int V[MAX]);
void caragar_vector( int V[MAX]);
void ordenacion_seleccion(int V[MAX]);
void ordenamiento_insercion( int V[MAX]);
void ordenamiento_burbuja(V3)( int V[MAX]);

int main()
{
    int V1[MAX], V2[MAX],V3[MAX],V4[MAX];

    printf("\n VECTORES: ");
    caragar_vector(V1);
    caragar_vector(V2);
    caragar_vector(V3);
    caragar_vector(V4);

    imprimir_vector(V1);
    imprimir_vector(V2);
    imprimir_vector(V3);
    imprimir_vector(V4);

    ordenacion_seleccion(V1);
    ordenamiento_insercion(V2);
    ordenamiento_burbuja(V3);
    return 0;
}

void caragar_vector( int V[MAX]){
    //srand(time(NULL));
    int i;
    for ( i=0 ; i<MAX ; i++){
        V[i]= 1+rand()%10;
    }
}

void imprimir_vector( int V[MAX]){
    int i;
    printf("\nElemento del vector: ");
    for ( i=0 ; i<MAX ; i++){
        printf("%d ",V[i]);
    }
}

// ORDENAMIENTO POR SELECCION
void ordenacion_seleccion(int V[MAX]){
    int  i, j, aux;
    for ( i=0 ; i<MAX-1 ; i++ ){
        for ( j=i+1 ; j<MAX ; j++ ){
            if ( V[j]<V[i] ){
                aux=V[i];
                V[i]=V[j];
                V[j]=aux;
            }
        }
    }
    printf("\n\nORDENAMIENTO POR SELECCIÓN: ");
    imprimir_vector(V);
}

// ORDENAMIENTO POR INSERCCION
void ordenamiento_insercion( int V[MAX]){
    int i,j,aux;
    for ( i=1 ; i<MAX ; i++ ){
        aux=V[i];
        j=i-1;
        while ( (j>=0)&&(aux<V[j]) ){
            V[j+1]=V[j];
            j--;
        }
        V[j+1]=aux;
    }
    printf("\n\nORDENAMIENTO POR INSERCIÓN: ");
    imprimir_vector(V);
}

// ORDENAMIENTO POR BURBUJA
void ordenamiento_burbuja(V3)( int V[MAX]){


}


