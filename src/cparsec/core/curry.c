/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include "cparsec/core/curry.h"

union Fp {
    Fp1 fp1;
    Fp2 fp2;
    Fp3 fp3;
    Fp4 fp4;
    Fp5 fp5;
    Fp6 fp6;
    Fp7 fp7;
    Fp8 fp8;
    Fp9 fp9;
};

static Val Fp_run( int n, const Val* x[] )
{
    assert( 2 <= n );
    union Fp* p = (union Fp*)(x[0]->ptr);
    switch (n-1) {
    case 1: return p->fp1(*x[1]); /* ? */
    case 2: return p->fp2(*x[1],*x[2]);
    case 3: return p->fp3(*x[1],*x[2],*x[3]);
    case 4: return p->fp4(*x[1],*x[2],*x[3],*x[4]);
    case 5: return p->fp5(*x[1],*x[2],*x[3],*x[4],*x[5]);
    case 6: return p->fp6(*x[1],*x[2],*x[3],*x[4],*x[5],*x[6]);
    case 7: return p->fp7(*x[1],*x[2],*x[3],*x[4],*x[5],*x[6],*x[7]);
    case 8: return p->fp8(*x[1],*x[2],*x[3],*x[4],*x[5],*x[6],*x[7],*x[8]);
    case 9: return p->fp9(*x[1],*x[2],*x[3],*x[4],*x[5],*x[6],*x[7],*x[8],*x[9]);
    default: return VAL(ERROR)("too much arguments");
    }
}

static Fn Fp_fn( union Fp g )
{
    union Fp* p = malloc( sizeof(union Fp) );
    assert( p );
    *p = g;
    return Fn_bind1_v( fn(Fp_run), VAL(D_PTR)(p) );
}

Fn1 fn1( Fp1 g ) { return (Fn1){ Fp_fn((union Fp){.fp1=g}) }; }
Fn2 fn2( Fp2 g ) { return (Fn2){ Fp_fn((union Fp){.fp2=g}) }; }
Fn3 fn3( Fp3 g ) { return (Fn3){ Fp_fn((union Fp){.fp3=g}) }; }
Fn4 fn4( Fp4 g ) { return (Fn4){ Fp_fn((union Fp){.fp4=g}) }; }
Fn5 fn5( Fp5 g ) { return (Fn5){ Fp_fn((union Fp){.fp5=g}) }; }
Fn6 fn6( Fp6 g ) { return (Fn6){ Fp_fn((union Fp){.fp6=g}) }; }
Fn7 fn7( Fp7 g ) { return (Fn7){ Fp_fn((union Fp){.fp7=g}) }; }
Fn8 fn8( Fp8 g ) { return (Fn8){ Fp_fn((union Fp){.fp8=g}) }; }
Fn9 fn9( Fp9 g ) { return (Fn9){ Fp_fn((union Fp){.fp9=g}) }; }

Val Fp1_apply( Fp1 g, Val x ) { return g(x); }
Val Fn1_apply( Fn1 g, Val x ) { return Fn_eval( Fn_bind1_v( g.f, x ) ); }

Fn1 Fp2_apply( Fp2 g, Val x ) { return Fn2_apply( fn2(g), x ); }
Fn1 Fn2_apply( Fn2 g, Val x ) { return (Fn1){ Fn_bind1_v( g.f, x ) }; }

Fn2 Fp3_apply( Fp3 g, Val x ) { return Fn3_apply( fn3(g), x ); }
Fn2 Fn3_apply( Fn3 g, Val x ) { return (Fn2){ Fn_bind1_v( g.f, x ) }; }

Fn3 Fp4_apply( Fp4 g, Val x ) { return Fn4_apply( fn4(g), x ); }
Fn3 Fn4_apply( Fn4 g, Val x ) { return (Fn3){ Fn_bind1_v( g.f, x ) }; }

Fn4 Fp5_apply( Fp5 g, Val x ) { return Fn5_apply( fn5(g), x ); }
Fn4 Fn5_apply( Fn5 g, Val x ) { return (Fn4){ Fn_bind1_v( g.f, x ) }; }

Fn5 Fp6_apply( Fp6 g, Val x ) { return Fn6_apply( fn6(g), x ); }
Fn5 Fn6_apply( Fn6 g, Val x ) { return (Fn5){ Fn_bind1_v( g.f, x ) }; }

Fn6 Fp7_apply( Fp7 g, Val x ) { return Fn7_apply( fn7(g), x ); }
Fn6 Fn7_apply( Fn7 g, Val x ) { return (Fn6){ Fn_bind1_v( g.f, x ) }; }

Fn7 Fp8_apply( Fp8 g, Val x ) { return Fn8_apply( fn8(g), x ); }
Fn7 Fn8_apply( Fn8 g, Val x ) { return (Fn7){ Fn_bind1_v( g.f, x ) }; }

Fn8 Fp9_apply( Fp9 g, Val x ) { return Fn9_apply( fn9(g), x ); }
Fn8 Fn9_apply( Fn9 g, Val x ) { return (Fn8){ Fn_bind1_v( g.f, x ) }; }
