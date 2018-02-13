/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include <stdio.h>

#include "cparsec.h"
#include "cparsec/core/val.h"
#include "cparsec/core/parser.h"

Val parse( const Parser x, const char* str )
{
    if ( ! x ) { return VAL(ERROR)( "null parser" ); }
    Parser_ref( x );
    Val ret = VAL(ERROR)( "null text" );
    if ( str ) {
        Source s = Source_init( str );
        ret = x->run( x, &s );
    }
    Parser_unref( x );
    return ret;
}

void parse_test( const Parser x, const char* str )
{
    Val result = parse( x, str );
    Val_print( &result );
    Val_del( &result);
}
