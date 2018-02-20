/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include "cparsec/primitive/optional.h"

// \todo error message should be "expected <X> but was <y>"
DEF_PARSER__UNARY_OP( optional )
{
    Val ret = RUN_PARSER( tryp( self->arg1.parser ) );
    if ( ret.type != ERROR ) {
        return ret;
    }
    Val_del( &ret );
    return VAL(STRING)("");
}
