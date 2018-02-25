/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include "cparsec.h"

Parser many1( Parser x )
{
    return seq( x, many( x ) );
}
