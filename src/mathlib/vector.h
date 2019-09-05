/*

vector.h

Vector math!

Notes:
	- Possible endianness issue with the unions (only would happen on big endian systems)
	- Unions are not always 16 bytes in size. they are aligned to 16-byte boundaries, so they wont cause segfaults as they don't cross page boundaries.
	- Compile with g++ or another c++ compiler.
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
} vec3_t;

typedef ALIGN16 PACKED union vec4_s
{
	struct {
		float x, y, z, m;
	} components;
	float xyzm[4];
} vec4_t;

/* Not using SIMD stuff right now since a 2 component vector doesn't really need it much */
typedef ALIGN16 PACKED union vec2_s
{
	struct {
		float x, y;
	} components;
	float xy[2];
} vec2_t;

typedef ALIGN16 PACKED union vec3d_s
{
	struct {
		double x, y, z;
	} components;
	double xyz[3];
} vec3d_t;

typedef ALIGN16 PACKED union vec4d_s
{
	struct {
		double x,y,z,m;
	} components;
	double xyzm[4];
} vec4d_t;

typedef ALIGN16 PACKED union vec2d_s
{
	struct {
		double x, y;
	} components;
	double xy[2];
} vec2d_t;

/* This is REQUIRED for legacy Quake compat! */
#ifdef __cplusplus 

/* Operation: v1 = v1 + v2; return v1 */
vec3_t Vector3Add(vec3_t& v1, vec3_t v2);
vec2_t Vector2Add(vec2_t& v1, vec2_t v2);

/* Operation: v1 = v1 - v2; return v1 */
vec3_t Vector3Sub(vec3_t& v1, vec3_t v2);
vec2_t Vector2Sub(vec2_t& v1, vec2_t v2);

/* Operation: v1 = v1 * c; return v1 */
vec3_t Vector3Mul(vec3_t& v1, double c);
vec2_t Vector2Mul(vec2_t& v1, double c);

/* Operation: v1 = v1 / c; return v1 */
vec3_t Vector3Div(vec3_t& v1, double c);
vec2_t Vector2Div(vec2_t& v1, double c);

/* Linear interpolation */
vec3_t Vector3Lerp(vec3_t v1, vec3_t v2, float bias);
vec2_t Vector2Lerp(vec2_t v1, vec2_t v2, float bias);

/* Dot product */
float Vector3Dot(vec3_t v1, vec3_t v2);
float Vector2Dot(vec2_t v1, vec2_t v2);

/* Cross product */
vec2_t Vector3Cross(vec3_t v1, vec3_t v2);
vec2_t Vector2Cross(vec2_t v1, vec2_t v2);

#endif /* _cpplusplus */

/*========================================
 * Overrides for the quake mathlib 
 *========================================*/

/* Return dot between x and y */
float 	DotProduct					(vec3_t x, vec3_t y);
/* Return double dot between x and y */
double	DoublePrecisionDotProduct	(vec3_t x, vec3_t y);
/* c = a - b */
void	VectorSubtract				(vec3_t a, vec3_t b, vec3_t* c);
/* c = a + b */
void	VectorAdd					(vec3_t a, vec3_t b, vec3_t* c);
/* b = a */
void	VectorCopy					(vec3_t a, vec3_t* b);
void 	TurnVector					(vec3_t& out, const vec3_t forward, const vec3_t side, float angle); //johnfitz
/* Generates pitch, yaw and roll from forward. Result in angles */
void 	VectorAngles				(const vec3_t forward, vec3_t* angles); //johnfitz
/* Operation: vecc = veca + vecb * scale; */
void 	VectorMA					(vec3_t veca, float scale, vec3_t vecb, vec3_t* vecc);
/* Returns dot of v1 and v2 */
float	_DotProduct					(vec3_t v1, vec3_t v2);
/* Operation: out = veca - vecb */
void	_VectorSubtract 			(vec3_t veca, vec3_t vecb, vec3_t* out);
/* Operation: out = veca + vecb */
void	_VectorAdd					(vec3_t veca, vec3_t vecb, vec3_t* out);
/* Copies in to out */
void	_VectorCopy					(vec3_t in, vec3_t* out);
/* Compare v1 and v2, return 0 if not equal */
int		VectorCompare				(vec3_t v1, vec3_t v2);
/* Returns the length of the vector, similar to normalize, but does not actually normalize the vector */
float	VectorLength				(vec3_t v);
/* Performs the cross product on v1 and v2, stores result in cross */
void	CrossProduct				(vec3_t v1, vec3_t v2, vec3_t* cross);
/* Normalizes a vector and returns the magnitude of it */
float	VectorNormalize 			(vec3_t* v);
/* v = -v */
void	VectorInverse				(vec3_t* v);
/* Scales vector by scale and puts result in out */
void	VectorScale					(vec3_t in, float scale, vec3_t* out);
int		Q_log2						(int val);
int		Q_nextPow2					(int val);

#define VectorNormalizeFast(_v) VectorNormalize(_v)
