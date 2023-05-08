#include <stdio.h>

int old_data = 1;
int new_data = 2;

int foo(void **buffer) { // do not change function signature
    *buffer = &new_data;
}

int main(int argc, char *argv[])
{
    int *data_pointer = &old_data;

    printf("data = %d\n", *data_pointer);

    foo(&data_pointer);

    printf("data = %d\n", *data_pointer);

    return 0;
}