/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include <string>
#include "catch.hpp"

#include "cparsec.h"
#include "cparsec/primitive/singleton.h"

static Val a_filter( Val x ) { return x; }

SCENARIO( "Tests various type of Val", "[cparsec][val]" ) {
    GIVEN( "Val nil = VAL(STRING)(\"\")" ) {
        Val nil = VAL(STRING)("");
        GIVEN( "Val x = VAL(NONE)" ) {
            Val x = VAL(NONE);
            REQUIRE( NONE == x.type );
            WHEN( "x = Val_concat( &nil, &x )" ) {
                x = Val_concat( &nil, &x );
                THEN( "x's type is STRING" )
                    AND_THEN( "x's value is \"<{NONE}>\"" ) {
                    REQUIRE( STRING == x.type );
                    REQUIRE( std::string("<{NONE}>") == x.str );
                }
            }
            Val_del( &x );
        }
        GIVEN( "Val x = VAL(ERROR)(\"an error\")" ) {
            Val x = VAL(ERROR)("an error");
            REQUIRE( ERROR == x.type );
            REQUIRE( std::string("an error") == x.error );
            WHEN( "x = Val_concat( &nil, &x )" ) {
                x = Val_concat( &nil, &x );
                THEN( "x's type is STRING" )
                    AND_THEN( "x's value is \"an error\"" ) {
                    REQUIRE( STRING == x.type );
                    REQUIRE( std::string("an error") == x.str );
                }
            }
            Val_del( &x );
        }
        GIVEN( "Val x = VAL(ERROR)(NULL)" ) {
            Val x = VAL(ERROR)(NULL);
            REQUIRE( ERROR == x.type );
            REQUIRE( nullptr == x.error );
            WHEN( "x = Val_concat( &nil, &x )" ) {
                x = Val_concat( &nil, &x );
                THEN( "x's type is STRING" )
                    AND_THEN( "x's value is \"<{null:ERROR}>\"" ) {
                    REQUIRE( STRING == x.type );
                    REQUIRE( std::string("<{null:ERROR}>") == x.str );
                }
            }
            Val_del( &x );
        }
        GIVEN( "Val x = VAL(CHAR)('a')" ) {
            Val x = VAL(CHAR)('a');
            REQUIRE( CHAR == x.type );
            REQUIRE( 'a' == x.c );
            WHEN( "x = Val_concat( &nil, &x )" ) {
                x = Val_concat( &nil, &x );
                THEN( "x's type is STRING" )
                    AND_THEN( "x's value is \"a\"" ) {
                    REQUIRE( STRING == x.type );
                    REQUIRE( std::string("a") == x.str );
                }
            }
            Val_del( &x );
        }
        GIVEN( "Val x = VAL(INT)(1)" ) {
            Val x = VAL(INT)(1);
            REQUIRE( INT == x.type );
            REQUIRE( 1 == x.i );
            WHEN( "x = Val_concat( &nil, &x )" ) {
                x = Val_concat( &nil, &x );
                THEN( "x's type is STRING" )
                    AND_THEN( "x's value is \"1\"" ) {
                    REQUIRE( STRING == x.type );
                    REQUIRE( std::string("1") == x.str );
                }
            }
            Val_del( &x );
        }
        GIVEN( "Val x = VAL(DOUBLE)(1.0)" ) {
            Val x = VAL(DOUBLE)(1.0);
            REQUIRE( DOUBLE == x.type );
            REQUIRE( 1.0 == x.d );
            WHEN( "x = Val_concat( &nil, &x )" ) {
                x = Val_concat( &nil, &x );
                THEN( "x's type is STRING" )
                    AND_THEN( "x's value is \"1.000000\"" ) {
                    REQUIRE( STRING == x.type );
                    REQUIRE( std::string("1.000000") == x.str );
                }
            }
            Val_del( &x );
        }
        GIVEN( "Val x = VAL(PTR)(NULL)" ) {
            Val x = VAL(PTR)(NULL);
            REQUIRE( PTR == x.type );
            REQUIRE( nullptr == x.ptr );
            WHEN( "x = Val_concat( &nil, &x )" ) {
                x = Val_concat( &nil, &x );
                THEN( "x's type is STRING" )
                    AND_THEN( "x's value is \"<{null:void*}>\"" ) {
                    REQUIRE( STRING == x.type );
                    REQUIRE( std::string("<{null:void*}>") == x.str );
                }
            }
            Val_del( &x );
        }
        GIVEN( "Val x = VAL(STRING)(\"foo bar\")" ) {
            Val x = VAL(STRING)("foo bar");
            REQUIRE( STRING == x.type );
            REQUIRE( std::string("foo bar") == x.str );
            WHEN( "x = Val_concat( &nil, &x )" ) {
                x = Val_concat( &nil, &x );
                THEN( "x's type is STRING" )
                    AND_THEN( "x's value is \"foo bar\"" ) {
                    REQUIRE( STRING == x.type );
                    REQUIRE( std::string("foo bar") == x.str );
                }
            }
            Val_del( &x );
        }
        GIVEN( "Val x = VAL(STRING)(NULL)" ) {
            Val x = VAL(STRING)(NULL);
            REQUIRE( STRING == x.type );
            REQUIRE( nullptr == x.str );
            WHEN( "x = Val_concat( &nil, &x )" ) {
                x = Val_concat( &nil, &x );
                THEN( "x's type is STRING" )
                    AND_THEN( "x's value is \"<{null:const char*}>\"" ) {
                    REQUIRE( STRING == x.type );
                    REQUIRE( std::string("<{null:const char*}>") == x.str );
                }
            }
            Val_del( &x );
        }
        GIVEN( "Val x = VAL(PARSER)(NULL)" ) {
            Val x = VAL(PARSER)(NULL);
            REQUIRE( PARSER == x.type );
            REQUIRE( nullptr == x.parser );
            WHEN( "x = Val_concat( &nil, &x )" ) {
                x = Val_concat( &nil, &x );
                THEN( "x's type is STRING" )
                    AND_THEN( "x's value is \"<{null:Parser}>\"" ) {
                    REQUIRE( STRING == x.type );
                    REQUIRE( std::string("<{null:Parser}>") == x.str );
                }
            }
            Val_del( &x );
        }
        GIVEN( "Val x = VAL(PREDICATE)(is_digit)" ) {
            Val x = VAL(PREDICATE)(is_digit);
            REQUIRE( PREDICATE == x.type );
            // REQUIRE( is_digit == x.predicate );
            Predicate pred = is_digit;
            REQUIRE( pred == x.predicate );
            WHEN( "x = Val_concat( &nil, &x )" ) {
                x = Val_concat( &nil, &x );
                THEN( "x's type is STRING" )
                    AND_THEN( "x's value is \"<{\?:Predicate}>\"" ) {
                    REQUIRE( STRING == x.type );
                    REQUIRE( std::string("<{\?:Predicate}>") == x.str );
                }
            }
            Val_del( &x );
        }
        GIVEN( "Val x = VAL(FN)(fn1(a_filter).f)" ) {
            Fn f = fn1(a_filter).f;
            Val x = VAL(D_FN)(Fn_ref(f));
            REQUIRE( FN == x.type );
            REQUIRE( f == x.fn );
            WHEN( "x = Val_concat( &nil, &x )" ) {
                x = Val_concat( &nil, &x );
                char p[32] = {0};
                snprintf( p, sizeof(p), "<{%p:Fn}>", (void*)f );
                THEN( "x's type is STRING" )
                    AND_THEN( "x's value is \"" + p + "\"" ) {
                    REQUIRE( STRING == x.type );
                    REQUIRE( std::string(p) == x.str );
                }
            }
            Val_del( &x );
            REQUIRE( 0 == Fn_live_count() );
        }
        GIVEN( "Val x = VAL(INT8)(1)" ) {
            Val x = VAL(INT8)(1);
            REQUIRE( INT8 == x.type );
            REQUIRE( 1 == x.i8 );
            WHEN( "Val y = VAL(I8)(1)" ) {
                Val y = VAL(I8)(1);
                THEN( "x == y" ) {
                    REQUIRE( INT8 == y.type );
                    REQUIRE( 1 == y.i8 );
                }
                Val_del( &y );
            }
            WHEN( "x = Val_concat( &nil, &x )" ) {
                x = Val_concat( &nil, &x );
                THEN( "x's type is STRING" )
                    AND_THEN( "x's value is \"1\"" ) {
                    REQUIRE( STRING == x.type );
                    REQUIRE( std::string("1") == x.str );
                }
            }
            Val_del( &x );
        }
        GIVEN( "Val x = VAL(INT16)(1)" ) {
            Val x = VAL(INT16)(1);
            REQUIRE( INT16 == x.type );
            REQUIRE( 1 == x.i16 );
            WHEN( "Val y = VAL(I16)(1)" ) {
                Val y = VAL(I16)(1);
                THEN( "x == y" ) {
                    REQUIRE( INT16 == y.type );
                    REQUIRE( 1 == y.i16 );
                }
                Val_del( &y );
            }
            WHEN( "x = Val_concat( &nil, &x )" ) {
                x = Val_concat( &nil, &x );
                THEN( "x's type is STRING" )
                    AND_THEN( "x's value is \"1\"" ) {
                    REQUIRE( STRING == x.type );
                    REQUIRE( std::string("1") == x.str );
                }
            }
            Val_del( &x );
        }
        GIVEN( "Val x = VAL(INT32)(1)" ) {
            Val x = VAL(INT32)(1);
            REQUIRE( INT32 == x.type );
            REQUIRE( 1 == x.i32 );
            WHEN( "Val y = VAL(I32)(1)" ) {
                Val y = VAL(I32)(1);
                THEN( "x == y" ) {
                    REQUIRE( INT32 == y.type );
                    REQUIRE( 1 == y.i32 );
                }
                Val_del( &y );
            }
            WHEN( "x = Val_concat( &nil, &x )" ) {
                x = Val_concat( &nil, &x );
                THEN( "x's type is STRING" )
                    AND_THEN( "x's value is \"1\"" ) {
                    REQUIRE( STRING == x.type );
                    REQUIRE( std::string("1") == x.str );
                }
            }
            Val_del( &x );
        }
        GIVEN( "Val x = VAL(INT64)(1)" ) {
            Val x = VAL(INT64)(1);
            REQUIRE( INT64 == x.type );
            REQUIRE( 1 == x.i64 );
            WHEN( "Val y = VAL(I64)(1)" ) {
                Val y = VAL(I64)(1);
                THEN( "x == y" ) {
                    REQUIRE( INT64 == y.type );
                    REQUIRE( 1 == y.i64 );
                }
                Val_del( &y );
            }
            WHEN( "x = Val_concat( &nil, &x )" ) {
                x = Val_concat( &nil, &x );
                THEN( "x's type is STRING" )
                    AND_THEN( "x's value is \"1\"" ) {
                    REQUIRE( STRING == x.type );
                    REQUIRE( std::string("1") == x.str );
                }
            }
            Val_del( &x );
        }
        GIVEN( "Val x = VAL(UINT8)(1)" ) {
            Val x = VAL(UINT8)(1);
            REQUIRE( UINT8 == x.type );
            REQUIRE( 1 == x.u8 );
            WHEN( "Val y = VAL(U8)(1)" ) {
                Val y = VAL(U8)(1);
                THEN( "x == y" ) {
                    REQUIRE( UINT8 == y.type );
                    REQUIRE( 1 == y.u8 );
                }
                Val_del( &y );
            }
            WHEN( "x = Val_concat( &nil, &x )" ) {
                x = Val_concat( &nil, &x );
                THEN( "x's type is STRING" )
                    AND_THEN( "x's value is \"1\"" ) {
                    REQUIRE( STRING == x.type );
                    REQUIRE( std::string("1") == x.str );
                }
            }
            Val_del( &x );
        }
        GIVEN( "Val x = VAL(UINT16)(1)" ) {
            Val x = VAL(UINT16)(1);
            REQUIRE( UINT16 == x.type );
            REQUIRE( 1 == x.u16 );
            WHEN( "Val y = VAL(U16)(1)" ) {
                Val y = VAL(U16)(1);
                THEN( "x == y" ) {
                    REQUIRE( UINT16 == y.type );
                    REQUIRE( 1 == y.u16 );
                }
                Val_del( &y );
            }
            WHEN( "x = Val_concat( &nil, &x )" ) {
                x = Val_concat( &nil, &x );
                THEN( "x's type is STRING" )
                    AND_THEN( "x's value is \"1\"" ) {
                    REQUIRE( STRING == x.type );
                    REQUIRE( std::string("1") == x.str );
                }
            }
            Val_del( &x );
        }
        GIVEN( "Val x = VAL(UINT32)(1)" ) {
            Val x = VAL(UINT32)(1);
            REQUIRE( UINT32 == x.type );
            REQUIRE( 1 == x.u32 );
            WHEN( "Val y = VAL(U32)(1)" ) {
                Val y = VAL(U32)(1);
                THEN( "x == y" ) {
                    REQUIRE( UINT32 == y.type );
                    REQUIRE( 1 == y.u32 );
                }
                Val_del( &y );
            }
            WHEN( "x = Val_concat( &nil, &x )" ) {
                x = Val_concat( &nil, &x );
                THEN( "x's type is STRING" )
                    AND_THEN( "x's value is \"1\"" ) {
                    REQUIRE( STRING == x.type );
                    REQUIRE( std::string("1") == x.str );
                }
            }
            Val_del( &x );
        }
        GIVEN( "Val x = VAL(UINT64)(1)" ) {
            Val x = VAL(UINT64)(1);
            REQUIRE( UINT64 == x.type );
            REQUIRE( 1 == x.u64 );
            WHEN( "Val y = VAL(U64)(1)" ) {
                Val y = VAL(U64)(1);
                THEN( "x == y" ) {
                    REQUIRE( UINT64 == y.type );
                    REQUIRE( 1 == y.u64 );
                }
                Val_del( &y );
            }
            WHEN( "x = Val_concat( &nil, &x )" ) {
                x = Val_concat( &nil, &x );
                THEN( "x's type is STRING" )
                    AND_THEN( "x's value is \"1\"" ) {
                    REQUIRE( STRING == x.type );
                    REQUIRE( std::string("1") == x.str );
                }
            }
            Val_del( &x );
        }
        Val_del( &nil );
    }
}
