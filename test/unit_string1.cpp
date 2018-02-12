/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include <string>
#include "catch.hpp"

#include "cparsec.h"

SCENARIO( "'string1' parser", "[cparsec][string1]" ) {
    GIVEN( "Parser p = string1( \"abc\" )" ) {
        // Parser p = Parser_ref( string1( "abc" ) );
        Parser p = string1( "abc" );
        REQUIRE( 1 == Parser_live_count() );
        WHEN( "parse( string1(\"abc\"), NULL )" ) {
            Val result = parse( p, NULL );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "result an error" ) {
                REQUIRE( ERROR == result.type );
                CHECK( result.error );
            }
            Val_del( &result );
        }
        WHEN( "parse( string1(\"abc\"), \"\" )" ) {
            Val result = parse( p, "" );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "result an error" ) {
                REQUIRE( ERROR == result.type );
                CHECK( result.error );
            }
            Val_del( &result );
        }
        WHEN( "parse( string1(\"abc\"), \"0\" )" ) {
            Val result = parse( p, "0" );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "result an error" ) {
                REQUIRE( ERROR == result.type );
                CHECK( result.error );
            }
            Val_del( &result );
        }
        WHEN( "parse( string1(\"abc\"), \"a\" )" ) {
            Val result = parse( p, "a" );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "result an error" ) {
                REQUIRE( ERROR == result.type );
                CHECK( result.error );
            }
            Val_del( &result );
        }
        WHEN( "parse( string1(\"abc\"), \"A\" )" ) {
            Val result = parse( p, "A" );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "result an error" ) {
                REQUIRE( ERROR == result.type );
                CHECK( result.error );
            }
            Val_del( &result );
        }
        WHEN( "parse( string1(\"abc\"), \"ab\" )" ) {
            Val result = parse( p, "ab" );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "result an error" ) {
                REQUIRE( ERROR == result.type );
                CHECK( result.error );
            }
            Val_del( &result );
        }
        WHEN( "parse( string1(\"abc\"), \"abc\" )" ) {
            Val result = parse( p, "abc" );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "result is (const char*)\"abc\"" ) {
                REQUIRE( STRING == result.type );
                REQUIRE( std::string("abc") == result.str );
            }
            Val_del( &result );
        }
        WHEN( "parse( string1(\"abc\"), \"abcd\" )" ) {
            Val result = parse( p, "abcd" );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "result is (const char*)\"abc\"" ) {
                REQUIRE( STRING == result.type );
                REQUIRE( std::string("abc") == result.str );
            }
            Val_del( &result );
        }
        WHEN( "parse( string1(\"abc\"), \"abx\" )" ) {
            Val result = parse( p, "abx" );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "result an error" ) {
                REQUIRE( ERROR == result.type );
                CHECK( result.error );
            }
            Val_del( &result );
        }
        // Parser_unref( p );
    }
    REQUIRE( 0 == Parser_live_count() );
}
