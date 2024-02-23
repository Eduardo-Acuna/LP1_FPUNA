/*Se desea crear una lista enlazada de numeros enteros ordenada.
La lista se organiza de tal forma que el nodo cabecera tenga el menor
elemento y asi en orden creciente los demas nodos. Una vez creada la lista
se puede recorrer para escribir los datos por pantalla.
*/
#include<stdio.h>
#include<stdlib.h>

struct elemento {
       int dato;
       struct elemento * sig;
};
typedef struct elemento NODO;
NODO * cabeza;
void insertarOrden(NODO **, int);
NODO *crearNodo(int);
void imprimir(NODO *cabeza);
void eliminar(NODO **, int);
main(){
   int a;
   cabeza = NULL;
   printf("Ingrese las operaciones");
   printf("\n1-Insertar Elemento");
   printf("\n2-Eliminar Elemento");
   printf("\n3-Imprimir Elemento");
   printf("\n4-Salir\n");
   scanf("%d", &a);
   while(a!=4){
     switch(a){
       case 1:
           int b;
           printf("Ingrese el elemnto a la lista");
           scanf("%d", &b);
           insertarOrden(&cabeza, b);
           break;
       case 2:
            printf("Ingrese el numero a borrar \n");
            int entrada;
            scanf("%d", &entrada);
            eliminar(&cabeza, entrada);
            break;
        case 3:
            printf("La Lista es \n");
            imprimir(cabeza);
            break;
       default :
             printf("El numero que ingreso no tine ninguna operacion");
             break;
     }
     printf("\nIngrese las operaciones");
     printf("\n1-Insertar Elemento");
     printf("\n2-Eliminar Elemento");
     printf("\n3-Imprimir Elemento");
     printf("\n4-Salir\n");
     scanf("%d", &a);
   }
}
void insertarOrden(NODO ** cabeza, int dato){
  NODO *nuevo;
  nuevo = crearNodo(dato);
  if (*cabeza==NULL){     // verifica si no existe elementos
     *cabeza = nuevo;
  }else if(dato<(*cabeza)->dato) {  // verifica si esta despues del
    nuevo->sig = *cabeza;           // primer elemento
    *cabeza = nuevo;
  } else {
     NODO *anterior , *p;
     anterior = p = *cabeza;
     while((p->sig!=NULL)&& (dato>p->dato)) {
        anterior = p;
        p= p->sig;
     }
     if (dato>p->dato){
         anterior =p;
     }
     nuevo->sig = anterior->sig;
     anterior->sig = nuevo;
  }
}
NODO *crearNodo(int x){
     NODO *a;
     a=(NODO*)malloc(sizeof(NODO));
     a->dato = x;
     a->sig= NULL;
     return a;
}

void imprimir(NODO *cabeza){
     int i;
     //for(cabeza; cabeza!=NULL; cabeza=cabeza->sig)
     for(i=0; cabeza; cabeza=cabeza->sig){
         printf("%d\t",cabeza->dato);
         i++;
     }
}
void eliminar (NODO ** cabeza, int entrada){
    NODO * actual = *cabeza;
	NODO *anterior = NULL;
	int encontrado = 0;
	while ((actual!=NULL) && (!encontrado)){ /* búsqueda del nodo y del anterior */
		encontrado = (actual -> dato == entrada);
		if (!encontrado){
			anterior = actual;
			actual = actual -> sig;
		}
	}
	if (actual != NULL){ /* Enlace nodo anterior con siguiente. Si es NULL No existe elemento */
		if (actual == *cabeza)	 /* distingue entre el nodo cabecera o el resto de la lista */
			*cabeza = actual -> sig;
		else
			anterior -> sig = actual -> sig;
		free(actual); /*Se libera el nodo. Tener en cuenta el tipo de dato con el que se está trabajando!*/
	}
	if (encontrado==0){
       printf("NO SE ENCONTRO ELEMENTO");
    }
}

