#ifndef _lib_calc_early_v0_
#define _lib_calc_early_v0_

#include "types.h"
#include "lib_uart_mini.h"
#include "lib_hex.h"
#include "lib_host.h"
#include "lib_bsp_entity.h"

typedef enum
{
    T_OP_MINUS,           /* "<"           */
    T_OP_GREATER,         /* ">"           */
    T_OP_EQUAL,           /* "?"           */
    T_OP_factorial,       /* "!"           */
    T_OP_LET,             /* "=            */
    T_VAR,                /*  varID        */
    T_L_PAREN,            /* "(            */
    T_R_PAREN,            /* ")            */
    T_PLUS,               /* "+"           */
    T_MINUS,              /* "-"           */
    T_TIMES,              /* "*"           */
    T_DIV,                /* "/"           */
    T_INT,                /* integerNumber */
    T_NO,                 /* not operation */
    T_SUB_EXPR,
    T_IO_WR,
    T_IO_RD,
    T_IO_ADDR,
    T_IO_DATA,
    T_end_of_expr,
    T_EOF                 /* End of file   */
} token_kind_t;

typedef struct
{
    token_kind_t token_type;
    sint32_t     position;
    sint32_t     value;
} token_t;


#include "lib_calc_early_v0.interface"

#endif

