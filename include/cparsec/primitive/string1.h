/* -*- mode: c++ ; coding: utf-8-unix -*- */

#pragma once

#ifndef CPARSEC_PRIMITIVE_STRING1_H
#define CPARSEC_PRIMITIVE_STRING1_H

#include "cparsec/gen_parser/string.h"

#define STRING1( x )            STRING( string1, (x) )
#define STRING1_ST( x )         STRING_ST( string1, (x) )
#define STRING1_ST_INIT( x )    STRING_ST_INIT( string1, (x) )

#ifdef __cplusplus
extern "C" {
#endif

  extern DECL_PARSER_FUNC( string1 );
  
#ifdef __cplusplus
}
#endif

#endif	/* CPARSEC_PRIMITIVE_STRING1_H */
