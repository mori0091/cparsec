/* -*- mode: c++ ; coding: utf-8-unix -*- */

#pragma once

#ifndef CPARSEC_SOURCE_H
#define CPARSEC_SOURCE_H

#include "cparsec.h"

#ifdef __cplusplus
extern "C" {
#endif

  typedef struct Source Source;
  struct Source {
    const char* s;
    int line;
    int col;
  };

  Source Source_init( const char* str );
  Val Source_peek( Source* src );
  Val Source_next( Source* src );
  Val Source_error( const Source* src, const char* msg );

#ifdef __cplusplus
}
#endif

#endif	/* CPARSEC_SOURCE_H */
