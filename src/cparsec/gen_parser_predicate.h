/* -*- mode: c++ ; coding: utf-8-unix -*- */

#pragma once

#ifndef CPARSEC_GEN_PARSER_PREDICATE_H
#define CPARSEC_GEN_PARSER_PREDICATE_H

#include "cparsec.h"
#include "cparsec/parser.h"

//// Constructs ParserSt< T (Predicate) >
#define PREDICATE( name, x )            &(PREDICATE_ST( name, (x) ))
#define PREDICATE_ST( name, x )         (ParserSt)PREDICATE_ST_INIT( name, (x) )
#define PREDICATE_ST_INIT( name, x )    \
  {					\
    .ref_cnt = 0,			\
    .arg1 = PREDICATE_VAL_INIT( (x) ),	\
    .arg2 = NONE_VAL_INIT,		\
    .run  = PARSER_FUNC_NAME( name ),	\
  }


//// Define a parser generator `Parser<T> name( Predicate x )`
#define DEF_GEN_PARSER__PREDICATE( name )		\
  Parser name( Predicate x )				\
  {							\
    Parser p = Parser_new();				\
    if ( p ) { *p = PREDICATE_ST( name, x ); }		\
    return p;						\
  }							\
  DECL_PARSER_FUNC( name )

#ifdef __cplusplus
extern "C" {
#endif
  
#ifdef __cplusplus
}
#endif

#endif	/* CPARSEC_GEN_PARSER_PREDICATE_H */
