/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include <string>
#include "catch.hpp"

#include "cparsec.h"

SCENARIO( "'either' parser combinator", "[cparsec][either]" ) {
    GIVEN( "Parser a = char1('a'), b = char1('b')" ) {
        Parser a = char1('a');
        Parser b = char1('b');
        WHEN( "parse( either(a,b), \"\")" ) {
            const char* input = "";
            Val ret = parse( either(a,b), input );
            THEN( "results an error" ) {
                REQUIRE( ret.type == ERROR );
                CHECK( ret.error );
            }
            Val_del( &ret );
        }
        WHEN( "parse( either(a,b), \"a\")" ) {
            const char* input = "a";
            const char expect = 'a';
            Val ret = parse( either(a,b), input );
            THEN( std::string("") + "results a char'" + expect + "'" ) {
                REQUIRE( ret.type == CHAR );
                REQUIRE( expect == ret.c );
            }
            Val_del( &ret );
        }
        WHEN( "parse( either(a,b), \"b\")" ) {
            const char* input = "b";
            const char expect = 'b';
            Val ret = parse( either(a,b), input );
            THEN( std::string("") + "results a char'" + expect + "'" ) {
                REQUIRE( ret.type == CHAR );
                REQUIRE( expect == ret.c );
            }
            Val_del( &ret );
        }
        WHEN( "parse( either(a,b), \"c\")" ) {
            const char* input = "c";
            Val ret = parse( either(a,b), input );
            THEN( "results an error" ) {
                REQUIRE( ret.type == ERROR );
                CHECK( ret.error );
            }
            Val_del( &ret );
        }
        WHEN( "parse( either(a,b), \"ab\")" ) {
            const char* input = "ab";
            const char expect = 'a';
            Val ret = parse( either(a,b), input );
            THEN( std::string("") + "results a char'" + expect + "'" ) {
                REQUIRE( ret.type == CHAR );
                REQUIRE( expect == ret.c );
            }
            Val_del( &ret );
        }
        WHEN( "parse( either(a,b), \"abc\")" ) {
            const char* input = "abc";
            const char expect = 'a';
            Val ret = parse( either(a,b), input );
            THEN( std::string("") + "results a char'" + expect + "'" ) {
                REQUIRE( ret.type == CHAR );
                REQUIRE( expect == ret.c );
            }
            Val_del( &ret );
        }
        WHEN( "parse( either(a,b), \"ac\")" ) {
            const char* input = "ac";
            const char expect = 'a';
            Val ret = parse( either(a,b), input );
            THEN( std::string("") + "results a char'" + expect + "'" ) {
                REQUIRE( ret.type == CHAR );
                REQUIRE( expect == ret.c );
            }
            Val_del( &ret );
        }
        WHEN( "parse( either(a,b), \"ba\")" ) {
            const char* input = "ba";
            const char expect = 'b';
            Val ret = parse( either(a,b), input );
            THEN( std::string("") + "results a char'" + expect + "'" ) {
                REQUIRE( ret.type == CHAR );
                REQUIRE( expect == ret.c );
            }
            Val_del( &ret );
        }
        WHEN( "parse( either(a,b), \"bab\")" ) {
            const char* input = "bab";
            const char expect = 'b';
            Val ret = parse( either(a,b), input );
            THEN( std::string("") + "results a char'" + expect + "'" ) {
                REQUIRE( ret.type == CHAR );
                REQUIRE( expect == ret.c );
            }
            Val_del( &ret );
        }
        Parser_del( a );
        Parser_del( b );
    }
}
