/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include <string>
#include "catch.hpp"

#include "cparsec.h"

SCENARIO( "'lower' parser", "[cparsec][lower]" ) {
    WHEN( "parse( lower, NULL )" ) {
        Val result = parse( lower, NULL );
        THEN( "result an error" ) {
            REQUIRE( ERROR == result.type );
            CHECK( result.error );
        }
        Val_del( &result );
    }
    WHEN( "parse( lower, \"\" )" ) {
        Val result = parse( lower, "" );
        THEN( "result an error" ) {
            REQUIRE( ERROR == result.type );
            CHECK( result.error );
        }
        Val_del( &result );
    }
    WHEN( "parse( lower, \"0\" )" ) {
        Val result = parse( lower, "0" );
        THEN( "result an error" ) {
            REQUIRE( ERROR == result.type );
            CHECK( result.error );
        }
        Val_del( &result );
    }
    WHEN( "parse( lower, \"1\" )" ) {
        Val result = parse( lower, "1" );
        THEN( "result an error" ) {
            REQUIRE( ERROR == result.type );
            CHECK( result.error );
        }
        Val_del( &result );
    }
    WHEN( "parse( lower, \"2\" )" ) {
        Val result = parse( lower, "2" );
        THEN( "result an error" ) {
            REQUIRE( ERROR == result.type );
            CHECK( result.error );
        }
        Val_del( &result );
    }
    WHEN( "parse( lower, \"3\" )" ) {
        Val result = parse( lower, "3" );
        THEN( "result an error" ) {
            REQUIRE( ERROR == result.type );
            CHECK( result.error );
        }
        Val_del( &result );
    }
    WHEN( "parse( lower, \"4\" )" ) {
        Val result = parse( lower, "4" );
        THEN( "result an error" ) {
            REQUIRE( ERROR == result.type );
            CHECK( result.error );
        }
        Val_del( &result );
    }
    WHEN( "parse( lower, \"5\" )" ) {
        Val result = parse( lower, "5" );
        THEN( "result an error" ) {
            REQUIRE( ERROR == result.type );
            CHECK( result.error );
        }
        Val_del( &result );
    }
    WHEN( "parse( lower, \"6\" )" ) {
        Val result = parse( lower, "6" );
        THEN( "result an error" ) {
            REQUIRE( ERROR == result.type );
            CHECK( result.error );
        }
        Val_del( &result );
    }
    WHEN( "parse( lower, \"7\" )" ) {
        Val result = parse( lower, "7" );
        THEN( "result an error" ) {
            REQUIRE( ERROR == result.type );
            CHECK( result.error );
        }
        Val_del( &result );
    }
    WHEN( "parse( lower, \"8\" )" ) {
        Val result = parse( lower, "8" );
        THEN( "result an error" ) {
            REQUIRE( ERROR == result.type );
            CHECK( result.error );
        }
        Val_del( &result );
    }
    WHEN( "parse( lower, \"9\" )" ) {
        Val result = parse( lower, "9" );
        THEN( "result an error" ) {
            REQUIRE( ERROR == result.type );
            CHECK( result.error );
        }
        Val_del( &result );
    }
    WHEN( "parse( lower, \"a\" )" ) {
        Val result = parse( lower, "a" );
        THEN( "result is (char)'a'" ) {
            REQUIRE( CHAR == result.type );
            REQUIRE( 'a' == result.c );
        }
        Val_del( &result );
    }
    WHEN( "parse( lower, \"z\" )" ) {
        Val result = parse( lower, "z" );
        THEN( "result is (char)'z'" ) {
            REQUIRE( CHAR == result.type );
            REQUIRE( 'z' == result.c );
        }
        Val_del( &result );
    }
    WHEN( "parse( lower, \"A\" )" ) {
        Val result = parse( lower, "A" );
        THEN( "result an error" ) {
            REQUIRE( ERROR == result.type );
            CHECK( result.error );
        }
        Val_del( &result );
    }
    WHEN( "parse( lower, \"Z\" )" ) {
        Val result = parse( lower, "Z" );
        THEN( "result an error" ) {
            REQUIRE( ERROR == result.type );
            CHECK( result.error );
        }
        Val_del( &result );
    }
    WHEN( "parse( lower, \"_\" )" ) {
        Val result = parse( lower, "_" );
        THEN( "result an error" ) {
            REQUIRE( ERROR == result.type );
            CHECK( result.error );
        }
        Val_del( &result );
    }
    WHEN( "parse( lower, \"!\" )" ) {
        Val result = parse( lower, "!" );
        THEN( "result an error" ) {
            REQUIRE( ERROR == result.type );
            CHECK( result.error );
        }
        Val_del( &result );
    }
    REQUIRE( 0 == Parser_live_count() );
}
