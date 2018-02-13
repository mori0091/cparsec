/* -*- mode: c++ ; coding: utf-8-unix -*- */

#pragma once

#ifndef CPARSEC_CORE_VAL_H
#define CPARSEC_CORE_VAL_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

/**
 * \brief Constructs various compound literal of Val.
 *
 * VAL(T) is expanded to (Val)VAL_INIT(T), and VAL_INIT(T) is expanded
 * to T_VAL_INIT.
 *
 * Thus, for example\n
 * - VAL(NONE) is expanded to (Val){0}
 * - VAL(ERROR)("an error") is expanded to (Val){ .type = ERROR, .error = ("an error"), .del = 0 }
 * - VAL(INT)(100) is expanded to (Val){ .type = INT, .i = (100), .del = 0 }
 * - and so on.
 *
 * \param T    An enum ValType or one of D_ERROR, D_PTR, D_STRING, D_PARSER.
 */
#ifdef __cplusplus
#define VAL(T)         VAL_INIT(T)
#else
#define VAL(T)         (Val)VAL_INIT(T)
#endif

/**
 * \brief Constructs various initializer of Val.
 *
 * VAL_INIT(T) is expanded to T_VAL_INIT.
 *
 * Thus, for example,\n
 * - VAL_INIT(NONE) is expanded to {0}
 * - VAL_INIT(ERROR)("an error") is expanded to { .type = ERROR, .error = ("an error"), .del = 0 }
 * - VAL_INIT(INT)(100) is expanded to { .type = INT, .i = (100), .del = 0 }
 * - and so on.
 *
 * \param T    An enum ValType or one of D_ERROR, D_PTR, D_STRING, D_PARSER.
 */
#define VAL_INIT(T)    VAL_INIT_I(T)
#define VAL_INIT_I(T)  T ## _VAL_INIT

//// macros of various initializer of Val
#ifdef __cplusplus

#define      NONE_VAL_INIT       Val_NONE()
#define     ERROR_VAL_INIT( x )  Val_ERROR( (x) )
#define      CHAR_VAL_INIT( x )  Val_CHAR( (x) )
#define       INT_VAL_INIT( x )  Val_INT( (x) )
#define    DOUBLE_VAL_INIT( x )  Val_DOUBLE( (x) )
#define       PTR_VAL_INIT( x )  Val_PTR( (x) )
#define    STRING_VAL_INIT( x )  Val_STRING( (x) )
#define    PARSER_VAL_INIT( x )  Val_PARSER( (x) )
#define PREDICATE_VAL_INIT( x )  Val_PREDICATE( (x) )
#define      INT8_VAL_INIT( x )  Val_INT8( (x) )
#define        I8_VAL_INIT       INT8_VAL_INIT
#define     INT16_VAL_INIT( x )  Val_INT16( (x) )
#define       I16_VAL_INIT       INT16_VAL_INIT
#define     INT32_VAL_INIT( x )  Val_INT32( (x) )
#define       I32_VAL_INIT       INT32_VAL_INIT
#define     INT64_VAL_INIT( x )  Val_INT64( (x) )
#define       I64_VAL_INIT       INT64_VAL_INIT
#define     UINT8_VAL_INIT( x )  Val_UINT8( (x) )
#define        U8_VAL_INIT       UINT8_VAL_INIT
#define    UINT16_VAL_INIT( x )  Val_UINT16( (x) )
#define       U16_VAL_INIT       UINT16_VAL_INIT
#define    UINT32_VAL_INIT( x )  Val_UINT32( (x) )
#define       U32_VAL_INIT       UINT32_VAL_INIT
#define    UINT64_VAL_INIT( x )  Val_UINT64( (x) )
#define       U64_VAL_INIT       UINT64_VAL_INIT
#define   D_ERROR_VAL_INIT( x )  Val_D_ERROR( (x) )
#define     D_PTR_VAL_INIT( x )  Val_D_PTR( (x) )
#define  D_STRING_VAL_INIT( x )  Val_D_STRING( (x) )
#define  D_PARSER_VAL_INIT( x )  Val_D_PARSER( (x) )

#else

