/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include <string>
#include "catch.hpp"

#include "cparsec.h"
#include "cparsec/core/curry.h"

static Val add4( Val x1, Val x2, Val x3, Val x4 ) {
    return VAL(INT)( x1.i + x2.i + x3.i + x4.i );
}

static Val add9( Val x1, Val x2, Val x3, Val x4, Val x5, Val x6, Val x7, Val x8, Val x9 ) {
    return VAL(INT)( x1.i + x2.i + x3.i + x4.i + x5.i + x6.i + x7.i + x8.i + x9.i );
}

SCENARIO( "Tests function object type of Fn4", "[cparsec][fn][curry]" ) {
    GIVEN( "Val add4( Val,Val,Val,Val ) - returns sum of four integers" ) {
        WHEN( "Fn4 f = fn4(add4)" ) {
            Fn4 f = fn4(add4);
            REQUIRE( 1 == Fn_live_count() );
            THEN( "Fn_apply(f,1,2,3,4) results VAL(INT)(10)" ) {
                Val ret = Fn_apply(f,1,2,3,4);
                REQUIRE( 0 == Fn_live_count() );
                REQUIRE( INT == ret.type );
                REQUIRE( 10 == ret.i );
            }
        }
        WHEN( "Fn3 f = Fn_apply(add4,1)" ) {
            Fn3 f = Fn_apply(add4,1);
            REQUIRE( 2 == Fn_live_count() );
            THEN( "Fn_apply(f,2,3,4) results VAL(INT)(10)" ) {
                Val ret = Fn_apply(f,2,3,4);
                REQUIRE( 0 == Fn_live_count() );
                REQUIRE( INT == ret.type );
                REQUIRE( 10 == ret.i );
            }
        }
        WHEN( "Fn2 f = Fn_apply(add4,1,2)" ) {
            Fn2 f = Fn_apply(add4,1,2);
            REQUIRE( 3 == Fn_live_count() );
            THEN( "Fn_apply(f,3,4) results VAL(INT)(10)" ) {
                Val ret = Fn_apply(f,3,4);
                REQUIRE( 0 == Fn_live_count() );
                REQUIRE( INT == ret.type );
                REQUIRE( 10 == ret.i );
            }
        }
        WHEN( "Fn1 f = Fn_apply(add4,1,2,3)" ) {
            Fn1 f = Fn_apply(add4,1,2,3);
            REQUIRE( 4 == Fn_live_count() );
            THEN( "Fn_apply(f,4) results VAL(INT)(10)" ) {
                Val ret = Fn_apply(f,4);
                REQUIRE( 0 == Fn_live_count() );
                REQUIRE( INT == ret.type );
                REQUIRE( 10 == ret.i );
            }
        }
        WHEN( "Val ret = Fn_apply(add4,1,2,3,4)" ) {
            Val ret = Fn_apply(add4,1,2,3,4);
            REQUIRE( 0 == Fn_live_count() );
            THEN( "results ret = VAL(INT)(10)" ) {
                REQUIRE( INT == ret.type );
                REQUIRE( 10 == ret.i );
            }
        }
    }
    REQUIRE( 0 == Fn_live_count() );
}

