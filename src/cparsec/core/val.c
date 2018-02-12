/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include <stdio.h>
#include <string.h>

#include "cparsec.h"
#include "cparsec/core/val.h"
#include "cparsec/util/string_utils.h"

static int Val_snprint( char* buf, size_t maxlen, const Val* x )
{
    assert( x );
    switch ( x->type ) {
    case ERROR:     return snprintf( buf, maxlen, "%s", x->error );
    case CHAR:      return snprintf( buf, maxlen, "%c", x->c );
    case INT:       return snprintf( buf, maxlen, "%d", x->i );
    case DOUBLE:    return snprintf( buf, maxlen, "%f", x->d );
    case PTR:       return snprintf( buf, maxlen, "%p", x->ptr );
    case STRING:    return snprintf( buf, maxlen, "%s", x->str );
    case PARSER:    return snprintf( buf, maxlen, "<{Parser(%p)}>", x->ptr );
    case PREDICATE: return snprintf( buf, maxlen, "<{Predicate(\?\?)}>" );
    default:        return snprintf( buf, maxlen, "<{UNKNOWN}>" );
    }
}

void Val_del( Val* x )
{
    if ( x ) {
        if ( x->del ) {
            x->del( x->ptr );
            x->ptr = 0;
        }
    }
}

void Val_print( Val* x )
{
    char s[256] = { 0, };
    Val_snprint( s, sizeof(s), x );
    printf( "%s\n", s );
}

Val Val_concat( Val* x, Val* y )
{
    char sx[256] = { 0, };
    char sy[256] = { 0, };
    Val_snprint( sx, sizeof( sx ), x );
    Val_snprint( sy, sizeof( sy ), y );
    Val_del( x );
    Val_del( y );
    DEF_STRING( sxy, sx, sy );
    return D_STRING_VAL( strdup( sxy ) );
}
