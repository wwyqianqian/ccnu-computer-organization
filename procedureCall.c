#include <stdio.h>

double fun (int i) {
    volatile double d[1] = {3.14};
    volatile long int a[2];
    a[i] = 1073741824;
    return d[0];
}

int main(int argc, char const *argv[]) {

    printf("%f\n%f\n%f\n", fun(0), fun(1), fun(2));
    printf("%f\n", fun(3));
    printf("%f\n", fun(4));
    return 0;
}


// 3.140000
// 3.140000
// 3.139999
// 0.000000
// 3.140000 存储保护错

//      -----------------
// EBP |   EBP 的旧值     |
//     |   d7 d6 d5 d4   |
//     |   d3 d2 d1 d0   |
//     |   a[1]          |
// ESP |   a[0]          |