/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include <string>
#include "catch.hpp"

#include "cparsec.h"

SCENARIO( "'tryp' parser combinator", "[cparsec][tryp][either]" ) {
    GIVEN( "Parser ab = string1(\"ab\") and Parser ac = string1(\"ac\")" ) {
        Parser ab = string1( "ab" );
        Parser ac = string1( "ac" );
        WHEN( "parse( either( ab, ac ), \"ab\" )" ) {
            Val ret = parse( either( ab, ac ), "ab" );
            std::string expect = "ab";
            THEN( "results a string \"ab\"" ) {
                REQUIRE( STRING == ret.type );
                REQUIRE( expect == ret.str );
            }
            Val_del( &ret );
        }
        WHEN( "parse( either( ab, ac ), \"ac\" )" ) {
            Val ret = parse( either( ab, ac ), "ac" );
            THEN( "results an error" ) {
                REQUIRE( ERROR == ret.type );
                CHECK( ret.error );
            }
            Val_del( &ret );
        }
        WHEN( "parse( either( tryp(ab), ac ), \"ab\" )" ) {
            Val ret = parse( either( tryp(ab), ac ), "ab" );
            std::string expect = "ab";
            THEN( "results a string \"ab\"" ) {
                REQUIRE( STRING == ret.type );
                REQUIRE( expect == ret.str );
            }
            Val_del( &ret );
        }
        WHEN( "parse( either( tryp(ab), ac ), \"ac\" )" ) {
            Val ret = parse( either( tryp(ab), ac ), "ac" );
            std::string expect = "ac";
            THEN( "results a string \"ac\"" ) {
                REQUIRE( STRING == ret.type );
                REQUIRE( expect == ret.str );
            }
            Val_del( &ret );
        }
    }
}
