/* -*- mode: c++ ; coding: utf-8-unix -*- */

#pragma once

#ifndef CPARSEC_CORE_GEN_PARSER_UNARY_OP_H
#define CPARSEC_CORE_GEN_PARSER_UNARY_OP_H

#include "cparsec.h"
#include "cparsec/core/parser.h"

//// Constructs ParserSt< T (Parser) >
#define UNARY_OP( name, x )            &(UNARY_OP_ST( name, x ))
#define UNARY_OP_ST( name, x )         (ParserSt)UNARY_OP_ST_INIT( name, x )
#define UNARY_OP_ST_INIT( name, x )             \
    {                                           \
        .ref_cnt = -1,                          \
        .arg1 = VAL_INIT(D_PARSER)( x ),        \
        .arg2 = VAL_INIT(NONE),                 \
        .run  = PARSER_FUNC_NAME( name ),       \
    }


//// Define a parser generator `Parser<T> name( Parser x )`
#define DEF_PARSER__UNARY_OP( name )                    \
    Parser name( Parser x )                             \
    {                                                   \
        assert( x );                                    \
        Parser p = Parser_new();                        \
        if ( p ) {                                      \
            *p = UNARY_OP_ST( name, x );                \
            p->ref_cnt = 0;                             \
            Parser_ref( x );                            \
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

#endif  /* CPARSEC_CORE_GEN_PARSER_UNARY_OP_H */
