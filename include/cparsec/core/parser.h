/* -*- mode: c++ ; coding: utf-8-unix -*- */

#pragma once

#ifndef CPARSEC_CORE_PARSER_H
#define CPARSEC_CORE_PARSER_H

#include "cparsec.h"
#include "cparsec/core/source.h"

#define PARSER_FUNC_NAME( name )    PARSER_FUNC_NAME_I( name )
#define PARSER_FUNC_NAME_I( name )  name ## _run
#define DECL_PARSER_FUNC( name )    Val PARSER_FUNC_NAME(name)( const Parser self, Source* psrc )
#define RUN_PARSER( p )             (p)->run( (p), psrc )

#ifdef __cplusplus
extern "C" {
#endif

  typedef Val (*ParserFunc)( const Parser, Source* );

  typedef struct ParserSt ParserSt;

  struct ParserSt {
    int ref_cnt;
    Val arg1;
    Val arg2;
    ParserFunc run;
  };

  Parser Parser_new( void );
  void Parser_ref( Parser p );
  int Parser_unref( Parser p );
  // void Parser_del( Parser p );

#ifdef __cplusplus
}
#endif

#endif	/* CPARSEC_CORE_PARSER_H */
