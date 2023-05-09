#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#define RETURN_ERROR (-1)
#define RETURN_SUCCESS (0)

enum element_size
{
    element_size_word = 0,
    element_size_dword,
    element_size_qword
};

void prep_array(uint8_t **array, int array_len_bytes)
{
    *array = (uint8_t*)malloc(array_len_bytes);

    // Sequentially fill the array
    for (uint8_t i = 0; i < array_len_bytes; ++i)
    {
        // @todo1:
        // this assignment will not behave as commented above, please fix
        *array[i] = i;
    }
}

int reverse_bytes_by_element(void *array, int array_len_bytes, enum element_size element_size)
{
    // @todo2:
    // 1. Ignore any outstanding bytes, process only full size elements of the array
    // 2. Reverse byte order within each element e.g.
    // for element_size_word { 0x1234, 0xabcd } -> { 0x3412, 0xcdab }
    // 3. return RETURN_ERROR for any use case this function will not handle
    //    return RETURN_SUCCESS otherwise
    return RETURN_SUCCESS;
}

void ugly_print_array(uint8_t *array, int array_len_bytes)
{
    for (uint8_t i = 0; i < array_len_bytes; ++i)
    {
        printf("%02x", array[i]);
    }
    printf("\n");
}

void pretty_print_array(void *array, int array_len_bytes, enum element_size element_size)
{
    // @todo3:
    // 1. print array in a way that will make it easier on the eyes to see if the bytes are flipped
    // 2. use it instead of ugly_print_array
}

int main(int argc, char *argv[])
{
    int array_len_bytes = 16;
    enum element_size element_size = element_size_word;
    uint8_t *array = NULL;

    prep_array(&array, array_len_bytes);
    ugly_print_array(array, array_len_bytes);

    if (reverse_bytes_by_element(array, array_len_bytes, element_size))
        return RETURN_ERROR;

    ugly_print_array(array, array_len_bytes);

    return RETURN_SUCCESS;
}
