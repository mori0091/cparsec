/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include "cparsec/core/parser.h"

static Val number_run( Val psrc_ )
{
    Source* psrc = (Source*)psrc_.ptr;
    Val x = Parser_eval( many1( digit ), psrc );
    if ( x.type == ERROR ) return x;
    Val ret = VAL(INT)( atoi( x.str ) );
    Val_del( &x );
    return ret;
}

static Val number_fp0( int n, const Val* x[] )
{
    assert( n == 1 );
    return number_run( *x[0] );
}

static FnSt number_fn0 = {
    .ref_cnt = -1,
    .depth   = 0,
    .funcptr = number_fp0,
};

static ParserSt number_ = {
    .ref_cnt = -1,
    .run     = { &number_fn0 },
};

const Parser number = &number_;
