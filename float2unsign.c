#include <stdio.h>

unsigned float_to_unsigned (float f) {
    union {
        float f;
        unsigned u;
    } tmp_union;

    tmp_union.f = f;
    return tmp_union.u;
}

int main(int argc, char const *argv[]) {
    unsigned res = float_to_unsigned(10.0);
    printf("%u\n", res);
    return 0;
}


// 1092616192

// _float_to_unsigned:
// 100000f20:  55                          pushq   %rbp
// 100000f21:  48 89 e5                    movq    %rsp, %rbp

// 100000f24:  f3 0f 11 45 fc              movss   %xmm0, -4(%rbp)
// 100000f29:  f3 0f 10 45 fc              movss   -4(%rbp), %xmm0
// 100000f2e:  f3 0f 11 45 f8              movss   %xmm0, -8(%rbp)
// 100000f33:  8b 45 f8                    movl    -8(%rbp), %eax  // 把入口参数 f 送到 eax 返回值。

// 100000f36:  5d                          popq    %rbp
// 100000f37:  c3                          retq
// 100000f38:  0f 1f 84 00 00 00 00 00     nopl    (%rax,%rax)