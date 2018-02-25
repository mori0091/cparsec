/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include "cparsec/core/parser.h"

static Val string1_run( Val str_, Val psrc_ );

Parser string1( const char* str )
{
    Parser p = Parser_new();
    if ( p ) {
        p->ref_cnt = 0;
        Val str_ = VAL(STRING)(str);
        Fn1 run = Fn_apply( string1_run, str_ );
        p->run = run;
    }
    return p;
}

static Val string1_run( Val str_, Val psrc_ )
{
    Source* psrc = (Source*)psrc_.ptr;
    const char* expect = str_.str;
    const char* p = expect;
    while ( *p ) {
        Val ret = Parser_eval( char1(*p), psrc );
        if ( ret.type == ERROR ) return ret;
        p++;
    }
    return VAL(STRING)( expect );
}
