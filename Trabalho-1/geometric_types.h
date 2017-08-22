#include <stdlib.h>

typedef struct ponto_plano {
    double x;
    double y;
}ponto_plano;

typedef struct circulo {
    struct ponto_plano ponto;
    double raio;
}circulo;
