/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include "cparsec/core/function.h"

#include <assert.h>
#include <stdarg.h>

static int Fn__live_count = 0;

int Fn_live_count( void )
{
    return Fn__live_count;
}

/** \brief Allocates memory for a function object type of Fn. */
static Fn Fn_new( void )
{
    Fn ret = malloc( sizeof( struct FnSt ) );
    if ( ret ) {
        ++Fn__live_count;
        *ret = (struct FnSt){0};
    }
    return ret;
}

/** \brief Deallocates memory for a function object type of Fn. */
static void Fn_del( Fn f )
{
    assert( f );
    free( f );
    --Fn__live_count;
}

Fn Fn_ref( Fn f )
{
    assert( f );
    if ( 0 <= f->ref_cnt ) {
        ++( f->ref_cnt );
    }
    return f;
}

void Fn_unref( Fn f )
{
    assert( f );
    if ( 0 < f->ref_cnt ) {
        if ( 0 == --( f->ref_cnt ) ) {
            if ( 0 < f->depth ) {
                Val_del( &( f->fx.x ) );
                Fn_unref( f->fx.f );
            }
            Fn_del( f );
        }
    }
}

Fn fn( FnFunc funcptr )
{
    assert( funcptr );
    Fn f = Fn_new();
    if ( f ) {
        f->ref_cnt = 0;
        f->depth   = 0;
        f->funcptr = funcptr;
    }
    return f;
}

Fn Fn_bind1_v( Fn f, Val x )
{
    assert( f );
    assert( x.type != NONE );
    Fn g = Fn_new();
    if ( g ) {
        g->ref_cnt = 0;
        g->depth   = f->depth + 1;
        g->fx.f    = f;
        g->fx.x    = x;
        Fn_ref( f );
    }
    return g;
}

Val Fn_eval( Fn f )
{
    int n = f->depth;
    const Val* args[n+1];
    args[n] = &VAL(NONE);
    Fn g = f;
    for ( int i = n-1; 0 <= i; --i ) {
        args[i] = &(g->fx.x);
        g = g->fx.f;
    }
    Fn_ref( f );
    Val ret = g->funcptr( n, args );
    Fn_unref( f );
    return ret;
}
