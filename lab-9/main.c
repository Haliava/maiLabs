#include <stdio.h>

const int SMALL_R = 5;
const int BIG_R = 10;
const int CENTRE_X = 10;
const int CENTRE_Y = 10;

int sign(int x) {
    return x > 0 ? 1 : x == 0 ? 0 : -1;
}

int abs(int x) {
    return x >= 0 ? x : -x;
}

int max(int x, int y) {
    return x >= y ? x : y;
}

int isInArea(int i, int j) {
    int isInSmallCircle = (i - CENTRE_X) + (j - CENTRE_Y) <= SMALL_R * SMALL_R ? 1 : -1;
    int isInBigCircle = (i - CENTRE_X) + (j - CENTRE_Y) <= BIG_R * BIG_R ? 1 : -1;

    return isInSmallCircle == -1 && isInBigCircle == 1 ? 1 : -1;
}

int checkTrajectory(int iterMax, int i, int j, int l) {
    int nxtI, nxtJ, nxtL, k = 0;

    while (k < iterMax) {
        if (isInArea(i, j) == 1) {
            printf("Point is in the area: i=%d j=%d l=%d k=%d", i, j, l, k);
            return 1;
        }

        nxtI = abs(i - j + l) / (3 - sign(i - j + k)) + 10;
        nxtJ = abs(i + j - l) / (3 - sign(i - j + k)) + 10;
        nxtL = max(i * j, j * l) * (k + 1) % 40;

        i = nxtI;
        j = nxtJ;
        l = nxtL;

        ++k;
    }

    printf("Point is NOT in the area: i=%d j=%d l=%d k=%d", i, j, l, k);
    return -1;
}

int main() {
    const int iterMax = 50;

    checkTrajectory(iterMax, 0, -3, -7);

    return 0;
}
