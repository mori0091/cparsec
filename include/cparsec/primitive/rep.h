/* -*- mode: c++ ; coding: utf-8-unix -*- */

#pragma once

#ifndef CPARSEC_PRIMITIVE_REP_H
#define CPARSEC_PRIMITIVE_REP_H

#include "cparsec/gen_parser/int_parser.h"

#define REP( n, x )            INT_PARSER( rep, (n), (x) )
#define REP_ST( n, x )         INT_PARSER_ST( rep, (n), (x) )
#define REP_ST_INIT( n, x )    INT_PARSER_ST_INIT( rep, (n), (x) )

#ifdef __cplusplus
extern "C" {
#endif

    extern DECL_PARSER_FUNC( rep );

#ifdef __cplusplus
}
#endif

#endif  /* CPARSEC_PRIMITIVE_REP_H */
