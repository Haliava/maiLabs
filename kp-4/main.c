#include <stdio.h>
#include <math.h>
#include <float.h>

// Решить методом дихотомии
long double funcVar24(long double x) {
    // cos(2/x) -2sin(1/x) + 1/x = 0
    return coshl(2 / x) - 2 * sinhl(1 / x) + 1 / x;
}

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

// Для funcVar24
long double binarySearch(double_t left, double_t right) {
    while (fabsl(right - left) > LDBL_EPSILON) {
        left = funcVar24(left) * funcVar24((left + right) / 2) > 0 ? (left + right) / 2 : left;
        right = funcVar24(right) * funcVar24((left + right) / 2) > 0 ? (left + right) / 2 : right;
    }

    return (right + left) / 2;
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
    long double x24 = 1.8756;
    long double x25 = 0.7672;

    long double ans24 = binarySearch(1, 2);
    long double ans25 = iterativeSearch(0, 1);

    printf("#24 - x0: %Lf, x: %Lf \n#25 - x0: %Lf, x: %Lf", x24, ans24, x25, ans25);

    return 0;
}
