#include <stdio.h>
#include <math.h>
#include <float.h>

// Решить методом итераций
long double funcVar25(long double x) {
    // sqrt(1-0.4x^2) - arcsin(x) = 0
    // x = arcsin(x) / sqrt(1/(x*x) - 0.4)
    // return sqrtl(1 - 0.4 * x * x) - asinhl(x);
    return asinhl(x) / sqrtl(1 / (x * x) - 0.4);
}

long double firstDerivative25(long double x) {
    long double a = asinhl(x) / (x * x * x) + (1 / x * x - 0.4) / sqrtl(1 - x * x);
    long double sub = (1 / x * x - 0.4);
    long double b = sub * sqrtl(sub);
    return a / b;
}

// Для funcVar25
long double iterativeSearch(double_t left, double_t right) {
    long double x;
    long double newX;

    if (fabsl(firstDerivative25(left)) < 1)
        x = left;
    else if (fabsl(firstDerivative25(right)) < 1)
        x = right;
    else {
        x = (left + right) / 2;
        printf("ERROR. Func for #25 Does not converge.\n");
        return x;
    }

    newX = firstDerivative25(x);
    while (fabsl(newX - x) > LDBL_EPSILON) {
        x = newX;
        newX = firstDerivative25(x);
    }

    return x;
}

int main() {
    long double x25 = 0.7672;

    long double ans25 = iterativeSearch(0, 1);

    printf("#25 - x0: %Lf, x: %Lf", x25, ans25);

    return 0;
}
