#include <stdio.h>

void swapByAdd (int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}

void swapByVal (int x, int y) {
    int t = x;
    x = y;
    y = t;
}

int main(int argc, char const *argv[]) {
    int a = 11, b = 11;
    int c = 22, d = 22;

    swapByAdd(&a, &c);
    swapByVal(b, d);

    printf("%d %d\n", a, c);
    printf("%d %d\n", b, d);
    return 0;
}

// 22 11
// 11 22

// _swapByAdd:
// 100000eb0:  55              pushq   %rbp
// 100000eb1:  48 89 e5        movq    %rsp, %rbp
// 100000eb4:  48 89 7d f8     movq    %rdi, -8(%rbp)
// 100000eb8:  48 89 75 f0     movq    %rsi, -16(%rbp)
// 100000ebc:  48 8b 75 f8     movq    -8(%rbp), %rsi
// 100000ec0:  8b 06           movl    (%rsi), %eax
// 100000ec2:  89 45 ec        movl    %eax, -20(%rbp)
// 100000ec5:  48 8b 75 f0     movq    -16(%rbp), %rsi
// 100000ec9:  8b 06           movl    (%rsi), %eax
// 100000ecb:  48 8b 75 f8     movq    -8(%rbp), %rsi
// 100000ecf:  89 06           movl    %eax, (%rsi)
// 100000ed1:  8b 45 ec        movl    -20(%rbp), %eax
// 100000ed4:  48 8b 75 f0     movq    -16(%rbp), %rsi
// 100000ed8:  89 06           movl    %eax, (%rsi)
// 100000eda:  5d              popq    %rbp
// 100000edb:  c3              retq
// 100000edc:  0f 1f 40 00     nopl    (%rax)

// _swapByVal:
// 100000ee0:  55          pushq   %rbp
// 100000ee1:  48 89 e5    movq    %rsp, %rbp
// 100000ee4:  89 7d fc    movl    %edi, -4(%rbp)
// 100000ee7:  89 75 f8    movl    %esi, -8(%rbp)
// 100000eea:  8b 75 fc    movl    -4(%rbp), %esi
// 100000eed:  89 75 f4    movl    %esi, -12(%rbp)
// 100000ef0:  8b 75 f8    movl    -8(%rbp), %esi
// 100000ef3:  89 75 fc    movl    %esi, -4(%rbp)
// 100000ef6:  8b 75 f4    movl    -12(%rbp), %esi
// 100000ef9:  89 75 f8    movl    %esi, -8(%rbp)
// 100000efc:  5d          popq    %rbp
// 100000efd:  c3          retq
// 100000efe:  66 90       nop

// _main:
// 100000f00:  55                      pushq   %rbp
// 100000f01:  48 89 e5                movq    %rsp, %rbp
// 100000f04:  48 83 ec 30             subq    $48, %rsp
// 100000f08:  c7 45 fc 00 00 00 00    movl    $0, -4(%rbp)
// 100000f0f:  89 7d f8                movl    %edi, -8(%rbp)
// 100000f12:  48 89 75 f0             movq    %rsi, -16(%rbp)
// 100000f16:  c7 45 ec 0b 00 00 00    movl    $11, -20(%rbp)  a
// 100000f1d:  c7 45 e8 0b 00 00 00    movl    $11, -24(%rbp)  b
// 100000f24:  c7 45 e4 16 00 00 00    movl    $22, -28(%rbp)  c
// 100000f2b:  c7 45 e0 16 00 00 00    movl    $22, -32(%rbp)  d


// 100000f32:  48 8d 7d ec             leaq    -20(%rbp), %rdi        rbp-20 的内容作为地址装入 rdi。而不是把 rbp-20 作为地址取内容。lea 是装入有效地址指令。
// 100000f36:  48 8d 75 e4             leaq    -28(%rbp), %rsi
// 100000f3a:  e8 71 ff ff ff          callq   -143 <_swapByAdd>

// 100000f3f:  8b 7d e8                movl    -24(%rbp), %edi        rbp-24 的内容（参数值）放入edi。使用 mov 指令。
// 100000f42:  8b 75 e0                movl    -32(%rbp), %esi
// 100000f45:  e8 96 ff ff ff          callq   -106 <_swapByVal>


// 100000f4a:  8b 75 ec                movl    -20(%rbp), %esi
// 100000f4d:  8b 55 e4                movl    -28(%rbp), %edx
// 100000f50:  48 8d 3d 4b 00 00 00    leaq    75(%rip), %rdi
// 100000f57:  b0 00                   movb    $0, %al
// 100000f59:  e8 24 00 00 00          callq   36 <dyld_stub_binder+0x100000f82>
// 100000f5e:  8b 75 e8                movl    -24(%rbp), %esi
// 100000f61:  8b 55 e0                movl    -32(%rbp), %edx
// 100000f64:  48 8d 3d 37 00 00 00    leaq    55(%rip), %rdi
// 100000f6b:  89 45 dc                movl    %eax, -36(%rbp)
// 100000f6e:  b0 00                   movb    $0, %al
// 100000f70:  e8 0d 00 00 00          callq   13 <dyld_stub_binder+0x100000f82>
// 100000f75:  31 d2                   xorl    %edx, %edx
// 100000f77:  89 45 d8                movl    %eax, -40(%rbp)
// 100000f7a:  89 d0                   movl    %edx, %eax
// 100000f7c:  48 83 c4 30             addq    $48, %rsp
// 100000f80:  5d                      popq    %rbp
// 100000f81:  c3                      retq