#include <stdint.h>
#include <stdio.h>

#define PLACEHOLDER  int

uint32_t raw_data = 0x457dde11;

/*
    Data layout
    | header  |       data     | seq   |  crc   |
    |   9b    |       16b      |  7b   |   8b   |
*/

int main(int argc, char *argv[])
{
    PLACEHOLDER data;

    printf("extracted data = %x\n", data);

    return 0;
}