/* -*- mode: c++ ; coding: utf-8-unix -*- */

#pragma once

#ifndef CPARSEC_CORE_CURRY_H
#define CPARSEC_CORE_CURRY_H

#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include "cparsec/core/function.h"
#include "cppmp/cppmp.h"

#define Fn_apply(g,...)   CPPMP_ACCUMULATE(Fn_apply1,(g),__VA_ARGS__)

#ifdef __cplusplus
extern "C" {
#endif

    typedef Val (*Fp1)(Val);
    typedef Val (*Fp2)(Val,Val);
    typedef Val (*Fp3)(Val,Val,Val);
    typedef Val (*Fp4)(Val,Val,Val,Val);
    typedef Val (*Fp5)(Val,Val,Val,Val,Val);
    typedef Val (*Fp6)(Val,Val,Val,Val,Val,Val);
    typedef Val (*Fp7)(Val,Val,Val,Val,Val,Val,Val);
    typedef Val (*Fp8)(Val,Val,Val,Val,Val,Val,Val,Val);
    typedef Val (*Fp9)(Val,Val,Val,Val,Val,Val,Val,Val,Val);

    typedef struct Fn1St { Fn f; } Fn1;
    typedef struct Fn2St { Fn f; } Fn2;
    typedef struct Fn3St { Fn f; } Fn3;
    typedef struct Fn4St { Fn f; } Fn4;
    typedef struct Fn5St { Fn f; } Fn5;
    typedef struct Fn6St { Fn f; } Fn6;
    typedef struct Fn7St { Fn f; } Fn7;
    typedef struct Fn8St { Fn f; } Fn8;
    typedef struct Fn9St { Fn f; } Fn9;

    Fn1 fn1( Fp1 g );
    Fn2 fn2( Fp2 g );
    Fn3 fn3( Fp3 g );
    Fn4 fn4( Fp4 g );
    Fn5 fn5( Fp5 g );
    Fn6 fn6( Fp6 g );
    Fn7 fn7( Fp7 g );
    Fn8 fn8( Fp8 g );
    Fn9 fn9( Fp9 g );

    Val Fp1_apply( Fp1 g, Val x );
    Val Fn1_apply( Fn1 g, Val x );

    Fn1 Fp2_apply( Fp2 g, Val x );
    Fn1 Fn2_apply( Fn2 g, Val x );

    Fn2 Fp3_apply( Fp3 g, Val x );
    Fn2 Fn3_apply( Fn3 g, Val x );

    Fn3 Fp4_apply( Fp4 g, Val x );
    Fn3 Fn4_apply( Fn4 g, Val x );

    Fn4 Fp5_apply( Fp5 g, Val x );
    Fn4 Fn5_apply( Fn5 g, Val x );

    Fn5 Fp6_apply( Fp6 g, Val x );
    Fn5 Fn6_apply( Fn6 g, Val x );

    Fn6 Fp7_apply( Fp7 g, Val x );
    Fn6 Fn7_apply( Fn7 g, Val x );

    Fn7 Fp8_apply( Fp8 g, Val x );
    Fn7 Fn8_apply( Fn8 g, Val x );

    Fn8 Fp9_apply( Fp9 g, Val x );
    Fn8 Fn9_apply( Fn9 g, Val x );

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
// For C++ ; template function
template <typename T>
Val Fn_apply1( Fn1 g, T x ) { return Fn1_apply(g,val(x)); }
template <typename T>
Val Fn_apply1( Fp1 g, T x ) { return Fp1_apply(g,val(x)); }
template <typename T>
Fn1 Fn_apply1( Fn2 g, T x ) { return Fn2_apply(g,val(x)); }
template <typename T>
Fn1 Fn_apply1( Fp2 g, T x ) { return Fp2_apply(g,val(x)); }
template <typename T>
Fn2 Fn_apply1( Fn3 g, T x ) { return Fn3_apply(g,val(x)); }
template <typename T>
Fn2 Fn_apply1( Fp3 g, T x ) { return Fp3_apply(g,val(x)); }
template <typename T>
Fn3 Fn_apply1( Fn4 g, T x ) { return Fn4_apply(g,val(x)); }
template <typename T>
Fn3 Fn_apply1( Fp4 g, T x ) { return Fp4_apply(g,val(x)); }
template <typename T>
Fn4 Fn_apply1( Fn5 g, T x ) { return Fn5_apply(g,val(x)); }
template <typename T>
Fn4 Fn_apply1( Fp5 g, T x ) { return Fp5_apply(g,val(x)); }
template <typename T>
Fn5 Fn_apply1( Fn6 g, T x ) { return Fn6_apply(g,val(x)); }
template <typename T>
Fn5 Fn_apply1( Fp6 g, T x ) { return Fp6_apply(g,val(x)); }
template <typename T>
Fn6 Fn_apply1( Fn7 g, T x ) { return Fn7_apply(g,val(x)); }
template <typename T>
Fn6 Fn_apply1( Fp7 g, T x ) { return Fp7_apply(g,val(x)); }
template <typename T>
Fn7 Fn_apply1( Fn8 g, T x ) { return Fn8_apply(g,val(x)); }
template <typename T>
Fn7 Fn_apply1( Fp8 g, T x ) { return Fp8_apply(g,val(x)); }
template <typename T>
Fn8 Fn_apply1( Fn9 g, T x ) { return Fn9_apply(g,val(x)); }
template <typename T>
Fn8 Fn_apply1( Fp9 g, T x ) { return Fp9_apply(g,val(x)); }

#else
// For C11 ; function overload by the generic selection macro
#define Fn_apply1(g,x)                          \
    _Generic((g)                                \
             , Fp1 : Fp1_apply, Fn1 : Fn1_apply \
             , Fp2 : Fp2_apply, Fn2 : Fn2_apply \
             , Fp3 : Fp3_apply, Fn3 : Fn3_apply \
             , Fp4 : Fp4_apply, Fn4 : Fn4_apply \
             , Fp5 : Fp5_apply, Fn5 : Fn5_apply \
             , Fp6 : Fp6_apply, Fn6 : Fn6_apply \
             , Fp7 : Fp7_apply, Fn7 : Fn7_apply \
             , Fp8 : Fp8_apply, Fn8 : Fn8_apply \
             , Fp9 : Fp9_apply, Fn9 : Fn9_apply \
             )(g,val(x))

#endif

#endif  /* CPARSEC_CORE_CURRY_H */
