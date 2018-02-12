/* -*- mode: c++ ; coding: utf-8-unix -*- */

#pragma once

#ifndef CPARSEC_H
#define CPARSEC_H

#include <assert.h>

#include "cparsec/core/val.h"

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct ParserSt* Parser;

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

    int Parser_live_count( void );
    Parser Parser_ref( Parser p );
    void Parser_unref( Parser p );

    //// pre-instantiated singleton primitive parsers
    extern const Parser any_char;
    extern const Parser digit;
    extern const Parser lower;
    extern const Parser upper;
    extern const Parser alpha;
    extern const Parser alnum;
    extern const Parser letter;

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

#endif  /* CPARSEC_H */
