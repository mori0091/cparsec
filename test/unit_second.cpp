/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include <string>
#include "catch.hpp"

#include "cparsec.h"

SCENARIO( "'second' parser combinator", "[cparsec][second]" ) {
    GIVEN( "Parser a = char1('a')" ) {
        Parser a = char1('a');
        REQUIRE( 1 == Parser_live_count() );
        WHEN( "parse( second(a,number), \"\")" ) {
            const char* input  = "";
            Val ret = parse( second(a,number), input );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results an error" ) {
                REQUIRE( ret.type == ERROR );
                CHECK( ret.error );
            }
            Val_del( &ret );
        }
        WHEN( "parse( second(a,number), \"a\")" ) {
            const char* input  = "a";
            Val ret = parse( second(a,number), input );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results an error" ) {
                REQUIRE( ret.type == ERROR );
                CHECK( ret.error );
            }
            Val_del( &ret );
        }
        WHEN( "parse( second(a,number), \"1\")" ) {
            const char* input  = "1";
            Val ret = parse( second(a,number), input );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results an error" ) {
                REQUIRE( ret.type == ERROR );
                CHECK( ret.error );
            }
            Val_del( &ret );
        }
        WHEN( "parse( second(a,number), \"a1\")" ) {
            const char* input  = "a1";
            int expect = 1;
            Val ret = parse( second(a,number), input );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results an int 1" ) {
                REQUIRE( ret.type == INT );
                REQUIRE( expect == ret.i );
            }
            Val_del( &ret );
        }
    }
    REQUIRE( 0 == Parser_live_count() );
}
