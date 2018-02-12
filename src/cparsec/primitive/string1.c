/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include "cparsec/primitive/string1.h"
#include "cparsec/primitive/char1.h"

// \todo error message should be "expected <X> but was <y>"
DEF_GEN_PARSER__STRING( string1 )
{
    const char* expect = self->arg1.str;
    const char* p = expect;
    while ( *p ) {
        Val ret = RUN_PARSER( char1(*p) );
        if ( ret.type == ERROR ) return ret;
        p++;
    }
    return STRING_VAL( expect );
}
