/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include "cparsec/core/parser.h"
#include <string.h>

static Val one_of_run( Val str_, Val psrc_ );

Parser one_of( const char* str )
{
    Parser p = Parser_new();
    if ( p ) {
        p->ref_cnt = 0;
        Val str_ = VAL(D_STRING)(strdup(str));
        Fn1 run = Fn_apply( one_of_run, str_ );
        p->run = run;
    }
    return p;
}

static Val one_of_run( Val str_, Val psrc_ )
{
    Source* psrc = (Source*)psrc_.ptr;
    const char* p = str_.str;
    while ( *p ) {
        Val ret = Parser_eval( char1(*p), psrc );
        if ( ret.type != ERROR ) return ret;
        p++;
    }
    return Source_error( psrc, "not satisfy" );
}
