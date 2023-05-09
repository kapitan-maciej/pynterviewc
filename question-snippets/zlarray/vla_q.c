#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

struct data_blob {
    uint8_t size;
    uint8_t bytes[];
};

struct data_blob * get_random_data()
{
    uint8_t cnt;
    struct data_blob *ret;

    srand(time(0));
    cnt = rand() % 255;

	/* TODO: fill ret->bytes with cnt random values */

    return ret;
}

int main()
{
    struct data_blob *data = get_random_data();

	/* TODO: print content of the data_blob */

    return 0;
}