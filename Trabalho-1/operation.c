#include <stdio.h>
#include <stdlib.h>
#include "operation.h"
#include <math.h>
#include "geometric_types.h"


void setCenterPoint(circle c, point p[3]) {
    double u = 0, v = 0, d = 0;
    u = (pow(p[0].x,2) - pow(p[1].x,2) + pow(p[0].y,2) - pow(p[1].y,2)) / 2;
    v = (pow(p[1].x,2) - pow(p[2].x,2) + pow(p[1].y,2) - pow(p[2].y,2)) / 2;
    d = ((p[0].x - p[1].x)*(p[1].y - p[2].y)) - ((p[1].x - p[2].x)*(p[0].y - p[1].y));
    c.centerPoint.x = (u * (p[1].y - p[2].y)- v * (p[0].y - p[1].y)) / d;
    c.centerPoint.y = (v * (p[0].x - p[1].x)- u * (p[1].x - p[2].x)) / d;
}

double calcDistance(point a, point b) {
    double distance_between_AB = 0;
    distance_between_AB = sqrt((a.x - b.x) * (a.x - b.x) + (a.y-b.y) *(a.y-b.y));
    return distance_between_AB;
}

double calcRadius(point a, point b, point c) {
    double radius = 0, s = 0;
    double distance_between_AB = calcDistance(a,b);
    double distance_between_BC = calcDistance(b,c);
    double distance_between_CA = calcDistance(c,a);
    s = (distance_between_AB + distance_between_BC + distance_between_CA) / 2;
    radius = (distance_between_AB * distance_between_BC * distance_between_CA) /
    (4 * sqrt(s * (s - distance_between_AB) * (s - distance_between_CA) *
    (s - distance_between_BC)));
    return radius;
}
