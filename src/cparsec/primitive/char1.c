/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include "cparsec/core/parser.h"

static Val char1_run( Val c_, Val psrc_ );

Parser char1( char c )
{
    Parser p = Parser_new();
    if ( p ) {
        p->ref_cnt = 0;
        Val c_ = VAL(CHAR)(c);
        Fn1 run = Fn_apply( char1_run, c_ );
        p->run = run;
    }
    return p;
}

static Val char1_run( Val c_, Val psrc_ )
{
    Source* psrc = (Source*)psrc_.ptr;
    char expect = c_.c;
    Val ret = Source_peek( psrc );
    if ( ret.type == ERROR ) return ret;
    if ( expect != ret.c ) return Source_error( psrc, "not satisfy" );
    return Source_next( psrc );
}
