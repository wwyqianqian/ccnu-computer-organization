#include <stdio.h>
void test (char a, char *ap, short b, short *bp, int c, int *cp, long d, long *dp);

long caller () {
    char a = 1;
    short b = 2;
    int c = 3;
    long d = 4;

    test(a, &a, b, &b, c, &c, d, &d);
    return a * b + c * d;
}

void test (char a, char *ap, short b, short *bp, int c, int *cp, long d, long *dp) {
    *ap += a;
    *bp += b;
    *cp += c;
    *dp += d;
}

int main () {
    caller();
    return 0;
}
