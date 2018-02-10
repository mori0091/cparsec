/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include "cparsec/primitive/singleton.h"

#define UNUSED_VARIABLE(x)    (void)(x)

bool is_any_char( char c ) { UNUSED_VARIABLE(c); return true; }
bool is_digit   ( char c ) { return '0' <= c && c <= '9'; }
bool is_lower   ( char c ) { return 'a' <= c && c <= 'z'; }
bool is_upper   ( char c ) { return 'A' <= c && c <= 'Z'; }
bool is_alpha   ( char c ) { return is_lower(c) || is_upper(c); }
bool is_alnum   ( char c ) { return is_alpha(c) || is_digit(c); }
bool is_letter  ( char c ) { return is_alpha(c) || c == '_'; }

static ParserSt any_char_ = SATISFY_ST_INIT( is_any_char );
static ParserSt digit_    = SATISFY_ST_INIT( is_digit );
static ParserSt lower_    = SATISFY_ST_INIT( is_lower );
static ParserSt upper_    = SATISFY_ST_INIT( is_upper );
static ParserSt alpha_    = SATISFY_ST_INIT( is_alpha );
static ParserSt alnum_    = SATISFY_ST_INIT( is_alnum );
static ParserSt letter_   = SATISFY_ST_INIT( is_letter );

const Parser any_char = &any_char_;
const Parser digit    = &digit_;
const Parser lower    = &lower_;
const Parser upper    = &upper_;
const Parser alpha    = &alpha_;
const Parser alnum    = &alnum_;
const Parser letter   = &letter_;
