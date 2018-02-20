/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include <string>
#include "catch.hpp"

#include "cparsec.h"

SCENARIO( "'optional' parser combinator", "[cparsec][optional]" ) {
    GIVEN( "Parser a = char1('a')" ) {
        // Parser a = Parser_ref( char1('a') );
        Parser a = char1('a');
        REQUIRE( 1 == Parser_live_count() );
        WHEN( "parse( optional(a), \"\")" ) {
            const char* input  = "";
            Val ret = parse( optional(a), input );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results a null string \"\"" ) {
                REQUIRE( ret.type == STRING );
                REQUIRE( std::string("") == ret.str );
            }
            Val_del( &ret );
        }
        WHEN( "parse( optional(a), \"a\")" ) {
            const char* input  = "a";
            char expect = 'a';
            Val ret = parse( optional(a), input );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results a char 'a'" ) {
                REQUIRE( ret.type == CHAR );
                REQUIRE( expect == ret.c );
            }
            Val_del( &ret );
        }
        WHEN( "parse( optional(a), \"b\")" ) {
            const char* input  = "b";
            Val ret = parse( optional(a), input );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results a null string \"\"" ) {
                REQUIRE( ret.type == STRING );
                REQUIRE( std::string("") == ret.str );
            }
            Val_del( &ret );
        }
        WHEN( "parse( optional(a), \"c\")" ) {
            const char* input  = "c";
            Val ret = parse( optional(a), input );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results a null string \"\"" ) {
                REQUIRE( ret.type == STRING );
                REQUIRE( std::string("") == ret.str );
            }
            Val_del( &ret );
        }
        WHEN( "parse( optional(a), \"ab\")" ) {
            const char* input  = "ab";
            char expect = 'a';
            Val ret = parse( optional(a), input );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results a char 'a'" ) {
                REQUIRE( ret.type == CHAR );
                REQUIRE( expect == ret.c );
            }
            Val_del( &ret );
        }
        WHEN( "parse( optional(a), \"abc\")" ) {
            const char* input  = "abc";
            char expect = 'a';
            Val ret = parse( optional(a), input );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results a char 'a'" ) {
                REQUIRE( ret.type == CHAR );
                REQUIRE( expect == ret.c );
            }
            Val_del( &ret );
        }
        WHEN( "parse( optional(a), \"ac\")" ) {
            const char* input  = "ac";
            char expect = 'a';
            Val ret = parse( optional(a), input );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results a char 'a'" ) {
                REQUIRE( ret.type == CHAR );
                REQUIRE( expect == ret.c );
            }
            Val_del( &ret );
        }
        WHEN( "parse( optional(a), \"ba\")" ) {
            const char* input  = "ba";
            Val ret = parse( optional(a), input );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results a null string \"\"" ) {
                REQUIRE( ret.type == STRING );
                REQUIRE( std::string("") == ret.str );
            }
            Val_del( &ret );
        }
        WHEN( "parse( optional(a), \"bab\")" ) {
            const char* input  = "bab";
            Val ret = parse( optional(a), input );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results a null string \"\"" ) {
                REQUIRE( ret.type == STRING );
                REQUIRE( std::string("") == ret.str );
            }
            Val_del( &ret );
        }
        WHEN( "parse( optional(a), \"aa\")" ) {
            const char* input  = "aa";
            char expect = 'a';
            Val ret = parse( optional(a), input );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results a char 'a'" ) {
                REQUIRE( ret.type == CHAR );
                REQUIRE( expect == ret.c );
            }
            Val_del( &ret );
        }
        WHEN( "parse( optional(a), \"aaa\")" ) {
            const char* input  = "aaa";
            char expect = 'a';
            Val ret = parse( optional(a), input );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results a char 'a'" ) {
                REQUIRE( ret.type == CHAR );
                REQUIRE( expect == ret.c );
            }
            Val_del( &ret );
        }
        WHEN( "parse( optional(a), \"aaaa\")" ) {
            const char* input  = "aaaa";
            char expect = 'a';
            Val ret = parse( optional(a), input );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results a char 'a'" ) {
                REQUIRE( ret.type == CHAR );
                REQUIRE( expect == ret.c );
            }
            Val_del( &ret );
        }
        WHEN( "parse( optional(a), \"aaabbb\")" ) {
            const char* input  = "aaabbb";
            char expect = 'a';
            Val ret = parse( optional(a), input );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results a char 'a'" ) {
                REQUIRE( ret.type == CHAR );
                REQUIRE( expect == ret.c );
            }
            Val_del( &ret );
        }
        // Parser_unref( a );
    }
    GIVEN( "Parser sign = either( char1('+'), char1('-') )" ) {
        Parser sign = either( char1('+'), char1('-') );
        REQUIRE( 3 == Parser_live_count() );
        WHEN( "parse( seq( optional( sign ), number ), \"123\" )" ) {
            const char* input = "123";
            Val ret = parse( seq( optional( sign ), number ), input );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results a string \"123\"" ) {
                REQUIRE( STRING == ret.type );
                REQUIRE( std::string("123") == ret.str );
            }
            Val_del( &ret );
        }
        WHEN( "parse( seq( optional( sign ), number ), \"+123\" )" ) {
            const char* input = "+123";
            Val ret = parse( seq( optional( sign ), number ), input );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results a string \"+123\"" ) {
                REQUIRE( STRING == ret.type );
                REQUIRE( std::string("+123") == ret.str );
            }
            Val_del( &ret );
        }
        WHEN( "parse( seq( optional( sign ), number ), \"-123\" )" ) {
            const char* input = "-123";
            Val ret = parse( seq( optional( sign ), number ), input );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results a string \"-123\"" ) {
                REQUIRE( STRING == ret.type );
                REQUIRE( std::string("-123") == ret.str );
            }
            Val_del( &ret );
        }
        WHEN( "parse( seq( optional( sign ), number ), \"*123\" )" ) {
            const char* input = "*123";
            Val ret = parse( seq( optional( sign ), number ), input );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results an error" ) {
                REQUIRE( ERROR == ret.type );
                CHECK( ret.error );
            }
            Val_del( &ret );
        }
        WHEN( "parse( optional( seq( sign, number ) ), \"*123\" )" ) {
            const char* input = "*123";
            Val ret = parse( optional( seq( sign, number ) ), input );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results a null string \"\"" ) {
                REQUIRE( STRING == ret.type );
                REQUIRE( std::string("") == ret.str );
            }
            Val_del( &ret );
        }
    }
    REQUIRE( 0 == Parser_live_count() );
}
