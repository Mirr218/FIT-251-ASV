#include "integral.h"
#include <math.h>
#include <stdio.h>

double sq(double x) { return x * x; }

double sn(double x) { return sin(x); }

double l(double x) { return 2 * x + 1; }

double constant(double x) {
  (void)x;
  return 5.0;
}

double expon(double x) { return exp(x); }

// Сравнивает два числа с плавающей точкой с точностью k
int approx_equal(double a, double b, double k) { return fabs(a - b) < k; }

int main() {

  int n = 1000;

  printf("Определённый интеграл x^2 на отрезке от 0 до 1\n");
  double res1 = trap_rule(sq, 0.0, 1.0, n);
  double exp1 = 1.0 / 3.0;
  printf("Результат: %.8f\n", res1);
  printf("Ожидание:  %.8f\n", exp1);
  printf("Тест: %s\n\n",
         approx_equal(res1, exp1, 1e-6) ? " пройден" : " не пройден");

  printf("Определённый интеграл 2x+1 на отрезке от 0 до 1\n");
  double res2 = trap_rule(l, 0.0, 1.0, n);
  double exp2 = 2.0;
  printf("Результат: %.8f\n", res2);
  printf("Ожидание:  %.8f\n", exp2);
  printf("Тест: %s\n\n",
         approx_equal(res2, exp2, 1e-6) ? " пройден" : " не пройден");

  printf("Определённый интеграл sin(x) на отрезке от 0 до pi\n");
  double res3 = trap_rule(sn, 0.0, M_PI, n);
  double exp3 = 2.0;
  printf("Результат: %.8f\n", res3);
  printf("Ожидание:  %.8f\n", exp3);
  printf("Тест: %s\n\n",
         approx_equal(res3, exp3, 1e-4) ? " пройден" : " не пройден");

  printf("Определённый интеграл константы 5 на отрезке от 2 до 7\n");
  double res4 = trap_rule(constant, 2.0, 7.0, n);
  double exp4 = 25.0;
  printf("Результат: %.8f\n", res4);
  printf("Ожидание:  %.8f\n", exp4);
  printf("Тест: %s\n\n",
         approx_equal(res4, exp4, 1e-6) ? " пройден" : " не пройден");

  printf("Определённый интеграл e^x на отрезке от 0 до 1\n");
  double res5 = trap_rule(expon, 0.0, 1.0, n);
  double exp5 = exp(1.0) - 1.0;
  printf("Результат: %.8f\n", res5);
  printf("Ожидание:  %.8f\n", exp5);
  printf("Тест: %s\n\n",
         approx_equal(res5, exp5, 1e-6) ? " пройден" : " не пройден");

  return 0;
}
