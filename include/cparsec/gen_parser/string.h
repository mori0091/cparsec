/* -*- mode: c++ ; coding: utf-8-unix -*- */

#pragma once

#ifndef CPARSEC_CORE_GEN_PARSER_STRING_H
#define CPARSEC_CORE_GEN_PARSER_STRING_H

#include "cparsec.h"
#include "cparsec/core/parser.h"

//// Constructs ParserSt< T (const char*) >
#define STRING( name, x )            &(STRING_ST( name, x ))
#define STRING_ST( name, x )         (ParserSt)STRING_ST_INIT( name, x )
#define STRING_ST_INIT( name, x )               \
    {                                           \
        .ref_cnt = -1,                          \
        .arg1 = VAL_INIT(STRING)( x ),          \
        .arg2 = VAL_INIT(NONE),                 \
        .run  = PARSER_FUNC_NAME( name ),       \
    }


//// Define a parser generator `Parser<T> name( const char* x )`
#define DEF_PARSER__STRING( name )                      \
    Parser name( const char* x )                        \
    {                                                   \
        Parser p = Parser_new();                        \
        if ( p ) {                                      \
            *p = STRING_ST( name, x );                  \
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

#endif  /* CPARSEC_CORE_GEN_PARSER_STRING_H */
