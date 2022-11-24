#include <stdio.h>
#include <ctype.h>
#include <locale.h>
#include <assert.h>

const char answersLen3[1][3] = {
        "xor"
};

const char answersLen4[6][4] = {
        "case",
        "else",
        "then",
        "lock",
        "goto",
        "type"
};

const char answersLen5[2][5] = {
        "break",
        "using"
};

const char answersLen6[9][6] = {
        "repeat",
        "sizeof",
        "typeof",
        "static",
        "inline",
        "struct",
        "return",
        "signed",
        "extern"
};

const char answersLen7[2][7] = {
        "program",
        "default"
};

const char answersLen8[1][8] = {
        "register"
};

const int answersLenArr[9] = {
        0, 0, 0, 1, 6, 2, 9, 2, 1
};

const int escapeCharacters[6] = {
        '\n', '\t', '\r', '\v', '\n', '\b'
};

int isEqualStr(const char str1[], const char str2[], int lenEdge) {
    //printf("\n 1: %s \n 2: %s \n", str1, str2);

    for (int i = 0; i < lenEdge; ++i)
        if (str1[i] != str2[i]) return 0;

    return 1;
}

int isReservedWord(char currentCh[], int len) {
    switch (len) {
        case 3:
            for (int i = 0; i < answersLenArr[len]; ++i)
                if (isEqualStr(currentCh, answersLen3[i], len)) return 1;
            return 0;

        case 4:
            for (int i = 0; i < answersLenArr[len]; ++i)
                if (isEqualStr(currentCh, answersLen4[i], len)) return 1;
            return 0;

        case 5:
            for (int i = 0; i < answersLenArr[len]; ++i)
                if (isEqualStr(currentCh, answersLen5[i], len)) return 1;
            return 0;

        case 6:
            for (int i = 0; i < answersLenArr[len]; ++i)
                if (isEqualStr(currentCh, answersLen6[i], len)) return 1;
            return 0;

        case 7:
            for (int i = 0; i < answersLenArr[len]; ++i)
                if (isEqualStr(currentCh, answersLen7[i], len)) return 1;
            return 0;

        case 8:
            for (int i = 0; i < answersLenArr[len]; ++i)
                if (isEqualStr(currentCh, answersLen8[i], len)) return 1;
            return 0;

        default:
            return 0;
    }
}

int isSpecial(char input) {
    for (int i = 0; i < sizeof escapeCharacters; ++i)
        if (input == escapeCharacters[i]) return 1;

    return 0;
}

void resetCurrentCh(char current[10]) {
    for (int i = 0; i < 10; ++i)
        current[i] = 0;
}

void test_isSpecial() {
    assert(isSpecial('\n') == 1);
    assert(isSpecial('\r') == 1);
    assert(isSpecial('\t') == 1);
    assert(isSpecial('\v') == 1);
    assert(isSpecial('\\') == 0);
    assert(isSpecial('b') == 0);
}

void test_isReservedWord() {
    assert(isReservedWord("bebra", 5) == 0);
    assert(isReservedWord("xor", 3) == 1);
    assert(isReservedWord("babus", 5) == 0);
    assert(isReservedWord("program", 7) == 1);
    assert(isReservedWord("progr.m", 7) == 0);
    assert(isReservedWord("progr.m", 7) == 0);
    assert(isReservedWord("lock", 4) == 1);
}

void test_isEqualStr() {
    assert(isEqualStr("str1", "str2", 4) == 0);
    assert(isEqualStr("then", answersLen4[2], 4) == 1);
    assert(isEqualStr("register", answersLen8[0], 8) == 1);
    assert(isEqualStr("registed", answersLen8[0], 8) == 0);
    assert(isEqualStr("\nthen", answersLen5[0], 5) == 0);
}

void doAllTests() {
    test_isSpecial();
    test_isEqualStr();
    test_isReservedWord();
}

typedef enum {
    PRE_START,
    START,
    WORD_START,
    WORD_END
} State;

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    setlocale(LC_NUMERIC, "C");

    doAllTests();

    char ch;
    char currentCh[10] = {-1};
    int len = 0;
    int res = 0;

    State currentState = PRE_START;

    /*
     * РЕГУЛЯРКА ДЛЯ ЗАДАЧИ
     * 1. Удалить все специальные знаки [a-zA-Z0-9 ]+
     * 2. Найти все подходящие слова \W(xor|break|using|program|...)\W
    */

    while ((ch = tolower(getchar())) != '1') {
        if (isSpecial(ch)) continue;
        if (ch == '\0' && currentState != WORD_END && currentState != WORD_START) break;

        switch (currentState) {
            case PRE_START:
                ++currentState;

                if (ch == ' ') break;

            case START:
                currentCh[currentCh[0] == -1 ? 0 : 1] = ch;

                if (len == 0) len = 1;
                else ++len;

                ++currentState;
                break;

            case WORD_START:
                if (len > 10) {
                    len = 0;
                    currentState = START;
                    break;
                }

                if (ch != ' ' && ch != '\0') {
                    currentCh[len] = ch;
                    ++len;
                    break;
                } else {
                    ++currentState;
                    // mb delete
                    break;
                }

            case WORD_END:
                printf("\n %s END \n", currentCh);

                res += isReservedWord(currentCh, len);

                resetCurrentCh(currentCh);
                currentCh[0] = ch;
                len = 1;

                currentState = START;
                break;
        }
    }

    printf("\nres: %d", res);

    return 0;
}