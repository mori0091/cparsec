/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include "cparsec/core/parser.h"

static Val many_run( Val x_, Val psrc_ );

Parser many( Parser x )
{
    Parser p = Parser_new();
    if ( p ) {
        p->ref_cnt = 0;
        Val x_ = VAL(D_PARSER)(x);
        Fn1 run = Fn_apply( many_run, x_ );
        Parser_ref( x );
        p->run = run;
    }
    return p;
}

static Val many_run( Val x_, Val psrc_ )
{
    Source* psrc = (Source*)psrc_.ptr;
    Val ret = VAL(STRING)( "" );
    for (;;) {
        Val x = Parser_eval( x_.parser, psrc );
        if ( x.type == ERROR ) {
            Val_del( &x );
            break;
        }
        ret = Val_concat( &ret, &x );
    }
    return ret;
}
