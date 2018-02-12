/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include <string>
#include "catch.hpp"

#include "cparsec.h"

SCENARIO( "Tests each char-type parsers for all chars", "[cparsec][chars]" ) {
    WHEN( "parser was 'any_char'") {
        Parser p = any_char;
        THEN( "passes any except for '\0'" ) {
            for ( int c = 0; c < 256; ++c ) {
                const char src[] = { (char)c, '\0' };
                Val ret = parse( p, src );
                if ( '\0' != c ) {
                    REQUIRE( ret.type == CHAR );
                    REQUIRE( ret.c == (char)c );
                }
                else {
                    REQUIRE( ret.type == ERROR );
                    CHECK( ret.error );
                }
                Val_del( &ret );
            }
        }
    }
    WHEN( "parser was 'digit'") {
        Parser p = digit;
        THEN( "passes only '0'..'9'" ) {
            for ( int c = 0; c < 256; ++c ) {
                const char src[] = { (char)c, '\0' };
                Val ret = parse( p, src );
                if ( '0' <= c && c <= '9' ) {
                    REQUIRE( ret.type == CHAR );
                    REQUIRE( ret.c == (char)c );
                }
                else {
                    REQUIRE( ret.type == ERROR );
                    CHECK( ret.error );
                }
                Val_del( &ret );
            }
        }
    }
    WHEN( "parser was 'lower'") {
        Parser p = lower;
        THEN( "passes only 'a'..'z'" ) {
            for ( int c = 0; c < 256; ++c ) {
                const char src[] = { (char)c, '\0' };
                Val ret = parse( p, src );
                if ( 'a' <= c && c <= 'z' ) {
                    REQUIRE( ret.type == CHAR );
                    REQUIRE( ret.c == (char)c );
                }
                else {
                    REQUIRE( ret.type == ERROR );
                    CHECK( ret.error );
                }
                Val_del( &ret );
            }
        }
    }
    WHEN( "parser was 'upper'") {
        Parser p = upper;
        THEN( "passes only 'A'..'Z'" ) {
            for ( int c = 0; c < 256; ++c ) {
                const char src[] = { (char)c, '\0' };
                Val ret = parse( p, src );
                if ( 'A' <= c && c <= 'Z' ) {
                    REQUIRE( ret.type == CHAR );
                    REQUIRE( ret.c == (char)c );
                }
                else {
                    REQUIRE( ret.type == ERROR );
                    CHECK( ret.error );
                }
                Val_del( &ret );
            }
        }
    }
    WHEN( "parser was 'alpha'") {
        Parser p = alpha;
        THEN( "passes only 'a'..'z','A'..'Z'" ) {
            for ( int c = 0; c < 256; ++c ) {
                const char src[] = { (char)c, '\0' };
                Val ret = parse( p, src );
                if (( 'a' <= c && c <= 'z' ) ||
                    ( 'A' <= c && c <= 'Z' )) {
                    REQUIRE( ret.type == CHAR );
                    REQUIRE( ret.c == (char)c );
                }
                else {
                    REQUIRE( ret.type == ERROR );
                    CHECK( ret.error );
                }
                Val_del( &ret );
            }
        }
    }
    WHEN( "parser was 'alnum'") {
        Parser p = alnum;
        THEN( "passes only 'a'..'z','A'..'Z','0-9'" ) {
            for ( int c = 0; c < 256; ++c ) {
                const char src[] = { (char)c, '\0' };
                Val ret = parse( p, src );
                if (( 'a' <= c && c <= 'z' ) ||
                    ( 'A' <= c && c <= 'Z' ) ||
                    ( '0' <= c && c <= '9' )) {
                    REQUIRE( ret.type == CHAR );
                    REQUIRE( ret.c == (char)c );
                }
                else {
                    REQUIRE( ret.type == ERROR );
                    CHECK( ret.error );
                }
                Val_del( &ret );
            }
        }
    }
    WHEN( "parser was 'letter'") {
        Parser p = letter;
        THEN( "passes only 'a'..'z','A'..'Z','_'" ) {
            for ( int c = 0; c < 256; ++c ) {
                const char src[] = { (char)c, '\0' };
                Val ret = parse( p, src );
                if (( 'a' <= c && c <= 'z' ) ||
                    ( 'A' <= c && c <= 'Z' ) ||
                    ( '_' == c )) {
                    REQUIRE( ret.type == CHAR );
                    REQUIRE( ret.c == (char)c );
                }
                else {
                    REQUIRE( ret.type == ERROR );
                    CHECK( ret.error );
                }
                Val_del( &ret );
            }
        }
    }
    REQUIRE( 0 == Parser_live_count() );
}
