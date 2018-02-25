/* -*- mode: c++ ; coding: utf-8-unix -*- */

#pragma once

#ifndef CPARSEC_PRIMITIVE_SINGLETON_H
#define CPARSEC_PRIMITIVE_SINGLETON_H

#include "cparsec.h"

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

    //// primitive predicates
    bool is_any_char( char c );
    bool is_digit( char c );
    bool is_lower( char c );
    bool is_upper( char c );
    bool is_alpha( char c );
    bool is_alnum( char c );
    bool is_letter( char c );

#ifdef __cplusplus
}
#endif

#endif  /* CPARSEC_PRIMITIVE_SINGLETON_H */
