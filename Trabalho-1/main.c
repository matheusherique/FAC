#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  double x[3] = {0};
  double y[3] = {0};
  double distance_between_AB = 0;
  double distance_between_BC = 0;
  double distance_between_CA = 0;
  double radius = 0;
  double s = 0, u = 0, v = 0, d = 0;
  double center_x = 0, center_y = 0;

  int i = 0;
  while(i < 3){
    scanf("%lf %lf", &x[i], &y[i]);
    i++;
  }

  distance_between_AB = sqrt((x[0] - x[1]) * (x[0] - x[1]) + (y[0]-y[1]) *(y[0]-y[1]));
  distance_between_BC = sqrt((x[1] - x[2]) * (x[1] - x[2]) + (y[1]-y[2]) *(y[1]-y[2]));
  distance_between_CA = sqrt((x[2] - x[0]) * (x[2] - x[0]) + (y[2]-y[0]) *(y[2]-y[0]));

  d = ((x[0]-x[1])*(y[1] - y[2])) - ((x[1] - x[2])*(y[0] - y[1]));

  s = (distance_between_AB + distance_between_BC + distance_between_CA) / 2;

  radius = (distance_between_AB * distance_between_BC * distance_between_CA) /
          (4 * sqrt(s * (s - distance_between_AB) * (s - distance_between_CA) *
          (s - distance_between_BC)));

  u = (pow(x[0],2) - pow(x[1],2) + pow(y[0],2) - pow(y[1],2)) / 2;
  v = (pow(x[1],2) - pow(x[2],2) + pow(y[1],2) - pow(y[2],2)) / 2;

  center_x = (u * (y[1] - y[2])- v * (y[0] - y[1])) / d;
  center_y = (v * (x[0] - x[1])- u * (x[1] - x[2])) / d;

  if(radius != radius || radius == INFINITY){
    printf("Circulo nao viavel.\n");
  } else {
    //printf("AB: %.3f, BC: %.3f, CA: %.3f\n", distance_between_AB,distance_between_BC,distance_between_CA);
    printf("Radius: %.3f\n", radius );
    printf("Centro: (%.3f, %.3f).\n", center_x, center_y );
  }

  return 0;
}