/** \note use VAL_INIT(NONE) instead. */
#define      NONE_VAL_INIT       { .type = NONE     , .ptr       = 0  , .del = 0 }
/** \note use VAL_INIT(ERROR)(x) instead. */
#define     ERROR_VAL_INIT( x )  { .type = ERROR    , .error     = (x), .del = 0 }
/** \note use VAL_INIT(CHAR)(x) instead. */
#define      CHAR_VAL_INIT( x )  { .type = CHAR     , .c         = (x), .del = 0 }
/** \note use VAL_INIT(INT)(x) instead. */
#define       INT_VAL_INIT( x )  { .type = INT      , .i         = (x), .del = 0 }
/** \note use VAL_INIT(DOUBLE)(x) instead. */
#define    DOUBLE_VAL_INIT( x )  { .type = DOUBLE   , .d         = (x), .del = 0 }
/** \note use VAL_INIT(PTR)(x) instead. */
#define       PTR_VAL_INIT( x )  { .type = PTR      , .ptr       = (x), .del = 0 }
/** \note use VAL_INIT(STRING)(x) instead. */
#define    STRING_VAL_INIT( x )  { .type = STRING   , .str       = (x), .del = 0 }
/** \note use VAL_INIT(PARSER)(x) instead. */
#define    PARSER_VAL_INIT( x )  { .type = PARSER   , .parser    = (x), .del = 0 }
/** \note use VAL_INIT(PREDICATE)(x) instead. */
#define PREDICATE_VAL_INIT( x )  { .type = PREDICATE, .predicate = (x), .del = 0 }
/** \note use VAL_INIT(INT8)(x) or VAL_INIT(I8)(x) instead. */
#define      INT8_VAL_INIT( x )  { .type = INT8     , .i8        = (x), .del = 0 }
/** \note use VAL_INIT(INT8)(x) or VAL_INIT(I8)(x) instead. */
#define        I8_VAL_INIT       INT8_VAL_INIT
/** \note use VAL_INIT(INT16)(x) or VAL_INIT(I16)(x) instead. */
#define     INT16_VAL_INIT( x )  { .type = INT16    , .i16       = (x), .del = 0 }
/** \note use VAL_INIT(INT16)(x) or VAL_INIT(I16)(x) instead. */
#define       I16_VAL_INIT       INT16_VAL_INIT
/** \note use VAL_INIT(INT32)(x) or VAL_INIT(I32)(x) instead. */
#define     INT32_VAL_INIT( x )  { .type = INT32    , .i32       = (x), .del = 0 }
/** \note use VAL_INIT(INT32)(x) or VAL_INIT(I32)(x) instead. */
#define       I32_VAL_INIT       INT32_VAL_INIT
/** \note use VAL_INIT(INT64)(x) or VAL_INIT(I64)(x) instead. */
#define     INT64_VAL_INIT( x )  { .type = INT64    , .i64       = (x), .del = 0 }
/** \note use VAL_INIT(INT64)(x) or VAL_INIT(I64)(x) instead. */
#define       I64_VAL_INIT       INT64_VAL_INIT
/** \note use VAL_INIT(UINT8)(x) or VAL_INIT(U8)(x) instead. */
#define     UINT8_VAL_INIT( x )  { .type = UINT8    , .u8        = (x), .del = 0 }
/** \note use VAL_INIT(UINT8)(x) or VAL_INIT(U8)(x) instead. */
#define        U8_VAL_INIT       UINT8_VAL_INIT
/** \note use VAL_INIT(UINT16)(x) or VAL_INIT(U16)(x) instead. */
#define    UINT16_VAL_INIT( x )  { .type = UINT16   , .u16       = (x), .del = 0 }
/** \note use VAL_INIT(UINT16)(x) or VAL_INIT(U16)(x) instead. */
#define       U16_VAL_INIT       UINT16_VAL_INIT
/** \note use VAL_INIT(UINT32)(x) or VAL_INIT(U32)(x) instead. */
#define    UINT32_VAL_INIT( x )  { .type = UINT32   , .u32       = (x), .del = 0 }
/** \note use VAL_INIT(UINT32)(x) or VAL_INIT(U32)(x) instead. */
#define       U32_VAL_INIT       UINT32_VAL_INIT
/** \note use VAL_INIT(UINT64)(x) or VAL_INIT(U64)(x) instead. */
#define    UINT64_VAL_INIT( x )  { .type = UINT64   , .u64       = (x), .del = 0 }
/** \note use VAL_INIT(UINT64)(x) or VAL_INIT(U64)(x) instead. */
#define       U64_VAL_INIT       UINT64_VAL_INIT

