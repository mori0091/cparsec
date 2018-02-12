/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include "cparsec/primitive/tryp.h"

// \todo error message should be "expected <X> but was <y>"
DEF_PARSER__UNARY_OP( tryp )
{
    Source bak = *psrc;
    Val ret = RUN_PARSER( self->arg1.parser );
    if ( ret.type == ERROR ) {
        *psrc = bak;
    }
    return ret;
}
