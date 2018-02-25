/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include "cparsec/primitive/apply.h"

// \todo error message should be "expected <X> but was <y>"
DEF_PARSER__FILTER_PARSER( apply )
{
    Val x = RUN_PARSER( self->arg2.parser );
    if ( x.type == ERROR ) return x;
    return Fn_apply( (Fn1){self->arg1.fn}, x );
}
