#ifndef KORNI_H
#define KORNI_H

typedef struct {
  int num_roots;
  double roots[2];
} QuadraticResult;

QuadraticResult korni(double a, double b, double c);

#endif