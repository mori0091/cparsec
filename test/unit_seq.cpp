/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include <string>
#include "catch.hpp"

#include "cparsec.h"

SCENARIO( "'seq' parser combinator", "[cparsec][seq]" ) {
    GIVEN( "Parser a = char1('a'), b = char1('b')" ) {
        // Parser a = Parser_ref( char1('a') );
        // Parser b = Parser_ref( char1('b') );
        Parser a = char1('a');
        Parser b = char1('b');
        REQUIRE( 2 == Parser_live_count() );
        WHEN( "parse( seq(a,b), \"\")" ) {
            const char* input  = "";
            Val ret = parse( seq(a,b), input );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results an error" ) {
                REQUIRE( ret.type == ERROR );
                CHECK( ret.error );
            }
            Val_del( &ret );
        }
        WHEN( "parse( seq(a,b), \"a\")" ) {
            const char* input  = "a";
            Val ret = parse( seq(a,b), input );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results an error" ) {
                REQUIRE( ret.type == ERROR );
                CHECK( ret.error );
            }
            Val_del( &ret );
        }
        WHEN( "parse( seq(a,b), \"b\")" ) {
            const char* input  = "b";
            Val ret = parse( seq(a,b), input );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results an error" ) {
                REQUIRE( ret.type == ERROR );
                CHECK( ret.error );
            }
            Val_del( &ret );
        }
        WHEN( "parse( either(a,b), \"c\")" ) {
            const char* input  = "c";
            Val ret = parse( either(a,b), input );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results an error" ) {
                REQUIRE( ret.type == ERROR );
                CHECK( ret.error );
            }
            Val_del( &ret );
        }
        WHEN( "parse( seq(a,b), \"ab\")" ) {
            const char* input  = "ab";
            std::string expect = "ab";
            Val ret = parse( seq(a,b), input );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results a string \"" + expect + "\"" ) {
                REQUIRE( ret.type == STRING );
                REQUIRE( expect == ret.str );
            }
            Val_del( &ret );
        }
        WHEN( "parse( seq(a,b), \"abc\")" ) {
            const char* input  = "abc";
            std::string expect = "ab";
            Val ret = parse( seq(a,b), input );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results a string \"" + expect + "\"" ) {
                REQUIRE( ret.type == STRING );
                REQUIRE( expect == ret.str );
            }
            Val_del( &ret );
        }
        WHEN( "parse( seq(a,b), \"ac\")" ) {
            const char* input  = "ac";
            Val ret = parse( seq(a,b), input );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results an error" ) {
                REQUIRE( ret.type == ERROR );
                CHECK( ret.error );
            }
            Val_del( &ret );
        }
        WHEN( "parse( seq(a,b), \"ba\")" ) {
            const char* input  = "ba";
            Val ret = parse( seq(a,b), input );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results an error" ) {
                REQUIRE( ret.type == ERROR );
                CHECK( ret.error );
            }
            Val_del( &ret );
        }
        WHEN( "parse( seq(a,b), \"bab\")" ) {
            const char* input  = "bab";
            Val ret = parse( seq(a,b), input );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results an error" ) {
                REQUIRE( ret.type == ERROR );
                CHECK( ret.error );
            }
            Val_del( &ret );
        }
        // Parser_unref( a );
        // Parser_unref( b );
    }
    REQUIRE( 0 == Parser_live_count() );
}
