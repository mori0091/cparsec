/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include "cparsec/primitive/char1.h"

// \todo error message should be "expected <X> but was <y>"
DEF_PARSER__CHAR( char1 )
{
    char expect = self->arg1.c;
    Val ret = Source_peek( psrc );
    if ( ret.type == ERROR     ) return ret;
    if ( expect != ret.c ) return Source_error( psrc, "not satisfy" );
    return Source_next( psrc );
}
