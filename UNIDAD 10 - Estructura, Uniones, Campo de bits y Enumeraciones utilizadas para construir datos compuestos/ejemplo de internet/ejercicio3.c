#include <stdio.h>

// Enumeración para tipos de figuras
enum TipoFigura {
    CIRCULO,
    RECTANGULO
};

// Estructura para un círculo
struct Circulo {
    float radio;
};

// Estructura para un rectángulo
struct Rectangulo {
    float base;
    float altura;
};

// Unión que puede ser un círculo o un rectángulo
union Figura {
    struct Circulo circulo;
    struct Rectangulo rectangulo;
};

// Estructura que representa una figura geométrica
struct FiguraGeometrica {
    enum TipoFigura tipo;
    union Figura figura;
};

int main() {
    // Crear un array de figuras geométricas
    struct FiguraGeometrica figuras[3];

    // Asignar valores a las figuras
    figuras[0].tipo = CIRCULO;
    figuras[0].figura.circulo.radio = 2.5;

    figuras[1].tipo = RECTANGULO;
    figuras[1].figura.rectangulo.base = 4.0;
    figuras[1].figura.rectangulo.altura = 3.0;

    figuras[2].tipo = CIRCULO;
    figuras[2].figura.circulo.radio = 1.8;

    // Calcular el tamaño de una figura geométrica
    size_t tamañoFigura = sizeof(struct FiguraGeometrica);

    // Imprimir información sobre las figuras
    for (int i = 0; i < 3; i++) {
        if (figuras[i].tipo == CIRCULO) {
            printf("Figura %d: Círculo con radio %.2f\n", i + 1, figuras[i].figura.circulo.radio);
        } else if (figuras[i].tipo == RECTANGULO) {
            printf("Figura %d: Rectángulo de base %.2f y altura %.2f\n", i + 1, figuras[i].figura.rectangulo.base, figuras[i].figura.rectangulo.altura);
        }
    }

    printf("Tamaño de una figura geométrica: %zu bytes\n", tamañoFigura);

    return 0;
}
