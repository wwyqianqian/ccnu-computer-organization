#include <stdio.h>

int main () {
    int a = 10;
    double *p = (double*)&a; // fldl

    printf("%f\n", *p);
    printf("%f\n", (double)a); // fildl
}

// xxxx.000000
// 10.000000