/* -*- mode: c++ ; coding: utf-8-unix -*- */

#pragma once

#ifndef CPARSEC_H
#define CPARSEC_H

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

//// macros of various compound literal of Val
#define            NONE_VAL       (Val)NONE_VAL_INIT
#define           ERROR_VAL( x )  (Val)ERROR_VAL_INIT((x))
#define            CHAR_VAL( x )  (Val)CHAR_VAL_INIT((x))
#define             INT_VAL( x )  (Val)INT_VAL_INIT((x))
#define          DOUBLE_VAL( x )  (Val)DOUBLE_VAL_INIT((x))
#define             PTR_VAL( x )  (Val)PTR_VAL_INIT((x))
#define          STRING_VAL( x )  (Val)STRING_VAL_INIT((x))
#define          PARSER_VAL( x )  (Val)PARSER_VAL_INIT((x))
#define       PREDICATE_VAL( x )  (Val)PREDICATE_VAL_INIT((x))

//// macros of various initializer of Val
#define      NONE_VAL_INIT       { 0 }
#define     ERROR_VAL_INIT( x )  { .type = ERROR    , .value.error     = (x), .del = 0 }
#define      CHAR_VAL_INIT( x )  { .type = CHAR     , .value.c         = (x), .del = 0 }
#define       INT_VAL_INIT( x )  { .type = INT      , .value.i         = (x), .del = 0 }
#define    DOUBLE_VAL_INIT( x )  { .type = DOUBLE   , .value.d         = (x), .del = 0 }
#define       PTR_VAL_INIT( x )  { .type = PTR      , .value.ptr       = (x), .del = 0 }
#define    STRING_VAL_INIT( x )  { .type = STRING   , .value.str       = (x), .del = 0 }
#define    PARSER_VAL_INIT( x )  { .type = PARSER   , .value.parser    = (x), .del = 0 }
#define PREDICATE_VAL_INIT( x )  { .type = PREDICATE, .value.predicate = (x), .del = 0 }

//// macros of various compound literal of Val, whose value must be deallocated
#define        D_ERROR_VAL( x )  (Val)D_ERROR_VAL_INIT((x))
#define          D_PTR_VAL( x )  (Val)D_PTR_VAL_INIT((x))
#define       D_STRING_VAL( x )  (Val)D_STRING_VAL_INIT((x))
#define       D_PARSER_VAL( x )  (Val)D_STRING_VAL_INIT((x))

//// macros of various initializer of Val, whose value must be deallocated
#define   D_ERROR_VAL_INIT( x )  { .type = ERROR    , .value.str       = (x), .del = free }
#define     D_PTR_VAL_INIT( x )  { .type = PTR      , .value.ptr       = (x), .del = free }
#define  D_STRING_VAL_INIT( x )  { .type = STRING   , .value.str       = (x), .del = free }
#define  D_PARSER_VAL_INIT( x )  { .type = PARSER   , .value.parser    = (x), .del = (Deallocator)Parser_del }

#ifdef __cplusplus
extern "C" {
#endif

  typedef struct ParserSt* Parser;
  typedef bool (*Predicate)( char );
  typedef void (*Deallocator)( void* );

  enum ValT {
    ERROR,			///< const char* error
    CHAR,			///< char c
    INT,			///< int i
    DOUBLE,			///< double d
    PTR,			///< void* ptr
    STRING,			///< const char* str
    PARSER,			///< Parser parser
    PREDICATE,			///< Predicate predicate
  };

  union ValD {
    const char* error;
    char        c;
    int         i;
    double      d;
    void*       ptr;
    const char* str;
    Parser      parser;
    Predicate   predicate;
  };

  typedef struct Val Val;

  struct Val {
    enum  ValT  type;
    union ValD  value;
    Deallocator del;
  };

  void Val_del( Val* x );

  /**
   * \brief Parses a string.
   *
   * Parses a text with the given parser.
   *
   * \param x    a parser
   * \param str  a text to be parsed
   * \return     result or an error
   */
  Val parse( const Parser x, const char* str );

  /**
   * \brief Parses a string, then outputs result.
   *
   * Parses a text with the given parser.\n
   * Then prints the result or an error message to stdout.
   *
   * \param x    a parser
   * \param str  a text to be parsed
   * \return     result or an error
   */
  void parse_test( const Parser x, const char* str );

  void Parser_del( Parser p );

  //// primitive predicates
  bool is_any_char( char c );
  bool is_digit( char c );
  bool is_lower( char c );
  bool is_upper( char c );
  bool is_alpha( char c );
  bool is_alnum( char c );
  bool is_letter( char c );

  //// pre-instantiated primitive parsers
  extern Parser any_char;
  extern Parser digit;
  extern Parser lower;
  extern Parser upper;
  extern Parser alpha;
  extern Parser alnum;
  extern Parser letter;

  //// primitive parser generators
  Parser satisfy( Predicate pred );
  Parser char1( char c );
  Parser string1( const char* str );

  //// primitive parser generators - unary operator
  Parser many( const Parser x );
  Parser many1( const Parser x );
  Parser tryp( const Parser x );

  //// primitive parser generators - binary operator
  Parser seq( const Parser x, const Parser y );
  Parser either( const Parser x, const Parser y );

  //// primitive parser generators - (int, Parser)
  Parser rep( int n, const Parser x );
  
#ifdef __cplusplus
}
#endif

#endif	/* CPARSEC_H */
