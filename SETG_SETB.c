#include <stdio.h>

int main(int argc, char const *argv[]) {

    unsigned int a = 1;
    unsigned short b = 1;
    char c = -1;
    int d, e;

    d = (a > c) ? 1 : 0;
    e = (b > c) ? 1 : 0;

    printf("d = %d\n", d);
    printf("e = %d\n", e);

    return 0;
}


// 0000000000400526 <main>:
//   400526:   55                      push   %rbp
//   400527:   48 89 e5                mov    %rsp,%rbp
//   40052a:   48 83 ec 20             sub    $0x20,%rsp
//   40052e:   89 7d ec                mov    %edi,-0x14(%rbp)
//   400531:   48 89 75 e0             mov    %rsi,-0x20(%rbp)
//   400535:   c7 45 f4 01 00 00 00    movl   $0x1,-0xc(%rbp)
//   40053c:   66 c7 45 f2 01 00       movw   $0x1,-0xe(%rbp)
//   400542:   c6 45 f1 ff             movb   $0xff,-0xf(%rbp)
//   400546:   0f be 45 f1             movsbl -0xf(%rbp),%eax
//   40054a:   3b 45 f4                cmp    -0xc(%rbp),%eax
//   40054d:   0f 92 c0                setb   %al                     // setb a, c 无符号比较 unsigned
//   400550:   0f b6 c0                movzbl %al,%eax
//   400553:   89 45 f8                mov    %eax,-0x8(%rbp)
//   400556:   0f b7 55 f2             movzwl -0xe(%rbp),%edx
//   40055a:   0f be 45 f1             movsbl -0xf(%rbp),%eax
//   40055e:   39 c2                   cmp    %eax,%edx
//   400560:   0f 9f c0                setg   %al                     // setg b, c 带符号比较 取 d 的 int
//   400563:   0f b6 c0                movzbl %al,%eax
//   400566:   89 45 fc                mov    %eax,-0x4(%rbp)
//   400569:   8b 45 f8                mov    -0x8(%rbp),%eax
//   40056c:   89 c6                   mov    %eax,%esi
//   40056e:   bf 24 06 40 00          mov    $0x400624,%edi
//   400573:   b8 00 00 00 00          mov    $0x0,%eax
//   400578:   e8 83 fe ff ff          callq  400400 <printf@plt>
//   40057d:   8b 45 fc                mov    -0x4(%rbp),%eax
//   400580:   89 c6                   mov    %eax,%esi
//   400582:   bf 2c 06 40 00          mov    $0x40062c,%edi
//   400587:   b8 00 00 00 00          mov    $0x0,%eax
//   40058c:   e8 6f fe ff ff          callq  400400 <printf@plt>
//   400591:   b8 00 00 00 00          mov    $0x0,%eax
//   400596:   c9                      leaveq
//   400597:   c3                      retq
//   400598:   0f 1f 84 00 00 00 00    nopl   0x0(%rax,%rax,1)
//   40059f:   00
