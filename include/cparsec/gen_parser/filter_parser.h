/* -*- mode: c++ ; coding: utf-8-unix -*- */

#pragma once

#ifndef CPARSEC_CORE_GEN_PARSER_FILTER_PARSER_H
#define CPARSEC_CORE_GEN_PARSER_FILTER_PARSER_H

#include "cparsec.h"
#include "cparsec/core/parser.h"

//// Constructs ParserSt< T (Fn1, Parser) >
#define FILTER_PARSER( name, f, x )            &(FILTER_PARSER_ST( name, f, x ))
#define FILTER_PARSER_ST( name, f, x )         (ParserSt)FILTER_PARSER_ST_INIT( name, f, x )
#define FILTER_PARSER_ST_INIT( name, f, x )        \
    {                                              \
        .ref_cnt = -1,                             \
        .arg1 = VAL_INIT(D_FN)( f.f ),             \
        .arg2 = VAL_INIT(D_PARSER)( x ),           \
        .run  = PARSER_FUNC_NAME( name ),          \
    }


//// Define a parser generator `Parser<T> name( Fn1 f, Parser x )`
#define DEF_PARSER__FILTER_PARSER( name )          \
    Parser name( Fn1 f, Parser x )                 \
    {                                              \
        assert( x );                               \
        Parser p = Parser_new();                   \
        if ( p ) {                                 \
            *p = FILTER_PARSER_ST( name, f, x );   \
            Fn_ref( f.f );                         \
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
