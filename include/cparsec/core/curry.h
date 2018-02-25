/* -*- mode: c++ ; coding: utf-8-unix -*- */

#pragma once

#ifndef CPARSEC_CORE_CURRY_H
#define CPARSEC_CORE_CURRY_H

#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include "cparsec/core/function.h"
#include "cppmp/cppmp.h"

/**
 * \brief Applies one or more values to a function object (or a
 *        function pointer) g.
 *
 * Fn_apply() performs *Partial (Function) Application* for a function
 * pointer or a function object.
 * 
 * Example:
 * \includelineno ex_Fn_apply.c
 *
 * \param g    a function object such as Fn1, Fn2, ..., Fn9. or a
 *             function pointer such as Fp1, Fp2, ..., Fp9.
 *
 * \param ...  the rest are arguments to be applied to g.\n
 *             Type of the rest arguments must be one of a Val, char,
 *             int, double, const char* or void* .
 *
 * \return     a function object or a result value.
 *
 * \sa val()
 */
#define Fn_apply(g,...)   CPPMP_ACCUMULATE(Fn_apply1,(g),__VA_ARGS__)

#ifdef __cplusplus
extern "C" {
#endif

    /** \brief The type of a function pointer which takes 1 argument. */
    typedef Val (*Fp1)(Val);
    /** \brief The type of a function pointer which takes 2 arguments. */
    typedef Val (*Fp2)(Val,Val);
    /** \brief The type of a function pointer which takes 3 arguments. */
    typedef Val (*Fp3)(Val,Val,Val);
    /** \brief The type of a function pointer which takes 4 arguments. */
    typedef Val (*Fp4)(Val,Val,Val,Val);
    /** \brief The type of a function pointer which takes 5 arguments. */
    typedef Val (*Fp5)(Val,Val,Val,Val,Val);
    /** \brief The type of a function pointer which takes 6 arguments. */
    typedef Val (*Fp6)(Val,Val,Val,Val,Val,Val);
    /** \brief The type of a function pointer which takes 7 arguments. */
    typedef Val (*Fp7)(Val,Val,Val,Val,Val,Val,Val);
    /** \brief The type of a function pointer which takes 8 arguments. */
    typedef Val (*Fp8)(Val,Val,Val,Val,Val,Val,Val,Val);
    /** \brief The type of a function pointer which takes 9 arguments. */
    typedef Val (*Fp9)(Val,Val,Val,Val,Val,Val,Val,Val,Val);

    /** \brief The type of a function object which takes 1 argument. */
    typedef struct Fn1St { Fn f; } Fn1;
    /** \brief The type of a function object which takes 2 arguments. */
    typedef struct Fn2St { Fn f; } Fn2;
    /** \brief The type of a function object which takes 3 arguments. */
    typedef struct Fn3St { Fn f; } Fn3;
    /** \brief The type of a function object which takes 4 arguments. */
    typedef struct Fn4St { Fn f; } Fn4;
    /** \brief The type of a function object which takes 5 arguments. */
    typedef struct Fn5St { Fn f; } Fn5;
    /** \brief The type of a function object which takes 6 arguments. */
    typedef struct Fn6St { Fn f; } Fn6;
    /** \brief The type of a function object which takes 7 arguments. */
    typedef struct Fn7St { Fn f; } Fn7;
    /** \brief The type of a function object which takes 8 arguments. */
    typedef struct Fn8St { Fn f; } Fn8;
    /** \brief The type of a function object which takes 9 arguments. */
    typedef struct Fn9St { Fn f; } Fn9;

    /**
     * \brief Makes a Fn1 function object from a function pointer.
     * \param g     a function pointer which takes 1 argument.
     * \return      a function object which takes 1 argument.
     */
    Fn1 fn1( Fp1 g );
    /**
     * \brief Makes a Fn2 function object from a function pointer.
     * \param g     a function pointer which takes 2 arguments.
     * \return      a function object which takes 2 arguments.
     */
    Fn2 fn2( Fp2 g );
    /**
     * \brief Makes a Fn3 function object from a function pointer.
     * \param g     a function pointer which takes 3 arguments.
     * \return      a function object which takes 3 arguments.
     */
    Fn3 fn3( Fp3 g );
    /**
     * \brief Makes a Fn4 function object from a function pointer.
     * \param g     a function pointer which takes 4 arguments.
     * \return      a function object which takes 4 arguments.
     */
    Fn4 fn4( Fp4 g );
    /**
     * \brief Makes a Fn5 function object from a function pointer.
     * \param g     a function pointer which takes 5 arguments.
     * \return      a function object which takes 5 arguments.
     */
    Fn5 fn5( Fp5 g );
    /**
     * \brief Makes a Fn6 function object from a function pointer.
     * \param g     a function pointer which takes 6 arguments.
     * \return      a function object which takes 6 arguments.
     */
    Fn6 fn6( Fp6 g );
    /**
     * \brief Makes a Fn7 function object from a function pointer.
     * \param g     a function pointer which takes 7 arguments.
     * \return      a function object which takes 7 arguments.
     */
    Fn7 fn7( Fp7 g );
    /**
     * \brief Makes a Fn8 function object from a function pointer.
     * \param g     a function pointer which takes 8 arguments.
     * \return      a function object which takes 8 arguments.
     */
    Fn8 fn8( Fp8 g );
    /**
     * \brief Makes a Fn9 function object from a function pointer.
     * \param g     a function pointer which takes 9 arguments.
     * \return      a function object which takes 9 arguments.
     */
    Fn9 fn9( Fp9 g );

    /**
     * \brief Applies a value x to a Fp1 function pointer g.
     *
     * \note You may use Fn_apply(g,...) instead.
     *
     * \param g    a function pointer which takes 1 argument.
     * \param x    an argument to be applied to g.
     * \return     a result value of g(x).
     *
     * \sa Fn_apply()
     */
    Val Fp1_apply( Fp1 g, Val x );
    /**
     * \brief Applies a value x to a Fn1 function object g.
     *
     * \note You may use Fn_apply(g,...) instead.
     *
     * \param g    a function object which takes 1 argument.
     * \param x    an argument to be applied to g.
     * \return     a result value of g(x).
     *
     * \sa Fn_apply()
     */
    Val Fn1_apply( Fn1 g, Val x );

    /**
     * \brief Applies a value x to a Fp2 function pointer g.
     *
     * \note You may use Fn_apply(g,...) instead.
     *
     * \param g    a function pointer which takes 2 argument.
     * \param x    an argument to be applied to g.
     * \return     a Fn1 function object f where f = g(x).
     *
     * \sa Fn_apply()
     */
    Fn1 Fp2_apply( Fp2 g, Val x );
    /**
     * \brief Applies a value x to a Fn2 function object g.
     *
     * \note You may use Fn_apply(g,...) instead.
     *
     * \param g    a function object which takes 2 argument.
     * \param x    an argument to be applied to g.
     * \return     a Fn1 function object f where f = g(x).
     *
     * \sa Fn_apply()
     */
    Fn1 Fn2_apply( Fn2 g, Val x );

    /**
     * \brief Applies a value x to a Fp3 function pointer g.
     *
     * \note You may use Fn_apply(g,...) instead.
     *
     * \param g    a function pointer which takes 3 argument.
     * \param x    an argument to be applied to g.
     * \return     a Fn2 function object f where f = g(x).
     *
     * \sa Fn_apply()
     */
    Fn2 Fp3_apply( Fp3 g, Val x );
    /**
     * \brief Applies a value x to a Fn3 function object g.
     *
     * \note You may use Fn_apply(g,...) instead.
     *
     * \param g    a function object which takes 3 argument.
     * \param x    an argument to be applied to g.
     * \return     a Fn2 function object f where f = g(x).
     *
     * \sa Fn_apply()
     */
    Fn2 Fn3_apply( Fn3 g, Val x );

    /**
     * \brief Applies a value x to a Fp4 function pointer g.
     *
     * \note You may use Fn_apply(g,...) instead.
     *
     * \param g    a function pointer which takes 4 argument.
     * \param x    an argument to be applied to g.
     * \return     a Fn3 function object f where f = g(x).
     *
     * \sa Fn_apply()
     */
    Fn3 Fp4_apply( Fp4 g, Val x );
    /**
     * \brief Applies a value x to a Fn4 function object g.
     *
     * \note You may use Fn_apply(g,...) instead.
     *
     * \param g    a function object which takes 4 argument.
     * \param x    an argument to be applied to g.
     * \return     a Fn3 function object f where f = g(x).
     *
     * \sa Fn_apply()
     */
    Fn3 Fn4_apply( Fn4 g, Val x );

    /**
     * \brief Applies a value x to a Fp5 function pointer g.
     *
     * \note You may use Fn_apply(g,...) instead.
     *
     * \param g    a function pointer which takes 5 argument.
     * \param x    an argument to be applied to g.
     * \return     a Fn4 function object f where f = g(x).
     *
     * \sa Fn_apply()
     */
    Fn4 Fp5_apply( Fp5 g, Val x );
    /**
     * \brief Applies a value x to a Fn5 function object g.
     *
     * \note You may use Fn_apply(g,...) instead.
     *
     * \param g    a function object which takes 5 argument.
     * \param x    an argument to be applied to g.
     * \return     a Fn4 function object f where f = g(x).
     *
     * \sa Fn_apply()
     */
    Fn4 Fn5_apply( Fn5 g, Val x );

    /**
     * \brief Applies a value x to a Fp6 function pointer g.
     *
     * \note You may use Fn_apply(g,...) instead.
     *
     * \param g    a function pointer which takes 6 argument.
     * \param x    an argument to be applied to g.
     * \return     a Fn5 function object f where f = g(x).
     *
     * \sa Fn_apply()
     */
    Fn5 Fp6_apply( Fp6 g, Val x );
    /**
     * \brief Applies a value x to a Fn6 function object g.
     *
     * \note You may use Fn_apply(g,...) instead.
     *
     * \param g    a function object which takes 6 argument.
     * \param x    an argument to be applied to g.
     * \return     a Fn5 function object f where f = g(x).
     *
     * \sa Fn_apply()
     */
    Fn5 Fn6_apply( Fn6 g, Val x );

    /**
     * \brief Applies a value x to a Fp7 function pointer g.
     *
     * \note You may use Fn_apply(g,...) instead.
     *
     * \param g    a function pointer which takes 7 argument.
     * \param x    an argument to be applied to g.
     * \return     a Fn6 function object f where f = g(x).
     *
     * \sa Fn_apply()
     */
    Fn6 Fp7_apply( Fp7 g, Val x );
    /**
     * \brief Applies a value x to a Fn7 function object g.
     *
     * \note You may use Fn_apply(g,...) instead.
     *
     * \param g    a function object which takes 7 argument.
     * \param x    an argument to be applied to g.
     * \return     a Fn6 function object f where f = g(x).
     *
     * \sa Fn_apply()
     */
    Fn6 Fn7_apply( Fn7 g, Val x );

    /**
     * \brief Applies a value x to a Fp8 function pointer g.
     *
     * \note You may use Fn_apply(g,...) instead.
     *
     * \param g    a function pointer which takes 8 argument.
     * \param x    an argument to be applied to g.
     * \return     a Fn7 function object f where f = g(x).
     *
     * \sa Fn_apply()
     */
    Fn7 Fp8_apply( Fp8 g, Val x );
    /**
     * \brief Applies a value x to a Fn8 function object g.
     *
     * \note You may use Fn_apply(g,...) instead.
     *
     * \param g    a function object which takes 8 argument.
     * \param x    an argument to be applied to g.
     * \return     a Fn7 function object f where f = g(x).
     *
     * \sa Fn_apply()
     */
    Fn7 Fn8_apply( Fn8 g, Val x );

    /**
     * \brief Applies a value x to a Fp9 function pointer g.
     *
     * \note You may use Fn_apply(g,...) instead.
     *
     * \param g    a function pointer which takes 9 argument.
     * \param x    an argument to be applied to g.
     * \return     a Fn8 function object f where f = g(x).
     *
     * \sa Fn_apply()
     */
    Fn8 Fp9_apply( Fp9 g, Val x );
    /**
     * \brief Applies a value x to a Fn9 function object g.
     *
     * \note You may use Fn_apply(g,...) instead.
     *
     * \param g    a function object which takes 9 argument.
     * \param x    an argument to be applied to g.
     * \return     a Fn8 function object f where f = g(x).
     *
     * \sa Fn_apply()
     */
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
/**
 * \brief Applies a value to a function object (or a function pointer) g.
 *
 * \note You may use Fn_apply(g,...) instead.
 *
 * \param g    a function object such as Fn1, Fn2, ..., Fn9. or a
 *             function pointer such as Fp1, Fp2, ..., Fp9.
 *
 * \param x    an arguments to be applied to g.\n
 *             Type of x must be one of a Val, char, int, double,
 *             const char* or void* .
 *
 * \return     a function object or a result value.
 *
 * \sa Fn_apply()
 */
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
