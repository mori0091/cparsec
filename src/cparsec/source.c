/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include <stdio.h>
#include <string.h>

#include "cparsec/source.h"

Source Source_init( const char* str )
{
  return (Source) { .s = str, .line = 1, .col = 1, };
}

Val Source_peek( Source* src )
{
  assert( src );
  char c = *( src->s );
  if ( ! c ) { return Source_error( src, "too short" ); }
  return CHAR_VAL( c );
}

Val Source_next( Source* src )
{
  Val ret = Source_peek( src );
  if ( ret.type != ERROR ) {
    ++(src->s);
    ++(src->col);
    if ( ret.c == '\n' ) {
      ++(src->line);
      src->col = 1;
    }
  }
  return ret;
}

// \todo construct "[line,col] error-msg"
Val Source_error( const Source* src, const char* msg )
{
  const char fmt[] = "[line %d, col %d] %s%s";
  const char ch[] = { ' ', '<', *(src->s), '>', '\0' };
  const char* pch = ( ( *(src->s) ) ? ch : "" );
  char buf[256];
  const int n = sizeof( buf );
  int m = snprintf( buf, n, fmt, src->line, src->col, msg, pch );
  if ( 0 < m && m < n ) {
    buf[n-1] = '\0';
    return D_ERROR_VAL( strdup( buf ) );
  }
  return ERROR_VAL( msg );	// couldn't customize error message
}
