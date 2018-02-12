/* -*- mode: c++ ; coding: utf-8-unix -*- */

#pragma once

#ifndef CPARSEC_PRIMITIVE_SEQ_H
#define CPARSEC_PRIMITIVE_SEQ_H

#include "cparsec/gen_parser/binary_op.h"

#define SEQ( x, y )            BINARY_OP( seq, (x), (y) )
#define SEQ_ST( x, y )         BINARY_OP_ST( seq, (x), (y) )
#define SEQ_ST_INIT( x, y )    BINARY_OP_ST_INIT( seq, (x), (y) )

#ifdef __cplusplus
extern "C" {
#endif

    extern DECL_PARSER_FUNC( seq );

#ifdef __cplusplus
}
#endif

#endif  /* CPARSEC_PRIMITIVE_SEQ_H */
