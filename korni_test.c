#include "korni.h"
#include <math.h>

int equals_with_precision(double expected, double actual, int precision) {
  double epsilon = pow(10, -precision);
  return fabs(expected - actual) < epsilon;
}

int main() {
  // Тест 1: a=0
  {
    QuadraticResult res = korni(0, 2, 3);
    if (res.num_roots != 0)
      return 1;
  }

  // Тест 2: a = 1, b = 0, c = -1 (корни -1 и 1)
  {
    QuadraticResult res = korni(1, 0, -1);
    if (res.num_roots != 2 || fabs(res.roots[0] - (-1.0)) >= 1e-10 ||
        fabs(res.roots[1] - 1.0) >= 1e-10)
      return 1;
  }

  // Тест 3: a = 1, b = 0, c = 0 (корень 0)
  {
    QuadraticResult res = korni(1, 0, 0);
    if (res.num_roots != 1 || fabs(res.roots[0] - 0.0) >= 1e-10)
      return 1;
  }

  // Тест 4: a = 1, b = 0, c = 1 (отрицательный дискриминант)
  {
    QuadraticResult res = korni(1, 0, 1);
    if (res.num_roots != 0)
      return 1;
  }

  // Тест 5: a = 1, b = 0, c = -1E-7 (корни ±3.1623E-4)
  {
    QuadraticResult res = korni(1, 0, -1e-7);
    double expected1 = -3.1623e-4;
    double expected2 = 3.1623e-4;
    if (res.num_roots != 2 ||
        !equals_with_precision(expected1, res.roots[0], 4) ||
        !equals_with_precision(expected2, res.roots[1], 4))
      return 1;
  }

  // Тест 6: a = 1, b = -1E+10, c = -1
  {
    QuadraticResult res = korni(1, -1e10, -1);
    double expected_small = -1e-10;
    double expected_large = 1e10;
    if (res.num_roots != 2 ||
        !equals_with_precision(expected_small, res.roots[0], 11) ||
        fabs(res.roots[1] - expected_large) / expected_large >= 1e-10)
      return 1;
  }

  // Тест 7: a = 1, b = 0, c = -1E-8
  {
    QuadraticResult res = korni(1, 0, -1e-8);
    if (res.num_roots != 2 || fabs(res.roots[0]) >= 1e-3 ||
        fabs(res.roots[1]) >= 1e-3)
      return 1;
  }

  return 0;
}