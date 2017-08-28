#include <stdlib.h>

typedef struct ponto {
    double x;
    double y;
}ponto;

typedef struct circulo {
    struct ponto pontoCentro;
    double raio;
}circulo;
