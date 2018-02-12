/* -*- mode: c++ ; coding: utf-8-unix -*- */

#pragma once

#ifndef CPARSEC_PRIMITIVE_TRYP_H
#define CPARSEC_PRIMITIVE_TRYP_H

#include "cparsec/gen_parser/unary_op.h"

#define TRYP( x )            UNARY_OP( tryp, (x) )
#define TRYP_ST( x )         UNARY_OP_ST( tryp, (x) )
#define TRYP_ST_INIT( x )    UNARY_OP_ST_INIT( tryp, (x) )

#ifdef __cplusplus
extern "C" {
#endif

  extern DECL_PARSER_FUNC( tryp );

#ifdef __cplusplus
}
#endif

#endif	/* CPARSEC_PRIMITIVE_TRYP_H */
