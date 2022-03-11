#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <sys/queue.h>
#include <stdbool.h>
#include "system.h"
#include "get-time-protocol.h"

struct protocol_entry
{
    uint64_t identifier;
    void *protocol;
    LIST_ENTRY(protocol_entry) nodes;
};

LIST_HEAD(, protocol_entry) installed_protocols;

void system_init(void)
{
    LIST_INIT(&installed_protocols);
}

int system_open_protocol(uint64_t identifier, void **protocol)
{
    struct protocol_entry *entry;
    LIST_FOREACH(entry, &installed_protocols, nodes)
    {
        if (entry->identifier == identifier)
        {
            *protocol = entry->protocol;
            return 0;
        }
    }

    return -1;
}

void system_install_protocol(uint64_t identifier, void *protocol)
{
    struct protocol_entry *entry = (struct protocol_entry *)malloc(sizeof(struct protocol_entry));
    entry->identifier = identifier;
    entry->protocol = protocol;
    
    LIST_INSERT_HEAD(&installed_protocols, entry, nodes);
}

int system_uninstall_protocol(uint64_t identifier)
{
    // @todo3-b:
    // 1. Go over installed_protocols list an remove matching element
    // 2. return 0 on success
    //    return -1 if not found
    printf("Please implement me!\n");
    return -1;
}

int system_tell_time(enum time_format time_format)
{
    char *time_string = NULL;
    struct get_time_protocol *protocol;
    if (system_open_protocol(GET_TIME_PROTOCOL_IDENTIFIER, (void **)&protocol))
        return -1;
    
    switch (time_format)
    {
    case time_format_raw:
        printf("raw time: %ld\n", protocol->get_raw_time());
        break;
    case time_format_format_time:
        time_string = protocol->get_formatted_time();
        printf("formatted time: %s\n", time_string);
        break;
    
    default:
        return -1;
    }

    if (time_string)
        free(time_string);
    
    return 0;
}

int system_tell_date(bool us_format)
{
    char *time_string = NULL;
    struct get_time_protocol *protocol;
    if (system_open_protocol(GET_TIME_PROTOCOL_IDENTIFIER, (void **)&protocol))
        return -1;
    
    time_string = protocol->get_date(us_format);
    printf("date format %s: %s\n", us_format ? "us" : "iso", time_string);

    if (time_string)
        free(time_string);
    return 0;
}