//// macros of various initializer of Val, whose value must be deallocated
/** \note use VAL_INIT(D_ERROR)(x) instead. */
#define   D_ERROR_VAL_INIT( x )  { .type = ERROR    , .str       = (x), .del = free }
/** \note use VAL_INIT(D_PTR)(x) instead. */
#define     D_PTR_VAL_INIT( x )  { .type = PTR      , .ptr       = (x), .del = free }
/** \note use VAL_INIT(D_STRING)(x) instead. */
#define  D_STRING_VAL_INIT( x )  { .type = STRING   , .str       = (x), .del = free }
/** \note use VAL_INIT(D_PARSER)(x) instead. */
#define  D_PARSER_VAL_INIT( x )  { .type = PARSER   , .parser    = (x), .del = (Deletor)Parser_unref }

#endif

#ifdef __cplusplus
extern "C" {
#endif

    /** \brief A type synonym of struct Val */
    typedef struct Val Val;
    /** \brief Type of a predicate function - a function pointer bool (*)(char) */
    typedef bool (*Predicate)( char );
    /** \brief Type of a deletor function - a function pointer void (*)(void*) */
    typedef void (*Deletor)( void* );

    /** \brief Type identifier of a Val's value */
    enum ValType {
        NONE = 0,               ///< (none)
        ERROR,                  ///< const char* error
        CHAR,                   ///< char c
        INT,                    ///< int i
        DOUBLE,                 ///< double d
        PTR,                    ///< void* ptr
        STRING,                 ///< const char* str
        PARSER,                 ///< Parser parser
        PREDICATE,              ///< Predicate predicate
        /* signed integers */
        INT8,                   ///< int8_t  i8
        I8 = INT8,              ///< int8_t  i8  (synonym for INT8)
        INT16,                  ///< int16_t i16
        I16 = INT16,            ///< int16_t i16 (synonym for INT8)
        INT32,                  ///< int32_t i32
        I32 = INT32,            ///< int32_t i32 (synonym for INT32)
        INT64,                  ///< int64_t i64
        I64 = INT64,            ///< int64_t i64 (synonym for INT64)
        /* unsigned integers */
        UINT8,                  ///< uint8_t  u8
        U8 = UINT8,             ///< uint8_t  u8  (synonym for UINT8)
        UINT16,                 ///< uint16_t u16
        U16 = UINT16,           ///< uint16_t u16 (synonym for UINT16)
        UINT32,                 ///< uint32_t u32
        U32 = UINT32,           ///< uint32_t u32 (synonym for UINT32)
        UINT64,                 ///< uint64_t u64
        U64 = UINT64,           ///< uint64_t u64 (synonym for UINT64)
    };

    struct Val {
        /** \brief Type identifier of the value */
        enum  ValType  type;
        /** \brief the value of this Val */
        union {
            const char*      error;     ///< An error message for type of ERROR
            char             c;         ///< A char value for type of CHAR
            int              i;         ///< An int value for type of INT
            double           d;         ///< A double value for type of DOUBLE
            void*            ptr;       ///< A void* value for type of PTR
            const char*      str;       ///< A const char* value for type of STRING
            struct ParserSt* parser;    ///< A Parser value for type of PARSER
            Predicate        predicate; ///< A Predicate value for type of PREDICATE
            /* signed integers */
            int8_t           i8;        ///< An int8_t value for type of INT8
            int16_t          i16;       ///< An int16_t value for type of INT16
            int32_t          i32;       ///< An int32_t value for type of INT32
            int64_t          i64;       ///< An int64_t value for type of INT64
            /* unsigned integers */
            uint8_t          u8;        ///< An uint8_t value for type of UINT8
            uint16_t         u16;       ///< An uint16_t value for type of UINT16
            uint32_t         u32;       ///< An uint32_t value for type of UINT32
            uint64_t         u64;       ///< An uint64_t value for type of UINT64
        };
        /** \brief A deletor function of the value. NULL if the value does not need to be deleted. */
        Deletor del;
    };

    extern void Parser_unref( struct ParserSt* );

    inline Val Val_NONE  ( void )                      { Val ret; ret.type = NONE;      ret.ptr = 0;               ret.del = 0; return ret; }
    inline Val Val_ERROR ( const char* error )         { Val ret; ret.type = ERROR;     ret.error = error;         ret.del = 0; return ret; }
    inline Val Val_CHAR  ( char c )                    { Val ret; ret.type = CHAR;      ret.c = c;                 ret.del = 0; return ret; }
    inline Val Val_INT   ( int i )                     { Val ret; ret.type = INT;       ret.i = i;                 ret.del = 0; return ret; }
    inline Val Val_DOUBLE( double d  )                 { Val ret; ret.type = DOUBLE;    ret.d = d;                 ret.del = 0; return ret; }
    inline Val Val_PTR   ( void* ptr )                 { Val ret; ret.type = PTR;       ret.ptr = ptr;             ret.del = 0; return ret; }
    inline Val Val_STRING( const char* str )           { Val ret; ret.type = STRING;    ret.str = str;             ret.del = 0; return ret; }
    inline Val Val_PARSER( struct ParserSt* parser )   { Val ret; ret.type = PARSER;    ret.parser = parser;       ret.del = 0; return ret; }
    inline Val Val_PREDICATE( Predicate predicate )    { Val ret; ret.type = PREDICATE; ret.predicate = predicate; ret.del = 0; return ret; }
    inline Val Val_INT8  ( int8_t i8 )                 { Val ret; ret.type = INT8;      ret.i8 = i8;               ret.del = 0; return ret; }
    inline Val Val_INT16 ( int16_t i16 )               { Val ret; ret.type = INT16;     ret.i16 = i16;             ret.del = 0; return ret; }
    inline Val Val_INT32 ( int32_t i32 )               { Val ret; ret.type = INT32;     ret.i32 = i32;             ret.del = 0; return ret; }
    inline Val Val_INT64 ( int64_t i64 )               { Val ret; ret.type = INT64;     ret.i64 = i64;             ret.del = 0; return ret; }
    inline Val Val_UINT8 ( uint8_t u8 )                { Val ret; ret.type = UINT8;     ret.u8 = u8;               ret.del = 0; return ret; }
    inline Val Val_UINT16( uint16_t u16 )              { Val ret; ret.type = UINT16;    ret.u16 = u16;             ret.del = 0; return ret; }
    inline Val Val_UINT32( uint32_t u32 )              { Val ret; ret.type = UINT32;    ret.u32 = u32;             ret.del = 0; return ret; }
    inline Val Val_UINT64( uint64_t u64 )              { Val ret; ret.type = UINT64;    ret.u64 = u64;             ret.del = 0; return ret; }
    inline Val Val_D_ERROR ( const char* error )       { Val ret; ret.type = ERROR;     ret.error = error;         ret.del = free; return ret; }
    inline Val Val_D_PTR   ( void* ptr )               { Val ret; ret.type = PTR;       ret.ptr = ptr;             ret.del = free; return ret; }
    inline Val Val_D_STRING( const char* str )         { Val ret; ret.type = STRING;    ret.str = str;             ret.del = free; return ret; }
    inline Val Val_D_PARSER( struct ParserSt* parser ) { Val ret; ret.type = PARSER;    ret.parser = parser;       ret.del = (Deletor)Parser_unref; return ret; }

    /**
     * \brief Deallocates a value.
     *
     * Val_del() deallocates `x->ptr` by calling `x->del( x->ptr )` if
     * `x->del` was not NULL.
     *
     * You should deallocate Val by calling this function when a Val
     * was no longer needed.
     *
     * \param x    a pointer to a Val
     */
    void Val_del( Val* x );
    /**
     * \brief Prints a Val to stdout as string.
     *
     * \param x    a pointer to a Val
     */
    void Val_print( Val* x );
    /**
     * \brief Concatenates two Val, and deallocates them.
     *
     * \param x    a pointer to a Val
     * \param y    a pointer to a Val
     * \param      a Val which has concatenated string.
     */
    Val Val_concat( Val* x, Val* y );
  
#ifdef __cplusplus
}
#endif

#endif  /* CPARSEC_CORE_VAL_H */
