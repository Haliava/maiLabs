#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

long double function(long double x){
    return cosl(2 / x) - 2 * sinl(1 / x) + 1 / x;
}

int main(){
    long double a = 1;
    long double b = 2;

    printf("\nDichotomy Method");

    if (function(a) * function(b) > 0){
        printf("No roots on the segment");
        exit(0);
    }

    for (int i = 0; i < 100; ++i){
        if (fabsl(a - b) < LDBL_EPSILON){
            printf("\n%Lf %Lf", a, b);
            break;
        }
        
        if (function(a) * function((a + b) / 2) > 0)
            a = (a + b) / 2;
        
        else if (function(b) * function((a + b) / 2) > 0)
            b = (a + b) / 2;
    }

    printf("\nx = %Lf\n", (a + b) / 2);
    printf("The value of the function for such x: %Lf\n", function((a + b) / 2));

    return 0;
}
