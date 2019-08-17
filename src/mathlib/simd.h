/*

simd.h

SIMD extensions main header

*/
#pragma once

#include <stdint.h>
#include <stddef.h>

#ifdef _USE_SSE 
#include "sse.h"
#endif

#ifdef _USE_AVX
#include "avx.h"
#endif

#ifdef _USE_NEON
#include "neon.h"
#endif

#ifdef _USE_SVE
#include "sve.h"
#endif

#if defined(_USE_SSE) || defined(_USE_AVX) || defined(_USE_NEON) || defined(_USE_SVE)
#define _USE_SIMD
#endif //_USE_SIMD

/* If the SIMD headers do not override this stuff, we must act! */
#ifndef _DEFINED_M64
typedef union
{
	float		f32[2];
	uint32_t	u32[2];
} __m64;
#endif

#ifndef _DEFINED_M128
typedef union
{
	float		f32[4];
	uint32_t	u32[4];
} __m128;

typedef union
{
	double		f64[2];
	uint64_t	u64[2];
} __m128d;

typedef union
{
	uint32_t 	u32[4];
} __m128i;
#endif

#ifndef _DEFINED_M256
typedef union
{
	float 		f32[8];
	uint32_t	u32[8];
} __m256;

typedef union
{
	double 		f64[4];
	uint64_t 	u64[4];
} __m256d;

typedef union
{
	uint32_t	u32[8];
} __m256i;
#endif

typedef __m64	v64_t;
typedef __m128 	v128_t;
typedef __m128d v128d_t;
typedef __m128i v128i_t;
typedef __m256	v256_t;
typedef __m256d v256d_t;
typedef __m256i v256i_t;
typedef __m64	m64_t;
typedef __m128 	m128_t;
typedef __m128d m128d_t;
typedef __m128i m128i_t;
typedef __m256	m256_t;
typedef __m256d m256d_t;
typedef __m256i m256i_t;
