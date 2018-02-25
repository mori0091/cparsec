/* -*- mode: c ; coding: utf-8-unix -*- */

#include <stdio.h>

#define UNUSED_VARIABLE(x)    (void)(x)
#define EXAMPLE(expr)         \
    printf("Example : %s\n--------------------------------\n", #expr); expr

extern void ex_Fn_apply( void );

int main( int argc, char** argv )
{
    UNUSED_VARIABLE(argc);
    UNUSED_VARIABLE(argv);

    EXAMPLE( ex_Fn_apply() );

    return 0;
}
