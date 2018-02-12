/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include "cparsec/primitive/either.h"

// \todo error message should be "expected <X> but was <y>"
DEF_PARSER__BINARY_OP( either )
{
    Source bak = *psrc;
    Val x = RUN_PARSER( self->arg1.parser );
    if ( x.type != ERROR ) return x;
    if ( !Source_eq( &bak, psrc ) ) return x;
    Val_del( &x );
    return RUN_PARSER( self->arg2.parser );
}
