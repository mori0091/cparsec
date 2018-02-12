/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include "cparsec/core/parser.h"
#include "cparsec/core/val.h"

Parser Parser_new( void )
{
    Parser p = malloc( sizeof( ParserSt ) );
    if ( p ) {
        *p = ( ParserSt ){
            .ref_cnt = 0,
            .arg1 = NONE_VAL_INIT,
            .arg2 = NONE_VAL_INIT,
            .run  = NULL,
        };
    }
    return p;
}

void Parser_ref( Parser p )
{
    assert( p );
    ++( p->ref_cnt );
}

int Parser_unref( Parser p )
{
    assert( p );
    if ( p->ref_cnt <= 0 ) {
        return -1;
    }
    return --( p->ref_cnt );
}

void Parser_del( Parser p )
{
    assert( p );
    if ( ! Parser_unref( p ) ) {
        Val_del( &( p->arg1 ) );
        Val_del( &( p->arg2 ) );
        free( p );
    }
}

