#include "app.h"

char_t msg0[] = "[*] mycalc v2.1 24/04/2002";
char_t msg1[] = "       restyled 24/06/2014";
char_t msg2[] = "    iset={+,-,*,/,!,=,?,<,>,a..z,A..Z,0..9}";

void app()
{
    uart_putmsg(msg0);
    uart_nl();
    uart_putmsg(msg1);
    uart_nl();
    uart_putmsg(msg2);
    uart_nl();

    uart_nl();
    calc_init();
    interactive();
}

int main(int argc, char *argv[])
{
    app();

    return 0;
}
