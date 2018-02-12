/* -*- mode: c++ ; coding: utf-8-unix -*- */

#pragma once

#ifndef CPARSEC_PRIMITIVE_SATISFY_H
#define CPARSEC_PRIMITIVE_SATISFY_H

#include "cparsec/gen_parser/predicate.h"

#define SATISFY( x )            PREDICATE( satisfy, (x) )
#define SATISFY_ST( x )         PREDICATE_ST( satisfy, (x) )
#define SATISFY_ST_INIT( x )    PREDICATE_ST_INIT( satisfy, (x) )

#ifdef __cplusplus
extern "C" {
#endif

    extern DECL_PARSER_FUNC( satisfy );

#ifdef __cplusplus
}
#endif

#endif  /* CPARSEC_PRIMITIVE_SATISFY_H */
