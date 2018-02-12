/* -*- mode: c++ ; coding: utf-8-unix -*- */

#pragma once

#ifndef CPARSEC_UTIL_STRING_UTILS_H
#define CPARSEC_UTIL_STRING_UTILS_H

/**
 * \brief Define a concatenated string (char[])
 *
 * DEF_STRING( str, ... ) defines and instantiates `char str[]` and
 * `size_t str_length` as an auto (local) variable.
 *
 * ~~~c
 * DEF_STRING( x, "aaa", "bbb" );
 * // --> size_t x_length = 7;
 * // --> char x[] = "aaabbb";
 *
 * const char* msg = "Hello World!"
 * DEF_STRING( y, "<<< ", msg, " >>>" );
 * // --> size_t y_length = 21;
 * // --> char y[] = "<<< Hello World! >>>";
 * ~~~
 *
 * \param _msg_   an identifier of variable to be defined.
 */
#define DEF_STRING( _msg_, ... )           DEF_STRING_1( _msg_, __VA_ARGS__ )
#define DEF_STRING_1( _msg_, ... )         DEF_STRING_2( _msg_, _msg_ ## __len_gth, __VA_ARGS__ )
#define DEF_STRING_2( _msg_, _len_, ... )  DEF_STRING_3( _msg_, _len_, __VA_ARGS__ )
#define DEF_STRING_3( _msg_, _len_, ... )               \
    size_t _len_ = 1;                                   \
    {                                                   \
        const char* _s[] = { __VA_ARGS__, NULL };       \
        for ( int i = 0; _s[i]; ++i ) {                 \
            _len_ += strlen( _s[i] );                   \
        }                                               \
    }                                                   \
    char _msg_[_len_];                                  \
    _msg_[0] = '\0';                                    \
    do {                                                \
        const char* _s[] = { __VA_ARGS__, NULL };       \
        for ( int i = 0; _s[i]; ++i ) {                 \
            strcat( _msg_, _s[i] );                     \
        }                                               \
    } while(0)

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif  /* CPARSEC_UTIL_STRING_UTILS_H */
