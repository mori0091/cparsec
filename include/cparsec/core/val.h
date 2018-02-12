/* -*- mode: c++ ; coding: utf-8-unix -*- */

#pragma once

#ifndef CPARSEC_CORE_VAL_H
#define CPARSEC_CORE_VAL_H

#include <stdbool.h>
#include <stdlib.h>

//// macros of various compound literal of Val
#define            NONE_VAL       (Val)NONE_VAL_INIT
#define           ERROR_VAL( x )  (Val)ERROR_VAL_INIT((x))
#define            CHAR_VAL( x )  (Val)CHAR_VAL_INIT((x))
#define             INT_VAL( x )  (Val)INT_VAL_INIT((x))
#define          DOUBLE_VAL( x )  (Val)DOUBLE_VAL_INIT((x))
#define             PTR_VAL( x )  (Val)PTR_VAL_INIT((x))
#define          STRING_VAL( x )  (Val)STRING_VAL_INIT((x))
#define          PARSER_VAL( x )  (Val)PARSER_VAL_INIT((x))
#define       PREDICATE_VAL( x )  (Val)PREDICATE_VAL_INIT((x))

//// macros of various initializer of Val
#define      NONE_VAL_INIT       { 0 }
#define     ERROR_VAL_INIT( x )  { .type = ERROR    , .error     = (x), .del = 0 }
#define      CHAR_VAL_INIT( x )  { .type = CHAR     , .c         = (x), .del = 0 }
#define       INT_VAL_INIT( x )  { .type = INT      , .i         = (x), .del = 0 }
#define    DOUBLE_VAL_INIT( x )  { .type = DOUBLE   , .d         = (x), .del = 0 }
#define       PTR_VAL_INIT( x )  { .type = PTR      , .ptr       = (x), .del = 0 }
#define    STRING_VAL_INIT( x )  { .type = STRING   , .str       = (x), .del = 0 }
#define    PARSER_VAL_INIT( x )  { .type = PARSER   , .parser    = (x), .del = 0 }
#define PREDICATE_VAL_INIT( x )  { .type = PREDICATE, .predicate = (x), .del = 0 }

//// macros of various compound literal of Val, whose value must be deallocated
#define        D_ERROR_VAL( x )  (Val)D_ERROR_VAL_INIT((x))
#define          D_PTR_VAL( x )  (Val)D_PTR_VAL_INIT((x))
#define       D_STRING_VAL( x )  (Val)D_STRING_VAL_INIT((x))
#define       D_PARSER_VAL( x )  (Val)D_STRING_VAL_INIT((x))

//// macros of various initializer of Val, whose value must be deallocated
#define   D_ERROR_VAL_INIT( x )  { .type = ERROR    , .str       = (x), .del = free }
#define     D_PTR_VAL_INIT( x )  { .type = PTR      , .ptr       = (x), .del = free }
#define  D_STRING_VAL_INIT( x )  { .type = STRING   , .str       = (x), .del = free }
#define  D_PARSER_VAL_INIT( x )  { .type = PARSER   , .parser    = (x), .del = (Deleter)Parser_unref }

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct Val Val;
    typedef bool (*Predicate)( char );
    typedef void (*Deleter)( void* );

    enum ValType {
        ERROR,                  ///< const char* error
        CHAR,                   ///< char c
        INT,                    ///< int i
        DOUBLE,                 ///< double d
        PTR,                    ///< void* ptr
        STRING,                 ///< const char* str
        PARSER,                 ///< Parser parser
        PREDICATE,              ///< Predicate predicate
    };

    struct Val {
        enum  ValType  type;    ///< Type of the value
        union {
            const char*      error;     ///< An error message for type of ERROR
            char             c;         ///< A char value for type of CHAR
            int              i;         ///< An int value for type of INT
            double           d;         ///< A double value for type of DOUBLE
            void*            ptr;       ///< A void* value for type of PTR
            const char*      str;       ///< A const char* value for type of STRING
            struct ParserSt* parser;    ///< A Parser value for type of PARSER
            Predicate        predicate; ///< A Predicate value for type of PREDICATE
        };
        Deleter del;
    };

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
