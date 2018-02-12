/* -*- mode: c++ ; coding: utf-8-unix -*- */

#pragma once

#ifndef CPARSEC_PRIMITIVE_MANY1_H
#define CPARSEC_PRIMITIVE_MANY1_H

#include "cparsec/primitive/many.h"
#include "cparsec/primitive/seq.h"

#define MANY1( x )            SEQ( x, MANY( x ) )

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif  /* CPARSEC_PRIMITIVE_MANY1_H */
