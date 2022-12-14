#include <stdio.h>
#include <float.h>
#include <stdint.h>
#include <math.h>

int64_t factorial(int64_t n) {
    int64_t res = 1;

    for (int64_t i = 1; i <= n; ++i)
        res *= i;

    return res;
}

long double func(long double x) {
    return (x * x / 4 + x / 2 + 1) * expl(x / 2);
}

long double getTaylorSeries(long double x, int64_t n) {
    long double res = 0;
    for (int64_t i = 0; i <= n; ++i)
        res += (((long double) (i * i + 1)) / ((long double) factorial(i))) * powl(x / 2, (long double) i);

    return res;
}

int main() {
    long double sum = 0.0;
    long double a = 0.1;
    long double b = 0.6;

    int64_t n;
    scanf_s("%lld", &n);
    printf("N = %lld\n", n);
    printf("Machine epsilon is equal to: %g\n", LDBL_EPSILON);

    printf("Table for values of Taylor series and of base function\n");
    printf("________________________________________________________________________\n");
    printf("|   x   |          sum       |        f(x)        |number of iterations |\n");
    printf("________________________________________________________________________\n");

    long double currentX;
    long double step = (b - a) / (long double) n;
    for (int64_t i = 1; i <= n; ++i) {
        currentX = a + step * (long double) i;
        sum = getTaylorSeries(currentX, i);

        printf("| %.3Lf | %.16Lf | %.16Lf |      %lld       |\n", currentX, sum, func(currentX), i);
        printf("________________________________________________________________________\n");

        if (fabsl(func(currentX) - sum) < LDBL_EPSILON) break;
    }

    return 0;
}