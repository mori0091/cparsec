/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include <string>
#include "catch.hpp"

#include "cparsec.h"

SCENARIO( "'alpha' parser", "[cparsec]" ) {
  WHEN( "parse( alpha, NULL )" ) {
    Val result = parse( alpha, NULL );
    THEN( "result an error" ) {
      REQUIRE( ERROR == result.type );
      CHECK( result.value.error );
    }
    Val_del( &result );
  }
  WHEN( "parse( alpha, \"\" )" ) {
    Val result = parse( alpha, "" );
    THEN( "result an error" ) {
      REQUIRE( ERROR == result.type );
      CHECK( result.value.error );
    }
    Val_del( &result );
  }
  WHEN( "parse( alpha, \"0\" )" ) {
    Val result = parse( alpha, "0" );
    THEN( "result an error" ) {
      REQUIRE( ERROR == result.type );
      CHECK( result.value.error );
    }
    Val_del( &result );
  }
  WHEN( "parse( alpha, \"1\" )" ) {
    Val result = parse( alpha, "1" );
    THEN( "result an error" ) {
      REQUIRE( ERROR == result.type );
      CHECK( result.value.error );
    }
    Val_del( &result );
  }
  WHEN( "parse( alpha, \"2\" )" ) {
    Val result = parse( alpha, "2" );
    THEN( "result an error" ) {
      REQUIRE( ERROR == result.type );
      CHECK( result.value.error );
    }
    Val_del( &result );
  }
  WHEN( "parse( alpha, \"3\" )" ) {
    Val result = parse( alpha, "3" );
    THEN( "result an error" ) {
      REQUIRE( ERROR == result.type );
      CHECK( result.value.error );
    }
    Val_del( &result );
  }
  WHEN( "parse( alpha, \"4\" )" ) {
    Val result = parse( alpha, "4" );
    THEN( "result an error" ) {
      REQUIRE( ERROR == result.type );
      CHECK( result.value.error );
    }
    Val_del( &result );
  }
  WHEN( "parse( alpha, \"5\" )" ) {
    Val result = parse( alpha, "5" );
    THEN( "result an error" ) {
      REQUIRE( ERROR == result.type );
      CHECK( result.value.error );
    }
    Val_del( &result );
  }
  WHEN( "parse( alpha, \"6\" )" ) {
    Val result = parse( alpha, "6" );
    THEN( "result an error" ) {
      REQUIRE( ERROR == result.type );
      CHECK( result.value.error );
    }
    Val_del( &result );
  }
  WHEN( "parse( alpha, \"7\" )" ) {
    Val result = parse( alpha, "7" );
    THEN( "result an error" ) {
      REQUIRE( ERROR == result.type );
      CHECK( result.value.error );
    }
    Val_del( &result );
  }
  WHEN( "parse( alpha, \"8\" )" ) {
    Val result = parse( alpha, "8" );
    THEN( "result an error" ) {
      REQUIRE( ERROR == result.type );
      CHECK( result.value.error );
    }
    Val_del( &result );
  }
  WHEN( "parse( alpha, \"9\" )" ) {
    Val result = parse( alpha, "9" );
    THEN( "result an error" ) {
      REQUIRE( ERROR == result.type );
      CHECK( result.value.error );
    }
    Val_del( &result );
  }
  WHEN( "parse( alpha, \"a\" )" ) {
    Val result = parse( alpha, "a" );
    THEN( "result is (char)'a'" ) {
      REQUIRE( CHAR == result.type );
      REQUIRE( 'a' == result.value.c );
    }
    Val_del( &result );
  }
  WHEN( "parse( alpha, \"z\" )" ) {
    Val result = parse( alpha, "z" );
    THEN( "result is (char)'z'" ) {
      REQUIRE( CHAR == result.type );
      REQUIRE( 'z' == result.value.c );
    }
    Val_del( &result );
  }
  WHEN( "parse( alpha, \"A\" )" ) {
    Val result = parse( alpha, "A" );
    THEN( "result is (char)'A'" ) {
      REQUIRE( CHAR == result.type );
      REQUIRE( 'A' == result.value.c );
    }
    Val_del( &result );
  }
  WHEN( "parse( alpha, \"Z\" )" ) {
    Val result = parse( alpha, "Z" );
    THEN( "result is (char)'Z'" ) {
      REQUIRE( CHAR == result.type );
      REQUIRE( 'Z' == result.value.c );
    }
    Val_del( &result );
  }
  WHEN( "parse( alpha, \"_\" )" ) {
    Val result = parse( alpha, "_" );
    THEN( "result an error" ) {
      REQUIRE( ERROR == result.type );
      CHECK( result.value.error );
    }
    Val_del( &result );
  }
  WHEN( "parse( alpha, \"!\" )" ) {
    Val result = parse( alpha, "!" );
    THEN( "result an error" ) {
      REQUIRE( ERROR == result.type );
      CHECK( result.value.error );
    }
    Val_del( &result );
  }
}
