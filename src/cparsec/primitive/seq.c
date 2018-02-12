/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include "cparsec/primitive/seq.h"

// \todo error message should be "expected <X> but was <y>"
DEF_PARSER__BINARY_OP( seq )
{
    Val x = RUN_PARSER( self->arg1.parser );
    if ( x.type == ERROR ) return x;
    Val y = RUN_PARSER( self->arg2.parser );
    if ( y.type == ERROR ) { Val_del( &x ); return y; }
    return Val_concat( &x, &y );
}
