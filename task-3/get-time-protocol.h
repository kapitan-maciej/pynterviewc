#include <time.h>
#include <stdbool.h>

#define GET_TIME_PROTOCOL_IDENTIFIER 12  // Used as identifier for install/open/uninstall

struct get_time_protocol
{
    time_t (*get_raw_time)(void); // return time in raw format
    char* (*get_formatted_time)(void); // return pointer to allocated hh:mm:ss string
    char* (*get_date)(bool); // return pointer to allocated yy/mm/dd or yy/dd/mm string based on
                             // parameter
};