SCENARIO( "Tests function object type of Fn9", "[cparsec][fn][curry]" ) {
    GIVEN( "Val add9( Val,Val,Val,Val,Val,Val,Val,Val,Val ) - returns sum of nine integers" ) {
        WHEN( "Fn9 f = fn9(add9)" ) {
            Fn9 f = fn9(add9);
            REQUIRE( 1 == Fn_live_count() );
            THEN( "Fn_apply(f,1,2,3,4,5,6,7,8,9) results VAL(INT)(45)" ) {
                Val ret = Fn_apply(f,1,2,3,4,5,6,7,8,9);
                REQUIRE( 0 == Fn_live_count() );
                REQUIRE( INT == ret.type );
                REQUIRE( 45 == ret.i );
            }
        }
        WHEN( "Fn8 f = Fn_apply(add9,1)" ) {
            Fn8 f = Fn_apply(add9,1);
            REQUIRE( 2 == Fn_live_count() );
            THEN( "Fn_apply(f,2,3,4,5,6,7,8,9) results VAL(INT)(45)" ) {
                Val ret = Fn_apply(f,2,3,4,5,6,7,8,9);
                REQUIRE( 0 == Fn_live_count() );
                REQUIRE( INT == ret.type );
                REQUIRE( 45 == ret.i );
            }
        }
        WHEN( "Fn7 f = Fn_apply(add9,1,2)" ) {
            Fn7 f = Fn_apply(add9,1,2);
            REQUIRE( 3 == Fn_live_count() );
            THEN( "Fn_apply(f,3,4,5,6,7,8,9) results VAL(INT)(45)" ) {
                Val ret = Fn_apply(f,3,4,5,6,7,8,9);
                REQUIRE( 0 == Fn_live_count() );
                REQUIRE( INT == ret.type );
                REQUIRE( 45 == ret.i );
            }
        }
        WHEN( "Fn6 f = Fn_apply(add9,1,2,3)" ) {
            Fn6 f = Fn_apply(add9,1,2,3);
            REQUIRE( 4 == Fn_live_count() );
            THEN( "Fn_apply(f,4,5,6,7,8,9) results VAL(INT)(45)" ) {
                Val ret = Fn_apply(f,4,5,6,7,8,9);
                REQUIRE( 0 == Fn_live_count() );
                REQUIRE( INT == ret.type );
                REQUIRE( 45 == ret.i );
            }
        }
        WHEN( "Fn5 f = Fn_apply(add9,1,2,3,4)" ) {
            Fn5 f = Fn_apply(add9,1,2,3,4);
            REQUIRE( 5 == Fn_live_count() );
            THEN( "Fn_apply(f,5,6,7,8,9) results VAL(INT)(45)" ) {
                Val ret = Fn_apply(f,5,6,7,8,9);
                REQUIRE( 0 == Fn_live_count() );
                REQUIRE( INT == ret.type );
                REQUIRE( 45 == ret.i );
            }
        }
        WHEN( "Fn4 f = Fn_apply(add9,1,2,3,4,5)" ) {
            Fn4 f = Fn_apply(add9,1,2,3,4,5);
            REQUIRE( 6 == Fn_live_count() );
            THEN( "Fn_apply(f,6,7,8,9) results VAL(INT)(45)" ) {
                Val ret = Fn_apply(f,6,7,8,9);
                REQUIRE( 0 == Fn_live_count() );
                REQUIRE( INT == ret.type );
                REQUIRE( 45 == ret.i );
            }
        }
        WHEN( "Fn3 f = Fn_apply(add9,1,2,3,4,5,6)" ) {
            Fn3 f = Fn_apply(add9,1,2,3,4,5,6);
            REQUIRE( 7 == Fn_live_count() );
            THEN( "Fn_apply(f,7,8,9) results VAL(INT)(45)" ) {
                Val ret = Fn_apply(f,7,8,9);
                REQUIRE( 0 == Fn_live_count() );
                REQUIRE( INT == ret.type );
                REQUIRE( 45 == ret.i );
            }
        }
        WHEN( "Fn2 f = Fn_apply(add9,1,2,3,4,5,6,7)" ) {
            Fn2 f = Fn_apply(add9,1,2,3,4,5,6,7);
            REQUIRE( 8 == Fn_live_count() );
            THEN( "Fn_apply(f,8,9) results VAL(INT)(45)" ) {
                Val ret = Fn_apply(f,8,9);
                REQUIRE( 0 == Fn_live_count() );
                REQUIRE( INT == ret.type );
                REQUIRE( 45 == ret.i );
            }
        }
        WHEN( "Fn1 f = Fn_apply(add9,1,2,3,4,5,6,7,8)" ) {
            Fn1 f = Fn_apply(add9,1,2,3,4,5,6,7,8);
            REQUIRE( 9 == Fn_live_count() );
            THEN( "Fn_apply(f,9) results VAL(INT)(45)" ) {
                Val ret = Fn_apply(f,9);
                REQUIRE( 0 == Fn_live_count() );
                REQUIRE( INT == ret.type );
                REQUIRE( 45 == ret.i );
            }
        }
        WHEN( "Val ret = Fn_apply(add9,1,2,3,4,5,6,7,8,9)" ) {
            Val ret = Fn_apply(add9,1,2,3,4,5,6,7,8,9);
            REQUIRE( 0 == Fn_live_count() );
            THEN( "results ret = VAL(INT)(45)" ) {
                REQUIRE( INT == ret.type );
                REQUIRE( 45 == ret.i );
            }
        }
    }
    REQUIRE( 0 == Fn_live_count() );
}
