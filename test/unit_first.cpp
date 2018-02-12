/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include <string>
#include "catch.hpp"

#include "cparsec.h"

SCENARIO( "'first' parser combinator", "[cparsec][first]" ) {
    GIVEN( "Parser a = char1('a')" ) {
        Parser a = char1('a');
        REQUIRE( 1 == Parser_live_count() );
        WHEN( "parse( first(a,number), \"\")" ) {
            const char* input  = "";
            Val ret = parse( first(a,number), input );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results an error" ) {
                REQUIRE( ret.type == ERROR );
                CHECK( ret.error );
            }
            Val_del( &ret );
        }
        WHEN( "parse( first(a,number), \"a\")" ) {
            const char* input  = "a";
            Val ret = parse( first(a,number), input );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results an error" ) {
                REQUIRE( ret.type == ERROR );
                CHECK( ret.error );
            }
            Val_del( &ret );
        }
        WHEN( "parse( first(a,number), \"1\")" ) {
            const char* input  = "1";
            Val ret = parse( first(a,number), input );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results an error" ) {
                REQUIRE( ret.type == ERROR );
                CHECK( ret.error );
            }
            Val_del( &ret );
        }
        WHEN( "parse( first(a,number), \"a1\")" ) {
            const char* input  = "a1";
            char expect = 'a';
            Val ret = parse( first(a,number), input );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results a char 'a'" ) {
                REQUIRE( ret.type == CHAR );
                REQUIRE( expect == ret.c );
            }
            Val_del( &ret );
        }
    }
    REQUIRE( 0 == Parser_live_count() );
}
