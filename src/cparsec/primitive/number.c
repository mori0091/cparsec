/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include "cparsec/primitive/number.h"
#include "cparsec/primitive/many.h"
#include "cparsec/primitive/seq.h"

#define UNUSED_VARIABLE(x)    (void)(x)

static ParserSt number_ = PARSER_0_ST_INIT( number );
const Parser number = &number_;

DEF_PARSER_0( number )
{
    UNUSED_VARIABLE( self );
    Parser p = BINARY_OP( seq, digit, UNARY_OP( many, digit ) );
    Val x = RUN_PARSER( p );
    if ( x.type == ERROR ) return x;
    Val ret = INT_VAL( atoi( x.str ) );
    Val_del( &x );
    return ret;
}
