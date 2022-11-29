#include <stdio.h>
#include <inttypes.h>

int main() {
    // удаление всех столбцов, содержащих максимальный элемент матрицы

    int64_t size = 4;
    int64_t matrix[4][4] = {
            {1, 2, 3, 4},
            {2, 3, 4, 5},
            {3, 4, 5, 6},
            {4, 7, 6, 7}
    };

    // --> 1 3
    //     2 4
    //     3 5
    //     4 6

    int64_t max = matrix[0][0];
    int64_t colsMax[4] = {0};

    // находим максимум
    for (int64_t i = 0; i < size; ++i)
        for (int64_t j = 0; j < size; ++j)
            if (matrix[i][j] >= max) max = matrix[i][j];

    // находим номера столбцов, где есть максимальный элемент
    for (int64_t i = 0; i < size; ++i)
        for (int64_t j = 0; j < size; ++j)
            if (matrix[i][j] >= max) colsMax[j] = 1;

    // выводим столбцы без максимального элемента
    for (int64_t i = 0; i < size; ++i) {
        for (int64_t j = 0; j < size; ++j)
            if (colsMax[j] == 0) printf("%lld ", matrix[i][j]);
        printf("\n");
    }

    return 0;
}
