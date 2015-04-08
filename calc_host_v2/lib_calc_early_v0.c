#include "lib_calc_early_v0.h"
#include "lib_calc_early_v0.private"


#define linea_size    100

private char_t    linea[linea_size];
private uint32_t  cur_char;
private token_t   cur_token;

private sint32_t  var[54];
private sint32_t  ivar;

private sint32_t  IO_data;
private sint32_t  IO_addr;

private boolean_t any_error;
private boolean_t is_sub_expr;


private char_t msg_err0[] = "expression incorrect";
private char_t msg_err1[] = "waiting for ')'";
private char_t msg_err2[] = "waiting for - integer - '(' - var";
private char_t msg_err3[] = "division by zero";
private char_t msg_err4[] = "garbage linea";

/*
 * used for IO
 */
#define ivar_addr_in     31
#define ivar_addr_out    32
#define ivar_data_in     33
#define ivar_data_out    34



private boolean_t is_digit(char_t ch)
{
    boolean_t ans;
    switch (ch)
    {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    case 'A':
    case 'B':
    case 'C':
    case 'D':
    case 'E':
    case 'F':
        ans = True;
        break;
    default:
        ans = False;
        break;
    }
    return ans;
}

void calc_init()
{
    ivar      = 0;
    cur_char  = 0;
    any_error = False;
}

private sint32_t getFactorial(sint32_t number)
{
    uint32_t i;
    sint32_t result;

    result = 1;
    for (i = 1; i <= number; i++)
    {
        result = result * i;
    }
    return result;
}

private void token_get_next()
{
    if (((cur_char + 1) < linea_size))
    {
        while ((linea[cur_char] == ' ')logicalAnd((cur_char + 1) < linea_size))
        {
            cur_char++;
        }
        cur_token.position = cur_char;
        switch (linea[cur_char])
        {
        case ';':
            cur_token.token_type = T_end_of_expr;
            is_sub_expr          = True;
            break;
        case '?':
            cur_token.token_type = T_OP_EQUAL;
            break;
        case '>':
            cur_token.token_type = T_OP_GREATER;
            break;
        case '<':
            cur_token.token_type = T_OP_MINUS;
            break;
        case '!':
            cur_token.token_type = T_OP_factorial;
            break;
        case '=':
            cur_token.token_type = T_OP_LET;
            break;
        case 'q':
            ivar                 = 0;
            cur_token.token_type = T_VAR;
            break;
        case 'w':
            ivar                 = 1;
            cur_token.token_type = T_VAR;
            break;
        case 'e':
            ivar                 = 2;
            cur_token.token_type = T_VAR;
            break;
        case 'r':
            ivar                 = 3;
            cur_token.token_type = T_VAR;
            break;
        case 't':
            ivar                 = 4;
            cur_token.token_type = T_VAR;
            break;
        case 'y':
            ivar                 = 5;
            cur_token.token_type = T_VAR;
            break;
        case 'u':
            ivar                 = 6;
            cur_token.token_type = T_VAR;
            break;
        case 'i':
            ivar                 = 7;
            cur_token.token_type = T_VAR;
            break;
        case 'o':
            ivar                 = 8;
            cur_token.token_type = T_VAR;
            break;
        case 'p':
            ivar                 = 9;
            cur_token.token_type = T_VAR;
            break;
        case 'a':
            ivar                 = 10;
            cur_token.token_type = T_VAR;
            break;
        case 's':
            ivar                 = 11;
            cur_token.token_type = T_VAR;
            break;
        case 'd':
            ivar                 = 12;
            cur_token.token_type = T_VAR;
            break;
        case 'f':
            ivar                 = 13;
            cur_token.token_type = T_VAR;
            break;
        case 'g':
            ivar                 = 14;
            cur_token.token_type = T_VAR;
            break;
        case 'h':
            ivar                 = 15;
            cur_token.token_type = T_VAR;
            break;
        case 'j':
            ivar                 = 16;
            cur_token.token_type = T_VAR;
            break;
        case 'k':
            ivar                 = 17;
            cur_token.token_type = T_VAR;
            break;
        case 'l':
            ivar                 = 18;
            cur_token.token_type = T_VAR;
            break;
        case 'z':
            ivar                 = 19;
            cur_token.token_type = T_VAR;
            break;
        case 'x':
            ivar                 = 20;
            cur_token.token_type = T_VAR;
            break;
        case 'c':
            ivar                 = 21;
            cur_token.token_type = T_VAR;
            break;
        case 'v':
            ivar                 = 22;
            cur_token.token_type = T_VAR;
            break;
        case 'b':
            ivar                 = 23;
            cur_token.token_type = T_VAR;
            break;
        case 'n':
            ivar                 = 24;
            cur_token.token_type = T_VAR;
            break;
        case 'm':
            ivar                 = 25;
            cur_token.token_type = T_VAR;
            break;

        case '(':
            cur_token.token_type = T_L_PAREN;
            break;
        case ')':
            cur_token.token_type = T_R_PAREN;
            break;
        case '*':
            cur_token.token_type = T_TIMES;
            break;
        case '/':
            cur_token.token_type = T_DIV;
            break;
        case '+':
            cur_token.token_type = T_PLUS;
            break;
        case '-':
            cur_token.token_type = T_MINUS;
            break;
        case '\0':
            cur_token.token_type = T_EOF;
            break;

        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case 'A':
        case 'B':
        case 'C':
        case 'D':
        case 'E':
        case 'F':
            cur_token.token_type = T_INT;
            cur_token.value      = 0;
            while (is_digit(linea[cur_char]))
            {
                cur_token.value = (cur_token.value * 16);
                if (linea[cur_char] >= 'A')
                {
                    cur_token.value += (linea[cur_char] - 'A');
                    cur_token.value += 10;
                }
                else
                {
                    cur_token.value += (linea[cur_char] - '0');
                }
                cur_char++;
            }
            cur_char--;     /* pointing to the last char */
            break;
        default:
            error(msg_err0);
            break;
        }
        cur_char++;
    }
}

