
__text:
100000f44:  55  pushq   %rbp
100000f45:  48 89 e5    movq    %rsp, %rbp
100000f48:  89 7d ec    movl    %edi, -20(%rbp)
100000f4b:  89 75 e8    movl    %esi, -24(%rbp)
100000f4e:  8b 55 ec    movl    -20(%rbp), %edx
100000f51:  8b 45 e8    movl    -24(%rbp), %eax
100000f54:  01 d0   addl    %edx, %eax
100000f56:  89 45 fc    movl    %eax, -4(%rbp)
100000f59:  8b 45 fc    movl    -4(%rbp), %eax
100000f5c:  5d  popq    %rbp
100000f5d:  c3  retq
100000f5e:  55  pushq   %rbp
100000f5f:  48 89 e5    movq    %rsp, %rbp
100000f62:  be 02 00 00 00  movl    $2, %esi
100000f67:  bf 01 00 00 00  movl    $1, %edi
100000f6c:  e8 d3 ff ff ff  callq   -45 <_add>
100000f71:  b8 00 00 00 00  movl    $0, %eax
100000f76:  5d  popq    %rbp
100000f77:  c3  retq

_add:
100000f44:  55  pushq   %rbp
100000f45:  48 89 e5    movq    %rsp, %rbp
100000f48:  89 7d ec    movl    %edi, -20(%rbp)
100000f4b:  89 75 e8    movl    %esi, -24(%rbp)
100000f4e:  8b 55 ec    movl    -20(%rbp), %edx
100000f51:  8b 45 e8    movl    -24(%rbp), %eax
100000f54:  01 d0   addl    %edx, %eax
100000f56:  89 45 fc    movl    %eax, -4(%rbp)
100000f59:  8b 45 fc    movl    -4(%rbp), %eax
100000f5c:  5d  popq    %rbp
100000f5d:  c3  retq

_main:
100000f5e:  55  pushq   %rbp
100000f5f:  48 89 e5    movq    %rsp, %rbp
100000f62:  be 02 00 00 00  movl    $2, %esi
100000f67:  bf 01 00 00 00  movl    $1, %edi
100000f6c:  e8 d3 ff ff ff  callq   -45 <_add>
100000f71:  b8 00 00 00 00  movl    $0, %eax
100000f76:  5d  popq    %rbp
100000f77:  c3  retq