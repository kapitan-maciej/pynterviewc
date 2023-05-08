#include <stdint.h>
#include <stdio.h>

uint32_t raw_data = 0x457dde11;

/*
    Data layout
    | header  |       data     | seq   |  crc   |
    |   9b    |       16b      |  7b   |   8b   |
*/
union packet {
    struct {
        uint32_t header:9;
        uint32_t data:16;
        uint32_t seq:7;
        uint32_t crc:8;
    };
    uint32_t raw;
};

int main(int argc, char *argv[])
{
    union packet packet = { .raw = raw_data };

    printf("extracted data = %x\n", packet.data); // beef

    return 0;
}