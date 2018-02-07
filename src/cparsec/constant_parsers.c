/* -*- mode: c++ ; coding: utf-8-unix -*- */

#include "cparsec.h"
#include "cparsec/parser.h"
#include "cparsec/satisfy.h"

static ParserSt any_char_ = SATISFY_ST_INIT( is_any_char );
static ParserSt digit_    = SATISFY_ST_INIT( is_digit );
static ParserSt lower_    = SATISFY_ST_INIT( is_lower );
static ParserSt upper_    = SATISFY_ST_INIT( is_upper );
static ParserSt alpha_    = SATISFY_ST_INIT( is_alpha );
static ParserSt alnum_    = SATISFY_ST_INIT( is_alnum );
static ParserSt letter_   = SATISFY_ST_INIT( is_letter );

Parser any_char = &any_char_;
Parser digit    = &digit_;
Parser lower    = &lower_;
Parser upper    = &upper_;
Parser alpha    = &alpha_;
Parser alnum    = &alnum_;
Parser letter   = &letter_;
