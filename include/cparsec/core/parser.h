/* -*- mode: c++ ; coding: utf-8-unix -*- */

#pragma once

#ifndef CPARSEC_CORE_PARSER_H
#define CPARSEC_CORE_PARSER_H

#include "cparsec.h"
#include "cparsec/core/source.h"
#include "cparsec/core/curry.h"

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct ParserSt ParserSt;

    struct ParserSt {
        int ref_cnt;
        Fn1 run;
    };

    // int Parser_live_count( void );
    Parser Parser_new( void );
    void Parser_del( Parser p );
    // Parser Parser_ref( Parser p );
    // void Parser_unref( Parser p );
    Val Parser_eval( const Parser p, Source* psrc );

#ifdef __cplusplus
}
#endif

#endif  /* CPARSEC_CORE_PARSER_H */
