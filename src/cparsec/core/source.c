/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "cparsec/core/source.h"
#include "cparsec/util/string_utils.h"

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

bool Source_eq( const Source* a, const Source* b )
{
  assert( a );
  assert( b );
  return a->s == b->s;
}

// \todo construct "[line,col] error-msg"
Val Source_error( const Source* src, const char* msg )
{
  char sline[32];
  char scol[32];
  char ch[8] = {0,};
  snprintf( sline, sizeof(sline), "%d", src->line );
  snprintf( scol , sizeof(scol) , "%d", src->col );
  if ( *(src->s) ) {
    if ( isprint( *(src->s) ) ) {
      snprintf( ch, sizeof(ch), " <%c>", *(src->s) );
    }
    else {
      snprintf( ch, sizeof(ch), " <0x%02x>", (0xFF & *(src->s)) );
    }
  }
  DEF_STRING( err, "[line ", sline, ", col ", scol, "] ", msg, ch );
  return D_ERROR_VAL( strdup( err ) );
}
