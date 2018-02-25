/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include "cparsec/core/parser.h"

static Val apply_run( Val f_, Val parser_, Val psrc_ );

Parser apply( Fn1 f, Parser parser )
{
    Parser p = Parser_new();
    if ( p ) {
        p->ref_cnt = 0;
        Val f_ = VAL(D_FN)(f.f);
        Val parser_ = VAL(D_PARSER)(parser);
        Fn1 run = Fn_apply( apply_run, f_, parser_ );
        Fn_ref( f.f );
        Parser_ref( parser );
        p->run = run;
    }
    return p;
}

static Val apply_run( Val f_, Val parser_, Val psrc_ )
{
    Source* psrc = (Source*)psrc_.ptr;
    Fn1 f = (Fn1){ f_.fn };
    Parser parser = parser_.parser;
    Val x = Parser_eval( parser, psrc );
    if ( x.type == ERROR ) return x;
    return Fn_apply( f, x );
}
