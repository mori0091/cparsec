/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include <string>
#include "catch.hpp"

#include "cparsec.h"

SCENARIO( "'any_char' parser", "[cparsec][any_char]" ) {
  WHEN( "parse( any_char, NULL )" ) {
    Val result = parse( any_char, NULL );
    THEN( "result an error" ) {
      REQUIRE( ERROR == result.type );
      CHECK( result.error );
    }
    Val_del( &result );
  }
  WHEN( "parse( any_char, \"\" )" ) {
    Val result = parse( any_char, "" );
    THEN( "result an error" ) {
      REQUIRE( ERROR == result.type );
      CHECK( result.error );
    }
    Val_del( &result );
  }
  WHEN( "parse( any_char, \"0\" )" ) {
    Val result = parse( any_char, "0" );
    THEN( "result is (char)'0'" ) {
      REQUIRE( CHAR == result.type );
      REQUIRE( '0' == result.c );
    }
    Val_del( &result );
  }
  WHEN( "parse( any_char, \"1\" )" ) {
    Val result = parse( any_char, "1" );
    THEN( "result is (char)'1'" ) {
      REQUIRE( CHAR == result.type );
      REQUIRE( '1' == result.c );
    }
    Val_del( &result );
  }
  WHEN( "parse( any_char, \"2\" )" ) {
    Val result = parse( any_char, "2" );
    THEN( "result is (char)'2'" ) {
      REQUIRE( CHAR == result.type );
      REQUIRE( '2' == result.c );
    }
    Val_del( &result );
  }
  WHEN( "parse( any_char, \"3\" )" ) {
    Val result = parse( any_char, "3" );
    THEN( "result is (char)'3'" ) {
      REQUIRE( CHAR == result.type );
      REQUIRE( '3' == result.c );
    }
    Val_del( &result );
  }
  WHEN( "parse( any_char, \"4\" )" ) {
    Val result = parse( any_char, "4" );
    THEN( "result is (char)'4'" ) {
      REQUIRE( CHAR == result.type );
      REQUIRE( '4' == result.c );
    }
    Val_del( &result );
  }
  WHEN( "parse( any_char, \"5\" )" ) {
    Val result = parse( any_char, "5" );
    THEN( "result is (char)'5'" ) {
      REQUIRE( CHAR == result.type );
      REQUIRE( '5' == result.c );
    }
    Val_del( &result );
  }
  WHEN( "parse( any_char, \"6\" )" ) {
    Val result = parse( any_char, "6" );
    THEN( "result is (char)'6'" ) {
      REQUIRE( CHAR == result.type );
      REQUIRE( '6' == result.c );
    }
    Val_del( &result );
  }
  WHEN( "parse( any_char, \"7\" )" ) {
    Val result = parse( any_char, "7" );
    THEN( "result is (char)'7'" ) {
      REQUIRE( CHAR == result.type );
      REQUIRE( '7' == result.c );
    }
    Val_del( &result );
  }
  WHEN( "parse( any_char, \"8\" )" ) {
    Val result = parse( any_char, "8" );
    THEN( "result is (char)'8'" ) {
      REQUIRE( CHAR == result.type );
      REQUIRE( '8' == result.c );
    }
    Val_del( &result );
  }
  WHEN( "parse( any_char, \"9\" )" ) {
    Val result = parse( any_char, "9" );
    THEN( "result is (char)'9'" ) {
      REQUIRE( CHAR == result.type );
      REQUIRE( '9' == result.c );
    }
    Val_del( &result );
  }
  WHEN( "parse( any_char, \"a\" )" ) {
    Val result = parse( any_char, "a" );
    THEN( "result is (char)'a'" ) {
      REQUIRE( CHAR == result.type );
      REQUIRE( 'a' == result.c );
    }
    Val_del( &result );
  }
  WHEN( "parse( any_char, \"z\" )" ) {
    Val result = parse( any_char, "z" );
    THEN( "result is (char)'z'" ) {
      REQUIRE( CHAR == result.type );
      REQUIRE( 'z' == result.c );
    }
    Val_del( &result );
  }
  WHEN( "parse( any_char, \"A\" )" ) {
    Val result = parse( any_char, "A" );
    THEN( "result is (char)'A'" ) {
      REQUIRE( CHAR == result.type );
      REQUIRE( 'A' == result.c );
    }
    Val_del( &result );
  }
  WHEN( "parse( any_char, \"Z\" )" ) {
    Val result = parse( any_char, "Z" );
    THEN( "result is (char)'Z'" ) {
      REQUIRE( CHAR == result.type );
      REQUIRE( 'Z' == result.c );
    }
    Val_del( &result );
  }
  WHEN( "parse( any_char, \"_\" )" ) {
    Val result = parse( any_char, "_" );
    THEN( "result is (char)'_'" ) {
      REQUIRE( CHAR == result.type );
      REQUIRE( '_' == result.c );
    }
    Val_del( &result );
  }
  WHEN( "parse( any_char, \"!\" )" ) {
    Val result = parse( any_char, "!" );
    THEN( "result is (char)'!'" ) {
      REQUIRE( CHAR == result.type );
      REQUIRE( '!' == result.c );
    }
    Val_del( &result );
  }
}
