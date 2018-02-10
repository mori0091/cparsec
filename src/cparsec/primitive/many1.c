/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include "cparsec/primitive/many1.h"

Parser many1( Parser x )
{
    return seq( x, many( x ) );
}
