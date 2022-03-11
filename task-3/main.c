#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "system.h"
#include <time.h>
#include "get-time-protocol.h"

int main(int argc, char *argv[])
{
    system_init();

    // @todo1:
    // 1. Implement get_time_protocol functions
    //    You can return static example data e.g. "13:10:24" for formatted time
    // 2. Supply them to the protocol instance below
    struct get_time_protocol protocol;

    // @todo2:
    // uncomment when protocol is ready to install
    // system_install_protocol(GET_TIME_PROTOCOL_IDENTIFIER, &protocol);

    system_tell_time(time_format_raw);
    system_tell_time(time_format_format_time);
    system_tell_date(false);
    system_tell_date(true);

    // @todo3:
    // implement system_uninstall_protocol, details inside the stub
    if (system_uninstall_protocol(GET_TIME_PROTOCOL_IDENTIFIER))
        printf("Uninstall failed\n");

    struct get_time_protocol *p_protocol = NULL;
    system_open_protocol(GET_TIME_PROTOCOL_IDENTIFIER, (void **)&p_protocol);
    if (p_protocol)
        printf("protocol still intalled\n");

    return 0;
}
