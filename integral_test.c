#include "integral.h"
#include <math.h>

double sq(double x) { return x * x; }
double l(double x) { return 2 * x + 1; }
double constant(double x) {
  (void)x;
  return 5.0;
}

int approx_equal(double a, double b, double k) { return fabs(a - b) < k; }

int test_square() {
  double res = trap_rule(sq, 0.0, 1.0, 1000);
  return approx_equal(res, 1.0 / 3.0, 1e-6);
}

int test_line() {
  double res = trap_rule(l, 0.0, 1.0, 1000);`
  return approx_equal(res, 2.0, 1e-6);
}

int test_constant() {
  double res = trap_rule(constant, 2.0, 7.0, 1000);
  return approx_equal(res, 25.0, 1e-6);
}

int test_sine() {
  double res = trap_rule(sin, 0.0, M_PI, 1000);
  return approx_equal(res, 2.0, 1e-4);
}

int test_expon() {
  double res = trap_rule(exp, 0.0, 1.0, 1000);
  return approx_equal(res, exp(1.0) - 1.0, 1e-6);
}

int test_wrong_bounds() {
  double res = trap_rule(sq, 1.0, 0.0, 1000);
  return approx_equal(res, 0.0, 1e-6);
}

int test_zero_steps() {
  double res = trap_rule(sq, 0.0, 1.0, 0);
  return approx_equal(res, 0.0, 1e-6);
}

int test_negative_steps() {
  double res = trap_rule(sq, 0.0, 1.0, -10);
  return approx_equal(res, 0.0, 1e-6);
}

int main() {
  if (!test_square())
    return 1;
  if (!test_line())
    return 1;
  if (!test_constant())
    return 1;
  if (!test_sine())
    return 1;
  if (!test_expon())
    return 1;
  if (!test_wrong_bounds())
    return 1;
  if (!test_zero_steps())
    return 1;
  if (!test_negative_steps())
    return 1;
  return 0;
}
