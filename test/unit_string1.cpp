/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include <string>
#include "catch.hpp"

#include "cparsec.h"

SCENARIO( "'string1' parser", "[cparsec][string1]" ) {
    Parser p = string1( "abc" );
    WHEN( "parse( string1(\"abc\"), NULL )" ) {
        Val result = parse( p, NULL );
        THEN( "result an error" ) {
            REQUIRE( ERROR == result.type );
            CHECK( result.error );
        }
        Val_del( &result );
    }
    WHEN( "parse( string1(\"abc\"), \"\" )" ) {
        Val result = parse( p, "" );
        THEN( "result an error" ) {
            REQUIRE( ERROR == result.type );
            CHECK( result.error );
        }
        Val_del( &result );
    }
    WHEN( "parse( string1(\"abc\"), \"0\" )" ) {
        Val result = parse( p, "0" );
        THEN( "result an error" ) {
            REQUIRE( ERROR == result.type );
            CHECK( result.error );
        }
        Val_del( &result );
    }
    WHEN( "parse( string1(\"abc\"), \"a\" )" ) {
        Val result = parse( p, "a" );
        THEN( "result an error" ) {
            REQUIRE( ERROR == result.type );
            CHECK( result.error );
        }
        Val_del( &result );
    }
    WHEN( "parse( string1(\"abc\"), \"A\" )" ) {
        Val result = parse( p, "A" );
        THEN( "result an error" ) {
            REQUIRE( ERROR == result.type );
            CHECK( result.error );
        }
        Val_del( &result );
    }
    WHEN( "parse( string1(\"abc\"), \"ab\" )" ) {
        Val result = parse( p, "ab" );
        THEN( "result an error" ) {
            REQUIRE( ERROR == result.type );
            CHECK( result.error );
        }
        Val_del( &result );
    }
    WHEN( "parse( string1(\"abc\"), \"abc\" )" ) {
        Val result = parse( p, "abc" );
        THEN( "result is (const char*)\"abc\"" ) {
            REQUIRE( STRING == result.type );
            REQUIRE( std::string("abc") == result.str );
        }
        Val_del( &result );
    }
    WHEN( "parse( string1(\"abc\"), \"abcd\" )" ) {
        Val result = parse( p, "abcd" );
        THEN( "result is (const char*)\"abc\"" ) {
            REQUIRE( STRING == result.type );
            REQUIRE( std::string("abc") == result.str );
        }
        Val_del( &result );
    }
    WHEN( "parse( string1(\"abc\"), \"abx\" )" ) {
        Val result = parse( p, "abx" );
        THEN( "result an error" ) {
            REQUIRE( ERROR == result.type );
            CHECK( result.error );
        }
        Val_del( &result );
    }
    Parser_del( p );
}
