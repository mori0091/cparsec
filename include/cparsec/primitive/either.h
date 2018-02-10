/* -*- mode: c++ ; coding: utf-8-unix -*- */

#pragma once

#ifndef CPARSEC_PRIMITIVE_EITHER_H
#define CPARSEC_PRIMITIVE_EITHER_H

#include "cparsec/gen_parser/binary_op.h"

#define EITHER( x, y )            BINARY_OP( either, (x), (y) )
#define EITHER_ST( x, y )         BINARY_OP_ST( either, (x), (y) )
#define EITHER_ST_INIT( x, y )    BINARY_OP_ST_INIT( either, (x), (y) )

#ifdef __cplusplus
extern "C" {
#endif

  extern DECL_PARSER_FUNC( either );

#ifdef __cplusplus
}
#endif

#endif	/* CPARSEC_PRIMITIVE_EITHER_H */
