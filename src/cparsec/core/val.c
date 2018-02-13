/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include <stdio.h>
#include <string.h>
#include <inttypes.h>

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
    case INT8:      return snprintf( buf, maxlen, "%" PRId8 , x->i8  );
    case INT16:     return snprintf( buf, maxlen, "%" PRId16, x->i16 );
    case INT32:     return snprintf( buf, maxlen, "%" PRId32, x->i32 );
    case INT64:     return snprintf( buf, maxlen, "%" PRId64, x->i64 );
    case UINT8:     return snprintf( buf, maxlen, "%" PRIu8 , x->u8  );
    case UINT16:    return snprintf( buf, maxlen, "%" PRIu16, x->u16 );
    case UINT32:    return snprintf( buf, maxlen, "%" PRIu32, x->u32 );
    case UINT64:    return snprintf( buf, maxlen, "%" PRIu64, x->u64 );
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
    return VAL(D_STRING)( strdup( sxy ) );
}
