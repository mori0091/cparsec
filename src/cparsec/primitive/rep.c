/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include "cparsec/core/parser.h"

static Val rep_run( Val n_, Val x_, Val psrc_ );

Parser rep( int n, Parser x )
{
    Parser p = Parser_new();
    if ( p ) {
        p->ref_cnt = 0;
        Val n_ = VAL(INT)(n);
        Val x_ = VAL(D_PARSER)(x);
        Fn1 run = Fn_apply( rep_run, n_, x_ );
        Parser_ref( x );
        p->run = run;
    }
    return p;
}

static Val rep_run( Val n_, Val x_, Val psrc_ )
{
    Source* psrc = (Source*)psrc_.ptr;
    Val ret = VAL(STRING)( "" );
    const int n = n_.i;
    for ( int i = 0; i < n; ++i ) {
        Val x = Parser_eval( x_.parser, psrc );
        if ( x.type == ERROR ) {
            Val_del( &ret );
            return x;
        }
        ret = Val_concat( &ret, &x );
    }
    return ret;
}
