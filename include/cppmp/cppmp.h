/* -*- mode: c++ ; coding: utf-8-unix -*- */

#pragma once

#ifndef C_PRE_PROCESSOR_META_PROGRAMMING_H
#define C_PRE_PROCESSOR_META_PROGRAMMING_H

/** \brief CAT(x,y): concatnates x and y */
#define CPPMP_CAT(x,y)             CPPMP_CAT_I(x,y)
#define CPPMP_CAT_I(x,y)           x ## y

/** \brief COMPLEMENT(x): 1-bit complement ; i.e. 0 if x was 1, 1 if x was 0. */
#define CPPMP_COMPLEMENT(x)        CPPMP_CAT_I(CPPMP_COMPLEMENT_,x)
#define CPPMP_COMPLEMENT_0         1
#define CPPMP_COMPLEMENT_1         0

/** \brief BITAND(x)(y):  1-bit bitwise AND ; i.e. y if x was 1, 0 if x was 0. */
#define CPPMP_BITAND(x)            CPPMP_CAT_I(CPPMP_BITAND_,x)
#define CPPMP_BITAND_0(y)          0
#define CPPMP_BITAND_1(y)          y

/** \brief BITOR(x)(y):  1-bit bitwise OR ; i.e. 1 if x was 1, y if x was 0. */
#define CPPMP_BITOR(x)             CPPMP_CAT_I(CPPMP_BITOR_,x)
#define CPPMP_BITOR_0(y)           y
#define CPPMP_BITOR_1(y)           1

#define CPPMP_CHECK(...)           CPPMP_CHECK_N(__VA_ARGS__,0,)
#define CPPMP_CHECK_N(x,n,...)     n
#define CPPMP_PROBE(x)             x,1,

#define CPPMP_IS_PAREN(x)          CPPMP_CHECK(CPPMP_IS_PAREN_PROBE x)
#define CPPMP_IS_PAREN_PROBE(...)  CPPMP_PROBE(_)

/** \brief NOT(x): 1 if x was 0, otherwise 0 */
#define CPPMP_NOT(x)               CPPMP_CHECK(CPPMP_CAT_I(CPPMP_NOT_,x))
#define CPPMP_NOT_0                CPPMP_PROBE(_)

/** \brief BOOL(x): 1 if x was not 0, otherwise 0 */
#define CPPMP_BOOL(x)              CPPMP_COMPLEMENT(CPPMP_NOT(x))

/** \brief IIF(x)(t,f): t if x was 1, f if x was 0 */
#define CPPMP_IIF(x)               CPPMP_CAT(CPPMP_IIF_,x)
#define CPPMP_IIF_0(t,f)           f
#define CPPMP_IIF_1(t,f)           t

/** \brief IF(x)(t,f): t if x was not 0, f if x was 0 */
#define CPPMP_IF(c)                CPPMP_IIF(CPPMP_BOOL(c))

/** \brief EAT(...): consumes a subsequent paren */
#define CPPMP_EAT(...)
/** \brief EXPAND(...): expands token(s) in a subsequent paren */
#define CPPMP_EXPAND(...)          __VA_ARGS__
/** \brief WHEN(c)(t): expands t when and only when c was not 0 */
#define CPPMP_WHEN(c)              CPPMP_IF(c)(CPPMP_EXPAND,CPPMP_EAT)

#define CPPMP_EMPTY()
#define CPPMP_DEFER(id)            id CPPMP_EMPTY()
#define CPPMP_DEFER2(id)           id CPPMP_DEFER(CPPMP_EMPTY)()

/** \brief EVAL(...): expands and expands and expands ... */
#define CPPMP_EVAL(...)            CPPMP_EVAL1(CPPMP_EVAL1(CPPMP_EVAL1(__VA_ARGS__)))
#define CPPMP_EVAL1(...)           CPPMP_EVAL2(CPPMP_EVAL2(CPPMP_EVAL2(__VA_ARGS__)))
#define CPPMP_EVAL2(...)           CPPMP_EVAL3(CPPMP_EVAL3(CPPMP_EVAL3(__VA_ARGS__)))
#define CPPMP_EVAL3(...)           CPPMP_EVAL4(CPPMP_EVAL4(CPPMP_EVAL4(__VA_ARGS__)))
#define CPPMP_EVAL4(...)           CPPMP_EVAL5(CPPMP_EVAL5(CPPMP_EVAL5(__VA_ARGS__)))
#define CPPMP_EVAL5(...)           __VA_ARGS__

