/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include "cparsec/primitive/number.h"

#define UNUSED_VARIABLE(x)    (void)(x)

static ParserSt number_ = PARSER_0_ST_INIT( number );
const Parser number = &number_;

DEF_PARSER_0( number )
{
    UNUSED_VARIABLE( self );
    Val x = RUN_PARSER( many1( digit ) );
    if ( x.type == ERROR ) return x;
    Val ret = INT_VAL( atoi( x.str ) );
    Val_del( &x );
    return ret;
}
