#include <stdio.h>

int main(int argc, char const *argv[]) {
    union NUM {
        int a;
        char b;
    } num;

    num.a = 0x12345678;

    if (num.b == 0x12) {
        printf("Big Endian\n");
    } else {
        printf("Little Endian\n");
    }

    printf("num.b = 0x%X", num.b);
    return 0;
}


// Little Endian
// num.b = 0x78⏎