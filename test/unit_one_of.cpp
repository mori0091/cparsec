/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include <string>
#include "catch.hpp"

#include "cparsec.h"

SCENARIO( "'one_of' parser combinator", "[cparsec][one_of]" ) {
    GIVEN( "Parser sign = one_of( \"+-\" )" ) {
        Parser sign = one_of( "+-" );
        REQUIRE( 1 == Parser_live_count() );
        WHEN( "parse( seq( sign, number ), \"123\" )" ) {
            const char* input = "123";
            Val ret = parse( seq( sign, number ), input );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results an error" ) {
                REQUIRE( ERROR == ret.type );
                CHECK( ret.error );
            }
            Val_del( &ret );
        }
        WHEN( "parse( seq( sign, number ), \"+123\" )" ) {
            const char* input = "+123";
            Val ret = parse( seq( sign, number ), input );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results a string \"+123\"" ) {
                REQUIRE( STRING == ret.type );
                REQUIRE( std::string("+123") == ret.str );
            }
            Val_del( &ret );
        }
        WHEN( "parse( seq( sign, number ), \"-123\" )" ) {
            const char* input = "-123";
            Val ret = parse( seq( sign, number ), input );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results a string \"-123\"" ) {
                REQUIRE( STRING == ret.type );
                REQUIRE( std::string("-123") == ret.str );
            }
            Val_del( &ret );
        }
        WHEN( "parse( seq( sign, number ), \"*123\" )" ) {
            const char* input = "*123";
            Val ret = parse( seq( sign, number ), input );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results an error" ) {
                REQUIRE( ERROR == ret.type );
                CHECK( ret.error );
            }
            Val_del( &ret );
        }
    }
    REQUIRE( 0 == Parser_live_count() );
}
