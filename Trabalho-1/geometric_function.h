#include<stdlib.h>
#include<math.h>
#include "geometric_types.h"
#include<stdio.h>

double calcula_distancia(ponto_plano, ponto_plano);
double calcula_raio(ponto_plano, ponto_plano, ponto_plano);

void teste() {
    ponto_plano ponto1, ponto2, ponto3;
    ponto1.x = 0;
    ponto1.y = 0;
    ponto2.x = 0;
    ponto2.y = 1;
    ponto3.x = 1;
    ponto3.y = 1;
    calcula_distancia(ponto1,ponto2);
}

double calcula_distancia(ponto_plano ponto1, ponto_plano ponto2) {
    double distancia = pow((ponto1.x - ponto2.x),1/2) + ((ponto2.y - ponto2.y),1/2);
    printf("Distancia = %lf",distancia);
    return distancia;
}

double calcula_raio(ponto_plano ponto1, ponto_plano ponto2, ponto_plano ponto3) {
    double raio;
    double distancia[3];
    distancia1 = calcula_distancia(ponto1,ponto2);
    distancia2 = calcula_distancia(ponto1,ponto3);
    distancia3 = calcula_distancia(ponto2,ponto3);
    if(distancia1 == distancia 2 && distanci1 == distancia 3)
        return raio;
    return raio;
}
