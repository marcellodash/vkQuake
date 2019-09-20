#include "simd.h"
#include "vector.h"

/* Operation: v1 = v1 + v2; return v1 */
vec3_t Vector3Add(vec3_t& v1, vec3_t v2)
{
#ifdef _USE_SSE 
	/*=========================
	 * x86 SSE Implementation
	 *=========================*/

#elif defined(_USE_NEON)
	/*=========================
	 * ARM NEON Implementation
	 *=========================*/

#else
	/*=========================
	 * Non-SIMD Implementation
	 *=========================*/
	v1.xyz[0] = v1.xyz[0] + v2.xyz[0];
	v1.xyz[1] = v1.xyz[1] + v2.xyz[1];
	v1.xyz[2] = v1.xyz[2] + v2.xyz[2];
	return v1;
#endif
}

vec2_t Vector2Add(vec2_t& v1, vec2_t v2)
{
#ifdef _USE_SSE 
	/*=========================
	 * x86 SSE Implementation
	 *=========================*/


#elif defined(_USE_NEON)
	/*=========================
	 * ARM NEON Implementation
	 *=========================*/

#else
	/*=========================
	 * Non-SIMD Implementation
	 *=========================*/
	v1.xy[0] = v1.xy[0] + v2.xy[0];
	v1.xy[1] = v1.xy[1] + v2.xy[1];
	return v1;
#endif
}
/* Operation: v1 = v1 - v2; return v1 */
vec3_t Vector3Sub(vec3_t& v1, vec3_t v2)
{
#ifdef _USE_SSE 
	/*=========================
	 * x86 SSE Implementation
	 *=========================*/


#elif defined(_USE_NEON)
	/*=========================
	 * ARM NEON Implementation
	 *=========================*/

#else
	/*=========================
	 * Non-SIMD Implementation
	 *=========================*/
	v1.xyz[0] = v1.xyz[0] - v2.xyz[0];
	v1.xyz[1] = v1.xyz[1] - v2.xyz[1];
	v1.xyz[2] = v1.xyz[2] - v2.xyz[2];
	return v1;
#endif
}

vec2_t Vector2Sub(vec2_t& v1, vec2_t v2)
{
#ifdef _USE_SSE 
	/*=========================
	 * x86 SSE Implementation
	 *=========================*/


#elif defined(_USE_NEON)
	/*=========================
	 * ARM NEON Implementation
	 *=========================*/

#else
	/*=========================
	 * Non-SIMD Implementation
	 *=========================*/
	v1.xy[0] = v1.xy[0] + v2.xy[0];
	v1.xy[1] = v1.xy[1] + v2.xy[1];
	return v1;
#endif
}

/* Operation: v1 = v1 * c; return v1 */
vec3_t Vector3Mul(vec3_t& v1, double c)
{
#ifdef _USE_SSE 
	/*=========================
	 * x86 SSE Implementation
	 *=========================*/


#elif defined(_USE_NEON)
	/*=========================
	 * ARM NEON Implementation
	 *=========================*/

#else
	/*=========================
	 * Non-SIMD Implementation
	 *=========================*/
	v1.xyz[0] = v1.xyz[0] * c;
	v1.xyz[1] = v1.xyz[1] * c;
	v1.xyz[2] = v1.xyz[2] * c;
	return v1;
#endif
}

vec2_t Vector2Mul(vec2_t& v1, double c)
{
	/*=========================
	 * Non-SIMD Implementation
	 *=========================*/
	v1.xy[0] = v1.xy[0] * c;
	v1.xy[1] = v1.xy[1] * c;
	return v1;
}

/* Operation: v1 = v1 / c; return v1 */
vec3_t Vector3Div(vec3_t& v1, double c)
{
#ifdef _USE_SSE 
	/*=========================
	 * x86 SSE Implementation
	 *=========================*/


#elif defined(_USE_NEON)
	/*=========================
	 * ARM NEON Implementation
	 *=========================*/

#else
	/*=========================
	 * Non-SIMD Implementation
	 *=========================*/
	v1.xyz[0] = v1.xyz[0] / c;
	v1.xyz[1] = v1.xyz[1] / c;
	v1.xyz[2] = v1.xyz[2] / c;
	return v1;
#endif
}

vec2_t Vector2Div(vec2_t& v1, double c)
{
	/*=========================
	 * Non-SIMD Implementation
	 *=========================*/
	v1.xy[0] = v1.xy[0] / c;
	v1.xy[1] = v1.xy[1] / c;
	return v1;
}

/* Linear interpolation */
vec3_t Vector3Lerp(vec3_t v1, vec3_t v2, float bias)
{
#ifdef _USE_SSE 
	/*=========================
	 * x86 SSE Implementation
	 *=========================*/


#elif defined(_USE_NEON)
	/*=========================
	 * ARM NEON Implementation
	 *=========================*/

#else
	/*=========================
	 * Non-SIMD Implementation
	 *=========================*/
	
#endif
}

vec2_t Vector2Lerp(vec2_t v1, vec2_t v2, float bias)
{
	/*=========================
	 * Non-SIMD Implementation
	 *=========================*/


}
