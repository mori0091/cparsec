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
    - Parser apply(Filter,Parser)

### FUNCTION OBJECTS - Currying and Partial Application

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
      - Fn  fn(FnFunc) for zero or more (variable length) arguments ; \sa Fn_bind(), Fn_eval()
      - Fn1 fn1(Fp1) for one arguments ; \sa Fn_apply()
      - Fn2 fn2(Fp2) for two arguments ; \sa Fn_apply()
      - Fn3 fn3(Fp3) for three arguments ; \sa Fn_apply()
      - Fn4 fn4(Fp4) for four arguments ; \sa Fn_apply()
      - Fn5 fn5(Fp5) for five arguments ; \sa Fn_apply()
      - Fn6 fn6(Fp6) for six arguments ; \sa Fn_apply()
      - Fn7 fn7(Fp7) for seven arguments ; \sa Fn_apply()
      - Fn8 fn8(Fp8) for eight arguments ; \sa Fn_apply()
      - Fn9 fn9(Fp9) for nine arguments ; \sa Fn_apply()

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
