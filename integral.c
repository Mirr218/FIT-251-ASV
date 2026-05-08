#include "integral.h"
#include <stddef.h>

double trap_rule(double (*f)(double), double left, double right,
                 int number_of_steps) {
  if (number_of_steps <= 0 || f == NULL || left > right) {
    return 0.0;
  }

  double h = (right - left) / number_of_steps;
  double sum = 0.0;

  for (int i = 1; i < number_of_steps; i++) {
    double x = left + i * h;
    sum += f(x);
  }

  sum += (f(left) + f(right)) / 2.0;
  return h * sum;
}