private sint32_t factor()
{
    sint32_t value;

    switch (cur_token.token_type)
    {
    case T_OP_factorial:
        token_get_next();
        value = getFactorial(expr());
        return(value);
    case T_VAR:
        value = var[ivar];
        token_get_next();
        return(value);
    case T_INT:
        value = cur_token.value;
        token_get_next();
        return(value);
    case T_L_PAREN:
        token_get_next();
        value = expr();
        if (cur_token.token_type == T_R_PAREN)
        {
            token_get_next();
            return(value);
        }
        else
        {
            error(msg_err1);
        }
        break;
    default:
        error(msg_err2);
        break;
    }
    return(0);
}

private sint32_t term()
{
    sint32_t factor_value;
    sint32_t term_value;

    factor_value = factor();
    switch (cur_token.token_type)
    {
    case T_end_of_expr:
    case T_EOF:
        return(factor_value);
    case T_TIMES:
        token_get_next();
        term_value = term();
        return(factor_value * term_value);
    case T_DIV:
        token_get_next();
        term_value = term();
        if (term_value == 0)
        {
            cur_token.position--;
            error(msg_err3);
            return 0;
        }
        else
        {
            return(factor_value / term_value);
        }
    default:
        return(factor_value);
    }
}

private sint32_t expr()
{
    sint32_t local_ivar;
    sint32_t local_value;
    sint32_t term_value;
    sint32_t expr_value;

    switch (cur_token.token_type)
    {
    case T_MINUS:
        token_get_next();
        return(-expr());
    default:
        break;
    }

    term_value  = term();
    local_value = term_value;

    switch (cur_token.token_type)
    {
    case T_OP_EQUAL:
        token_get_next();
        expr_value = expr();
        if (term_value == expr_value)
        {
            expr_value = 1;
        }
        else
        {
            expr_value = 0;
        }
        return(expr_value);
    case T_OP_MINUS:
        token_get_next();
        expr_value = expr();
        if (term_value < expr_value)
        {
            expr_value = 1;
        }
        else
        {
            expr_value = 0;
        }
        return(expr_value);
    case T_OP_GREATER:
        token_get_next();
        expr_value = expr();
        if (term_value > expr_value)
        {
            expr_value = 1;
        }
        else
        {
            expr_value = 0;
        }
        return(expr_value);
    case T_OP_LET:
        local_ivar = ivar;
        token_get_next();
        expr_value      = expr();
        var[local_ivar] = expr_value;
        //printf("let[%lx] \n", var[local_ivar]);
        return(expr_value);
    case T_NO:
        local_ivar = ivar;
        token_get_next();
        expr_value      = expr();
        var[local_ivar] = local_value;
        //printf("NO[%lx] \n", local_value);
        return local_value;
    case T_end_of_expr:
    case T_EOF:
        return(term_value);
    case T_PLUS:
        token_get_next();
        expr_value = expr();
        return(term_value + expr_value);
    case T_MINUS:
        token_get_next();
        expr_value = expr();
        return(term_value - expr_value);
    default:
        return(term_value);
    }
}

