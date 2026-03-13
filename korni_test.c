#include "korni.h"
#include <math.h>
#include <stdio.h>

int equals_with_precision(double expected, double actual, int precision) {
  double epsilon = pow(10, -precision);
  return fabs(expected - actual) < epsilon;
}

void print_test_result(int test_num, int passed, const char *description) {
  printf("Тест %d: %s - %s\n", test_num, description,
         passed ? "ПРОЙДЕН" : "НЕ ПРОЙДЕН");
}

void print_detailed_result(int test_num, QuadraticResult res,
                           const char *description) {
  printf("\n--- Тест %d: %s ---\n", test_num, description);
  printf("Количество корней: %d\n", res.num_roots);
  if (res.num_roots > 0) {
    printf("Корни: ");
    for (int i = 0; i < res.num_roots; i++) {
      printf("%.10g ", res.roots[i]);
    }
    printf("\n");
  }
}

int main() {
  int tests_passed = 0;
  int total_tests = 7;

  // Тест 1: a=0
  {
    QuadraticResult res = korni(0, 2, 3);
    int passed = (res.num_roots == 0);
    print_test_result(1, passed,
                      "При нулевом коэффициенте a возвращает пустой список");
    if (!passed)
      print_detailed_result(1, res, "Должен быть пустой список");
    if (passed)
      tests_passed++;
  }

  // Тест 2: a = 1, b = 0, c = -1 (корни -1 и 1)
  {
    QuadraticResult res = korni(1, 0, -1);
    int passed = (res.num_roots == 2 && fabs(res.roots[0] - (-1.0)) < 1e-10 &&
                  fabs(res.roots[1] - 1.0) < 1e-10);
    print_test_result(2, passed, "a=1, b=0, c=-1: корни [-1, 1]");
    if (!passed)
      print_detailed_result(2, res, "Ожидались корни -1 и 1");
    if (passed)
      tests_passed++;
  }

  // Тест 3: a = 1, b = 0, c = 0 (корень 0)
  {
    QuadraticResult res = korni(1, 0, 0);
    int passed = (res.num_roots == 1 && fabs(res.roots[0] - 0.0) < 1e-10);
    print_test_result(3, passed, "a=1, b=0, c=0: корень [0]");
    if (!passed)
      print_detailed_result(3, res, "Ожидался корень 0");
    if (passed)
      tests_passed++;
  }

  // Тест 4: a = 1, b = 0, c = 1 (отрицательный дискриминант)
  {
    QuadraticResult res = korni(1, 0, 1);
    int passed = (res.num_roots == 0);
    print_test_result(4, passed, "a=1, b=0, c=1: пустой список []");
    if (!passed)
      print_detailed_result(4, res, "Ожидался пустой список");
    if (passed)
      tests_passed++;
  }

  // Тест 5: a = 1, b = 0, c = -1E-7 (корни ±3.1623E-4 с точностью до 4 знака)
  {
    QuadraticResult res = korni(1, 0, -1e-7);
    double expected1 = -3.1623e-4;
    double expected2 = 3.1623e-4;

    int passed = (res.num_roots == 2 &&
                  equals_with_precision(expected1, res.roots[0], 4) &&
                  equals_with_precision(expected2, res.roots[1], 4));
    print_test_result(
        5, passed, "a=1, b=0, c=-1E-7: корни [-3E-4, 3E-4] (точность 4 знака)");
    if (!passed) {
      print_detailed_result(5, res, "Ожидались корни ±3.1623e-4");
      printf("Полученные значения: %.8e, %.8e\n", res.roots[0], res.roots[1]);
    }
    if (passed)
      tests_passed++;
  }

  // Тест 6: a = 1, b = -1E+10, c = -1
  {
    QuadraticResult res = korni(1, -1e10, -1);
    double expected_small = -1e-10;
    double expected_large = 1e10;
    int passed = (res.num_roots == 2 &&
                  equals_with_precision(expected_small, res.roots[0], 11) &&
                  fabs(res.roots[1] - expected_large) / expected_large < 1e-10);

    print_test_result(
        6, passed,
        "a=1, b=-1E+10, c=-1: корни [-1E-10, 1E+10] (точность 11 знака)");
    if (!passed) {
      print_detailed_result(6, res, "Ожидались корни -1e-10 и 1e10");
      printf("Полученные значения: %.11e, %.11e\n", res.roots[0], res.roots[1]);
    }
    if (passed)
      tests_passed++;
  }

  // Тест 7: a = 1, b = 0, c = -1E-8 (проверка близости к нулю)
  {
    QuadraticResult res = korni(1, 0, -1e-8);
    int passed = (res.num_roots == 2 && fabs(res.roots[0]) < 1e-3 &&
                  fabs(res.roots[1]) < 1e-3);

    print_test_result(7, passed,
                      "a=1, b=0, c=-1E-8: корни близки к 0 (не объединены)");
    if (!passed) {
      print_detailed_result(7, res, "Ожидались корни близкие к 0: ±1e-4");
      printf("Полученные значения: %.8e, %.8e\n", res.roots[0], res.roots[1]);
    }
    if (passed)
      tests_passed++;
  }

  printf("\n========================================\n");
  printf("=== ИТОГ ТЕСТИРОВАНИЯ ===\n");
  printf("========================================\n");
  printf("Пройдено тестов: %d/%d\n", tests_passed, total_tests);
  printf("Успешность: %.1f%%\n", (float)tests_passed / total_tests * 100);

  if (tests_passed == total_tests) {
    printf("\n ВСЕ ТЕСТЫ ПРОЙДЕНЫ УСПЕШНО!\n");
  } else {
    printf("\n НЕКОТОРЫЕ ТЕСТЫ НЕ ПРОЙДЕНЫ.\n");
    printf("Провалено тестов: %d\n", total_tests - tests_passed);
  }

  return 0;
}