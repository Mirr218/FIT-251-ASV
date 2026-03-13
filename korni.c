#include "korni.h"
#include <math.h>
#include <stdlib.h>

QuadraticResult korni(double a, double b, double c) {
  QuadraticResult result = {0, {0, 0}};

  if (a == 0) {
    result.num_roots = 0;
    return result;
  }

  double d = b * b - 4 * a * c;

  if (d < 0) {
    result.num_roots = 0;
  } else if (d == 0) {
    result.num_roots = 1;
    result.roots[0] = -b / (2 * a);
  } else {
    result.num_roots = 2;
    double sqrt_d = sqrt(d);

    double q;
    if (b >= 0) {
      q = -0.5 * (b + sqrt_d);
      result.roots[0] = q / a;
      result.roots[1] = c / q;
    } else {
      q = -0.5 * (b - sqrt_d);
      result.roots[0] = q / a;
      result.roots[1] = c / q;
    }

    if (result.roots[0] > result.roots[1]) {
      double temp = result.roots[0];
      result.roots[0] = result.roots[1];
      result.roots[1] = temp;
    }
  }

  return result;
}
