#ifndef KORNI_H
#define KORNI_H

#define EPSILON_FOR_A 1e-10

typedef struct {
    int num_roots;
    double roots[2];
} QuadraticResult;

QuadraticResult quadraticRoots(double a, double b, double c);\

int equals_with_precision(double expected, double actual, int precision);

#endif
