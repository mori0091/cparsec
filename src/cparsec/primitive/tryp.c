/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include "cparsec/core/parser.h"

static Val tryp_run( Val x_, Val psrc_ );

Parser tryp( Parser x )
{
    Parser p = Parser_new();
    if ( p ) {
        p->ref_cnt = 0;
        Val x_ = VAL(D_PARSER)(x);
        Fn1 run = Fn_apply( tryp_run, x_ );
        Parser_ref( x );
        p->run = run;
    }
    return p;
}

static Val tryp_run( Val x_, Val psrc_ )
{
    Source* psrc = (Source*)psrc_.ptr;
    Source bak = *psrc;
    Val ret = Parser_eval( x_.parser, psrc );
    if ( ret.type == ERROR ) {
        *psrc = bak;
    }
    return ret;
}
