/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include "cparsec/primitive/one_of.h"

// \todo error message should be "expected <X> but was <y>"
DEF_PARSER__STRING( one_of )
{
    const char* p = self->arg1.str;
    while ( *p ) {
        Val ret = RUN_PARSER( char1(*p) );
        if ( ret.type != ERROR ) return ret;
        p++;
    }
    return Source_error( psrc, "not satisfy" );
}
