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

static Fn Fp_fn( Fn delegate, union Fp g )
{
    union Fp* p = malloc( sizeof(union Fp) );
    assert( p );
    *p = g;
    return Fn_bind1_v( delegate, VAL(D_PTR)(p) );
}

static Val Fp1_run( int n, const Val* x[] ) { assert(n==2) ; return ((union Fp*)(x[0]->ptr))->fp1(*x[1]); }
static Val Fp2_run( int n, const Val* x[] ) { assert(n==3) ; return ((union Fp*)(x[0]->ptr))->fp2(*x[1],*x[2]); }
static Val Fp3_run( int n, const Val* x[] ) { assert(n==4) ; return ((union Fp*)(x[0]->ptr))->fp3(*x[1],*x[2],*x[3]); }
static Val Fp4_run( int n, const Val* x[] ) { assert(n==5) ; return ((union Fp*)(x[0]->ptr))->fp4(*x[1],*x[2],*x[3],*x[4]); }
static Val Fp5_run( int n, const Val* x[] ) { assert(n==6) ; return ((union Fp*)(x[0]->ptr))->fp5(*x[1],*x[2],*x[3],*x[4],*x[5]); }
static Val Fp6_run( int n, const Val* x[] ) { assert(n==7) ; return ((union Fp*)(x[0]->ptr))->fp6(*x[1],*x[2],*x[3],*x[4],*x[5],*x[6]); }
static Val Fp7_run( int n, const Val* x[] ) { assert(n==8) ; return ((union Fp*)(x[0]->ptr))->fp7(*x[1],*x[2],*x[3],*x[4],*x[5],*x[6],*x[7]); }
static Val Fp8_run( int n, const Val* x[] ) { assert(n==9) ; return ((union Fp*)(x[0]->ptr))->fp8(*x[1],*x[2],*x[3],*x[4],*x[5],*x[6],*x[7],*x[8]); }
static Val Fp9_run( int n, const Val* x[] ) { assert(n==10); return ((union Fp*)(x[0]->ptr))->fp9(*x[1],*x[2],*x[3],*x[4],*x[5],*x[6],*x[7],*x[8],*x[9]); }

static FnSt Fp1_delegate = { .ref_cnt = -1, .depth = 0, .funcptr = Fp1_run };
static FnSt Fp2_delegate = { .ref_cnt = -1, .depth = 0, .funcptr = Fp2_run };
static FnSt Fp3_delegate = { .ref_cnt = -1, .depth = 0, .funcptr = Fp3_run };
static FnSt Fp4_delegate = { .ref_cnt = -1, .depth = 0, .funcptr = Fp4_run };
static FnSt Fp5_delegate = { .ref_cnt = -1, .depth = 0, .funcptr = Fp5_run };
static FnSt Fp6_delegate = { .ref_cnt = -1, .depth = 0, .funcptr = Fp6_run };
static FnSt Fp7_delegate = { .ref_cnt = -1, .depth = 0, .funcptr = Fp7_run };
static FnSt Fp8_delegate = { .ref_cnt = -1, .depth = 0, .funcptr = Fp8_run };
static FnSt Fp9_delegate = { .ref_cnt = -1, .depth = 0, .funcptr = Fp9_run };

Fn1 fn1( Fp1 g ) { return (Fn1){ Fp_fn( &Fp1_delegate, (union Fp){.fp1=g} ) }; }
Fn2 fn2( Fp2 g ) { return (Fn2){ Fp_fn( &Fp2_delegate, (union Fp){.fp2=g} ) }; }
Fn3 fn3( Fp3 g ) { return (Fn3){ Fp_fn( &Fp3_delegate, (union Fp){.fp3=g} ) }; }
Fn4 fn4( Fp4 g ) { return (Fn4){ Fp_fn( &Fp4_delegate, (union Fp){.fp4=g} ) }; }
Fn5 fn5( Fp5 g ) { return (Fn5){ Fp_fn( &Fp5_delegate, (union Fp){.fp5=g} ) }; }
Fn6 fn6( Fp6 g ) { return (Fn6){ Fp_fn( &Fp6_delegate, (union Fp){.fp6=g} ) }; }
Fn7 fn7( Fp7 g ) { return (Fn7){ Fp_fn( &Fp7_delegate, (union Fp){.fp7=g} ) }; }
Fn8 fn8( Fp8 g ) { return (Fn8){ Fp_fn( &Fp8_delegate, (union Fp){.fp8=g} ) }; }
Fn9 fn9( Fp9 g ) { return (Fn9){ Fp_fn( &Fp9_delegate, (union Fp){.fp9=g} ) }; }

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
