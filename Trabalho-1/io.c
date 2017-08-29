#include "io.h"
#include "geometric_types.h"
#include <math.h>
#include <stdio.h>

void setIn(point p[3]){
  int i = 0;
  while(i < 3){
    scanf("%lf %lf", &p[i].x, &p[i].y);
    i++;
  }
}

void out(circle c){
  if(c.radius != c.radius || c.radius == INFINITY){
    printf("Circulo nao viavel.\n");
  } else {
    printf("Radius: %.3f\n", c.radius );
    printf("Centro: (%.3f, %.3f).\n",c.centerPoint.x, c.centerPoint.y);
  }
}
