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

    ret = calloc(1, sizeof(*ret) + cnt);
    ret->size = cnt;
    for (uint8_t i = 0; i < cnt; i++) {
        ret->bytes[i] = rand() % 255;
    }

    return ret;
}

int main()
{
    struct data_blob *data = get_random_data();

    printf("size = %d", data->size);
    for (uint8_t i = 0; i < data->size; i++) {
        printf("data[%d] = %d\n", i, data->bytes[i]);
    }

	free(data);

    return 0;
}