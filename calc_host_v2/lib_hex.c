#include "lib_hex.h"
#include "lib_hex.private"

private char_t digit[] = "0123456789abcdef?";

void hex_digit_init()
{
}

void uart_printhex_32(uint32_t value)
{
    typedef union
    {
        uint32_t u32;
        uint16_t u16[2];
        uint8_t  u8[24];
    } my_32_t;

    my_32_t my;

    my.u32 = value;

    /*
     * host Little Endian
     */

    uart_printhex_8(my.u8[3]);
    uart_printhex_8(my.u8[2]);
    uart_printhex_8(my.u8[1]);
    uart_printhex_8(my.u8[0]);

    /*
     * host Big Endian
     */

    //uart_printhex_8(my.u8[0]);
    //uart_printhex_8(my.u8[1]);
    //uart_printhex_8(my.u8[2]);
    //uart_printhex_8(my.u8[3]);
}

void uart_printhex_16(uint16_t value)
{
    typedef union
    {
        uint16_t u16;
        uint8_t  u8[2];
    } my_16_t;

    my_16_t my;

    my.u16 = value;

    /*
     * host intel le
     *
     * (my.u8[1]);
     * (my.u8[0]);
     */

    uart_printhex_8(my.u8[0]);
    uart_printhex_8(my.u8[1]);
}

void uart_printhex_8(uint8_t value)
{
    uint8_t hi;
    uint8_t lo;
    char_t  ch_hi;
    char_t  ch_lo;

    lo = value bitwiseAnd 0x0f;
    hi = value shiftRight 4;

    ch_hi = digit[hi];
    ch_lo = digit[lo];

    uart_putchar(ch_hi);
    uart_putchar(ch_lo);
}
