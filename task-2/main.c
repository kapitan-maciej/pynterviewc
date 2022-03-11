#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <pthread.h>
#include <signal.h>

static bool g_condition = false;

void signal_handler(int signum)
{
    printf("got signal %d\n", signum);
    g_condition = signum % 2;
}

void *bus_watcher(void *ctx)
{
    while (!g_condition)
    {
        ;
    }

    printf("condition set\n");
}

int main(int argc, char *argv[])
{
    pthread_t thread;

    signal(SIGBUS, signal_handler); // signal 7
    signal(SIGUSR1, signal_handler); // signal 10

    pthread_create(&thread, NULL, bus_watcher, NULL);
    pthread_join(thread, NULL);

    // Depending on how was this program built we may never join
    // @todo:
    // 1. Why and how do we prevent that.
    // 2. Fix

    return 0;
}
