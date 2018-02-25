/* -*- mode: c ; coding: utf-8-unix -*- */

#include "cparsec/core/curry.h"

// A Fp3 type function 'add_i3', which takes 3 int type Val and returns sum of them.
Val add_i3( Val x, Val y, Val z ) {
    return val(x.i + y.i + z.i);
}

void ex_Fn_apply( void )
{
    // usage 1. same as `add_i3( val(1), val(2), val(3) )`
    {
        Val y = Fn_apply(add_i3, 1, 2, 3);
        Val_print( &y );         // outputs 6
    }

    // usage 2. apply argument one by one.
    {
        Fn3 a = fn3(add_i3);
        Fn2 f = Fn_apply(a, 1);
        Fn1 g = Fn_apply(f, 2);
        Val y = Fn_apply(g, 3);
        Val_print( &y );         // outputs 6
    }

    // usage 3. apply some argument, then apply the rest.
    {
        Fn1 g = Fn_apply(add_i3, 1, 2);
        Val y = Fn_apply(g, 3);
        Val_print( &y );         // outputs 6
    }

    // usage 4. apply some argument, then apply the rest twice or more.
    {
        Fn1 g = Fn_apply(add_i3, 1, 2);
        Fn_ref( g.f );           // increments reference count to reuse
        for (int i = 3; i < 10; ++i ) {
            Val y = Fn_apply(g, i);
            Val_print( &y );     // outputs 6,7,8,9,10,11,12
        }
        Fn_unref( g.f );         // decrements reference count to deallocate
    }
}
