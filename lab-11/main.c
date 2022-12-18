#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const char WORD_LIST[21][10] = {
        "xor",
        "case", "else", "then", "lock", "goto", "type",
        "break", "using",
        "repeat", "sizeof", "typeof", "static", "inline", "struct", "return", "signed", "extern",
        "program", "default",
        "register"
};

int isReservedWord(int size, char word[size]) {
    for (int i = 0; i < 21; ++i) {
        if (strcmp(WORD_LIST[i], word) == 0) {
            return 1;
        }
    }
    return 0;
}

void test_isReservedWord() {
    assert(isReservedWord(3, "xor") == 1);
    assert(isReservedWord(4, "case") == 1);
    assert(isReservedWord(4, "else") == 1);
    assert(isReservedWord(4, "bruh") == 0);
    assert(isReservedWord(8, "register") == 1);
}

typedef enum State {
    START,
    IN_WORD,
    TRASH
} State;

int main() {
    test_isReservedWord();

    char currentC;
    char word[10] = {'-'};
    int length = 0;
    int max_length = 10;
    int res = 0;

    State state = START;

    while ((currentC = tolower(getchar())) != ']') {
        switch (state) {
            case START:
                if (isspace(currentC)) {
                    length = 0;
                    break;
                }

                if (isalpha(currentC)) {
                    word[length] = currentC;

                    ++length;
                    state = IN_WORD;
                } else state = TRASH;

                break;

            case TRASH:
                length = 0;

                if (isspace(currentC))
                    state = START;

                break;

            case IN_WORD:
                if (isalpha(currentC)) {
                    if (length >= max_length) {
                        length = 0;
                        state = TRASH;
                    }

                    word[length] = currentC;
                    ++length;
                    break;
                }

                if (isspace(currentC)) {
                    word[length] = '\0';
                    res += isReservedWord(length, word);
                    length = 0;
                    state = START;
                    break;
                }

                state = TRASH;
                break;

            default:
                break;
        }
    }
    printf("\n%d\n", res);

    return 0;
}