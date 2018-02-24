/* -*- mode: c++ ; coding: utf-8-unix -*- */

#pragma once

#ifndef CPARSEC_CORE_FUNCTION_H
#define CPARSEC_CORE_FUNCTION_H

#include "cparsec/core/val.h"
#include "cppmp/cppmp.h"

#ifdef __cplusplus
extern "C" {
#endif

    /**
     * \brief Type of a function pointer of a curryable function.
     */
    typedef Val (*FnFunc)( int n, const Val* args[] );

    /**
     * \brief Type of curried function object.
     *
     * \note Fn is an opaque object. You need not know its
     *       implementation.
     */
    typedef struct FnSt* Fn;

    /**
     * \brief Returns the number of function objects living.
     *
     * \note This is debug purpose only.
     * \return the number of function objects living.
     */
    int Fn_live_count( void );

    /**
     * \brief Increments the reference count of a function object.
     *
     * Increments the reference count of a function object.
     *
     * In usually, you need not use Fn_ref() and Fn_unref() if any
     * function objects you created are evaluated just once by
     * Fn_eval().
     *
     * Otherwise you must use explicitlly Fn_ref() and Fn_unref().
     *
     * ~~~c
     * Val sum( int n, const Val* args[] )
     * {
     *     int ret = 0;
     *     for ( i = 0; i < n; ++i ) { ret += args[i]->i; }
     *     return VAL(INT)(ret);
     * }
     *
     * Val ret = Fn_eval( fn( sum ) ); // OK ( ret.i == 0 )
     *
     * Fn f = fn( sum );
     * Val x = Fn_eval( Fn_bind( f, 1 ) ); // OK ( x.i == 1 )
     * Val y = Fn_eval( Fn_bind( f, 1 ) ); // NG, `f` is no longer refered.
     *
     * Fn g = Fn_ref( fn( sum ) );
     * Val u = Fn_eval( Fn_bind( g, 1 ) );    // OK ( u.i == 1 )
     * Val v = Fn_eval( Fn_bind( g, 2 ) );    // OK ( v.i == 2 )
     * Val w = Fn_eval( Fn_bind( g, 1, 2 ) ); // OK ( w.i == 3 )
     * Fn_unref( g );         // Fn_unref() is needed to deallocate `g`.
     * ~~~
     *
     * \param f   a function object
     * \return    the function object `f` itself
     */
    Fn Fn_ref( Fn f );

    /**
     * \brief Decrements the reference count of a function object.
     * 
     * Decrements the reference count of a function object, and
     * deletes the function object if its reference count became zero.
     *
     * \param f   a function object
     * \sa Fn_unref()
     */
    void Fn_unref( Fn f );

    /**
     * \brief Currying - Creates a function object that makes a function curried.
     * \param funcptr a functioin pointer type of Val (*)(int, const Val*[])
     * \return        a functioin object
     */
    Fn fn( FnFunc funcptr );

    /**
     * \brief Partial application - Creates a function object g where g = f(x)
     * \param f   a functioin object
     * \param x   a value to be bounded as the 1st argument of f
     * \return    a functioin object g where g = f(x).
     *
     * \sa Fn_bind()
     */
    Fn Fn_bind1_v  ( Fn f, Val x );

    /**
     * \brief Evaluates a functioin object with its bounded arguments.
     *
     * ~~~c
     * // a function type of FnFunc ( i.e. Val (*)(int, const Val*[]) )
     * Val add( int n, const Val* args[] ) {
     *     int ret = 0;
     *     for ( int i = 0; i < n; ++i ) {
     *         assert( INT == args[i]->type );
     *         ret += args[i]->i;
     *     }
     *     return VAL(INT)(ret);
     * }
     *
     * Fn fadd = fn( add );
     * Fn add10 = Fn_ref( Fn_bind( fadd, 10 ) );
     * Val x = Fn_eval( Fn_bind( add10, 5 ) ); // --> x.i == 15
     * Val y = Fn_eval( Fn_bind( add10, 2 ) ); // --> y.i == 12
     * Fn_unref( add10 );
     * ~~~
     *
     * \param f   a functioin object
     * \return    a result of the function
     */
    Val Fn_eval( Fn f );

#ifdef __cplusplus
}
#endif

//------

/**
 * \brief Partial application - Creates a function object g where g = f(...)
 *
 * \note The type of f must be Fn. (must not be NULL)
 * \note The all rest arguments must be a Val type.
 * \note Fn_bind(f,x,y,z) is equivalent to
 *       Fn_bind1(Fn_bind1(Fn_bind1(f,x),y),z)
 *
 * \param f    a functioin object (Fn)
 * \param ...  one or more Val objects to be bounded as the arguments of f.
 * \return     a functioin object g where g = f(...).
 *
 * \sa Fn_bind1()
 */
#define Fn_bind( f, ... )    CPPMP_ACCUMULATE( Fn_bind1, f, __VA_ARGS__ )

#ifdef __cplusplus
// For C++, overloads Fn_bind1(f,x)
/**
 * \brief Partial application - Creates a function object g where g = f(x)
 *
 * \param f   a functioin object
 * \param x   a value to be bounded as the 1st argument of f
 * \return    a functioin object g where g = f(x).
 *
 * \note The type of x must be one of `Val`, `char`, `int`, `double`,
 *       `const char*`, or `void*`.
 *
 * \sa Fn_bind()
 * \sa Fn_bind1_v()
 */
template <typename T>
Fn Fn_bind1( Fn f, T x ) { return Fn_bind1_v(f,val(x)); }

#else
// For C11, use _Generic() generic selection macro
/**
 * \brief Partial application - Creates a function object g where g = f(x)
 *
 * \param f   a functioin object
 * \param x   a value to be bounded as the 1st argument of f
 * \return    a functioin object g where g = f(x).
 *
 * \note The type of x must be one of `Val`, `char`, `int`, `double`,
 *       `const char*`, or `void*`.
 *
 * \sa Fn_bind()
 * \sa Fn_bind1_v()
 */
#define Fn_bind1(f,x)    Fn_bind1_v(f,val(x))

#endif

//------

#endif  /* CPARSEC_CORE_FUNCTION_H */
