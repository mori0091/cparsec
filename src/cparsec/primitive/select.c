/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include "cparsec/primitive/select.h"

DEF_PARSER__BINARY_OP( first )
{
    Val x = RUN_PARSER( self->arg1.parser );
    if ( x.type == ERROR ) return x;
    Val y = RUN_PARSER( self->arg2.parser );
    if ( y.type == ERROR ) {
        Val_del( &x );
        return y;
    }
    Val_del( &y );
    return x;
}

DEF_PARSER__BINARY_OP( second )
{
    Val x = RUN_PARSER( self->arg1.parser );
    if ( x.type == ERROR ) return x;
    Val_del( &x );
    return RUN_PARSER( self->arg2.parser );
}
