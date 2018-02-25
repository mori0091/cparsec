/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include "cparsec/core/parser.h"

static Val optional_run( Val x_, Val psrc_ );

Parser optional( Parser x )
{
    Parser p = Parser_new();
    if ( p ) {
        p->ref_cnt = 0;
        Val x_ = VAL(D_PARSER)(x);
        Fn1 run = Fn_apply( optional_run, x_ );
        Parser_ref( x );
        p->run = run;
    }
    return p;
}

static Val optional_run( Val x_, Val psrc_ )
{
    Source* psrc = (Source*)psrc_.ptr;
    Val ret = Parser_eval( tryp( x_.parser ), psrc );
    if ( ret.type != ERROR ) {
        return ret;
    }
    Val_del( &ret );
    return VAL(STRING)("");
}
