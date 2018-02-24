/* -*- mode: c++ ; coding: utf-8-unix -*- */

#pragma once

#ifndef CPARSEC_CORE_VAL_H
#define CPARSEC_CORE_VAL_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

/**
 * \brief Constructs various Val.
 *
 * VAL(T) is expanded to Val_T a constructor type of T. T must be an
 * enum ValType or one of D_ERROR, D_PTR, D_STRING, D_PARSER.
 *
 * Thus, for example\n
 * - VAL(NONE) is expanded to Val_NONE
 * - VAL(ERROR)("an error") is expanded to Val_ERROR("an error")
 * - VAL(INT)(100) is expanded to Val_INT(100)
 * - and so on.
 *
 * \param T    An enum ValType or one of D_ERROR, D_PTR, D_STRING, D_PARSER.
 */
#define VAL(T)         VAL_I(T)
#define VAL_I(T)       Val_ ## T

/**
 * \brief Constructs various initializer of Val.
 *
 * VAL_INIT(T) is expanded to T_VAL_INIT a initializer type of T. T
 * must be an enum ValType or one of D_ERROR, D_PTR, D_STRING,
 * D_PARSER.
 *
 * Thus, for example,\n
 * - VAL_INIT(NONE) is expanded to { .type = NONE, .ptr = 0, .del = 0 }
 * - VAL_INIT(ERROR)("an error") is expanded to { .type = ERROR, .error = ("an error"), .del = 0 }
 * - VAL_INIT(INT)(100) is expanded to { .type = INT, .i = (100), .del = 0 }
 * - and so on.
 *
 * \note VAL_INIT(NONE) and VAL_INIT(T)(x) is expanded to a C99
 *       designated initializer, which ISO C++ doesn't support.
 *
 * \note VAL_INIT(NONE) and VAL_INIT(T)(x) is needed only for C to
 *       initialize static Val. For C++, use VAL(T) instead.
 *
 * \param T    An enum ValType or one of D_ERROR, D_PTR, D_STRING, D_PARSER.
 */
#define VAL_INIT(T)    VAL_INIT_I(T)
#define VAL_INIT_I(T)  T ## _VAL_INIT

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
/** \note use VAL_INIT(INT16)(x) or VAL_INIT(I16)(x) instead. */
#define     INT16_VAL_INIT( x )  { .type = INT16    , .i16       = (x), .del = 0 }
/** \note use VAL_INIT(INT32)(x) or VAL_INIT(I32)(x) instead. */
#define     INT32_VAL_INIT( x )  { .type = INT32    , .i32       = (x), .del = 0 }
/** \note use VAL_INIT(INT64)(x) or VAL_INIT(I64)(x) instead. */
#define     INT64_VAL_INIT( x )  { .type = INT64    , .i64       = (x), .del = 0 }
/** \note use VAL_INIT(UINT8)(x) or VAL_INIT(U8)(x) instead. */
#define     UINT8_VAL_INIT( x )  { .type = UINT8    , .u8        = (x), .del = 0 }
/** \note use VAL_INIT(UINT16)(x) or VAL_INIT(U16)(x) instead. */
#define    UINT16_VAL_INIT( x )  { .type = UINT16   , .u16       = (x), .del = 0 }
/** \note use VAL_INIT(UINT32)(x) or VAL_INIT(U32)(x) instead. */
#define    UINT32_VAL_INIT( x )  { .type = UINT32   , .u32       = (x), .del = 0 }
/** \note use VAL_INIT(UINT64)(x) or VAL_INIT(U64)(x) instead. */
#define    UINT64_VAL_INIT( x )  { .type = UINT64   , .u64       = (x), .del = 0 }

/** \note use VAL_INIT(INT8)(x) or VAL_INIT(I8)(x) instead. */
#define I8_VAL_INIT    INT8_VAL_INIT
/** \note use VAL_INIT(INT16)(x) or VAL_INIT(I16)(x) instead. */
#define I16_VAL_INIT   INT16_VAL_INIT
/** \note use VAL_INIT(INT32)(x) or VAL_INIT(I32)(x) instead. */
#define I32_VAL_INIT   INT32_VAL_INIT
/** \note use VAL_INIT(INT64)(x) or VAL_INIT(I64)(x) instead. */
#define I64_VAL_INIT   INT64_VAL_INIT
/** \note use VAL_INIT(UINT8)(x) or VAL_INIT(U8)(x) instead. */
#define U8_VAL_INIT    UINT8_VAL_INIT
/** \note use VAL_INIT(UINT16)(x) or VAL_INIT(U16)(x) instead. */
#define U16_VAL_INIT   UINT16_VAL_INIT
/** \note use VAL_INIT(UINT32)(x) or VAL_INIT(U32)(x) instead. */
#define U32_VAL_INIT   UINT32_VAL_INIT
/** \note use VAL_INIT(UINT64)(x) or VAL_INIT(U64)(x) instead. */
#define U64_VAL_INIT   UINT64_VAL_INIT

