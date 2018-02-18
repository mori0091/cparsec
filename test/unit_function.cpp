/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include <string>
#include "catch.hpp"

#include "cparsec.h"
#include "cparsec/core/function.h"

static Val add( int n, const Val* args[] ) {
    int ret = 0;
    for ( int i = 0; i < n; ++i ) {
        assert( INT == args[i]->type );
        ret += args[i]->i;
    }
    return VAL(INT)(ret);
}

static Val mul10_plus_x( int n, const Val* args[] ) {
    int ret = 0;
    for ( int i = 0; i < n; ++i ) {
        assert( INT == args[i]->type );
        ret = ret * 10 + args[i]->i;
    }
    return VAL(INT)(ret);
}

SCENARIO( "Tests function object type of Fn", "[cparsec][fn]" ) {
    GIVEN( "Val add( int n, Val* args[] ) - returns sum of 'n' integers" ) {
        WHEN( "Fn_eval( fn(add) )" ) {
            Val ret = Fn_eval( fn(add) );
            REQUIRE( 0 == Fn_live_count() );
            THEN( "results an int 0" ) {
                REQUIRE( INT == ret.type );
                REQUIRE( 0 == ret.i );
            }
        }
        WHEN( "Fn_eval( Fn_bind( fn(add), 10 ) )" ) {
            Val ret = Fn_eval( Fn_bind( fn(add), 10 ) );
            REQUIRE( 0 == Fn_live_count() );
            THEN( "results an int 10" ) {
                REQUIRE( INT == ret.type );
                REQUIRE( 10 == ret.i );
            }
        }
    }
    GIVEN( "Fn add10 = Fn_bind( fn( add ), 10 )" ) {
        Fn add10 = Fn_bind( fn(add), 10 );
        REQUIRE( 2 == Fn_live_count() );
        WHEN( "Fn_eval( Fn_bind( add10, 20 ) )" ) {
            Val ret = Fn_eval( Fn_bind( add10, 20 ) );
            REQUIRE( 0 == Fn_live_count() );
            THEN( "results an int 30" ) {
                REQUIRE( INT == ret.type );
                REQUIRE( 30 == ret.i );
            }
        }
    }
    GIVEN( "Fn f = fn(mul10_plus_x)" ) {
        Fn f = fn(mul10_plus_x);
        REQUIRE( 1 == Fn_live_count() );
        WHEN( "Fn_eval( Fn_bind( f, 1, 2, 3 ) )" ) {
            Val ret = Fn_eval( Fn_bind( f, 1, 2, 3 ) );
            REQUIRE( 0 == Fn_live_count() );
            THEN( "results an int 123" ) {
                REQUIRE( INT == ret.type );
                REQUIRE( 123 == ret.i );
            }
        }
        WHEN( "Fn_eval( Fn_bind( f, 3, 2, 1 ) )" ) {
            Val ret = Fn_eval( Fn_bind( f, 3, 2, 1 ) );
            REQUIRE( 0 == Fn_live_count() );
            THEN( "results an int 321" ) {
                REQUIRE( INT == ret.type );
                REQUIRE( 321 == ret.i );
            }
        }
    }
    REQUIRE( 0 == Fn_live_count() );
}
