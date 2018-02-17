/* -*- mode: c++ ; coding: utf-8-unix -*- */

#pragma once

#ifndef CPARSEC_CORE_GEN_PARSER_FILTER_PARSER_H
#define CPARSEC_CORE_GEN_PARSER_FILTER_PARSER_H

#include "cparsec.h"
#include "cparsec/core/parser.h"

//// Constructs ParserSt< T (int, Parser) >
#define FILTER_PARSER( name, f, x )            &(FILTER_PARSER_ST( name, f, x ))
#define FILTER_PARSER_ST( name, f, x )         (ParserSt)FILTER_PARSER_ST_INIT( name, f, x )
#define FILTER_PARSER_ST_INIT( name, f, x )        \
    {                                              \
        .ref_cnt = -1,                             \
        .arg1 = VAL_INIT(FILTER)( f ),             \
        .arg2 = VAL_INIT(D_PARSER)( x ),           \
        .run  = PARSER_FUNC_NAME( name ),          \
    }


//// Define a parser generator `Parser<T> name( int n, Parser x )`
#define DEF_PARSER__FILTER_PARSER( name )          \
    Parser name( Filter f, Parser x )              \
    {                                              \
        assert( x );                               \
        Parser p = Parser_new();                   \
        if ( p ) {                                 \
            *p = FILTER_PARSER_ST( name, f, x );   \
            p->ref_cnt = 0;                        \
            Parser_ref( x );                       \
        }                                          \
        return p;                                  \
    }                                              \
    DECL_PARSER_FUNC( name )

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif  /* CPARSEC_CORE_GEN_PARSER_FILTER_PARSER_H */
