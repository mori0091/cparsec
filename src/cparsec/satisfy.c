/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include "cparsec/satisfy.h"

DEF_GEN_PARSER__PREDICATE( satisfy )
{
  Predicate pred = self->arg1.value.predicate;
  Val ret = Source_peek( psrc );
  if ( ret.type == ERROR    ) return ret;
  if ( !pred( ret.value.c ) ) return Source_error( psrc, "not satisfy" );
  return Source_next( psrc );
}
