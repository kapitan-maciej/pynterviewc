#include <stdint.h>
#include <stdbool.h>

enum time_format
{
    time_format_raw,
    time_format_format_time,
};

void system_init(void);

int system_open_protocol(uint64_t identifier, void **protocol);

void system_install_protocol(uint64_t identifier, void *protocol);

int system_uninstall_protocol(uint64_t identifier);

int system_tell_time(enum time_format time_format);

int system_tell_date(bool us_format);
