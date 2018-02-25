# cparsec - A PARSEr Combinator library for C language

## Features

### PARSER and PARSER COMBNATORS

- Functions to parse a string
    - Val parse(Parser, const char*)
    - void parse_test(Parser, const char*)

- Pre-instantiated primitive parsers
    - const Parser any_char
    - const Parser digit
    - const Parser lower
    - const Parser upper
    - const Parser alpha
    - const Parser alnum
    - const Parser letter
    - const Parser number

- Primitive parser generators
    - Parser char1(char)
    - Parser string1(const char*)
    - Parser satisfy(Predicate)
    - Parser one_of(const char*)

- Unary operator parser combinators
    - Parser many(Parser)
    - Parser many1(Parser)
    - Parser tryp(Parser)
    - Parser optional(Parser)

- Binary operator parser combinators
    - Parser seq(Parser,Parser)
    - Parser either(Parser,Parser)
    - Parser first(Parser,Parser)
    - Parser second(Parser,Parser)

- Other parser combinators
    - Parser rep(int,Parser)
    - Parser apply(Fn1,Parser)

### FUNCTION OBJECTS - Currying and Partial Application

Example:

~~~c
#include "cparsec/core/curry.h"

// A Fp3 type function 'add_i3', which takes 3 int type Val and returns sum of them.
Val add_i3( Val x, Val y, Val z ) {
    return val(x.i + y.i + z.i);
}

#define UNUSED_VARIABLE(x)    (void)(x)

int main( int argc, char** argv )
{
    UNUSED_VARIABLE(argc);
    UNUSED_VARIABLE(argv);

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

    return 0;
}
~~~

- Functions for currying and/or partial application
    - Fn_apply(f, ...)
      : Partial application. Binds one or more arguments to f, then
        returns a result value of f(...) or a function object g where
        g = f(...).
    - Fn_bind(f, ...)
      : Binds one or more arguments to f, then returns a function
        object g where g = f(...).
    - Fn_eval(Fn f)
      : Evaluates a Fn type function object.
    - Creates a function object from a function pointer
      - Fn  fn(FnFunc) for zero or more (variable length) arguments
        : See also Fn_bind(), Fn_eval()
      - Fn1 fn1(Fp1) for one arguments
        :See also Fn_apply()
      - Fn2 fn2(Fp2) for two arguments
        :See also Fn_apply()
      - Fn3 fn3(Fp3) for three arguments
        : See also Fn_apply()
      - Fn4 fn4(Fp4) for four arguments
        : See also Fn_apply()
      - Fn5 fn5(Fp5) for five arguments
        : See also Fn_apply()
      - Fn6 fn6(Fp6) for six arguments
        : See also Fn_apply()
      - Fn7 fn7(Fp7) for seven arguments
        : See also Fn_apply()
      - Fn8 fn8(Fp8) for eight arguments
        : See also Fn_apply()
      - Fn9 fn9(Fp9) for nine arguments
        : See also Fn_apply()

- Function objects
    - Fn
      : A function object which takes zero or more arguments.
    - Fn1
      : A function object which takes one argument.
    - Fn2
      : A function object which takes two arguments.
    - Fn3
      : A function object which takes three arguments.
    - Fn4
      : A function object which takes four arguments.
    - Fn5
      : A function object which takes five arguments.
    - Fn6
      : A function object which takes six arguments.
    - Fn7
      : A function object which takes seven arguments.
    - Fn8
      : A function object which takes eight arguments.
    - Fn9
      : A function object which takes nine arguments.
