/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include "cparsec/core/parser.h"

static Val seq_run( Val x_, Val y_, Val psrc_ );

Parser seq( Parser x, Parser y )
{
    Parser p = Parser_new();
    if ( p ) {
        p->ref_cnt = 0;
        Val x_ = VAL(D_PARSER)(x);
        Val y_ = VAL(D_PARSER)(y);
        Fn1 run = Fn_apply( seq_run, x_, y_ );
        Parser_ref( x );
        Parser_ref( y );
        p->run = run;
    }
    return p;
}

static Val seq_run( Val x_, Val y_, Val psrc_ )
{
    Source* psrc = (Source*)psrc_.ptr;
    Val x = Parser_eval( x_.parser, psrc );
    if ( x.type == ERROR ) return x;
    Val y = Parser_eval( y_.parser, psrc );
    if ( y.type == ERROR ) { Val_del( &x ); return y; }
    return Val_concat( &x, &y );
}
