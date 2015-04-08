#ifndef _lib_host_
#define _lib_host_

#include "types.h"

typedef struct
{
    char_t    ch;
    boolean_t is_valid;
} uart_ans_t;

#include "lib_host.interface"

#endif

