/* -*- mode: c++ ; coding: utf-8-unix -*- */

#pragma once

#ifndef CPARSEC_H
#define CPARSEC_H

#include <assert.h>

#include "cparsec/core/val.h"

#ifdef __cplusplus
extern "C" {
#endif

    /**
     * \brief Type of Parser
     *
     * \note Parser is an opaque object. You need not know its
     *       implementation.
     */
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

    /**
     * \brief Returns the number of Parsers living.
     *
     * \note This is debug purpose only.
     * \return the number of Parsers living.
     */
    int Parser_live_count( void );

    /**
     * \brief Increments the reference count of a Parser.
     *
     * Increments the reference count of a Parser.
     *
     * In usually, you need not use Parser_ref() and Parser_unref() if
     * any parsers you created are parsed just once by parse() or
     * parse_test().
     *
     * Otherwise you must use explicitlly Parser_ref() and
     * Parser_unref().
     *
     * ~~~c
     * parse( many( char1('a') ), "aaa" ); // OK
     *
     * Parser a = char1( 'a' );
     * parse( many( a ), "aaa" ); // OK
     * parse( many( a ), "aaa" ); // NG, `a` is no longer refered.
     *
     * Parser a = Parser_ref( char1( 'a' ) );
     * parse( many( a ), "aaa" ); // OK
     * parse( many( a ), "aaa" ); // OK
     * Parser_unref( a );         // Parser_unref() is needed to deallocate `a`.
     * ~~~
     *
     * \param p   a parser
     * \return    the parser `p` itself
     */
    Parser Parser_ref( Parser p );

    /**
     * \brief Decrements the reference count of a Parser.
     * 
     * Decrements the reference count of a Parser, and deletes the
     * Parser if its reference count became zero.
     *
     * \param p   a parser
     * \return    the parser `p` itself
     * \sa Parser_unref()
     */
    void Parser_unref( Parser p );

    //// pre-instantiated singleton primitive parsers
    extern const Parser any_char; ///< A pre-instantiated singleton parser. Parses any `char` except for `'\0'`.
    extern const Parser digit;    ///< A pre-instantiated singleton parser. Parses `'0'`..`'9'`
    extern const Parser lower;    ///< A pre-instantiated singleton parser. Parses `'a'`..`'z'`
    extern const Parser upper;    ///< A pre-instantiated singleton parser. Parses `'A'`..`'Z'`
    extern const Parser alpha;    ///< A pre-instantiated singleton parser. Parses `'a'`..`'z'`, `'A'`..`'Z'`
    extern const Parser alnum;    ///< A pre-instantiated singleton parser. Parses `'a'`..`'z'`, `'A'`..`'Z'`, `'0'`..`'9'`
    extern const Parser letter;   ///< A pre-instantiated singleton parser. Parses `'a'`..`'z'`, `'A'`..`'Z'`, `'_'`

    //// primitive parser generators
    /**
     * \brief A primitive parser generator - satisfy.
     *
     * satisfy() creates a parser, which parses a `char ch` if
     * `pred(ch)` was `true`.
     * 
     * \param pred   predicate a function pointer `bool (*)(char)`
     * \return       a parser, which parses a `char ch` if `pred(ch)`
     *               was `true`.
     */
    Parser satisfy( Predicate pred );
    /**
     * \brief A primitive parser generator - char1.
     *
     * char1() creates a parser, which parses a `char ch` if `c == ch`
     * was `true`.
     * 
     * \param c      an expected `char`
     * \return       a parser, which parses a `char ch` if `c == ch`
     *               was `true`.
     */
    Parser char1( char c );
    /**
     * \brief A primitive parser generator - string1.
     *
     * string1() creates a parser, which parses a `const char* s` if
     * `strcmp( str, s ) == 0` was `true`.
     * 
     * \param str    an expected string
     * \return       a parser, which parses a `const char* s` if
     *               `strcmp( str, s ) == 0` was `true`.
     */
    Parser string1( const char* str );

    //// primitive parser generators - unary operator
    /**
     * \brief A primitive parser generator - many.
     *
     * many() creates a parser, which applies the parser `x` zero
     * times or more.
     * 
     * \param x      a parser
     * \return       a parser, which applies the parser `x` zero times
     *               or more.
     */
    Parser many( const Parser x );
    /**
     * \brief A primitive parser generator - many1.
     *
     * many1() creates a parser, which applies the parser `x` one
     * times or more.
     * 
     * \param x      a parser
     * \return       a parser, which applies the parser `x` one times
     *               or more.
     */
    Parser many1( const Parser x );
    /**
     * \brief A primitive parser generator - tryp.
     *
     * tryp() creates a parser, which applies the parser `x` but
     * rewind on error.
     * 
     * \param x      a parser
     * \return       a parser, which applies the parser `x` but rewind
     *               on error.
     */
    Parser tryp( const Parser x );

    //// primitive parser generators - binary operator
    /**
     * \brief A primitive parser generator - seq.
     *
     * seq() creates a parser, which applies the parser `x` then the
     * paser 'y'.
     * 
     * \param x      a parser
     * \param y      a parser
     * \return       a parser, which applies the parser `x` then the
     *               parser 'y'
     */
    Parser seq( const Parser x, const Parser y );
    /**
     * \brief A primitive parser generator - either.
     *
     * either() creates a parser, which applies the parser `x`. If `x`
     * caused an error and `x` didn't consume any `char`, applies the
     * parser `y`.
     * 
     * \param x      a parser
     * \param y      a parser
     * \return       a parser, which applies the parser `x`. If `x`
     *               caused an error and `x` didn't consume any
     *               `char`, applies the parser `y`.
     */
    Parser either( const Parser x, const Parser y );

    //// primitive parser generators - (int, Parser)
    /**
     * \brief A primitive parser generator - rep.
     *
     * rep() creates a parser, which applies the parser `x` `n` times.
     * 
     * \param x      a parser
     * \return       a parser, which applies the parser `x` `n` times.
     */
    Parser rep( int n, const Parser x );
  
#ifdef __cplusplus
}
#endif

#endif  /* CPARSEC_H */
