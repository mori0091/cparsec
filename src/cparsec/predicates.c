/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include <stdbool.h>

#define UNUSED_VARIABLE(x)    (void)(x)

bool is_any_char( char c ) { UNUSED_VARIABLE(c); return true; }
bool is_digit   ( char c ) { return '0' <= c && c <= '9'; }
bool is_lower   ( char c ) { return 'a' <= c && c <= 'z'; }
bool is_upper   ( char c ) { return 'A' <= c && c <= 'Z'; }
bool is_alpha   ( char c ) { return is_lower(c) || is_upper(c); }
bool is_alnum   ( char c ) { return is_alpha(c) || is_digit(c); }
bool is_letter  ( char c ) { return is_alpha(c) || c == '_'; }
