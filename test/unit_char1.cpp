/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include <string>
#include "catch.hpp"

#include "cparsec.h"

SCENARIO( "'char1' parser", "[cparsec][char1]" ) {
    GIVEN( "Parser p = char1( 'a' )" ) {
        // Parser p = Parser_ref( char1( 'a' ) );
        Parser p = char1( 'a' );
        REQUIRE( 1 == Parser_live_count() );
        WHEN( "parse( char1('a'), NULL )" ) {
            Val result = parse( p, NULL );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "result an error" ) {
                REQUIRE( ERROR == result.type );
                CHECK( result.error );
            }
            Val_del( &result );
        }
        WHEN( "parse( char1('a'), \"\" )" ) {
            Val result = parse( p, "" );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "result an error" ) {
                REQUIRE( ERROR == result.type );
                CHECK( result.error );
            }
            Val_del( &result );
        }
        WHEN( "parse( char1('a'), \"0\" )" ) {
            Val result = parse( p, "0" );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "result an error" ) {
                REQUIRE( ERROR == result.type );
                CHECK( result.error );
            }
            Val_del( &result );
        }
        WHEN( "parse( char1('a'), \"a\" )" ) {
            Val result = parse( p, "a" );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "result is (char)'a'" ) {
                REQUIRE( CHAR == result.type );
                REQUIRE( 'a' == result.c );
            }
            Val_del( &result );
        }
        WHEN( "parse( char1('a'), \"A\" )" ) {
            Val result = parse( p, "A" );
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
