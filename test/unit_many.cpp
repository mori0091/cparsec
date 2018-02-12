/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include <string>
#include "catch.hpp"

#include "cparsec.h"

SCENARIO( "'many' parser combinator", "[cparsec][many]" ) {
    GIVEN( "Parser a = char1('a')" ) {
        Parser a = char1('a');
        WHEN( "parse( many(a), \"\")" ) {
            const char* input  = "";
            std::string expect = "";
            Val ret = parse( many(a), input );
            THEN( "results a string \"" + expect + "\"" ) {
                REQUIRE( ret.type == STRING );
                REQUIRE( expect == ret.str );
            }
            Val_del( &ret );
        }
        WHEN( "parse( many(a), \"a\")" ) {
            const char* input  = "a";
            std::string expect = "a";
            Val ret = parse( many(a), input );
            THEN( "results a string \"" + expect + "\"" ) {
                REQUIRE( ret.type == STRING );
                REQUIRE( expect == ret.str );
            }
            Val_del( &ret );
        }
        WHEN( "parse( many(a), \"b\")" ) {
            const char* input  = "b";
            std::string expect = "";
            Val ret = parse( many(a), input );
            THEN( "results a string \"" + expect + "\"" ) {
                REQUIRE( ret.type == STRING );
                REQUIRE( expect == ret.str );
            }
            Val_del( &ret );
        }
        WHEN( "parse( many(a), \"c\")" ) {
            const char* input  = "c";
            std::string expect = "";
            Val ret = parse( many(a), input );
            THEN( "results a string \"" + expect + "\"" ) {
                REQUIRE( ret.type == STRING );
                REQUIRE( expect == ret.str );
            }
            Val_del( &ret );
        }
        WHEN( "parse( many(a), \"ab\")" ) {
            const char* input  = "ab";
            std::string expect = "a";
            Val ret = parse( many(a), input );
            THEN( "results a string \"" + expect + "\"" ) {
                REQUIRE( ret.type == STRING );
                REQUIRE( expect == ret.str );
            }
            Val_del( &ret );
        }
        WHEN( "parse( many(a), \"abc\")" ) {
            const char* input  = "abc";
            std::string expect = "a";
            Val ret = parse( many(a), input );
            THEN( "results a string \"" + expect + "\"" ) {
                REQUIRE( ret.type == STRING );
                REQUIRE( expect == ret.str );
            }
            Val_del( &ret );
        }
        WHEN( "parse( many(a), \"ac\")" ) {
            const char* input  = "ac";
            std::string expect = "a";
            Val ret = parse( many(a), input );
            THEN( "results a string \"" + expect + "\"" ) {
                REQUIRE( ret.type == STRING );
                REQUIRE( expect == ret.str );
            }
            Val_del( &ret );
        }
        WHEN( "parse( many(a), \"ba\")" ) {
            const char* input  = "ba";
            std::string expect = "";
            Val ret = parse( many(a), input );
            THEN( "results a string \"" + expect + "\"" ) {
                REQUIRE( ret.type == STRING );
                REQUIRE( expect == ret.str );
            }
            Val_del( &ret );
        }
        WHEN( "parse( many(a), \"bab\")" ) {
            const char* input  = "bab";
            std::string expect = "";
            Val ret = parse( many(a), input );
            THEN( "results a string \"" + expect + "\"" ) {
                REQUIRE( ret.type == STRING );
                REQUIRE( expect == ret.str );
            }
            Val_del( &ret );
        }
        WHEN( "parse( many(a), \"aaa\")" ) {
            const char* input  = "aaa";
            std::string expect = "aaa";
            Val ret = parse( many(a), input );
            THEN( "results a string \"" + expect + "\"" ) {
                REQUIRE( ret.type == STRING );
                REQUIRE( expect == ret.str );
            }
            Val_del( &ret );
        }
        WHEN( "parse( many(a), \"aaabbb\")" ) {
            const char* input  = "aaabbb";
            std::string expect = "aaa";
            Val ret = parse( many(a), input );
            THEN( "results a string \"" + expect + "\"" ) {
                REQUIRE( ret.type == STRING );
                REQUIRE( expect == ret.str );
            }
            Val_del( &ret );
        }
        Parser_del( a );
    }
}
