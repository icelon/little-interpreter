#ifndef _TYPES_
#define _TYPES_

/*********************************************
   special types, directive
*********************************************/
#define private          static
#define public           extern
#define memory_mapped    volatile

#undef True
#undef False
#undef Success
#undef Failure

/*********************************************
   special types, redefined
*********************************************/
/* typedef unsigned long long   uint64_t; */

typedef float           fp32_t;      /* ieee 574 */
typedef double          fp64_t;


#ifndef _UINT32_T_
#define _UINT32_T_
typedef unsigned long   uint32_t;
#endif
#define uint32_range_MAX    4294967295
#define uint32_range_MIN    0


#ifndef _UINT16_T_
#define _UINT16_T_
typedef unsigned short  uint16_t;
#endif

#ifndef _UINT8_T_
#define _UINT8_T_
typedef unsigned char    uint8_t;
#endif

#ifndef _SINT32_T_
#define _SINT32_T_
typedef   signed long    sint32_t;
#endif
#define sint32_range_MAX    2147483647
#define sint32_range_MIN    -2147483647

#ifndef _SINT16_T_
#define _SINT16_T_
typedef   signed short   sint16_t;
#endif

#ifndef _SINT8_T_
#define _SINT8_T_
typedef   signed char    sint8_t;
#endif

/*
   typedef unsigned long  UINT32;
   typedef unsigned short UINT16;
   typedef unsigned char  UINT8;
 */

/*********************************************
   special pointers types, redefined
*********************************************/
typedef unsigned long*        p_uint32_t;
typedef unsigned short*       p_uint16_t;
typedef unsigned char*        p_uint8_t;

typedef   signed long*        p_sint32_t;
typedef   signed short*       p_sint16_t;
typedef   signed char*        p_sint8_t;

/* typedef       char*        string_t; */
typedef          char         char_t;
typedef          char*        p_char_t;

typedef          void*        p_generic_t; /* generic, general-purpose pointer */

typedef          void*  p_this_t;
typedef          void*  p_that_t;

#define new_string(x, msg)    char_t x[] = msg

typedef const unsigned char   ro_uint8_t;


/*********************************************
   special types, redefined
*********************************************/
typedef enum
{
    False = 0,
    True  = 1
} boolean_t;
typedef boolean_t* p_boolean_t;

typedef enum
{
    Failure  = 0,
    Success  = 1
} boolean_result_t;
typedef boolean_result_t* p_boolean_result_t;

/*********************************************
   special function-answer types
*********************************************/
//typedef enum
//{
//    success = 0,
//    failure = 1,
//    out_of_memory
//} ans_error_t;/
//
//typedef ans_error_t   try_t;
//
//typedef struct
//{
//    uint32_t    number;
//    ans_error_t result;
//} ans_uint32_t;
//
//typedef struct
//{
//    uint8_t     number;
//    ans_error_t result;
//} ans_uint8_t;
//
//typedef struct
//{
//    char_t      ch;
//    ans_error_t result;
//} ans_char_t;
//
//typedef struct
//{
//    char_t      string;
//    ans_error_t result;
//} ans_string_t;
//
//typedef struct
//{
//    p_generic_t p;
//    ans_error_t result;
//} ans_p_generic_t;

typedef struct
{
    char_t   data;
    uint32_t len;
    uint32_t i;
} istring_t;

/*********************************************
   logical operations
*********************************************/
#define remaind        %
#define modula         %
#define bitwiseAnd     &
#define logicalAnd     &&
/* #define bitwiseNot     0xffffffffL ^ */
#define bitwiseNot     ~
#define bitwiseOr      |
#define bitwiseExOr    ^
#define logicalOr      ||
#define logicalNot     !
#define isEqualTo      ==
#define isNotEqualTo   !=

/*********************************************
   shift operations
*********************************************/
#define shiftLeft      <<
#define shiftRight     >>

/*********************************************
   pointer  operations
*********************************************/
/* #define get_pointer(x)      & x */
#define get_address(x)      & x
#define pointed_value(x)    *x

#ifndef NULL
        #define NULL    0x00
        #endif

#define is_even(x) ((x%2)isEqualTo 0)
#define is_string_empty(x) (x[0] isEqualTo '\0')
#define is_string_not_empty(x) (x[0] isNotEqualTo '\0')
#define make_string_empty(x) (x[0]='\0')

#endif
