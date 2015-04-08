#include "lib_uart_mini.h"
#include "lib_uart_mini.private"

void uart_nl()
{
    uint8_t ch1;
    uint8_t ch2;

    ch1 = '\n';
    ch2 = '\r';
    uart_putchar(ch1);
    uart_putchar(ch2);
}

void uart_putmsg(char_t msg[])
{
    uint8_t i;
    uint8_t ch;

    i  = 0;
    ch = msg[i];
    while (ch != '\0')
    {
        ch = msg[i];
        uart_putchar(ch);
        i++;
    }
}


