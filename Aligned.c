#include <stdio.h>
#include <stdint.h>

#pragma pack(4)

typedef struct {
    uint32_t f1;
    uint8_t f2;
    uint8_t f3;
    uint32_t f4;
    uint64_t f5;
}__attribute__((aligned(1024))) ts;

int main(int argc, char const *argv[]) {
    printf("struct size is %d, aligned on 1024\n", sizeof(ts));
    printf("Allocate f1 on address: 0x%x\n", &(((ts*)0)->f1));
    printf("Allocate f2 on address: 0x%x\n", &(((ts*)0)->f2));
    printf("Allocate f3 on address: 0x%x\n", &(((ts*)0)->f3));
    printf("Allocate f4 on address: 0x%x\n", &(((ts*)0)->f4));
    printf("Allocate f5 on address: 0x%x\n", &(((ts*)0)->f5));

    return 0;
}


// struct size is 1024, aligned on 1024    // __attribute__((aligned(1024))) ts：结构体按照 1024 对齐，占用大小为 1024 的整数倍。
// Allocate f1 on address: 0x0
// Allocate f2 on address: 0x4
// Allocate f3 on address: 0x5
// Allocate f4 on address: 0x8
// Allocate f5 on address: 0xc             // #pragma pack(4)：8 > 4，按照 4 字节对齐