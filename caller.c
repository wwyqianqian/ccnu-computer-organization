#include <stdio.h>

int add (int x, int y) {
    return x + y;
}

int caller () {
    int t1 = 125;
    int t2 = 80;
    int sum = add(t1, t2);
    return sum;
}

int main(int argc, char const *argv[]) {
    printf("%d", caller());
    return 0;
}


// _caller:
// 准备阶段
// 100000f20:  55                      pushq   %rbp
// 100000f21:  48 89 e5                movq    %rsp, %rbp
// 100000f24:  48 83 ec 10             subq    $16, %rsp

// 分配局部变量
// 100000f28:  c7 45 fc 7d 00 00 00    movl    $125, -4(%rbp)
// 100000f2f:  c7 45 f8 50 00 00 00    movl    $80, -8(%rbp)

// 准备入口参数
// 100000f36:  8b 7d fc                movl    -4(%rbp), %edi
// 100000f39:  8b 75 f8                movl    -8(%rbp), %esi

// 返回参数总是在 eax 中
// 100000f3c:  e8 bf ff ff ff          callq   -65 <_add>

// 准备返回参数
// 100000f41:  89 45 f4                movl    %eax, -12(%rbp)
// 100000f44:  8b 45 f4                movl    -12(%rbp), %eax

// 结束阶段 == leave
// 100000f47:  48 83 c4 10             addq    $16, %rsp
// 100000f4b:  5d                      popq    %rbp
// 100000f4c:  c3                      retq
// 100000f4d:  0f 1f 00                nopl    (%rax)