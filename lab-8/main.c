#include <stdio.h>

const int M = 120;

void getMaxPair(char testCase[]) {
    int n;
    scanf_s("%d", &n);

    int a, b, tmp, arrElem, max;
    int arr[120] = {0};

    a = -1;
    b = -1;
    max = -1;

    for (int i = 0; i < n; ++i) {
        scanf_s("%d", &tmp);
        arrElem = arr[M - tmp % M];

        if (tmp < arrElem && arrElem + tmp > max) {
            max = arrElem + tmp;
            a = arrElem;
            b = tmp;
        }

        if (tmp > arr[tmp % M]) arr[tmp % M] = tmp;
    }

    if (a == -1 && b == -1) {
        for (int j = 119; j > 0; --j) {
            if (arr[j] != 0) {
                printf("%s %d %d\n", testCase, j, arr[j]);

            }
        }
    } else {
        printf("%s %d %d\n", testCase, a, b);
    }

}

int main() {
    getMaxPair("base: ");
    getMaxPair("borderline case with n=2: ");
    getMaxPair("more than 1 good pair: ");
    getMaxPair("more than 1 good pair, only one has the right order: ");

    return 0;
}

/*
 * TEST1 (base)
6
60
140
61
100
300
59

100 140
*/

/*
 * TEST2 (пограничный случай с n=2)
2
61
59

61 59
*/

/*
 * TEST3 (несколько правильных пар)
5
119
1
118
2
3

119 1
*/

/*
 * TEST4 (несколько пар с максимальной суммой, у одной из них элементы не в правильном порядке)
6
1
119
118
2
3
123

118 2
*/

/* полный ввод всех тестов
6
60
140
61
100
300
59
2
61
59
5
119
1
118
2
3
6
1
119
118
2
3
123
*/
