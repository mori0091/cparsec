/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include "cparsec/core/parser.h"

static Val either_run( Val x_, Val y_, Val psrc_ );

Parser either( Parser x, Parser y )
{
    Parser p = Parser_new();
    if ( p ) {
        p->ref_cnt = 0;
        Val x_ = VAL(D_PARSER)(x);
        Val y_ = VAL(D_PARSER)(y);
        Fn1 run = Fn_apply( either_run, x_, y_ );
        Parser_ref( x );
        Parser_ref( y );
        p->run = run;
    }
    return p;
}

static Val either_run( Val x_, Val y_, Val psrc_ )
{
    Source* psrc = (Source*)psrc_.ptr;
    Source bak = *psrc;
    Val x = Parser_eval( x_.parser, psrc );
    if ( x.type != ERROR ) return x;
    if ( !Source_eq( &bak, psrc ) ) return x;
    Val_del( &x );
    return Parser_eval( y_.parser, psrc );
}
