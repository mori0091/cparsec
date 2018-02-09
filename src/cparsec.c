/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include <stdio.h>

#include "cparsec.h"
#include "cparsec/core/val.h"
#include "cparsec/core/parser.h"

Val parse( const Parser x, const char* str )
{
  if ( ! x   ) { return ERROR_VAL( "null parser" ); }
  if ( ! str ) { return ERROR_VAL( "null text" ); }
  Source s = Source_init( str );
  return x->run( x, &s );
}

void parse_test( const Parser x, const char* str )
{
  Val result = parse( x, str );
  Val_print( &result );
  Val_del( &result);
}
