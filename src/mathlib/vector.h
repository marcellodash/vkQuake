/*

vector.h

Vector math!

*/
#pragma once

#include "simd.h"
#include "platform.h"

/* TODO: This should be cleaned up a bit, especially member naming */
typedef ALIGN16 PACKED union vec3_s
{
	struct {
		float x, y, z;
	} components;
	float xyz[3];
#ifdef _USE_SIMD
	__m128 vec;
#endif //_USE_SIMD
} vec3_t;

typedef ALIGN16 PACKED union vec4_s
{
	struct {
		float x, y, z, m;
	} components;
	float xyzm[4];
#ifdef _USE_SIMD
	__m128 vec;
#endif
} vec4_t;

/* Not using SIMD stuff right now since a 2 component vector doesn't really need it much */
typedef ALIGN16 PACKED union vec2_s
{
	struct {
		float x, y;
	} components;
	float xy[2];
#ifdef _USE_SIMD
	//__m128 vec;
#endif //_USE_SIMD
} vec2_t;
