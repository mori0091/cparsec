/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include "cparsec/string1.h"
#include "cparsec/char1.h"

// \todo error message should be "expected <X> but was <y>"
DEF_GEN_PARSER__STRING( string1 )
{
  const char* expect = self->arg1.value.str;
  const char* p = expect;
  while ( *p ) {
    Val ret = RUN_PARSER( CHAR1( *p ) );
    if ( ret.type == ERROR ) return ret;
    p++;
  }
  return STRING_VAL( expect );
}
