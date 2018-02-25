/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include "cparsec/core/parser.h"

Val satisfy_run( Val pred_, Val psrc_ );

Parser satisfy( Predicate x )
{
    Parser p = Parser_new();
    if ( p ) {
        p->ref_cnt = 0;
        Val pred_ = VAL(PREDICATE)(x);
        Fn1 run = Fn_apply( satisfy_run, pred_ );
        p->run = run;
    }
    return p;
}

Val satisfy_run( Val pred_, Val psrc_ )
{
    Predicate pred = pred_.predicate;
    Source* psrc = (Source*)psrc_.ptr;
    Val ret = Source_peek( psrc );
    if ( ret.type == ERROR ) return ret;
    if ( !pred( ret.c ) ) return Source_error( psrc, "not satisfy" );
    return Source_next( psrc );
}
