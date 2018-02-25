/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include "cparsec/primitive/singleton.h"
#include "cparsec/core/parser.h"
// #include "cparsec/core/function.h"
// #include "cparsec/core/curry.h"

#define UNUSED_VARIABLE(x)    (void)(x)

bool is_any_char( char c ) { UNUSED_VARIABLE(c); return true; }
bool is_digit   ( char c ) { return '0' <= c && c <= '9'; }
bool is_lower   ( char c ) { return 'a' <= c && c <= 'z'; }
bool is_upper   ( char c ) { return 'A' <= c && c <= 'Z'; }
bool is_alpha   ( char c ) { return is_lower(c) || is_upper(c); }
bool is_alnum   ( char c ) { return is_alpha(c) || is_digit(c); }
bool is_letter  ( char c ) { return is_alpha(c) || c == '_'; }

extern Val satisfy_run( Val pred_, Val psrc_ );

static Val satisfy_run_delegate( int n, const Val* args[] )
{
    assert( n == 2 );
    return satisfy_run( *args[0], *args[1] );
}

static FnSt satisfy_fn0 = {
    .ref_cnt = -1,
    .depth   = 0,
    .funcptr = satisfy_run_delegate,
};

#define DEF_PREDICATE_PARSER( name, pred )              \
    static FnSt pred ## _fn = {                         \
        .ref_cnt = -1,                                  \
        .depth   = 1,                                   \
        .fx.f    = &satisfy_fn0,                        \
        .fx.x    = VAL_INIT(PREDICATE)(pred),           \
    };                                                  \
    static ParserSt name ## _ = {                       \
        .ref_cnt = -1,                                  \
        .run     = { &(pred ## _fn) },                  \
    };                                                  \
    const Parser name = &name ## _

DEF_PREDICATE_PARSER( any_char, is_any_char );
DEF_PREDICATE_PARSER( digit   , is_digit    );
DEF_PREDICATE_PARSER( lower   , is_lower    );
DEF_PREDICATE_PARSER( upper   , is_upper    );
DEF_PREDICATE_PARSER( alpha   , is_alpha    );
DEF_PREDICATE_PARSER( alnum   , is_alnum    );
DEF_PREDICATE_PARSER( letter  , is_letter   );
