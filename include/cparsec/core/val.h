/* -*- mode: c++ ; coding: utf-8-unix -*- */

#pragma once

#ifndef CPARSEC_CORE_VAL_H
#define CPARSEC_CORE_VAL_H

#include <stdbool.h>
#include <stdlib.h>

/**
 * \brief Constructs various compound literal of Val.
 *
 * VAL(T) is expanded to (Val)VAL_INIT(T), and VAL_INIT(T) is expanded
 * to T_VAL_INIT.
 *
 * Thus, for example\n
 * - VAL(NONE) is expanded to (Val){0}
 * - VAL(ERROR)("an error") is expanded to (Val){ .type = ERROR, .error = ("an error"), .del = 0 }
 * - VAL(INT)(100) is expanded to (Val){ .type = INT, .i = (100), .del = 0 }
 * - and so on.
 *
 * \param T    An enum ValType or one of D_ERROR, D_PTR, D_STRING, D_PARSER.
 */
#define VAL(T)         (Val)VAL_INIT(T)

/**
 * \brief Constructs various initializer of Val.
 *
 * VAL_INIT(T) is expanded to T_VAL_INIT.
 *
 * Thus, for example,\n
 * - VAL_INIT(NONE) is expanded to {0}
 * - VAL_INIT(ERROR)("an error") is expanded to { .type = ERROR, .error = ("an error"), .del = 0 }
 * - VAL_INIT(INT)(100) is expanded to { .type = INT, .i = (100), .del = 0 }
 * - and so on.
 *
 * \param T    An enum ValType or one of D_ERROR, D_PTR, D_STRING, D_PARSER.
 */
#define VAL_INIT(T)    VAL_INIT_I(T)
#define VAL_INIT_I(T)  T ## _VAL_INIT

//// macros of various initializer of Val
/** \note use VAL_INIT(NONE) instead. */
#define      NONE_VAL_INIT       { 0 }
/** \note use VAL_INIT(ERROR)(x) instead. */
#define     ERROR_VAL_INIT( x )  { .type = ERROR    , .error     = (x), .del = 0 }
/** \note use VAL_INIT(CHAR)(x) instead. */
#define      CHAR_VAL_INIT( x )  { .type = CHAR     , .c         = (x), .del = 0 }
/** \note use VAL_INIT(INT)(x) instead. */
#define       INT_VAL_INIT( x )  { .type = INT      , .i         = (x), .del = 0 }
/** \note use VAL_INIT(DOUBLE)(x) instead. */
#define    DOUBLE_VAL_INIT( x )  { .type = DOUBLE   , .d         = (x), .del = 0 }
/** \note use VAL_INIT(PTR)(x) instead. */
#define       PTR_VAL_INIT( x )  { .type = PTR      , .ptr       = (x), .del = 0 }
/** \note use VAL_INIT(STRING)(x) instead. */
#define    STRING_VAL_INIT( x )  { .type = STRING   , .str       = (x), .del = 0 }
/** \note use VAL_INIT(PARSER)(x) instead. */
#define    PARSER_VAL_INIT( x )  { .type = PARSER   , .parser    = (x), .del = 0 }
/** \note use VAL_INIT(PREDICATE)(x) instead. */
#define PREDICATE_VAL_INIT( x )  { .type = PREDICATE, .predicate = (x), .del = 0 }

//// macros of various initializer of Val, whose value must be deallocated
/** \note use VAL_INIT(D_ERROR)(x) instead. */
#define   D_ERROR_VAL_INIT( x )  { .type = ERROR    , .str       = (x), .del = free }
/** \note use VAL_INIT(D_PTR)(x) instead. */
#define     D_PTR_VAL_INIT( x )  { .type = PTR      , .ptr       = (x), .del = free }
/** \note use VAL_INIT(D_STRING)(x) instead. */
#define  D_STRING_VAL_INIT( x )  { .type = STRING   , .str       = (x), .del = free }
/** \note use VAL_INIT(D_PARSER)(x) instead. */
#define  D_PARSER_VAL_INIT( x )  { .type = PARSER   , .parser    = (x), .del = (Deletor)Parser_unref }

#ifdef __cplusplus
extern "C" {
#endif

    /** \brief A type synonym of struct Val */
    typedef struct Val Val;
    /** \brief Type of a predicate function - a function pointer bool (*)(char) */
    typedef bool (*Predicate)( char );
    /** \brief Type of a deletor function - a function pointer void (*)(void*) */
    typedef void (*Deletor)( void* );

    /** \brief Type identifier of a Val's value */
    enum ValType {
        NONE = 0,               ///< (none)
        ERROR,                  ///< const char* error
        CHAR,                   ///< char c
        INT,                    ///< int i
        DOUBLE,                 ///< double d
        PTR,                    ///< void* ptr
        STRING,                 ///< const char* str
        PARSER,                 ///< Parser parser
        PREDICATE,              ///< Predicate predicate
    };

    struct Val {
        /** \brief Type identifier of the value */
        enum  ValType  type;
        /** \brief the value of this Val */
        union {
            const char*      error;     ///< An error message for type of ERROR
            char             c;         ///< A char value for type of CHAR
            int              i;         ///< An int value for type of INT
            double           d;         ///< A double value for type of DOUBLE
            void*            ptr;       ///< A void* value for type of PTR
            const char*      str;       ///< A const char* value for type of STRING
            struct ParserSt* parser;    ///< A Parser value for type of PARSER
            Predicate        predicate; ///< A Predicate value for type of PREDICATE
        };
        /** \brief A deletor function of the value. NULL if the value does not need to be deleted. */
        Deletor del;
    };

    /**
     * \brief Deallocates a value.
     *
     * Val_del() deallocates `x->ptr` by calling `x->del( x->ptr )` if
     * `x->del` was not NULL.
     *
     * You should deallocate Val by calling this function when a Val
     * was no longer needed.
     *
     * \param x    a pointer to a Val
     */
    void Val_del( Val* x );
    /**
     * \brief Prints a Val to stdout as string.
     *
     * \param x    a pointer to a Val
     */
    void Val_print( Val* x );
    /**
     * \brief Concatenates two Val, and deallocates them.
     *
     * \param x    a pointer to a Val
     * \param y    a pointer to a Val
     * \param      a Val which has concatenated string.
     */
    Val Val_concat( Val* x, Val* y );
  
#ifdef __cplusplus
}
#endif

#endif  /* CPARSEC_CORE_VAL_H */
