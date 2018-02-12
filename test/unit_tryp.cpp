/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include <string>
#include "catch.hpp"

#include "cparsec.h"

SCENARIO( "'tryp' parser combinator", "[cparsec][tryp][either]" ) {
    GIVEN( "Parser ab = string1(\"ab\") and Parser ac = string1(\"ac\")" ) {
        // Parser ab = Parser_ref( string1( "ab" ) );
        // Parser ac = Parser_ref( string1( "ac" ) );
        Parser ab = string1( "ab" );
        Parser ac = string1( "ac" );
        REQUIRE( 2 == Parser_live_count() );
        WHEN( "parse( either( ab, ac ), \"ab\" )" ) {
            Val ret = parse( either( ab, ac ), "ab" );
            REQUIRE( 0 == Parser_live_count() );
            std::string expect = "ab";
            THEN( "results a string \"ab\"" ) {
                REQUIRE( STRING == ret.type );
                REQUIRE( expect == ret.str );
            }
            Val_del( &ret );
        }
        WHEN( "parse( either( ab, ac ), \"ac\" )" ) {
            Val ret = parse( either( ab, ac ), "ac" );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results an error" ) {
                REQUIRE( ERROR == ret.type );
                CHECK( ret.error );
            }
            Val_del( &ret );
        }
        WHEN( "parse( either( tryp(ab), ac ), \"ab\" )" ) {
            Val ret = parse( either( tryp(ab), ac ), "ab" );
            REQUIRE( 0 == Parser_live_count() );
            std::string expect = "ab";
            THEN( "results a string \"ab\"" ) {
                REQUIRE( STRING == ret.type );
                REQUIRE( expect == ret.str );
            }
            Val_del( &ret );
        }
        WHEN( "parse( either( tryp(ab), ac ), \"ac\" )" ) {
            Val ret = parse( either( tryp(ab), ac ), "ac" );
            REQUIRE( 0 == Parser_live_count() );
            std::string expect = "ac";
            THEN( "results a string \"ac\"" ) {
                REQUIRE( STRING == ret.type );
                REQUIRE( expect == ret.str );
            }
            Val_del( &ret );
        }
        // Parser_unref( ab );
        // Parser_unref( ac );
    }
    REQUIRE( 0 == Parser_live_count() );
}
