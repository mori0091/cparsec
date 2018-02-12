/* -*- mode: c++ ; coding: utf-8-unix -*- */

#pragma once

#ifndef CPARSEC_CORE_GEN_PARSER_BINARY_OP_H
#define CPARSEC_CORE_GEN_PARSER_BINARY_OP_H

#include "cparsec.h"
#include "cparsec/core/parser.h"

//// Constructs ParserSt< T (Parser, Parser) >
#define BINARY_OP( name, x, y )            &(BINARY_OP_ST( name, x, y ))
#define BINARY_OP_ST( name, x, y )         (ParserSt)BINARY_OP_ST_INIT( name, x, y )
#define BINARY_OP_ST_INIT( name, x, y )         \
    {                                           \
        .ref_cnt = -1,                          \
        .arg1 = D_PARSER_VAL_INIT( x ),         \
        .arg2 = D_PARSER_VAL_INIT( y ),         \
        .run  = PARSER_FUNC_NAME( name ),       \
    }


//// Define a parser generator `Parser<T> name( Parser x, Parser y )`
#define DEF_GEN_PARSER__BINARY_OP( name )               \
    Parser name( Parser x, Parser y )                   \
    {                                                   \
        assert( x );                                    \
        assert( y );                                    \
        Parser p = Parser_new();                        \
        if ( p ) {                                      \
            *p = BINARY_OP_ST( name, x, y );            \
            p->ref_cnt = 0;                             \
            Parser_ref( x );                            \
            Parser_ref( y );                            \
        }                                               \
        return p;                                       \
    }                                                   \
    DECL_PARSER_FUNC( name )

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif  /* CPARSEC_CORE_GEN_PARSER_BINARY_OP_H */
