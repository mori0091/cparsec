/* -*- mode: c++ ; coding: utf-8-unix -*- */

#pragma once

#ifndef CPARSEC_CORE_GEN_PARSER_NO_ARGS_H
#define CPARSEC_CORE_GEN_PARSER_NO_ARGS_H

#include "cparsec.h"
#include "cparsec/core/parser.h"

//// Constructs ParserSt< T ( void ) >
#define NO_ARGS( name )               &(NO_ARGS_ST( name ))
#define NO_ARGS_ST( name )            (ParserSt)NO_ARGS_ST_INIT( name )
#define NO_ARGS_ST_INIT( name )                 \
    {                                           \
        .ref_cnt = -1,                          \
        .arg1 = VAL_INIT(NONE),                 \
        .arg2 = VAL_INIT(NONE),                 \
        .run  = PARSER_FUNC_NAME( name ),       \
    }

//// Define a parser `Parser<T> name`
#define DEF_PARSER__NO_ARGS( name )             \
    DECL_PARSER_FUNC( name )

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif  /* CPARSEC_CORE_GEN_PARSER_NO_ARGS_H */
