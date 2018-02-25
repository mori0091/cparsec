/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include "cparsec/core/parser.h"
#include "cparsec/core/val.h"

static int Parser__live_count = 0;

int Parser_live_count( void )
{
    return Parser__live_count;
}

Parser Parser_new( void )
{
    Parser p = malloc( sizeof( ParserSt ) );
    if ( p ) {
        ++Parser__live_count;
        *p = ( ParserSt ){
            .ref_cnt = 0,
            .run = (Fn1){ NULL },
        };
    }
    return p;
}

void Parser_del( Parser p )
{
    assert( p );
    free( p );
    --Parser__live_count;
}

Parser Parser_ref( Parser p )
{
    assert( p );
    if ( 0 <= p->ref_cnt ) {
        ++( p->ref_cnt );
        Fn_ref( p->run.f );
    }
    return p;
}

void Parser_unref( Parser p )
{
    assert( p );
    if ( 0 < p->ref_cnt ) {
        Fn_unref( p->run.f );
        if ( 0 == --( p->ref_cnt ) ) {
            Parser_del( p );
        }
    }
}

Val Parser_eval( const Parser p, Source* psrc )
{
    assert( p );
    assert( psrc );
    Parser_ref( p );
    Val ret = Fn_apply( p->run, val((void*)psrc) );
    Parser_unref( p );
    return ret;
}
