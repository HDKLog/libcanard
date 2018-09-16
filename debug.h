/*
 * debug.h
 *
 *  Created on: Sep 16, 2018
 *      Author: John
 */

#ifndef DEBUG_H_
#define DEBUG_H_

/// By default this macro resolves to the standard assert(). The user can redefine this if necessary.
#ifndef CANARD_ASSERT
# define CANARD_ASSERT(x)
#endif

#define CANARD_GLUE(a, b)           CANARD_GLUE_IMPL_(a, b)
#define CANARD_GLUE_IMPL_(a, b)     a##b

/// By default this macro expands to static_assert if supported by the language (C11, C++11, or newer).
/// The user can redefine this if necessary.
#ifndef CANARD_STATIC_ASSERT
# if (defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 201112L)) ||\
     (defined(__cplusplus) && (__cplusplus >= 201103L))
#  define CANARD_STATIC_ASSERT(...) static_assert(__VA_ARGS__)
# else
#  define CANARD_STATIC_ASSERT(x, ...) typedef char CANARD_GLUE(_static_assertion_, __LINE__)[(x) ? 1 : -1]
# endif
#endif

#endif /* DEBUG_H_ */
