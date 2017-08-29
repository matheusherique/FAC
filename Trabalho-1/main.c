#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "geometric_types.h"

int main() {
  ponto p[3];
  double distance_between_AB = 0;
  double distance_between_BC = 0;
  double distance_between_CA = 0;
  double radius = 0;
  double s = 0, u = 0, v = 0, d = 0;
  circulo c;

  int i = 0;
  while(i < 3){
    scanf("%lf %lf", &p[i].x, &p[i].y);
    i++;
  }

  distance_between_AB = sqrt((p[0].x - p[1].x) * (p[0].x - p[1].x) + (p[0].y-p[1].y) *(p[0].y-p[1].y));
  distance_between_BC = sqrt((p[1].x - p[2].x) * (p[1].x - p[2].x) + (p[1].y-p[2].y) *(p[1].y-p[2].y));
  distance_between_CA = sqrt((p[2].x - p[0].x) * (p[2].x - p[0].x) + (p[2].y-p[0].y) *(p[2].y-p[0].y));

  d = ((p[0].x - p[1].x)*(p[1].y - p[2].y)) - ((p[1].x - p[2].x)*(p[0].y - p[1].y));

  s = (distance_between_AB + distance_between_BC + distance_between_CA) / 2;

  radius = (distance_between_AB * distance_between_BC * distance_between_CA) /
          (4 * sqrt(s * (s - distance_between_AB) * (s - distance_between_CA) *
          (s - distance_between_BC)));

  u = (pow(p[0].x,2) - pow(p[1].x,2) + pow(p[0].y,2) - pow(p[1].y,2)) / 2;
  v = (pow(p[1].x,2) - pow(p[2].x,2) + pow(p[1].y,2) - pow(p[2].y,2)) / 2;

  c.pontoCentro.x = (u * (p[1].y - p[2].y)- v * (p[0].y - p[1].y)) / d;
  c.pontoCentro.y = (v * (p[0].x - p[1].x)- u * (p[1].x - p[2].x)) / d;
  printf("radius = %lf\n", radius);
  printf("distance_between_AB = %lf\n", distance_between_AB);
  printf("distance_between_BC = %lf\n", distance_between_BC);
  printf("distance_between_CA = %lf\n", distance_between_CA);
  if(radius != radius || radius == INFINITY){
//    printf("Circulo nao viavel.\n");
  } else {
    //printf("AB: %.3f, BC: %.3f, CA: %.3f\n", distance_between_AB,distance_between_BC,distance_between_CA);
//    printf("Radius: %.3f\n", radius );
//    printf("Centro: (%.3f, %.3f).\n",c.pontoCentro.x, c.pontoCentro.y);
  }

  return 0;
}
