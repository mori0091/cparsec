/* -*- mode: c++ ; coding: utf-8-unix -*- */

#pragma once

#ifndef CPARSEC_PRIMITIVE_CHAR1_H
#define CPARSEC_PRIMITIVE_CHAR1_H

#include "cparsec/gen_parser/char.h"

#define CHAR1( x )            CHAR( char1, (x) )
#define CHAR1_ST( x )         CHAR_ST( char1, (x) )
#define CHAR1_ST_INIT( x )    CHAR_ST_INIT( char1, (x) )

#ifdef __cplusplus
extern "C" {
#endif

    extern DECL_PARSER_FUNC( char1 );

#ifdef __cplusplus
}
#endif

#endif  /* CPARSEC_PRIMITIVE_CHAR1_H */
