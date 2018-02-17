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

const Val Val_NONE = NONE_VAL_INIT;
Val Val_ERROR ( const char* error )         { return (Val)ERROR_VAL_INIT(error); }
Val Val_CHAR  ( char c )                    { return (Val)CHAR_VAL_INIT(c); }
Val Val_INT   ( int i )                     { return (Val)INT_VAL_INIT(i); }
Val Val_DOUBLE( double d  )                 { return (Val)DOUBLE_VAL_INIT(d); }
Val Val_PTR   ( void* ptr )                 { return (Val)PTR_VAL_INIT(ptr); }
Val Val_STRING( const char* str )           { return (Val)STRING_VAL_INIT(str); }
Val Val_PARSER( struct ParserSt* parser )   { return (Val)PARSER_VAL_INIT(parser); }
Val Val_PREDICATE( Predicate predicate )    { return (Val)PREDICATE_VAL_INIT(predicate); }
Val Val_INT8  ( int8_t i8 )                 { return (Val)INT8_VAL_INIT(i8); }
Val Val_INT16 ( int16_t i16 )               { return (Val)INT16_VAL_INIT(i16); }
Val Val_INT32 ( int32_t i32 )               { return (Val)INT32_VAL_INIT(i32); }
Val Val_INT64 ( int64_t i64 )               { return (Val)INT64_VAL_INIT(i64); }
Val Val_UINT8 ( uint8_t u8 )                { return (Val)UINT8_VAL_INIT(u8); }
Val Val_UINT16( uint16_t u16 )              { return (Val)UINT16_VAL_INIT(u16); }
Val Val_UINT32( uint32_t u32 )              { return (Val)UINT32_VAL_INIT(u32); }
Val Val_UINT64( uint64_t u64 )              { return (Val)UINT64_VAL_INIT(u64); }
Val Val_FILTER( Filter filter )             { return (Val)FILTER_VAL_INIT(filter); }
Val Val_D_ERROR ( const char* error )       { return (Val)D_ERROR_VAL_INIT(error); }
Val Val_D_PTR   ( void* ptr )               { return (Val)D_PTR_VAL_INIT(ptr); }
Val Val_D_STRING( const char* str )         { return (Val)D_STRING_VAL_INIT(str); }
Val Val_D_PARSER( struct ParserSt* parser ) { return (Val)D_PARSER_VAL_INIT(parser); }

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
