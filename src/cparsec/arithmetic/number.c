/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include "cparsec/arithmetic/number.h"

#define UNUSED_VARIABLE(x)    (void)(x)

static ParserSt number_ = NO_ARGS_ST_INIT( number );
const Parser number = &number_;

DEF_PARSER__NO_ARGS( number )
{
    UNUSED_VARIABLE( self );
    Val x = RUN_PARSER( many1( digit ) );
    if ( x.type == ERROR ) return x;
    Val ret = INT_VAL( atoi( x.str ) );
    Val_del( &x );
    return ret;
}
