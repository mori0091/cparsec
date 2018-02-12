/* -*- mode: c++ ; coding: utf-8-unix -*- */

#pragma once

#ifndef CPARSEC_CORE_GEN_PARSER_PARSER_0_H
#define CPARSEC_CORE_GEN_PARSER_PARSER_0_H

#include "cparsec.h"
#include "cparsec/core/parser.h"

//// Constructs ParserSt< T ( void ) >
#define PARSER_0( name )               &(PARSER_0_ST( name ))
#define PARSER_0_ST( name )            (ParserSt)PARSER_0_ST_INIT( name )
#define PARSER_0_ST_INIT( name )                \
    {                                           \
        .ref_cnt = -1,                          \
        .arg1 = NONE_VAL_INIT,                  \
        .arg2 = NONE_VAL_INIT,                  \
        .run  = PARSER_FUNC_NAME( name ),       \
    }

//// Define a parser `Parser<T> name`
#define DEF_PARSER_0( name )                    \
    DECL_PARSER_FUNC( name )

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif  /* CPARSEC_CORE_GEN_PARSER_PARSER_0_H */
