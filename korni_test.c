#include "korni.h"
#include <math.h>
#include <stdio.h>

int test_case_1()  {
    QuadraticResult res = quadraticRoots(0, 2, 3);
    if (res.num_roots != 0) return 1;
      return 0;
}

int test_case_2(){
    QuadraticResult res = quadraticRoots(1, 0, -1);
    if (res.num_roots != 2 || fabs(res.roots[0] - (-1.0)) >= 1e-10 ||
        fabs(res.roots[1] - 1.0) >= 1e-10) return 1;
      return 0;
}

int test_case_3(){
    QuadraticResult res = quadraticRoots(1, 0, 0);
    if (res.num_roots != 1 || fabs(res.roots[0] - 0.0) >= 1e-10) return 1;
      return 0;
}

int test_case_4(){
    QuadraticResult res = quadraticRoots(1, 0, 1);
    if (res.num_roots != 0) return 1;
      return 0;
}

int test_case_5(){
    QuadraticResult res = quadraticRoots(1, 0, -1e-7);
    double expected1 = -3.1623e-4;
    double expected2 = 3.1623e-4;
    if (res.num_roots != 2 ||
        !equals_with_precision(expected1, res.roots[0], 4) ||
        !equals_with_precision(expected2, res.roots[1], 4)) return 1;
      return 0;
}

int test_case_6(){
    QuadraticResult res = quadraticRoots(1, -1e10, -1);
    double expected_small = -1e-10;
    double expected_large = 1e10;
    if (res.num_roots != 2 ||
        !equals_with_precision(expected_small, res.roots[0], 11) ||
        fabs(res.roots[1] - expected_large) / expected_large >= 1e-10) return 1;
      return 0;
}

int test_case_7(){
    QuadraticResult res = quadraticRoots(1, 0, -1e-8);
    if (res.num_roots != 2 || fabs(res.roots[0]) >= 1e-3 ||
        fabs(res.roots[1]) >= 1e-3) return 1;
      return 0;
}

int main() {
    if (test_case_1()) return 1;
    if (test_case_2()) return 1;
    if (test_case_3()) return 1;
    if (test_case_4()) return 1;
    if (test_case_5()) return 1;
    if (test_case_6()) return 1;
    if (test_case_7()) return 1;
    return 0;
}

