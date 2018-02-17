/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include <string>
#include "catch.hpp"

#include "cparsec.h"

static Val inc( Val x )
{
    switch ( x.type ) {
    case CHAR:     return VAL(CHAR)  (x.c   + 1);
    case INT:      return VAL(INT)   (x.i   + 1);
    case INT8:     return VAL(INT8)  (x.i8  + 1);
    case INT16:    return VAL(INT16) (x.i16 + 1);
    case INT32:    return VAL(INT32) (x.i32 + 1);
    case INT64:    return VAL(INT64) (x.i64 + 1);
    case UINT8:    return VAL(UINT8) (x.u8  + 1);
    case UINT16:   return VAL(UINT16)(x.u16 + 1);
    case UINT32:   return VAL(UINT32)(x.u32 + 1);
    case UINT64:   return VAL(UINT64)(x.u64 + 1);
    default:       return VAL(ERROR) ("not a char nor an integer");
    }
}

SCENARIO( "'apply' parser combinator", "[cparsec][apply]" ) {
    GIVEN( "Parser a = char1('a')" ) {
        // Parser a = Parser_ref( char1('a') );
        Parser a = char1('a');
        REQUIRE( 1 == Parser_live_count() );
        WHEN( "parse( apply(inc,a), \"\")" ) {
            const char* input  = "";
            Val ret = parse( apply(inc,a), input );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results an error" ) {
                REQUIRE( ret.type == ERROR );
                CHECK( ret.error );
            }
            Val_del( &ret );
        }
        WHEN( "parse( apply(inc,a), \"a\")" ) {
            const char* input  = "a";
            char expect = 'b';
            Val ret = parse( apply(inc,a), input );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results a char 'b'" ) {
                REQUIRE( ret.type == CHAR );
                REQUIRE( expect == ret.c );
            }
            Val_del( &ret );
        }
        WHEN( "parse( apply(inc,a), \"b\")" ) {
            const char* input  = "b";
            Val ret = parse( apply(inc,a), input );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results an error" ) {
                REQUIRE( ret.type == ERROR );
                CHECK( ret.error );
            }
            Val_del( &ret );
        }
        // Parser_unref( a );
    }
    GIVEN( "Parser any_char" ) {
        REQUIRE( 0 == Parser_live_count() );
        WHEN( "parse( apply(inc,any_char), \"\")" ) {
            const char* input  = "";
            Val ret = parse( apply(inc,any_char), input );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results an error" ) {
                REQUIRE( ret.type == ERROR );
                CHECK( ret.error );
            }
            Val_del( &ret );
        }
        WHEN( "parse( apply(inc,any_char), \"a\")" ) {
            const char* input  = "a";
            char expect = 'b';
            Val ret = parse( apply(inc,any_char), input );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results a char 'b'" ) {
                REQUIRE( ret.type == CHAR );
                REQUIRE( expect == ret.c );
            }
            Val_del( &ret );
        }
        WHEN( "parse( apply(inc,any_char), \"b\")" ) {
            const char* input  = "b";
            char expect = 'c';
            Val ret = parse( apply(inc,any_char), input );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results a char 'c'" ) {
                REQUIRE( ret.type == CHAR );
                REQUIRE( expect == ret.c );
            }
            Val_del( &ret );
        }
        // Parser_unref( a );
    }
    GIVEN( "Parser number" ) {
        REQUIRE( 0 == Parser_live_count() );
        WHEN( "parse( apply(inc,number), \"\")" ) {
            const char* input  = "";
            Val ret = parse( apply(inc,number), input );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results an error" ) {
                REQUIRE( ret.type == ERROR );
                CHECK( ret.error );
            }
            Val_del( &ret );
        }
        WHEN( "parse( apply(inc,number), \"1\")" ) {
            const char* input  = "1";
            int expect = 2;
            Val ret = parse( apply(inc,number), input );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results a int 2" ) {
                REQUIRE( ret.type == INT );
                REQUIRE( expect == ret.i );
            }
            Val_del( &ret );
        }
        WHEN( "parse( apply(inc,number), \"100\")" ) {
            const char* input  = "100";
            int expect = 101;
            Val ret = parse( apply(inc,number), input );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results a int 101" ) {
                REQUIRE( ret.type == INT );
                REQUIRE( expect == ret.i );
            }
            Val_del( &ret );
        }
        WHEN( "parse( apply(inc,number), \"-1\")" ) {
            const char* input  = "-1";
            Val ret = parse( apply(inc,number), input );
            REQUIRE( 0 == Parser_live_count() );
            THEN( "results an error" ) {
                REQUIRE( ret.type == ERROR );
                CHECK( ret.error );
            }
            Val_del( &ret );
        }
        // Parser_unref( a );
    }
    REQUIRE( 0 == Parser_live_count() );
}
