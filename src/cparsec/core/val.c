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
    case NONE:           return snprintf( buf, maxlen, "<{NONE}>" );
    case ERROR:
        if ( x->error )  return snprintf( buf, maxlen, "%s", x->error );
        else             return snprintf( buf, maxlen, "<{null:ERROR}>" );
    case CHAR:           return snprintf( buf, maxlen, "%c", x->c );
    case INT:            return snprintf( buf, maxlen, "%d", x->i );
    case DOUBLE:         return snprintf( buf, maxlen, "%f", x->d );
    case PTR:
        if ( x->ptr )    return snprintf( buf, maxlen, "<{%p:void*}>", x->ptr );
        else             return snprintf( buf, maxlen, "<{null:void*}>" );
    case STRING:
        if ( x->str )    return snprintf( buf, maxlen, "%s", x->str );
        else             return snprintf( buf, maxlen, "<{null:const char*}>" );
    case PARSER:
        if ( x->parser ) return snprintf( buf, maxlen, "<{%p:Parser}>", (void*)x->parser );
        else             return snprintf( buf, maxlen, "<{null:Parser}>" );
    case PREDICATE:      return snprintf( buf, maxlen, "<{\?:Predicate}>" );
    case INT8:           return snprintf( buf, maxlen, "%" PRId8 , x->i8  );
    case INT16:          return snprintf( buf, maxlen, "%" PRId16, x->i16 );
    case INT32:          return snprintf( buf, maxlen, "%" PRId32, x->i32 );
    case INT64:          return snprintf( buf, maxlen, "%" PRId64, x->i64 );
    case UINT8:          return snprintf( buf, maxlen, "%" PRIu8 , x->u8  );
    case UINT16:         return snprintf( buf, maxlen, "%" PRIu16, x->u16 );
    case UINT32:         return snprintf( buf, maxlen, "%" PRIu32, x->u32 );
    case UINT64:         return snprintf( buf, maxlen, "%" PRIu64, x->u64 );
    case FILTER:         return snprintf( buf, maxlen, "<{\?:Filter}>" );
    default:             return snprintf( buf, maxlen, "<{UNKNOWN}>" );
    }
}

const Val Val_NONE = VAL_INIT(NONE);
Val Val_ERROR ( const char* error )         { return (Val)VAL_INIT(ERROR)(error); }
Val Val_CHAR  ( char c )                    { return (Val)VAL_INIT(CHAR)(c); }
Val Val_INT   ( int i )                     { return (Val)VAL_INIT(INT)(i); }
Val Val_DOUBLE( double d  )                 { return (Val)VAL_INIT(DOUBLE)(d); }
Val Val_PTR   ( void* ptr )                 { return (Val)VAL_INIT(PTR)(ptr); }
Val Val_STRING( const char* str )           { return (Val)VAL_INIT(STRING)(str); }
Val Val_PARSER( struct ParserSt* parser )   { return (Val)VAL_INIT(PARSER)(parser); }
Val Val_PREDICATE( Predicate predicate )    { return (Val)VAL_INIT(PREDICATE)(predicate); }
Val Val_INT8  ( int8_t i8 )                 { return (Val)VAL_INIT(INT8)(i8); }
Val Val_INT16 ( int16_t i16 )               { return (Val)VAL_INIT(INT16)(i16); }
Val Val_INT32 ( int32_t i32 )               { return (Val)VAL_INIT(INT32)(i32); }
Val Val_INT64 ( int64_t i64 )               { return (Val)VAL_INIT(INT64)(i64); }
Val Val_UINT8 ( uint8_t u8 )                { return (Val)VAL_INIT(UINT8)(u8); }
Val Val_UINT16( uint16_t u16 )              { return (Val)VAL_INIT(UINT16)(u16); }
Val Val_UINT32( uint32_t u32 )              { return (Val)VAL_INIT(UINT32)(u32); }
Val Val_UINT64( uint64_t u64 )              { return (Val)VAL_INIT(UINT64)(u64); }
Val Val_FILTER( Filter filter )             { return (Val)VAL_INIT(FILTER)(filter); }
Val Val_D_ERROR ( const char* error )       { return (Val)VAL_INIT(D_ERROR)(error); }
Val Val_D_PTR   ( void* ptr )               { return (Val)VAL_INIT(D_PTR)(ptr); }
Val Val_D_STRING( const char* str )         { return (Val)VAL_INIT(D_STRING)(str); }
Val Val_D_PARSER( struct ParserSt* parser ) { return (Val)VAL_INIT(D_PARSER)(parser); }

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
