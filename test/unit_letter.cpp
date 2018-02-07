/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include <string>
#include "catch.hpp"

#include "cparsec.h"

SCENARIO( "'letter' parser", "[cparsec]" ) {
  WHEN( "parse( letter, NULL )" ) {
    Val result = parse( letter, NULL );
    THEN( "result an error" ) {
      REQUIRE( ERROR == result.type );
      CHECK( result.value.error );
    }
    Val_del( &result );
  }
  WHEN( "parse( letter, \"\" )" ) {
    Val result = parse( letter, "" );
    THEN( "result an error" ) {
      REQUIRE( ERROR == result.type );
      CHECK( result.value.error );
    }
    Val_del( &result );
  }
  WHEN( "parse( letter, \"0\" )" ) {
    Val result = parse( letter, "0" );
    THEN( "result an error" ) {
      REQUIRE( ERROR == result.type );
      CHECK( result.value.error );
    }
    Val_del( &result );
  }
  WHEN( "parse( letter, \"1\" )" ) {
    Val result = parse( letter, "1" );
    THEN( "result an error" ) {
      REQUIRE( ERROR == result.type );
      CHECK( result.value.error );
    }
    Val_del( &result );
  }
  WHEN( "parse( letter, \"2\" )" ) {
    Val result = parse( letter, "2" );
    THEN( "result an error" ) {
      REQUIRE( ERROR == result.type );
      CHECK( result.value.error );
    }
    Val_del( &result );
  }
  WHEN( "parse( letter, \"3\" )" ) {
    Val result = parse( letter, "3" );
    THEN( "result an error" ) {
      REQUIRE( ERROR == result.type );
      CHECK( result.value.error );
    }
    Val_del( &result );
  }
  WHEN( "parse( letter, \"4\" )" ) {
    Val result = parse( letter, "4" );
    THEN( "result an error" ) {
      REQUIRE( ERROR == result.type );
      CHECK( result.value.error );
    }
    Val_del( &result );
  }
  WHEN( "parse( letter, \"5\" )" ) {
    Val result = parse( letter, "5" );
    THEN( "result an error" ) {
      REQUIRE( ERROR == result.type );
      CHECK( result.value.error );
    }
    Val_del( &result );
  }
  WHEN( "parse( letter, \"6\" )" ) {
    Val result = parse( letter, "6" );
    THEN( "result an error" ) {
      REQUIRE( ERROR == result.type );
      CHECK( result.value.error );
    }
    Val_del( &result );
  }
  WHEN( "parse( letter, \"7\" )" ) {
    Val result = parse( letter, "7" );
    THEN( "result an error" ) {
      REQUIRE( ERROR == result.type );
      CHECK( result.value.error );
    }
    Val_del( &result );
  }
  WHEN( "parse( letter, \"8\" )" ) {
    Val result = parse( letter, "8" );
    THEN( "result an error" ) {
      REQUIRE( ERROR == result.type );
      CHECK( result.value.error );
    }
    Val_del( &result );
  }
  WHEN( "parse( letter, \"9\" )" ) {
    Val result = parse( letter, "9" );
    THEN( "result an error" ) {
      REQUIRE( ERROR == result.type );
      CHECK( result.value.error );
    }
    Val_del( &result );
  }
  WHEN( "parse( letter, \"a\" )" ) {
    Val result = parse( letter, "a" );
    THEN( "result is (char)'a'" ) {
      REQUIRE( CHAR == result.type );
      REQUIRE( 'a' == result.value.c );
    }
    Val_del( &result );
  }
  WHEN( "parse( letter, \"z\" )" ) {
    Val result = parse( letter, "z" );
    THEN( "result is (char)'z'" ) {
      REQUIRE( CHAR == result.type );
      REQUIRE( 'z' == result.value.c );
    }
    Val_del( &result );
  }
  WHEN( "parse( letter, \"A\" )" ) {
    Val result = parse( letter, "A" );
    THEN( "result is (char)'A'" ) {
      REQUIRE( CHAR == result.type );
      REQUIRE( 'A' == result.value.c );
    }
    Val_del( &result );
  }
  WHEN( "parse( letter, \"Z\" )" ) {
    Val result = parse( letter, "Z" );
    THEN( "result is (char)'Z'" ) {
      REQUIRE( CHAR == result.type );
      REQUIRE( 'Z' == result.value.c );
    }
    Val_del( &result );
  }
  WHEN( "parse( letter, \"_\" )" ) {
    Val result = parse( letter, "_" );
    THEN( "result is (char)'_'" ) {
      REQUIRE( CHAR == result.type );
      REQUIRE( '_' == result.value.c );
    }
    Val_del( &result );
  }
  WHEN( "parse( letter, \"!\" )" ) {
    Val result = parse( letter, "!" );
    THEN( "result an error" ) {
      REQUIRE( ERROR == result.type );
      CHECK( result.value.error );
    }
    Val_del( &result );
  }
}
