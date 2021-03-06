/* -*- mode: c++ ; coding: utf-8-unix -*- */

#pragma once

#ifndef CPARSEC_H
#define CPARSEC_H

#include <assert.h>

#include "cparsec/core/val.h"
#include "cparsec/core/curry.h"

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
     *
     * \sa Parser_ref()
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
    extern const Parser number;   ///< A pre-instantiated singleton parser. Parses one or more digits and returns as `int`

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
    /**
     * \brief A primitive parser generator - one_of.
     *
     * one_of() creates a parser, which parses a `char ch` if ch is a
     * member of the char array `chars`.
     * 
     * \param chars  expected characters
     * \return       a parser, which parses a `char ch` if ch is a
     *               member of the char array `chars`.
     */
    Parser one_of( const char* chars );

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
    Parser many( Parser x );
    /**
     * \brief A primitive parser generator - many1.
     *
     * many1() creates a parser, which applies the parser `x` once or
     * more.
     * 
     * \param x      a parser
     * \return       a parser, which applies the parser `x` once or
     *               more.
     */
    Parser many1( Parser x );
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
    Parser tryp( Parser x );
    /**
     * \brief A primitive parser generator - optional.
     *
     * optional() creates a parser, which applies the parser `x` at
     * most once. If `x` failed, rewinds then returns a null string ""
     * instead of an error.
     * 
     * \param x      a parser
     * \return       a parser, which applies the parser `x` at most
     *               once.
     */
    Parser optional( Parser x );

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
    Parser seq( Parser x, Parser y );
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
    Parser either( Parser x, Parser y );
    /**
     * \brief A primitive parser generator - first.
     *
     * first() creates a parser, which applies the parser `x` then the
     * paser 'y' and returns result of `x`.
     *
     * ~~~c
     * Val ret = parse( first(char1('a'),number), "a1" )
     * // --> ret is VAL(CHAR)('a')
     * ~~~
     * 
     * \param x      a parser
     * \param y      a parser
     * \return       a parser, which applies the parser `x` then the
     *               paser 'y' and returns result of `x`.
     */
    Parser first( Parser x, Parser y );
    /**
     * \brief A primitive parser generator - second.
     *
     * second() creates a parser, which applies the parser `x` then the
     * paser 'y' and returns result of `y`.
     * 
     * ~~~c
     * Val ret = parse( second(char1('a'),number), "a1" )
     * // --> ret is VAL(INT)(1)
     * ~~~
     * 
     * \param x      a parser
     * \param y      a parser
     * \return       a parser, which applies the parser `x` then the
     *               paser 'y' and returns result of `y`.
     */
    Parser second( Parser x, Parser y );

    //// primitive parser generators - (int, Parser)
    /**
     * \brief A primitive parser generator - rep.
     *
     * rep() creates a parser, which applies the parser `x` `n` times.
     * 
     * \param x      a parser
     * \return       a parser, which applies the parser `x` `n` times.
     */
    Parser rep( int n, Parser x );

    /**
     * \brief A primitive parser generator - apply.
     *
     * apply() creates a parser, which applies the parser `x` then
     * applies a filter `f` to the result of `x`.
     * 
     * \param f      a filter (Fn1 type function object)
     * \param x      a parser
     * \return       a parser, which applies the parser `x` then
     *               applies a filter `f` to the result of `x`.
     */
    Parser apply( Fn1 f, Parser x );

#ifdef __cplusplus
}
#endif

#endif  /* CPARSEC_H */
