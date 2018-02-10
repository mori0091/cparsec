/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include <string>
#include "catch.hpp"

#include "cparsec.h"

SCENARIO( "'many1' parser combinator", "[cparsec][many1]" ) {
  GIVEN( "Parser a = char1('a')" ) {
    Parser a = char1('a');
    WHEN( "parse( many1(a), \"\")" ) {
      const char* input  = "";
      Val ret = parse( many1(a), input );
      THEN( "results an error" ) {
        REQUIRE( ret.type == ERROR );
        CHECK( ret.error );
      }
      Val_del( &ret );
    }
    WHEN( "parse( many1(a), \"a\")" ) {
      const char* input  = "a";
      std::string expect = "a";
      Val ret = parse( many1(a), input );
      THEN( "results a string \"" + expect + "\"" ) {
        REQUIRE( ret.type == STRING );
        REQUIRE( expect == ret.str );
      }
      Val_del( &ret );
    }
    WHEN( "parse( many1(a), \"b\")" ) {
      const char* input  = "b";
      Val ret = parse( many1(a), input );
      THEN( "results an error" ) {
        REQUIRE( ret.type == ERROR );
        CHECK( ret.error );
      }
      Val_del( &ret );
    }
    WHEN( "parse( many1(a), \"c\")" ) {
      const char* input  = "c";
      Val ret = parse( many1(a), input );
      THEN( "results an error" ) {
        REQUIRE( ret.type == ERROR );
        CHECK( ret.error );
      }
      Val_del( &ret );
    }
    WHEN( "parse( many1(a), \"ab\")" ) {
      const char* input  = "ab";
      std::string expect = "a";
      Val ret = parse( many1(a), input );
      THEN( "results a string \"" + expect + "\"" ) {
        REQUIRE( ret.type == STRING );
        REQUIRE( expect == ret.str );
      }
      Val_del( &ret );
    }
    WHEN( "parse( many1(a), \"abc\")" ) {
      const char* input  = "abc";
      std::string expect = "a";
      Val ret = parse( many1(a), input );
      THEN( "results a string \"" + expect + "\"" ) {
        REQUIRE( ret.type == STRING );
        REQUIRE( expect == ret.str );
      }
      Val_del( &ret );
    }
    WHEN( "parse( many1(a), \"ac\")" ) {
      const char* input  = "ac";
      std::string expect = "a";
      Val ret = parse( many1(a), input );
      THEN( "results a string \"" + expect + "\"" ) {
        REQUIRE( ret.type == STRING );
        REQUIRE( expect == ret.str );
      }
      Val_del( &ret );
    }
    WHEN( "parse( many1(a), \"ba\")" ) {
      const char* input  = "ba";
      Val ret = parse( many1(a), input );
      THEN( "results an error" ) {
        REQUIRE( ret.type == ERROR );
        CHECK( ret.error );
      }
      Val_del( &ret );
    }
    WHEN( "parse( many1(a), \"bab\")" ) {
      const char* input  = "bab";
      Val ret = parse( many1(a), input );
      THEN( "results an error" ) {
        REQUIRE( ret.type == ERROR );
        CHECK( ret.error );
      }
      Val_del( &ret );
    }
    WHEN( "parse( many1(a), \"aaa\")" ) {
      const char* input  = "aaa";
      std::string expect = "aaa";
      Val ret = parse( many1(a), input );
      THEN( "results a string \"" + expect + "\"" ) {
        REQUIRE( ret.type == STRING );
        REQUIRE( expect == ret.str );
      }
      Val_del( &ret );
    }
    WHEN( "parse( many1(a), \"aaabbb\")" ) {
      const char* input  = "aaabbb";
      std::string expect = "aaa";
      Val ret = parse( many1(a), input );
      THEN( "results a string \"" + expect + "\"" ) {
        REQUIRE( ret.type == STRING );
        REQUIRE( expect == ret.str );
      }
      Val_del( &ret );
    }
    Parser_del( a );
  }
}
