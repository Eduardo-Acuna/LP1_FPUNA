# define N 12
# define M 51

struct Tarea {
    int prioridad;
    char nombre[M];
} typedef struct Tarea TipoDato;

# include "coladinamica.h"

struct cola_prioridades {
    int numprioridades;
    colas colas[N];
} typedef struct cola_prioridades ColaPrioridad;

/* Operaciones sobre la cola de prioridades */
void crearColaPrioridades(ColaPrioridad *cp);
void insertarCola(ColaPrioridad *cp, TipoDato t);
TipoDato elementoMin(ColaPrioridad cp);
void quitaMin(ColaPrioridad *cp);
int colaPrioridadVacia(ColaPrioridad cp);

/* Crea una cola nueva */
void crearColaPrioridad(ColaPrioridad *cp) {
    int j;
    cp->numprioridades = N;

    for (j = 0; j < N; j++) {
        crearCola(&(cp->colas[j]));
    }
}

/* Insertar en la cola */
void insertarColaPrioridad(ColaPrioridad *cp, TipoDato t) {
    if (t.prioridad < cp->numprioridades) {
        insertar(&cp->colas[t.prioridad], t);
    } else {
        puts("Prioridad fuera de rango");
    }
}

/* Quitar de la cola */
TipoDato quitarMin(ColaPrioridad *cp) {
    int i, indiceCola;
    i = 0;
    indiceCola = -1;

    /* Búsqueda de la primera cola no vacía */
    do {
        if (!colaVacia(cp->colas[i])) {
            indiceCola = i;
            i = cp->numprioridades + 1;
        } else {
            i++;
        }
    } while (i < cp->numprioridades);

    if (indiceCola != -1) {
        return quitar(&cp->colas[indiceCola]);
    } else {
        puts("Cola de prioridad vacía");
        exit(1);
    }
}
