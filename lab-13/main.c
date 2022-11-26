#include <stdio.h>
#include <ctype.h>
#include <inttypes.h>
#include <assert.h>

const uint64_t CONSONANTS = (
        1u << ('b' - 'a') | 1u << ('c' - 'a') | 1u << ('d' - 'a') | 1u << ('f' - 'a') | 1u << ('g' - 'a') |
        1u << ('h' - 'a') | 1u << ('j' - 'a') | 1u << ('k' - 'a') | 1u << ('l' - 'a') | 1u << ('m' - 'a') |
        1u << ('n' - 'a') | 1u << ('p' - 'a') | 1u << ('q' - 'a') | 1u << ('r' - 'a') | 1u << ('s' - 'a') |
        1u << ('t' - 'a') | 1u << ('v' - 'a') | 1u << ('w' - 'a') | 1u << ('x' - 'a') | 1u << ('z' - 'a')
);

uint64_t addCharToNum(char c) {
    if (c > 'z' || c < 'a')
        return 0;
    return 1u << (c - 'a');
}

int isConsonant(char c) {
    uint64_t cNum = 1u << (c - 'a');

    if ((cNum & ~CONSONANTS) == 0) return 1;
    return 0;
}

int isAlreadyInNum(char c, uint64_t num) {
    uint64_t currentChar = 1u << (c - 'a');

    if ((currentChar & ~num) == 0) return 1;
    return 0;
}

void test_addCharToNum() {
    assert((addCharToNum('a') & ~(1u << ('a' - 'a'))) == 0);
    assert((addCharToNum('b') & ~(1u << ('b' - 'a'))) == 0);
    assert((addCharToNum('g') & ~(1u << ('g' - 'a'))) == 0);
}

void test_isConsonant() {
    assert(isConsonant('a') == 0);
    assert(isConsonant('o') == 0);
    assert(isConsonant('k') == 1);
    assert(isConsonant('c') == 1);
}

void test_isAlreadyInNum() {
    assert(isAlreadyInNum('a', (1u << ('a' - 'a'))) == 1);
    assert(isAlreadyInNum('b', (1u << ('a' - 'a'))) == 0);
}

void executeTests() {
    test_addCharToNum();
    test_isConsonant();
    test_isAlreadyInNum();
}

int main() {
    executeTests();
    // Есть ли слово, где все согласные различны?
    // a b c d e f g h i j k l m n o p q r s t u v w x y z
    // 0 1 1 1 0 1 1 1 0 1 1 1 1 1 0 1 1 1 1 1 0 1 1 1 0 1 ------ CONSONANTS

    char c;
    char isInWord = 0;
    char hasUniqueConsonants = 1;
    char hasConsonants = 0;
    uint64_t currentWord = 0;

    while ((c = tolower(getchar())) != '1') {
        if (isalpha(c) == 0 || isdigit(c) == 1) {
            if (isInWord == 1 && hasUniqueConsonants == 1 && hasConsonants == 1) {
                printf("1");
                return 1;
            }

            hasUniqueConsonants = 1;
            hasConsonants = 0;
            isInWord = 0;
            currentWord = 0;
            continue;
        } else if (hasUniqueConsonants == 0) continue;
        isInWord = 1;

        if (isConsonant(c) == 1) {
            if (isAlreadyInNum(c, currentWord) == 1) {
                hasUniqueConsonants = 0;
                continue;
            }

            hasConsonants = 1;
            currentWord |= addCharToNum(c);
        }
    }

    printf("0");
    return 0;
}
