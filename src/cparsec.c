/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include <stdio.h>

#include "cparsec.h"
#include "cparsec/parser.h"
#include "cparsec/source.h"

void Val_del( Val* x )
{
  if ( x ) {
    if ( x->del ) {
      x->del( x->value.ptr );
      x->value.ptr = 0;
    }
  }
}

void Val_print( Val* x )
{
  assert( x );
  switch ( x->type ) {
  case ERROR:
    printf( "parse error: %s\n", x->value.error );
    break;
  case CHAR:
    printf( "%c\n", x->value.c );
    break;
  case INT:
    printf( "%d\n", x->value.i );
    break;
  case DOUBLE:
    printf( "%f\n", x->value.d );
    break;
  case PTR:
    printf( "%p\n", x->value.ptr );
    break;
  case STRING:
    printf( "%s\n", x->value.str );
    break;
  case PARSER:
    printf( "Parser(%p)\n", x->value.ptr );
    break;
  case PREDICATE:
    printf( "Predicate(%p)\n", x->value.ptr );
    break;
  default:
    printf( "Unknown value\n" );
    break;
  }
}

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
