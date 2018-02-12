/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include <string>
#include "catch.hpp"

#include "cparsec.h"

SCENARIO( "'digit' parser", "[cparsec][digit]" ) {
    WHEN( "parse( digit, NULL )" ) {
        Val result = parse( digit, NULL );
        THEN( "result an error" ) {
            REQUIRE( ERROR == result.type );
            CHECK( result.error );
        }
        Val_del( &result );
    }
    WHEN( "parse( digit, \"\" )" ) {
        Val result = parse( digit, "" );
        THEN( "result an error" ) {
            REQUIRE( ERROR == result.type );
            CHECK( result.error );
        }
        Val_del( &result );
    }
    WHEN( "parse( digit, \"0\" )" ) {
        Val result = parse( digit, "0" );
        THEN( "result is (char)'0'" ) {
            REQUIRE( CHAR == result.type );
            REQUIRE( '0' == result.c );
        }
        Val_del( &result );
    }
    WHEN( "parse( digit, \"1\" )" ) {
        Val result = parse( digit, "1" );
        THEN( "result is (char)'1'" ) {
            REQUIRE( CHAR == result.type );
            REQUIRE( '1' == result.c );
        }
        Val_del( &result );
    }
    WHEN( "parse( digit, \"2\" )" ) {
        Val result = parse( digit, "2" );
        THEN( "result is (char)'2'" ) {
            REQUIRE( CHAR == result.type );
            REQUIRE( '2' == result.c );
        }
        Val_del( &result );
    }
    WHEN( "parse( digit, \"3\" )" ) {
        Val result = parse( digit, "3" );
        THEN( "result is (char)'3'" ) {
            REQUIRE( CHAR == result.type );
            REQUIRE( '3' == result.c );
        }
        Val_del( &result );
    }
    WHEN( "parse( digit, \"4\" )" ) {
        Val result = parse( digit, "4" );
        THEN( "result is (char)'4'" ) {
            REQUIRE( CHAR == result.type );
            REQUIRE( '4' == result.c );
        }
        Val_del( &result );
    }
    WHEN( "parse( digit, \"5\" )" ) {
        Val result = parse( digit, "5" );
        THEN( "result is (char)'5'" ) {
            REQUIRE( CHAR == result.type );
            REQUIRE( '5' == result.c );
        }
        Val_del( &result );
    }
    WHEN( "parse( digit, \"6\" )" ) {
        Val result = parse( digit, "6" );
        THEN( "result is (char)'6'" ) {
            REQUIRE( CHAR == result.type );
            REQUIRE( '6' == result.c );
        }
        Val_del( &result );
    }
    WHEN( "parse( digit, \"7\" )" ) {
        Val result = parse( digit, "7" );
        THEN( "result is (char)'7'" ) {
            REQUIRE( CHAR == result.type );
            REQUIRE( '7' == result.c );
        }
        Val_del( &result );
    }
    WHEN( "parse( digit, \"8\" )" ) {
        Val result = parse( digit, "8" );
        THEN( "result is (char)'8'" ) {
            REQUIRE( CHAR == result.type );
            REQUIRE( '8' == result.c );
        }
        Val_del( &result );
    }
    WHEN( "parse( digit, \"9\" )" ) {
        Val result = parse( digit, "9" );
        THEN( "result is (char)'9'" ) {
            REQUIRE( CHAR == result.type );
            REQUIRE( '9' == result.c );
        }
        Val_del( &result );
    }
    WHEN( "parse( digit, \"a\" )" ) {
        Val result = parse( digit, "a" );
        THEN( "result an error" ) {
            REQUIRE( ERROR == result.type );
            CHECK( result.error );
        }
        Val_del( &result );
    }
    WHEN( "parse( digit, \"z\" )" ) {
        Val result = parse( digit, "z" );
        THEN( "result an error" ) {
            REQUIRE( ERROR == result.type );
            CHECK( result.error );
        }
        Val_del( &result );
    }
    WHEN( "parse( digit, \"A\" )" ) {
        Val result = parse( digit, "A" );
        THEN( "result an error" ) {
            REQUIRE( ERROR == result.type );
            CHECK( result.error );
        }
        Val_del( &result );
    }
    WHEN( "parse( digit, \"Z\" )" ) {
        Val result = parse( digit, "Z" );
        THEN( "result an error" ) {
            REQUIRE( ERROR == result.type );
            CHECK( result.error );
        }
        Val_del( &result );
    }
    WHEN( "parse( digit, \"_\" )" ) {
        Val result = parse( digit, "_" );
        THEN( "result an error" ) {
            REQUIRE( ERROR == result.type );
            CHECK( result.error );
        }
        Val_del( &result );
    }
    WHEN( "parse( digit, \"!\" )" ) {
        Val result = parse( digit, "!" );
        THEN( "result an error" ) {
            REQUIRE( ERROR == result.type );
            CHECK( result.error );
        }
        Val_del( &result );
    }
}
