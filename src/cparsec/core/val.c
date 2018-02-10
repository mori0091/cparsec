/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include <stdio.h>

#include "cparsec.h"
#include "cparsec/core/val.h"

void Val_del( Val* x )
{
  if ( x ) {
    if ( x->del ) {
      x->del( x->ptr );
      x->ptr = 0;
    }
  }
}

void Val_print( Val* x )
{
  assert( x );
  switch ( x->type ) {
  case ERROR:
    printf( "parse error: %s\n", x->error );
    break;
  case CHAR:
    printf( "%c\n", x->c );
    break;
  case INT:
    printf( "%d\n", x->i );
    break;
  case DOUBLE:
    printf( "%f\n", x->d );
    break;
  case PTR:
    printf( "%p\n", x->ptr );
    break;
  case STRING:
    printf( "%s\n", x->str );
    break;
  case PARSER:
    printf( "Parser(%p)\n", x->ptr );
    break;
  case PREDICATE:
    printf( "Predicate(%p)\n", x->ptr );
    break;
  default:
    printf( "Unknown value\n" );
    break;
  }
}
