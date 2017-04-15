#ifndef VALUE_HPP
#define VALUE_HPP

#include "types.hpp"

#define FAILURE -1;
#define SUCCESS  1;

#define IS_FAILURE(x) ( x == -1 ? true : false )
#define IS_SUCCESS(x) ( x != -1 ? x : false )
#define IS_NULLPO(x) ( !x )
#define IS_ZERO(x) (!x)

#endif
