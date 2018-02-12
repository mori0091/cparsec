/* -*- mode: c++ ; coding: utf-8-unix -*- */

#pragma once

#ifndef CPARSEC_CORE_GEN_PARSER_PREDICATE_H
#define CPARSEC_CORE_GEN_PARSER_PREDICATE_H

#include "cparsec.h"
#include "cparsec/core/parser.h"

//// Constructs ParserSt< T (Predicate) >
#define PREDICATE( name, x )            &(PREDICATE_ST( name, x ))
#define PREDICATE_ST( name, x )         (ParserSt)PREDICATE_ST_INIT( name, x )
#define PREDICATE_ST_INIT( name, x )            \
    {                                           \
        .ref_cnt = -1,                          \
        .arg1 = PREDICATE_VAL_INIT( x ),        \
        .arg2 = NONE_VAL_INIT,                  \
        .run  = PARSER_FUNC_NAME( name ),       \
    }


//// Define a parser generator `Parser<T> name( Predicate x )`
#define DEF_PARSER__PREDICATE( name )                   \
    Parser name( Predicate x )                          \
    {                                                   \
        Parser p = Parser_new();                        \
        if ( p ) {                                      \
            *p = PREDICATE_ST( name, x );               \
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

#endif  /* CPARSEC_CORE_GEN_PARSER_PREDICATE_H */
