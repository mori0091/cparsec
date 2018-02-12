/* -*- mode: c++ ; coding: utf-8-unix -*- */

#pragma once

#ifndef CPARSEC_CORE_GEN_PARSER_INT_PARSER_H
#define CPARSEC_CORE_GEN_PARSER_INT_PARSER_H

#include "cparsec.h"
#include "cparsec/core/parser.h"

//// Constructs ParserSt< T (int, Parser) >
#define INT_PARSER( name, n, x )            &(INT_PARSER_ST( name, (n), (x) ))
#define INT_PARSER_ST( name, n, x )         (ParserSt)INT_PARSER_ST_INIT( name, (n), (x) )
#define INT_PARSER_ST_INIT( name, n, x )        \
    {                                           \
        .ref_cnt = 0,                           \
        .arg1 = INT_VAL_INIT( (n) ),            \
        .arg2 = D_PARSER_VAL_INIT( (x) ),       \
        .run  = PARSER_FUNC_NAME( name ),       \
    }


//// Define a parser generator `Parser<T> name( int n, Parser x )`
#define DEF_GEN_PARSER__INT_PARSER( name )      \
    Parser name( int n, Parser x )              \
    {                                           \
        assert( x );                            \
        Parser p = Parser_new();                \
        if ( p ) {                              \
            *p = INT_PARSER_ST( name, n, x );   \
            Parser_ref( x );                    \
        }                                       \
        return p;                               \
    }                                           \
    DECL_PARSER_FUNC( name )

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif  /* CPARSEC_CORE_GEN_PARSER_INT_PARSER_H */