/** \brief EQUAL(x,y): true if both of x and y are comparable and if x == y. */
#define CPPMP_EQUAL(x,y)           CPPMP_COMPLEMENT(CPPMP_NOT_EQUAL(x,y))
/** \brief NOT_EQUAL(x,y): true if either x or y is not comparable or if x != y. */
#define CPPMP_NOT_EQUAL(x,y)       CPPMP_IIF(CPPMP_BITAND(CPPMP_IS_COMPARABLE(x))(CPPMP_IS_COMPARABLE(y))) (CPPMP_COMPARE, 1 CPPMP_EAT)(x,y)

#define CPPMP_IS_COMPARABLE(x)     CPPMP_IS_PAREN( CPPMP_CAT( CPPMP_COMPARE_, x ) (()) )
#define CPPMP_COMPARE(x,y)         CPPMP_IS_PAREN( CPPMP_COMPARE_ ## x ( CPPMP_COMPARE_ ## y ) (()) )

#define CPPMP_COMPARE_0(x)         x
#define CPPMP_COMPARE_1(x)         x
#define CPPMP_COMPARE_2(x)         x
#define CPPMP_COMPARE_3(x)         x
#define CPPMP_COMPARE_4(x)         x
#define CPPMP_COMPARE_5(x)         x
#define CPPMP_COMPARE_6(x)         x
#define CPPMP_COMPARE_7(x)         x
#define CPPMP_COMPARE_8(x)         x
#define CPPMP_COMPARE_9(x)         x
#define CPPMP_COMPARE_10(x)        x
#define CPPMP_COMPARE_11(x)        x
#define CPPMP_COMPARE_12(x)        x
#define CPPMP_COMPARE_13(x)        x
#define CPPMP_COMPARE_14(x)        x
#define CPPMP_COMPARE_15(x)        x
#define CPPMP_COMPARE_16(x)        x
#define CPPMP_COMPARE_17(x)        x
#define CPPMP_COMPARE_18(x)        x
#define CPPMP_COMPARE_19(x)        x
#define CPPMP_COMPARE_20(x)        x
#define CPPMP_COMPARE_21(x)        x
#define CPPMP_COMPARE_22(x)        x
#define CPPMP_COMPARE_23(x)        x
#define CPPMP_COMPARE_24(x)        x
#define CPPMP_COMPARE_25(x)        x
#define CPPMP_COMPARE_26(x)        x
#define CPPMP_COMPARE_27(x)        x
#define CPPMP_COMPARE_28(x)        x
#define CPPMP_COMPARE_29(x)        x
#define CPPMP_COMPARE_30(x)        x
#define CPPMP_COMPARE_31(x)        x
#define CPPMP_COMPARE_32(x)        x

/** \brief VARIAIC_SIZE(...): How much elements are in the comma separated list? (1..32) */
#define CPPMP_VARIADIC_SIZE(...)   CPPMP_VARIADIC_SIZE_I(__VA_ARGS__,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,)
#define CPPMP_VARIADIC_SIZE_I(e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14,e15,e16,e17,e18,e19,e20,e21,e22,e23,e24,e25,e26,e27,e28,e29,e30,e31,size,...) size

/**
 * \brief ACCUMULATE(f,a,...): Accumulates ; ACCUMULATE(f,a,1,2,3) --> f(f(f(a,1),2),3)
 * ~~~c
 * #define add(x,y) x + y
 * #define SUM(...) CPPMP_ACCUMULATE(add,0,__VA_ARGS__)
 * SUM(1,2,3) --> expands to 0 + 1 + 2 + 3
 * ~~~
 */
#define CPPMP_ACCUMULATE(f,a,...)      CPPMP_EVAL(CPPMP_ACCUMULATE_I(f,a,__VA_ARGS__,))
#define CPPMP_ACCUMULATE_I(f,a,x,...)  CPPMP_IF(CPPMP_EQUAL(CPPMP_VARIADIC_SIZE(__VA_ARGS__,),2)) (f(a,x),CPPMP_DEFER2(CPPMP_ACCUMULATE_INDIRECT)()(f,f(a,x),__VA_ARGS__))
#define CPPMP_ACCUMULATE_INDIRECT()    CPPMP_ACCUMULATE_I

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif  /* C_PRE_PROCESSOR_META_PROGRAMMING_H */
