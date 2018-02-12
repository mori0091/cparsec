/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include <string>
#include "catch.hpp"

#include "cparsec.h"

SCENARIO( "'number' parser combinator", "[cparsec][number]" ) {
    WHEN( "parse( number, \"\")" ) {
        const char* input  = "";
        Val ret = parse( number, input );
        REQUIRE( 0 == Parser_live_count() );
        THEN( "results an error" ) {
            REQUIRE( ret.type == ERROR );
            CHECK( ret.error );
        }
        Val_del( &ret );
    }
    WHEN( "parse( number, \"a\")" ) {
        const char* input  = "a";
        Val ret = parse( number, input );
        REQUIRE( 0 == Parser_live_count() );
        THEN( "results an error" ) {
            REQUIRE( ret.type == ERROR );
            CHECK( ret.error );
        }
        Val_del( &ret );
    }
    WHEN( "parse( number, \"b\")" ) {
        const char* input  = "b";
        Val ret = parse( number, input );
        REQUIRE( 0 == Parser_live_count() );
        THEN( "results an error" ) {
            REQUIRE( ret.type == ERROR );
            CHECK( ret.error );
        }
        Val_del( &ret );
    }
    WHEN( "parse( number, \"c\")" ) {
        const char* input  = "c";
        Val ret = parse( number, input );
        REQUIRE( 0 == Parser_live_count() );
        THEN( "results an error" ) {
            REQUIRE( ret.type == ERROR );
            CHECK( ret.error );
        }
        Val_del( &ret );
    }
    WHEN( "parse( number, \"1\")" ) {
        const char* input  = "1";
        int expect = 1;
        Val ret = parse( number, input );
        REQUIRE( 0 == Parser_live_count() );
        THEN( "results an int 1" ) {
            REQUIRE( ret.type == INT );
            REQUIRE( expect == ret.i );
        }
        Val_del( &ret );
    }
    WHEN( "parse( number, \"123\")" ) {
        const char* input  = "123";
        int expect = 123;
        Val ret = parse( number, input );
        REQUIRE( 0 == Parser_live_count() );
        THEN( "results an int 123" ) {
            REQUIRE( ret.type == INT );
            REQUIRE( expect == ret.i );
        }
        Val_del( &ret );
    }
    WHEN( "parse( number, \"1a\")" ) {
        const char* input  = "1a";
        int expect = 1;
        Val ret = parse( number, input );
        REQUIRE( 0 == Parser_live_count() );
        THEN( "results an int 1" ) {
            REQUIRE( ret.type == INT );
            REQUIRE( expect == ret.i );
        }
        Val_del( &ret );
    }
    WHEN( "parse( number, \"-1\")" ) {
        const char* input  = "-1";
        Val ret = parse( number, input );
        REQUIRE( 0 == Parser_live_count() );
        THEN( "results an error" ) {
            REQUIRE( ret.type == ERROR );
            CHECK( ret.error );
        }
        Val_del( &ret );
    }
    REQUIRE( 0 == Parser_live_count() );
}
