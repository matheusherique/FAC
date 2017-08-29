#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "geometric_types.h"
#include "io.h"
#include "operation.h"

int main() {
  point p[3];
  circle c;
  setIn(p);
  setCenterPoint(c, p);
  c.radius = calcRadius(p[0], p[1], p[2]);
  out(c);

  return 0;
}
