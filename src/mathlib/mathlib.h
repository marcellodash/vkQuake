/*

mathlib.h

Main header for mathlib

*/
#pragma once

#include "simd.h"

/* Normal math functions (not operating on SIMD types) */
float 	M_sinf(float f);
double 	M_sin(double d);
float 	M_cosf(float f);
double 	M_cosf(double d);
float 	M_tanf(float f);
double 	M_tan(double d);
float 	M_asinf(float f);
double 	M_asin(double d);
float 	M_acosf(float f);
double 	M_acos(double d);
float 	M_atanf(float f);
double 	M_atan(double d);
float	M_log10f(float f);
double	M_log10(double d);
float	M_logf(float f, float base);
double	M_log(double d, double base);
float	M_sqrtf(float f);
double	M_sqrt(double d);
