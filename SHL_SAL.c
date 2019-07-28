#include <stdio.h>

int main(int argc, char const *argv[]) {

    int a = 0x80000000;
    unsigned b = 0x80000000;

    printf("a = 0x%X\n", a >> 1);
    printf("b = 0x%X\n", b >> 1);

    return 0;
}

// a = 0xC0000000
// b = 0x40000000

// 100000f10:  55  pushq   %rbp
// 100000f11:  48 89 e5    movq    %rsp, %rbp
// 100000f14:  48 83 ec 30     subq    $48, %rsp
// 100000f18:  c7 45 fc 00 00 00 00    movl    $0, -4(%rbp)
// 100000f1f:  89 7d f8    movl    %edi, -8(%rbp)
// 100000f22:  48 89 75 f0     movq    %rsi, -16(%rbp)
// 100000f26:  c7 45 ec 00 00 00 80    movl    $2147483648, -20(%rbp)
// 100000f2d:  c7 45 e8 00 00 00 80    movl    $2147483648, -24(%rbp)
// 100000f34:  8b 7d ec    movl    -20(%rbp), %edi
// 100000f37:  c1 ff 01    sarl    $1, %edi                                 // sarl int
// 100000f3a:  48 8d 35 55 00 00 00    leaq    85(%rip), %rsi
// 100000f41:  89 7d e4    movl    %edi, -28(%rbp)
// 100000f44:  48 89 f7    movq    %rsi, %rdi
// 100000f47:  8b 75 e4    movl    -28(%rbp), %esi
// 100000f4a:  b0 00   movb    $0, %al
// 100000f4c:  e8 25 00 00 00  callq   37 <dyld_stub_binder+0x100000f76>
// 100000f51:  8b 75 e8    movl    -24(%rbp), %esi
// 100000f54:  c1 ee 01    shrl    $1, %esi                                 // shrl unsigned
// 100000f57:  48 8d 3d 42 00 00 00    leaq    66(%rip), %rdi
// 100000f5e:  89 45 e0    movl    %eax, -32(%rbp)
// 100000f61:  b0 00   movb    $0, %al
// 100000f63:  e8 0e 00 00 00  callq   14 <dyld_stub_binder+0x100000f76>