boolean_t get_linea(char_t linea[])
{
    boolean_t  ans;
    uart_ans_t uart_ans;
    char_t     ch;
    uint32_t   i;
    boolean_t  is_run;


    uart_putchar('>');
    uart_putchar(' ');

    is_run = True;
    i      = 0;
    while (is_run == True)
    {
        uart_ans = uart_getchar();
        if (uart_ans.is_valid == True)
        {
            ch = uart_ans.ch;
            if ((ch == '\n')logicalOr(ch == '\r'))
            {
                linea[i] = '\0';
                is_run   = False;
                ans      = True;
            }
            else if (i < linea_size)
            {
                linea[i] = ch;
                /* echo */ uart_putchar(ch);
                i++;
            }
            else
            {
                linea[i] = '\0';
                is_run   = False;
                ans      = False;
            }
        }
    }

    if (i == 0)
    {
        ans = False;
    }

    uart_nl();
    return ans;
}

boolean_t eval_sub_linea()
{
    boolean_t ans;
    boolean_t is_ok;
    sint32_t  value;

    any_error = False;
    token_get_next(); /* get the first token */
    value = expr();
    is_ok = True;
    if (any_error == False)
    {
        uart_putchar('#');
        uart_putchar(' ');
        uart_printhex_32(value);
        uart_nl();
    }

    ans = any_error;
    return ans;
}

boolean_t eval_linea()
{
    boolean_t ans;
    sint32_t  value;

    cur_char = 0;
    do
    {
        is_sub_expr = False;
        ans         = eval_sub_linea();
    } while (is_sub_expr == True);

    if (cur_token.token_type != T_EOF)
    {
        error(msg_err4);
    }

    return ans;
}

private void error(char message[])
{
    uint32_t i;

    if (any_error == False)
    {
        any_error = True;

        uart_putchar(' ');
        uart_putchar(' ');
        for (i = 0; i < cur_token.position; i++)
        {
            uart_putchar(' ');
        }
        uart_putchar('^');
        uart_nl();

        uart_putchar('!');
        uart_putchar(' ');
        uart_putmsg(message);
        uart_nl();
    }
}

void do_diag()
{
    uart_ans_t uart_ans;
    char_t     ch;
    boolean_t  is_done;

    uart_putchar('d');
    uart_putchar('i');
    uart_putchar('a');
    uart_putchar('g');
    uart_nl();

    is_done = False;
    while (is_done == False)
    {
        uart_ans = uart_getchar();
        if (uart_ans.is_valid == True)
        {
            ch = uart_ans.ch;
            switch (ch)
            {
            case '.':
                is_done = True;
                break;
            case 'd':
                //mem_view(addr_data_begin, addr_data_end);
                uart_nl();
                break;
            case 's':
                //mem_view(addr_stack_begin, addr_stack_end);
                uart_nl();
                break;
            case  'c':
                //mem_view(addr_code_begin, addr_code_end);
                uart_nl();
                break;
            default:
                uart_putchar(ch);
                break;
            }
        }
    }
}

void interactive()
{
    boolean_t ans;
    boolean_t is_done;

    is_done = False;
    while (is_done == False)
    {
        any_error = False;
        ans       = get_linea(linea);
        if (ans == True)
        {
            if (linea[0] == '.')
            {
                do_diag();
                is_done = True;
            }
            else
            {
                ans = eval_linea();
            }
        }
        uart_nl();
    }
}


