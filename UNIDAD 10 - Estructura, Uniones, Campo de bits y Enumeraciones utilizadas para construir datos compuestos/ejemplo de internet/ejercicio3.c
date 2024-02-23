#include <stdio.h>

// Enumeraci�n para tipos de figuras
enum TipoFigura {
    CIRCULO,
    RECTANGULO
};

// Estructura para un c�rculo
struct Circulo {
    float radio;
};

// Estructura para un rect�ngulo
struct Rectangulo {
    float base;
    float altura;
};

// Uni�n que puede ser un c�rculo o un rect�ngulo
union Figura {
    struct Circulo circulo;
    struct Rectangulo rectangulo;
};

// Estructura que representa una figura geom�trica
struct FiguraGeometrica {
    enum TipoFigura tipo;
    union Figura figura;
};

int main() {
    // Crear un array de figuras geom�tricas
    struct FiguraGeometrica figuras[3];

    // Asignar valores a las figuras
    figuras[0].tipo = CIRCULO;
    figuras[0].figura.circulo.radio = 2.5;

    figuras[1].tipo = RECTANGULO;
    figuras[1].figura.rectangulo.base = 4.0;
    figuras[1].figura.rectangulo.altura = 3.0;

    figuras[2].tipo = CIRCULO;
    figuras[2].figura.circulo.radio = 1.8;

    // Calcular el tama�o de una figura geom�trica
    size_t tama�oFigura = sizeof(struct FiguraGeometrica);

    // Imprimir informaci�n sobre las figuras
    for (int i = 0; i < 3; i++) {
        if (figuras[i].tipo == CIRCULO) {
            printf("Figura %d: C�rculo con radio %.2f\n", i + 1, figuras[i].figura.circulo.radio);
        } else if (figuras[i].tipo == RECTANGULO) {
            printf("Figura %d: Rect�ngulo de base %.2f y altura %.2f\n", i + 1, figuras[i].figura.rectangulo.base, figuras[i].figura.rectangulo.altura);
        }
    }

    printf("Tama�o de una figura geom�trica: %zu bytes\n", tama�oFigura);

    return 0;
}
