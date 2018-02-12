/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include <string>
#include "catch.hpp"

#include "cparsec.h"

SCENARIO( "'rep' parser combinator", "[cparsec][rep]" ) {
    GIVEN( "Parser a = char1('a')" ) {
        // Parser a = Parser_ref( char1('a') );
        Parser a = char1('a');
        REQUIRE( 1 == Parser_live_count() );
        WHEN( "parse( rep(3,a), \"\")" ) {
            const char* input  = "";
            Val ret = parse( rep(3,a), input );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results an error" ) {
                REQUIRE( ret.type == ERROR );
                CHECK( ret.error );
            }
            Val_del( &ret );
        }
        WHEN( "parse( rep(3,a), \"a\")" ) {
            const char* input  = "a";
            Val ret = parse( rep(3,a), input );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results an error" ) {
                REQUIRE( ret.type == ERROR );
                CHECK( ret.error );
            }
            Val_del( &ret );
        }
        WHEN( "parse( rep(3,a), \"b\")" ) {
            const char* input  = "b";
            Val ret = parse( rep(3,a), input );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results an error" ) {
                REQUIRE( ret.type == ERROR );
                CHECK( ret.error );
            }
            Val_del( &ret );
        }
        WHEN( "parse( rep(3,a), \"c\")" ) {
            const char* input  = "c";
            Val ret = parse( rep(3,a), input );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results an error" ) {
                REQUIRE( ret.type == ERROR );
                CHECK( ret.error );
            }
            Val_del( &ret );
        }
        WHEN( "parse( rep(3,a), \"ab\")" ) {
            const char* input  = "ab";
            Val ret = parse( rep(3,a), input );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results an error" ) {
                REQUIRE( ret.type == ERROR );
                CHECK( ret.error );
            }
            Val_del( &ret );
        }
        WHEN( "parse( rep(3,a), \"abc\")" ) {
            const char* input  = "abc";
            Val ret = parse( rep(3,a), input );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results an error" ) {
                REQUIRE( ret.type == ERROR );
                CHECK( ret.error );
            }
            Val_del( &ret );
        }
        WHEN( "parse( rep(3,a), \"ac\")" ) {
            const char* input  = "ac";
            Val ret = parse( rep(3,a), input );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results an error" ) {
                REQUIRE( ret.type == ERROR );
                CHECK( ret.error );
            }
            Val_del( &ret );
        }
        WHEN( "parse( rep(3,a), \"ba\")" ) {
            const char* input  = "ba";
            Val ret = parse( rep(3,a), input );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results an error" ) {
                REQUIRE( ret.type == ERROR );
                CHECK( ret.error );
            }
            Val_del( &ret );
        }
        WHEN( "parse( rep(3,a), \"bab\")" ) {
            const char* input  = "bab";
            Val ret = parse( rep(3,a), input );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results an error" ) {
                REQUIRE( ret.type == ERROR );
                CHECK( ret.error );
            }
            Val_del( &ret );
        }
        WHEN( "parse( rep(3,a), \"aa\")" ) {
            const char* input  = "aa";
            Val ret = parse( rep(3,a), input );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results an error" ) {
                REQUIRE( ret.type == ERROR );
                CHECK( ret.error );
            }
            Val_del( &ret );
        }
        WHEN( "parse( rep(3,a), \"aaa\")" ) {
            const char* input  = "aaa";
            std::string expect = "aaa";
            Val ret = parse( rep(3,a), input );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results a string \"" + expect + "\"" ) {
                REQUIRE( ret.type == STRING );
                REQUIRE( expect == ret.str );
            }
            Val_del( &ret );
        }
        WHEN( "parse( rep(3,a), \"aaaa\")" ) {
            const char* input  = "aaaa";
            std::string expect = "aaa";
            Val ret = parse( rep(3,a), input );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results a string \"" + expect + "\"" ) {
                REQUIRE( ret.type == STRING );
                REQUIRE( expect == ret.str );
            }
            Val_del( &ret );
        }
        WHEN( "parse( rep(3,a), \"aaabbb\")" ) {
            const char* input  = "aaabbb";
            std::string expect = "aaa";
            Val ret = parse( rep(3,a), input );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results a string \"" + expect + "\"" ) {
                REQUIRE( ret.type == STRING );
                REQUIRE( expect == ret.str );
            }
            Val_del( &ret );
        }
        // Parser_unref( a );
    }
    REQUIRE( 0 == Parser_live_count() );
}
