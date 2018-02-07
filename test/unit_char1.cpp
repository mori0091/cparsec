/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include <string>
#include "catch.hpp"

#include "cparsec.h"

SCENARIO( "'char1' parser", "[cparsec]" ) {
  Parser p = char1( 'a' );
  WHEN( "parse( char1('a'), NULL )" ) {
    Val result = parse( p, NULL );
    THEN( "result an error" ) {
      REQUIRE( ERROR == result.type );
      CHECK( result.value.error );
    }
    Val_del( &result );
  }
  WHEN( "parse( char1('a'), \"\" )" ) {
    Val result = parse( p, "" );
    THEN( "result an error" ) {
      REQUIRE( ERROR == result.type );
      CHECK( result.value.error );
    }
    Val_del( &result );
  }
  WHEN( "parse( char1('a'), \"0\" )" ) {
    Val result = parse( p, "0" );
    THEN( "result an error" ) {
      REQUIRE( ERROR == result.type );
      CHECK( result.value.error );
    }
    Val_del( &result );
  }
  WHEN( "parse( char1('a'), \"a\" )" ) {
    Val result = parse( p, "a" );
    THEN( "result is (char)'a'" ) {
      REQUIRE( CHAR == result.type );
      REQUIRE( 'a' == result.value.c );
    }
    Val_del( &result );
  }
  WHEN( "parse( char1('a'), \"A\" )" ) {
    Val result = parse( p, "A" );
    THEN( "result an error" ) {
      REQUIRE( ERROR == result.type );
      CHECK( result.value.error );
    }
    Val_del( &result );
  }
  Parser_del( p );
}
