#include <stdio.h>
#include <inttypes.h>

int main() {
    // 13 12 11 10
    // 14 7  8  9  ----\  1 2 3 4 5 6 7 8 9 10 11 12 13 14
    // 15 6  3  2  ----/
    // 16 5  4  1

    char isEven = 1;

    int64_t size = 4;

    int64_t matrix[4][4] = {
            {13, 12, 11, 10},
            {14, 7,  8,  9},
            {15, 6,  3,  2},
            {16, 5,  4,  1}
    };

    /*int64_t size = 3;

    int64_t matrix[3][3] = {
            {7, 8, 9},
            {6, 3, 2},
            {5, 4, 1},
    };*/

    int64_t i = 1;
    int64_t a = size - 1;
    int64_t b = size - 1;

    printf("%lld ", matrix[a][b]);

    while (i < size) {
        if (isEven == 1) {
            --a;
            for (int j = 0; j < i; ++j)
                printf("%lld ", matrix[a][b--]);

            for (int j = 0; j < i; ++j)
                printf("%lld ", matrix[a++][b]);

            printf("%lld ", matrix[a][b]);
            isEven = 0;
        }

        else {
            --b;
            for (int j = 0; j < i; ++j)
                printf("%lld ", matrix[a--][b]);

            for (int j = 0; j < i; ++j)
                printf("%lld ", matrix[a][b++]);

            printf("%lld ", matrix[a][b]);
            isEven = 1;
        }

        ++i;
    }


    return 0;
}
