/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include <string>
#include "catch.hpp"

#include "cparsec.h"

SCENARIO( "'alnum' parser", "[cparsec][alnum]" ) {
    WHEN( "parse( alnum, NULL )" ) {
        Val result = parse( alnum, NULL );
        THEN( "result an error" ) {
            REQUIRE( ERROR == result.type );
            CHECK( result.error );
        }
        Val_del( &result );
    }
    WHEN( "parse( alnum, \"\" )" ) {
        Val result = parse( alnum, "" );
        THEN( "result an error" ) {
            REQUIRE( ERROR == result.type );
            CHECK( result.error );
        }
        Val_del( &result );
    }
    WHEN( "parse( alnum, \"0\" )" ) {
        Val result = parse( alnum, "0" );
        THEN( "result is (char)'0'" ) {
            REQUIRE( CHAR == result.type );
            REQUIRE( '0' == result.c );
        }
        Val_del( &result );
    }
    WHEN( "parse( alnum, \"1\" )" ) {
        Val result = parse( alnum, "1" );
        THEN( "result is (char)'1'" ) {
            REQUIRE( CHAR == result.type );
            REQUIRE( '1' == result.c );
        }
        Val_del( &result );
    }
    WHEN( "parse( alnum, \"2\" )" ) {
        Val result = parse( alnum, "2" );
        THEN( "result is (char)'2'" ) {
            REQUIRE( CHAR == result.type );
            REQUIRE( '2' == result.c );
        }
        Val_del( &result );
    }
    WHEN( "parse( alnum, \"3\" )" ) {
        Val result = parse( alnum, "3" );
        THEN( "result is (char)'3'" ) {
            REQUIRE( CHAR == result.type );
            REQUIRE( '3' == result.c );
        }
        Val_del( &result );
    }
    WHEN( "parse( alnum, \"4\" )" ) {
        Val result = parse( alnum, "4" );
        THEN( "result is (char)'4'" ) {
            REQUIRE( CHAR == result.type );
            REQUIRE( '4' == result.c );
        }
        Val_del( &result );
    }
    WHEN( "parse( alnum, \"5\" )" ) {
        Val result = parse( alnum, "5" );
        THEN( "result is (char)'5'" ) {
            REQUIRE( CHAR == result.type );
            REQUIRE( '5' == result.c );
        }
        Val_del( &result );
    }
    WHEN( "parse( alnum, \"6\" )" ) {
        Val result = parse( alnum, "6" );
        THEN( "result is (char)'6'" ) {
            REQUIRE( CHAR == result.type );
            REQUIRE( '6' == result.c );
        }
        Val_del( &result );
    }
    WHEN( "parse( alnum, \"7\" )" ) {
        Val result = parse( alnum, "7" );
        THEN( "result is (char)'7'" ) {
            REQUIRE( CHAR == result.type );
            REQUIRE( '7' == result.c );
        }
        Val_del( &result );
    }
    WHEN( "parse( alnum, \"8\" )" ) {
        Val result = parse( alnum, "8" );
        THEN( "result is (char)'8'" ) {
            REQUIRE( CHAR == result.type );
            REQUIRE( '8' == result.c );
        }
        Val_del( &result );
    }
    WHEN( "parse( alnum, \"9\" )" ) {
        Val result = parse( alnum, "9" );
        THEN( "result is (char)'9'" ) {
            REQUIRE( CHAR == result.type );
            REQUIRE( '9' == result.c );
        }
        Val_del( &result );
    }
    WHEN( "parse( alnum, \"a\" )" ) {
        Val result = parse( alnum, "a" );
        THEN( "result is (char)'a'" ) {
            REQUIRE( CHAR == result.type );
            REQUIRE( 'a' == result.c );
        }
        Val_del( &result );
    }
    WHEN( "parse( alnum, \"z\" )" ) {
        Val result = parse( alnum, "z" );
        THEN( "result is (char)'z'" ) {
            REQUIRE( CHAR == result.type );
            REQUIRE( 'z' == result.c );
        }
        Val_del( &result );
    }
    WHEN( "parse( alnum, \"A\" )" ) {
        Val result = parse( alnum, "A" );
        THEN( "result is (char)'A'" ) {
            REQUIRE( CHAR == result.type );
            REQUIRE( 'A' == result.c );
        }
        Val_del( &result );
    }
    WHEN( "parse( alnum, \"Z\" )" ) {
        Val result = parse( alnum, "Z" );
        THEN( "result is (char)'Z'" ) {
            REQUIRE( CHAR == result.type );
            REQUIRE( 'Z' == result.c );
        }
        Val_del( &result );
    }
    WHEN( "parse( alnum, \"_\" )" ) {
        Val result = parse( alnum, "_" );
        THEN( "result an error" ) {
            REQUIRE( ERROR == result.type );
            CHECK( result.error );
        }
        Val_del( &result );
    }
    WHEN( "parse( alnum, \"!\" )" ) {
        Val result = parse( alnum, "!" );
        THEN( "result an error" ) {
            REQUIRE( ERROR == result.type );
            CHECK( result.error );
        }
        Val_del( &result );
    }
    REQUIRE( 0 == Parser_live_count() );
}
