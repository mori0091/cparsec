/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include <string>
#include "catch.hpp"

#include "cparsec.h"

SCENARIO( "'upper' parser", "[cparsec][upper]" ) {
    WHEN( "parse( upper, NULL )" ) {
        Val result = parse( upper, NULL );
        THEN( "result an error" ) {
            REQUIRE( ERROR == result.type );
            CHECK( result.error );
        }
        Val_del( &result );
    }
    WHEN( "parse( upper, \"\" )" ) {
        Val result = parse( upper, "" );
        THEN( "result an error" ) {
            REQUIRE( ERROR == result.type );
            CHECK( result.error );
        }
        Val_del( &result );
    }
    WHEN( "parse( upper, \"0\" )" ) {
        Val result = parse( upper, "0" );
        THEN( "result an error" ) {
            REQUIRE( ERROR == result.type );
            CHECK( result.error );
        }
        Val_del( &result );
    }
    WHEN( "parse( upper, \"1\" )" ) {
        Val result = parse( upper, "1" );
        THEN( "result an error" ) {
            REQUIRE( ERROR == result.type );
            CHECK( result.error );
        }
        Val_del( &result );
    }
    WHEN( "parse( upper, \"2\" )" ) {
        Val result = parse( upper, "2" );
        THEN( "result an error" ) {
            REQUIRE( ERROR == result.type );
            CHECK( result.error );
        }
        Val_del( &result );
    }
    WHEN( "parse( upper, \"3\" )" ) {
        Val result = parse( upper, "3" );
        THEN( "result an error" ) {
            REQUIRE( ERROR == result.type );
            CHECK( result.error );
        }
        Val_del( &result );
    }
    WHEN( "parse( upper, \"4\" )" ) {
        Val result = parse( upper, "4" );
        THEN( "result an error" ) {
            REQUIRE( ERROR == result.type );
            CHECK( result.error );
        }
        Val_del( &result );
    }
    WHEN( "parse( upper, \"5\" )" ) {
        Val result = parse( upper, "5" );
        THEN( "result an error" ) {
            REQUIRE( ERROR == result.type );
            CHECK( result.error );
        }
        Val_del( &result );
    }
    WHEN( "parse( upper, \"6\" )" ) {
        Val result = parse( upper, "6" );
        THEN( "result an error" ) {
            REQUIRE( ERROR == result.type );
            CHECK( result.error );
        }
        Val_del( &result );
    }
    WHEN( "parse( upper, \"7\" )" ) {
        Val result = parse( upper, "7" );
        THEN( "result an error" ) {
            REQUIRE( ERROR == result.type );
            CHECK( result.error );
        }
        Val_del( &result );
    }
    WHEN( "parse( upper, \"8\" )" ) {
        Val result = parse( upper, "8" );
        THEN( "result an error" ) {
            REQUIRE( ERROR == result.type );
            CHECK( result.error );
        }
        Val_del( &result );
    }
    WHEN( "parse( upper, \"9\" )" ) {
        Val result = parse( upper, "9" );
        THEN( "result an error" ) {
            REQUIRE( ERROR == result.type );
            CHECK( result.error );
        }
        Val_del( &result );
    }
    WHEN( "parse( upper, \"a\" )" ) {
        Val result = parse( upper, "a" );
        THEN( "result an error" ) {
            REQUIRE( ERROR == result.type );
            CHECK( result.error );
        }
        Val_del( &result );
    }
    WHEN( "parse( upper, \"z\" )" ) {
        Val result = parse( upper, "z" );
        THEN( "result an error" ) {
            REQUIRE( ERROR == result.type );
            CHECK( result.error );
        }
        Val_del( &result );
    }
    WHEN( "parse( upper, \"A\" )" ) {
        Val result = parse( upper, "A" );
        THEN( "result is (char)'A'" ) {
            REQUIRE( CHAR == result.type );
            REQUIRE( 'A' == result.c );
        }
        Val_del( &result );
    }
    WHEN( "parse( upper, \"Z\" )" ) {
        Val result = parse( upper, "Z" );
        THEN( "result is (char)'Z'" ) {
            REQUIRE( CHAR == result.type );
            REQUIRE( 'Z' == result.c );
        }
        Val_del( &result );
    }
    WHEN( "parse( upper, \"_\" )" ) {
        Val result = parse( upper, "_" );
        THEN( "result an error" ) {
            REQUIRE( ERROR == result.type );
            CHECK( result.error );
        }
        Val_del( &result );
    }
    WHEN( "parse( upper, \"!\" )" ) {
        Val result = parse( upper, "!" );
        THEN( "result an error" ) {
            REQUIRE( ERROR == result.type );
            CHECK( result.error );
        }
        Val_del( &result );
    }
    REQUIRE( 0 == Parser_live_count() );
}
