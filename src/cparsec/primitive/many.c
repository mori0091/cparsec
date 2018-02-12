/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include "cparsec/primitive/many.h"

// \todo error message should be "expected <X> but was <y>"
DEF_GEN_PARSER__UNARY_OP( many )
{
  Val ret = STRING_VAL( "" );
  for (;;) {
    Val x = RUN_PARSER( self->arg1.parser );
    if ( x.type == ERROR ) {
      Val_del( &x );
      break;
    }
    ret = Val_concat( &ret, &x );
  }
  return ret;
}
