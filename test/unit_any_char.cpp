/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include <string>
#include "catch.hpp"

#include "cparsec.h"

SCENARIO( "'any_char' parser", "[cparsec]" ) {
  WHEN( "parse( any_char, NULL )" ) {
    Val result = parse( any_char, NULL );
    THEN( "result an error" ) {
      REQUIRE( ERROR == result.type );
      CHECK( result.value.error );
    }
    Val_del( &result );
  }
  WHEN( "parse( any_char, \"\" )" ) {
    Val result = parse( any_char, "" );
    THEN( "result an error" ) {
      REQUIRE( ERROR == result.type );
      CHECK( result.value.error );
    }
    Val_del( &result );
  }
  WHEN( "parse( any_char, \"0\" )" ) {
    Val result = parse( any_char, "0" );
    THEN( "result is (char)'0'" ) {
      REQUIRE( CHAR == result.type );
      REQUIRE( '0' == result.value.c );
    }
    Val_del( &result );
  }
  WHEN( "parse( any_char, \"a\" )" ) {
    Val result = parse( any_char, "a" );
    THEN( "result is (char)'a'" ) {
      REQUIRE( CHAR == result.type );
      REQUIRE( 'a' == result.value.c );
    }
    Val_del( &result );
  }
  WHEN( "parse( any_char, \"A\" )" ) {
    Val result = parse( any_char, "A" );
    THEN( "result is (char)'A'" ) {
      REQUIRE( CHAR == result.type );
      REQUIRE( 'A' == result.value.c );
    }
    Val_del( &result );
  }
  WHEN( "parse( any_char, \"_\" )" ) {
    Val result = parse( any_char, "_" );
    THEN( "result is (char)'_'" ) {
      REQUIRE( CHAR == result.type );
      REQUIRE( '_' == result.value.c );
    }
    Val_del( &result );
  }
  WHEN( "parse( any_char, \"!\" )" ) {
    Val result = parse( any_char, "!" );
    THEN( "result is (char)'!'" ) {
      REQUIRE( CHAR == result.type );
      REQUIRE( '!' == result.value.c );
    }
    Val_del( &result );
  }
}
