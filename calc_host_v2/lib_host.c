#include "lib_host.h"

#include "lib_host.private"

uart_ans_t uart_getchar(void)
{
    uart_ans_t ans;
    ans.ch       = getchar();
    ans.is_valid = True;
    return ans;
}

void uart_putchar(uint8_t ch)
{
    putchar(ch);
}

void uart_reset()
{
    /*
     * hw does not support it
     */
}

void uart_baud_set()
{
    /*
     * hw does not support it
     */
}

void uart_init()
{
    uart_reset();
    uart_baud_set();
}
