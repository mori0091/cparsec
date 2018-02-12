/* -*- mode: c++ ; coding: utf-8-unix -*- */

#pragma once

#ifndef CPARSEC_CORE_GEN_PARSER_CHAR_H
#define CPARSEC_CORE_GEN_PARSER_CHAR_H

#include "cparsec.h"
#include "cparsec/core/parser.h"

//// Constructs ParserSt< T (char) >
#define CHAR( name, x )            &(CHAR_ST( name, x ))
#define CHAR_ST( name, x )         (ParserSt)CHAR_ST_INIT( name, x )
#define CHAR_ST_INIT( name, x )                 \
    {                                           \
        .ref_cnt = -1,                          \
        .arg1 = CHAR_VAL_INIT( x ),             \
        .arg2 = NONE_VAL_INIT,                  \
        .run  = PARSER_FUNC_NAME( name ),       \
    }


//// Define a parser generator `Parser<T> name( char x )`
#define DEF_GEN_PARSER__CHAR( name )                    \
    Parser name( char x )                               \
    {                                                   \
        Parser p = Parser_new();                        \
        if ( p ) {                                      \
            *p = CHAR_ST( name, x );                    \
            p->ref_cnt = 0;                             \
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

#endif  /* CPARSEC_CORE_GEN_PARSER_CHAR_H */
