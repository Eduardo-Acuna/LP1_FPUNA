# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# define MX 100

void menu();
void cargar_M(int M[MX][MX], int f, int c);
void generar_M(int M[MX][MX], int f, int c);
void imprimir_M(int M[MX][MX], int f, int c);
void buscar_M(int M[MX][MX], int f, int c);
void ordenar_M(int M[MX][MX], int f, int c);

int main(){
    menu();
}

void menu(){
    int llave,valor,cargar;
    int M[MX][MX];
    int f,c;

    printf("        +-----------------------------------------------+\n");
    printf("        |   1. Crear Matriz.                            |\n");
    printf("        |   2. Cargar Matriz                            |\n");
    printf("        |   3. Generar elemento para la matriz          |\n");
    printf("        |   4. Buscar numero en la matriz               |\n");
    printf("        |   5. Imprimir la matriz                       |\n");
    printf("        |   6. Ordenar la matriz                        |\n");
    printf("        |   0. Finalizar programa                       |\n");
    printf("        +-----------------------------------------------+\n");

    llave=1;
    cargar=0;
    while( llave==1 ){

        printf("        =================================================\n");
        printf("        Ingrese valor: "); scanf("%d",&valor);

        if( valor==1){
            printf("        =================================================\n");
            printf("                    CREAR MATRIZ");
            printf("\n        FILA: "); scanf("%d",&f);
            printf("        COLUMNA:"); scanf("%d",&c);

        }else if (valor==2){
            cargar=1;
            printf("        =================================================\n");
            printf("                    CARGAR MATRIZ\n");
            cargar_M(M,f,c);
            printf("\n\n        Se cargo correcta los elementos en la matriz. \n");
        } else if (valor==3){
            printf("        =================================================\n");
            printf("                    GENERAR ELEMENTOS");

            generar_M(M,f,c);
            printf("\n\n        Se cargo correcta los elementos en la matriz. \n");
        } else if (valor==4){
            printf("        =================================================\n");
            printf("                    BUSCAR NUMERO");

            buscar_M(M,f,c);
        } else if (valor==5){
            printf("        =================================================\n");
            printf("                    IMPRIMIR MATRIZ\n");

            imprimir_M(M,f,c);

        } else if (valor==6){
            printf("        =================================================\n");
            printf("                    ORDENAR MATRIZ\n");

            ordenar_M(M,f,c);

        }else if (valor==0){
            printf("\n\n        Fin del programa... Hasta nunca HDP\n\n");
            return 1;
        } else{
            printf("        ERROR. Valor fuera del rango... \n");
        }
    }
    return 0;
}

// Se carga la matriz
void cargar_M(int M[MX][MX], int f, int c){
    int i,j;

    for ( i=0 ; i<f ; i++ ){
        for ( j=0 ; j<c ; j++){
            printf("          M[%d][%d]: ",i,j);
            scanf("%d",&M[i][j]);
        }
    }
}

// se genera valores para la matriz
void generar_M(int M[MX][MX], int f, int c){
    int i,j;
    srand(time(NULL));
    for ( i=0 ; i<f ; i++ ){
        for ( j=0 ; j<c ; j++){
            M[i][j]=10+rand()%89;
        }
    }
}

//* Busqueda binaria del eleemetos de la matriz
void buscar_M(int M[MX][MX], int f, int c){
    int buscar,a,b,central,valorCentral;
    int contA,contB,si;

    printf("\n        Numero a buscar: ");
    scanf("%d",&buscar);
    /*
    int i,j,x,cont,aux;
    x=f*c;
    int V[x];

    cont=0;
    for ( i=0 ; i<f ; i++ ){
        for (j=0 ; j<c ; j++){
            V[cont]=M[i][j];
            cont++;
        }
    }



    a=0;
    b=x-1;
    while ( a<=b ){
        central=(a+b)/2;
        valorCentral=V[central];

        if ( buscar==V[central] ){
            printf("        Se encuentra en la posicion V[%d]: %d\n",central,V[central]);
            break;
        } else if (buscar<valorCentral){

            b=central-1;
        } else {
            a=central+1;
        }

    }

    */
    int i,j;
    for ( i=0 ; i<f ; i++ ){
        for ( j=0 ; j<c ; j++ ){
            if (M[i][j]==buscar){
                printf("\n        El numero que busca se encuentra en:  M[%d][%d]: %d\n",i+1,j+1,buscar);
            }
        }

    }



}


// Ordenar matriz
void ordenar_M(int M[MX][MX], int f, int c){
    int i, j, l , k, aux;

    for ( i=0 ; i<f ; i++ ){
        for ( j=0 ; j<c ; j++ ){
            for ( l=0 ; l<f ; l++ ){
                for ( k=0 ; k<c ; k++ ){
                    if ( M[i][j]<M[l][k]){
                        aux=M[i][j];
                        M[i][j]=M[l][k];
                        M[l][k]=aux;
                    }
                }
            }
        }
    }

/*  int i,j,a,cont,aux;
    a=f*c;
    int V[a];
    cont=0;
    for ( i=0 ; i<f ; i++ ){
        for (j=0 ; j<c ; j++){
            V[cont]=M[i][j];
            cont++;
        }
    }
    for ( i=1 ; i<a ; i++ ){
        for (j=0 ; j<a-1 ; j++){
            if ( V[j]>V[j+1]){
                aux=V[j];
                V[j]=V[j+1];
                V[j+1]=aux;
            }
        }
    }
    cont=0;
    for ( i=0 ; i<f ; i++ ){
        for (j=0 ; j<c ; j++){
            M[i][j]=V[cont];
            cont++;
        }
    }*/
}

// Se imprime la matriz
void imprimir_M(int M[MX][MX], int f, int c){
    int i, j;


    for ( i=0; i<f ; i++ ) {
        printf("        [");
        for ( j=0; j<c ; j++ ) {
            printf("%3d", M[i][j]);
        }
        printf(" ]\n");
    }

}