#define Val_I8         Val_INT8
#define Val_I16        Val_INT16
#define Val_I32        Val_INT32
#define Val_I64        Val_INT64
#define Val_U8         Val_UINT8
#define Val_U16        Val_UINT16
#define Val_U32        Val_UINT32
#define Val_U64        Val_UINT64

/** \note use VAL_INIT(FILTER)(x) instead. */
#define    FILTER_VAL_INIT( x )  { .type = FILTER   , .filter    = (x), .del = 0 }

//// macros of various initializer of Val, whose value must be deallocated
/** \note use VAL_INIT(D_ERROR)(x) instead. */
#define   D_ERROR_VAL_INIT( x )  { .type = ERROR    , .str       = (x), .del = free }
/** \note use VAL_INIT(D_PTR)(x) instead. */
#define     D_PTR_VAL_INIT( x )  { .type = PTR      , .ptr       = (x), .del = free }
/** \note use VAL_INIT(D_STRING)(x) instead. */
#define  D_STRING_VAL_INIT( x )  { .type = STRING   , .str       = (x), .del = free }
/** \note use VAL_INIT(D_PARSER)(x) instead. */
#define  D_PARSER_VAL_INIT( x )  { .type = PARSER   , .parser    = (x), .del = (Deletor)Parser_unref }

#ifdef __cplusplus
extern "C" {
#endif

    /** \brief A type synonym of struct Val */
    typedef struct Val Val;
    /** \brief Type of a predicate function - a function pointer bool (*)(char) */
    typedef bool (*Predicate)( char );
    /** \brief Type of a filter function - a function pointer Val (*)(Val) */
    typedef Val (*Filter)( Val );
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
        I16 = INT16,            ///< int16_t i16 (synonym for INT16)
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
        /* filter function pointer */
        FILTER,
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
            /* filter function pointer */
            Filter           filter;    ///< A Filter value for type of FILTER
        };
        /** \brief A deletor function of the value. NULL if the value does not need to be deleted. */
        Deletor del;
    };

    //// constructors

    extern const Val Val_NONE;
    Val Val_VAL( Val x );
    Val Val_ERROR ( const char* error );
    Val Val_CHAR  ( char c );
    Val Val_INT   ( int i );
    Val Val_DOUBLE( double d  );
    Val Val_PTR   ( void* ptr );
    Val Val_STRING( const char* str );
    Val Val_PARSER( struct ParserSt* parser );
    Val Val_PREDICATE( Predicate predicate );
    Val Val_INT8  ( int8_t i8 );
    Val Val_INT16 ( int16_t i16 );
    Val Val_INT32 ( int32_t i32 );
    Val Val_INT64 ( int64_t i64 );
    Val Val_UINT8 ( uint8_t u8 );
    Val Val_UINT16( uint16_t u16 );
    Val Val_UINT32( uint32_t u32 );
    Val Val_UINT64( uint64_t u64 );
    Val Val_FILTER( Filter filter );
    Val Val_D_ERROR ( const char* error );
    Val Val_D_PTR   ( void* ptr );
    Val Val_D_STRING( const char* str );
    Val Val_D_PARSER( struct ParserSt* parser );

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

#ifdef __cplusplus
// For C++ ; function overload
inline Val val(Val         x) { return x; }
inline Val val(char        x) { return VAL(CHAR)(x); }
inline Val val(int         x) { return VAL(INT)(x); }
inline Val val(double      x) { return VAL(DOUBLE)(x); }
inline Val val(const char* x) { return VAL(STRING)(x); }
inline Val val(void*       x) { return VAL(PTR)(x); }

#else
// For C11 ; function overload by the generic selection macro
#define val(x)                                  \
    _Generic((x)                                \
             , Val         : Val_VAL            \
             , char        : Val_CHAR           \
             , int         : Val_INT            \
             , double      : Val_DOUBLE         \
             , const char* : Val_STRING         \
             , void*       : Val_PTR            \
             )(x)

#endif

#endif  /* CPARSEC_CORE_VAL_H */
