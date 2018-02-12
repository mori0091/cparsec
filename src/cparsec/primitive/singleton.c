/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include "cparsec/primitive/singleton.h"

#include "cparsec/primitive/satisfy.h"

#define UNUSED_VARIABLE(x)    (void)(x)

bool is_any_char( char c ) { UNUSED_VARIABLE(c); return true; }
bool is_digit   ( char c ) { return '0' <= c && c <= '9'; }
bool is_lower   ( char c ) { return 'a' <= c && c <= 'z'; }
bool is_upper   ( char c ) { return 'A' <= c && c <= 'Z'; }
bool is_alpha   ( char c ) { return is_lower(c) || is_upper(c); }
bool is_alnum   ( char c ) { return is_alpha(c) || is_digit(c); }
bool is_letter  ( char c ) { return is_alpha(c) || c == '_'; }

static ParserSt any_char_ = PREDICATE_ST_INIT( satisfy, is_any_char );
static ParserSt digit_    = PREDICATE_ST_INIT( satisfy, is_digit );
static ParserSt lower_    = PREDICATE_ST_INIT( satisfy, is_lower );
static ParserSt upper_    = PREDICATE_ST_INIT( satisfy, is_upper );
static ParserSt alpha_    = PREDICATE_ST_INIT( satisfy, is_alpha );
static ParserSt alnum_    = PREDICATE_ST_INIT( satisfy, is_alnum );
static ParserSt letter_   = PREDICATE_ST_INIT( satisfy, is_letter );

const Parser any_char = &any_char_;
const Parser digit    = &digit_;
const Parser lower    = &lower_;
const Parser upper    = &upper_;
const Parser alpha    = &alpha_;
const Parser alnum    = &alnum_;
const Parser letter   = &letter_;
