#include <stdint.h>
#include <stdio.h>

struct foo {
    uint8_t a;
    uint16_t b;
    uint8_t c;
};

struct bar {
    uint16_t a;
    uint8_t b;
    uint8_t c;
};

struct baz {
    uint8_t a;
    uint16_t b;
    uint8_t c;
} __attribute__((packed));


int main(int argc, char *argv[])
{
    printf("sizeof foo %d\n", sizeof(struct foo));
    printf("sizeof bar %d\n", sizeof(struct bar));
    printf("sizeof baz %d\n", sizeof(struct baz));

    return 0;
}