#include <stdio.h>
#include <ctype.h>
#include <stdint.h>
#include <assert.h>

int64_t powFunc(int64_t num, int64_t power) {
    if (power == 0) return 1;

    int64_t res = 1;

    while (power-- > 0)
        res *= num;

    return res;
}

int64_t getNewPair(char digit1, char digit2, int64_t pairsDone, int isReversed)  {
    if (isReversed == 1 ? digit1 >= digit2 : digit1 <= digit2)
        return digit2 * powFunc(10, pairsDone * 2) + digit1 * powFunc(10, pairsDone * 2 + 1);
    else return digit1 * powFunc(10, pairsDone * 2) + digit2 * powFunc(10, pairsDone * 2 + 1);
}

int64_t reverseNum(int64_t num, int64_t pairsDone, char isOdd) {
    int64_t counter = isOdd == 1 ? 0 : -1;
    int64_t res = 0;

    while (num > 0) {
        res += num % 10 * powFunc(10, pairsDone * 2 - counter++);
        num /= 10;
    }

    return res;
}

void test_powFunc() {
    assert(powFunc(10, 0) == 1);
    assert(powFunc(1, 100) == 1);
    assert(powFunc(10, 2) == 100);
    assert(powFunc(2, 9) == 512);
    assert(powFunc(0, 9) == 0);
}

void test_getNewPair() {
    assert(getNewPair('4' - '0', '1' - '0', 0, 0) == 14);
    assert(getNewPair('1' - '0', '4' - '0', 0, 0) == 14);
    assert(getNewPair('9' - '0', '9' - '0', 0, 0) == 99);
}

void test_reverseNum() {
    assert(reverseNum(123456, 2, 0) == 654321);
    assert(reverseNum(654321, 2, 0) == 123456);
    assert(reverseNum(5454545, 3, 1) == 5454545);
}

void execTests() {
    test_powFunc();
    test_getNewPair();
    test_reverseNum();
}

int main() {
    execTests();

    // попарно по убыванию
    // 1234
    // 1 * 10**3 + 2 * 10**2 + 3 * 10**1 + 4 * 10**0
    char c;

    char dig1 = -1;
    char dig2 = -1;
    char isOdd = 0;
    int64_t resNum = 0;
    int64_t pairsDone = 0;

    while ((c = getchar()) != 'a') {

        if (isdigit(c) == 0){
            if (resNum == 0) {
                if (dig1 == -1 && dig2 == -1) continue;
                printf("%d ", dig1 != -1 ? dig1 : dig2);

                dig1 = -1;
                dig2 = -1;
                continue;
            }

            if (dig1 != -1 || dig2 != -1) {
                if (dig1 != -1 && dig2 == -1) {
                    resNum += dig1 * powFunc(10, pairsDone * 2);
                    isOdd = 1;
                } else resNum += getNewPair(dig1, dig2, pairsDone, 0);
            }
            printf("%lld ", reverseNum(resNum, pairsDone, isOdd));
            resNum = 0;

            dig1 = -1;
            dig2 = -1;
            isOdd = 0;
            pairsDone = 0;

            continue;
        }

        if (dig1 == -1 || dig2 == -1) {
            if (dig1 == -1) dig1 = c - '0';
            else dig2 = c - '0';
        } else {
            resNum += getNewPair(dig1, dig2, pairsDone, 0);

            dig1 = c - '0';
            dig2 = -1;

            pairsDone++;
        }
    }

    if (dig1 != -1 && dig2 != -1) {
        resNum += getNewPair(dig1, dig2, pairsDone, 0);
        printf("%lld", resNum);
    } else if (dig1 != -1) printf("%d", dig1);
    else if (dig2 != -1) printf("%d", dig2);
}
