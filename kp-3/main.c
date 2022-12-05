#include <locale.h>
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
    return (x * x / 4 + x / 2 + 1) * expl(x * x);
}

long double getTaylorSeries(long double x, int64_t n) {
    return ((long double) (n * n + 1)) / (long double) factorial(n) * powl(x / 2, n);;
}

int main() {
    setlocale(LC_ALL, "Russian");

    long double sum = 0;
    double a = 0.1;
    double b = 0.6;

    int64_t n;
    scanf_s("%lld", &n);
    printf("\n");

    printf("Table for values of Taylor series and of base function\n");
    printf("________________________________________________________________________\n");
    printf("|   x   |          sum         |        f(x)          |number of iterations |\n");
    printf("________________________________________________________________________\n");

    long double currentX = a;
    long double step = (b - a) / (long double) n;
    for (int64_t i = 0; i <= n + 1; ++i) {
        currentX += step * (long double) i;
        sum += getTaylorSeries(currentX, i);

        printf("| %.3Lf | %.18Lf | %.18Lf |      %lld       |\n", currentX, sum, func(currentX), i);
        printf("________________________________________________________________________\n");

        if (getTaylorSeries(currentX, i) < FLT_EPSILON) break;
    }

    return 0;
}