/* -*- mode: c++ ; coding: utf-8-unix -*- */

#pragma once

#ifndef CPARSEC_PRIMITIVE_MANY_H
#define CPARSEC_PRIMITIVE_MANY_H

#include "cparsec/gen_parser/unary_op.h"

#define MANY( x )            UNARY_OP( many, (x) )
#define MANY_ST( x )         UNARY_OP_ST( many, (x) )
#define MANY_ST_INIT( x )    UNARY_OP_ST_INIT( many, (x) )

#ifdef __cplusplus
extern "C" {
#endif

  extern DECL_PARSER_FUNC( many );

#ifdef __cplusplus
}
#endif

#endif	/* CPARSEC_PRIMITIVE_MANY_H */
