#include <stdio.h>

double f (int x) {
    return 1.0 / x;
}

int main () {
    double a, b;
    int i;
    a = f(10); // 0.1 无法精确表示，float a store 进内存（80 =› 64），之后再 load 出来进栈顶（64 =› 80），被舍入过。
    b = f(10);
    i = a == b;

    printf("%d\n", i);


    double c, d, e;
    int j;
    c = f(10);
    d = f(10); // a b 同时都被一个方法舍入过
    e = f(10);
    j = c == d;

    printf("%d\n", j);

}


// 老版本 gcc - O2
// 0
// 1