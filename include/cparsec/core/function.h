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

    Fn Fn_bind1_v  ( Fn f, Val x );

    inline Fn Fn_bind1_c  ( Fn f, char        x ) { return Fn_bind1_v(f,VAL(CHAR)(x));   }
    inline Fn Fn_bind1_i  ( Fn f, int         x ) { return Fn_bind1_v(f,VAL(INT)(x));    }
    inline Fn Fn_bind1_d  ( Fn f, double      x ) { return Fn_bind1_v(f,VAL(DOUBLE)(x)); }
    inline Fn Fn_bind1_str( Fn f, const char* x ) { return Fn_bind1_v(f,VAL(STRING)(x)); }
    inline Fn Fn_bind1_ptr( Fn f, void*       x ) { return Fn_bind1_v(f,VAL(PTR)(x));    }
    inline Fn Fn_bind1_i8 ( Fn f, int8_t      x ) { return Fn_bind1_v(f,VAL(INT8)(x));   }
    inline Fn Fn_bind1_i16( Fn f, int16_t     x ) { return Fn_bind1_v(f,VAL(INT16)(x));  }
    inline Fn Fn_bind1_i32( Fn f, int32_t     x ) { return Fn_bind1_v(f,VAL(INT32)(x));  }
    inline Fn Fn_bind1_i64( Fn f, int64_t     x ) { return Fn_bind1_v(f,VAL(INT64)(x));  }
    inline Fn Fn_bind1_u8 ( Fn f, uint8_t     x ) { return Fn_bind1_v(f,VAL(UINT8)(x));  }
    inline Fn Fn_bind1_u16( Fn f, uint16_t    x ) { return Fn_bind1_v(f,VAL(UINT16)(x)); }
    inline Fn Fn_bind1_u32( Fn f, uint32_t    x ) { return Fn_bind1_v(f,VAL(UINT32)(x)); }
    inline Fn Fn_bind1_u64( Fn f, uint64_t    x ) { return Fn_bind1_v(f,VAL(UINT64)(x)); }

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
 * \note The 1st argument f must be a Fn type. (must not be NULL)
 * \note The rest argument must be a Val type.
 * \note Fn_bind(f,x,y,z) is equivalent to
 *       Fn_bind11(Fn_bind11(Fn_bind11(f,x),y),z)
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
inline Fn Fn_bind1( Fn f, Val         x ) { return Fn_bind1_v(f,x);   }
inline Fn Fn_bind1( Fn f, char        x ) { return Fn_bind1_c(f,x);   }
inline Fn Fn_bind1( Fn f, int         x ) { return Fn_bind1_i(f,x);   }
inline Fn Fn_bind1( Fn f, double      x ) { return Fn_bind1_d(f,x);   }
inline Fn Fn_bind1( Fn f, const char* x ) { return Fn_bind1_str(f,x); }
inline Fn Fn_bind1( Fn f, void*       x ) { return Fn_bind1_ptr(f,x); }
// inline Fn Fn_bind1( Fn f, int8_t      x ) { return Fn_bind1_i8(f,x);  }
// inline Fn Fn_bind1( Fn f, int16_t     x ) { return Fn_bind1_i16(f,x); }
// inline Fn Fn_bind1( Fn f, int32_t     x ) { return Fn_bind1_i32(f,x); }
// inline Fn Fn_bind1( Fn f, int64_t     x ) { return Fn_bind1_i64(f,x); }
// inline Fn Fn_bind1( Fn f, uint8_t     x ) { return Fn_bind1_u8(f,x);  }
// inline Fn Fn_bind1( Fn f, uint16_t    x ) { return Fn_bind1_u16(f,x); }
// inline Fn Fn_bind1( Fn f, uint32_t    x ) { return Fn_bind1_u32(f,x); }
// inline Fn Fn_bind1( Fn f, uint64_t    x ) { return Fn_bind1_u64(f,x); }
#else
// For C11, use _Generic() generic selection macro
/**
 * \brief Partial application - Creates a function object g where g = f(x)
 * \param f   a functioin object
 * \param x   a value to be bounded as the 1st argument of f
 * \return    a functioin object g where g = f(x).
 *
 * \sa Fn_bind()
 */
#if 1
#define Fn_bind1(f,x)                            \
    _Generic((x)                                 \
             , Val         : Fn_bind1_v          \
             , char        : Fn_bind1_c          \
             , double      : Fn_bind1_d          \
             , const char* : Fn_bind1_str        \
             , void*       : Fn_bind1_ptr        \
             )(f,x)
#else
#define Fn_bind1(f,x)                            \
    _Generic((x)                                 \
             , Val         : Fn_bind1_v          \
             , char        : Fn_bind1_c          \
             , double      : Fn_bind1_d          \
             , const char* : Fn_bind1_str        \
             , void*       : Fn_bind1_ptr        \
             , int8_t      : Fn_bind1_i8         \
             , int16_t     : Fn_bind1_i16        \
             , int32_t     : Fn_bind1_i32        \
             , int64_t     : Fn_bind1_i64        \
             , uint8_t     : Fn_bind1_u8         \
             , uint16_t    : Fn_bind1_u16        \
             , uint32_t    : Fn_bind1_u32        \
             , uint64_t    : Fn_bind1_u64        \
             )(f,x)
#endif
#endif

//------

#endif  /* CPARSEC_CORE_FUNCTION_H */
