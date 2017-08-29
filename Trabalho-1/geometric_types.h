#ifndef GEOMETRIC_TYPES_H
#define GEOMETRIC_TYPES_H

typedef struct point {
    double x;
    double y;
}point;

typedef struct circle {
    struct point centerPoint;
    double radius;
}circle;

#endif