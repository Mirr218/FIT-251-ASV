#include <stddef.h>
#include "integral.h"

double trap_rule(double (*f)(double), double a, double b, int c) {
    if (c <= 0 || f == NULL) {
        return 0.0;
    }

    double h = (b - a) / c;
    double sum = 0.0;

    for (int i = 1; i < c; i++) {
        double x = a + i * h;
        sum += f(x);
    }

    sum += (f(a) + f(b)) / 2.0;
    return h * sum;
}
