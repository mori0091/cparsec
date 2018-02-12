/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include "cparsec/primitive/rep.h"

// \todo error message should be "expected <X> but was <y>"
DEF_PARSER__INT_PARSER( rep )
{
    Val ret = STRING_VAL( "" );
    const int n = self->arg1.i;
    for ( int i = 0; i < n; ++i ) {
        Val x = RUN_PARSER( self->arg2.parser );
        if ( x.type == ERROR ) {
            Val_del( &ret );
            return x;
        }
        ret = Val_concat( &ret, &x );
    }
    return ret;
}
