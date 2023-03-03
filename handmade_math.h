/*
  handmade_math.h v2.0.0

  This is a single header file with a bunch of useful types and functions for
  games and graphics. Consider it a lightweight alternative to GLM that works
  both C and C++.

  =============================================================================
  CONFIG
  =============================================================================

  By default, all angles in Handmade Math are specified in radians. However, it
  can be configured to use degrees or turns instead. Use one of the following
  defines to specify the default unit for angles:

    #define HANDMADE_MATH_USE_RADIANS
    #define HANDMADE_MATH_USE_DEGREES
    #define HANDMADE_MATH_USE_TURNS

  Regardless of the default angle, you can use the following functions to
  specify an angle in a particular unit:

    angle_rad(radians)
    angle_deg(degrees)
    angle_turn(turns)

  The definitions of these functions change depending on the default unit.

  -----------------------------------------------------------------------------

  Handmade Math ships with SSE (SIMD) implementations of several common
  operations. To disable the use of SSE intrinsics, you must define
  HANDMADE_MATH_NO_SSE before including this file:

    #define HANDMADE_MATH_NO_SSE
    #include "handmade_math.h"

  -----------------------------------------------------------------------------

  To use Handmade Math without the C runtime library, you must provide your own
  implementations of basic math functions. Otherwise, handmade_math.h will use
  the runtime library implementation of these functions.

  Define HANDMADE_MATH_PROVIDE_MATH_FUNCTIONS and provide your own
  implementations of HMM_SINF, HMM_COSF, HMM_TANF, HMM_ACOSF, and HMM_SQRTF
  before including handmade_math.h, like so:

    #define HANDMADE_MATH_PROVIDE_MATH_FUNCTIONS
    #define HMM_SINF MySinF
    #define HMM_COSF MyCosF
    #define HMM_TANF MyTanF
    #define HMM_ACOSF MyACosF
    #define HMM_SQRTF MySqrtF
    #include "handmade_math.h"
  
  By default, it is assumed that your math functions take radians. To use
  different units, you must define HMM_ANGLE_USER_TO_INTERNAL and
  HMM_ANGLE_INTERNAL_TO_USER. For example, if you want to use degrees in your
  code but your math functions use turns:

    #define HMM_ANGLE_USER_TO_INTERNAL(a) ((a)*deg_to_turn)
    #define HMM_ANGLE_INTERNAL_TO_USER(a) ((a)*turn_to_deg)

  =============================================================================
  
  LICENSE

  This software is in the public domain. Where that dedication is not
  recognized, you are granted a perpetual, irrevocable license to copy,
  distribute, and modify this file as you see fit.

  =============================================================================

  CREDITS

  Originally written by Zakary Strange.

  Functionality:
   Zakary Strange (strangezak@protonmail.com && @strangezak)
   Matt Mascarenhas (@miblo_)
   Aleph
   FieryDrake (@fierydrake)
   Gingerbill (@TheGingerBill)
   Ben Visness (@bvisness)
   Trinton Bullard (@Peliex_Dev)
   @AntonDan
   Logan Forman (@dev_dwarf)

  Fixes:
   Jeroen van Rijn (@J_vanRijn)
   Kiljacken (@Kiljacken)
   Insofaras (@insofaras)
   Daniel Gibson (@DanielGibson)
*/

#ifndef HANDMADE_MATH_H
#define HANDMADE_MATH_H

// Dummy macros for when test framework is not present.
#ifndef COVERAGE
# define COVERAGE(a, b)
#endif

#ifndef ASSERT_COVERED
# define ASSERT_COVERED(a)
#endif

/* let's figure out if SSE is really available (unless disabled anyway)
   (it isn't on non-x86/x86_64 platforms or even x86 without explicit SSE support)
   => only use "#ifdef HANDMADE_MATH__USE_SSE" to check for SSE support below this block! */
#ifndef HANDMADE_MATH_NO_SSE
# ifdef _MSC_VER /* MSVC supports SSE in amd64 mode or _M_IX86_FP >= 1 (2 means SSE2) */
#  if defined(_M_AMD64) || ( defined(_M_IX86_FP) && _M_IX86_FP >= 1 )
#   define HANDMADE_MATH__USE_SSE 1
#  endif
# else /* not MSVC, probably GCC, clang, icc or something that doesn't support SSE anyway */
#  ifdef __SSE__ /* they #define __SSE__ if it's supported */
#   define HANDMADE_MATH__USE_SSE 1
#  endif /*  __SSE__ */
# endif /* not _MSC_VER */
#endif /* #ifndef HANDMADE_MATH_NO_SSE */

#if (!defined(__cplusplus) && defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L)
# define HANDMADE_MATH__USE_C11_GENERICS 1
#endif

#ifdef HANDMADE_MATH__USE_SSE
# include <xmmintrin.h>
#endif

#ifdef _MSC_VER
#pragma warning(disable:4201)
#endif

#if defined(__GNUC__) || defined(__clang__)
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wfloat-equal"
# if (defined(__GNUC__) && (__GNUC__ == 4 && __GNUC_MINOR__ < 8)) || defined(__clang__)
#  pragma GCC diagnostic ignored "-Wmissing-braces"
# endif
# ifdef __clang__
#  pragma GCC diagnostic ignored "-Wgnu-anonymous-struct"
#  pragma GCC diagnostic ignored "-Wmissing-field-initializers"
# endif
#endif

#if defined(__GNUC__) || defined(__clang__)
# define HMM_DEPRECATED(msg) __attribute__((deprecated(msg)))
#elif defined(_MSC_VER)
# define HMM_DEPRECATED(msg) __declspec(deprecated(msg))
#else
# define HMM_DEPRECATED(msg)
#endif

#ifdef __cplusplus
extern "C"
{
#endif

#if !defined(HANDMADE_MATH_USE_DEGREES) \
    && !defined(HANDMADE_MATH_USE_TURNS) \
    && !defined(HANDMADE_MATH_USE_RADIANS)
# define HANDMADE_MATH_USE_RADIANS
#endif
    
#define PI 3.14159265358979323846
#define PI32 3.14159265359f
#define DEG180 180.0
#define DEG18032 180.0f
#define TURNHALF 0.5
#define TURNHALF32 0.5f
#define rad_to_deg ((float)(DEG180/PI))
#define rad_to_turn ((float)(TURNHALF/PI))
#define deg_to_rad ((float)(PI/DEG180))
#define deg_to_turn ((float)(TURNHALF/DEG180))
#define turn_to_rad ((float)(PI/TURNHALF))
#define turn_to_deg ((float)(DEG180/TURNHALF))

#if defined(HANDMADE_MATH_USE_RADIANS)
# define angle_rad(a) (a)
# define angle_deg(a) ((a)*deg_to_rad)
# define angle_turn(a) ((a)*turn_to_rad)
#elif defined(HANDMADE_MATH_USE_DEGREES)
# define angle_rad(a) ((a)*rad_to_deg)
# define angle_deg(a) (a)
# define angle_turn(a) ((a)*turn_to_deg)
#elif defined(HANDMADE_MATH_USE_TURNS)
# define angle_rad(a) ((a)*rad_to_turn)
# define angle_deg(a) ((a)*deg_to_turn)
# define angle_turn(a) (a)
#endif

#if !defined(HANDMADE_MATH_PROVIDE_MATH_FUNCTIONS)
# include <math.h>
# define HMM_SINF sinf
# define HMM_COSF cosf
# define HMM_TANF tanf
# define HMM_SQRTF sqrtf
# define HMM_ACOSF acosf
#endif

#if !defined(HMM_ANGLE_USER_TO_INTERNAL)
# define HMM_ANGLE_USER_TO_INTERNAL(a) (to_rad(a))
#endif

#if !defined(HMM_ANGLE_INTERNAL_TO_USER)
# if defined(HANDMADE_MATH_USE_RADIANS)
#  define HMM_ANGLE_INTERNAL_TO_USER(a) (a) 
# elif defined(HANDMADE_MATH_USE_DEGREES)
#  define HMM_ANGLE_INTERNAL_TO_USER(a) ((a)*rad_to_deg)
# elif defined(HANDMADE_MATH_USE_TURNS)
#  define HMM_ANGLE_INTERNAL_TO_USER(a) ((a)*rad_to_turn)
# endif
#endif

#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define MAX(a, b) ((a) < (b) ? (b) : (a))
#define ABS(a) ((a) > 0 ? (a) : -(a))
#define MOD(a, m) (((a) % (m)) >= 0 ? ((a) % (m)) : (((a) % (m)) + (m)))
#define SQUARE(x) ((x) * (x))

typedef union Vec2
{
    struct
    {
        float x, y;
    };

    struct
    {
        float u, v;
    };

    struct
    {
        float left, right;
    };

    struct
    {
        float width, height;
    };

    float elements[2];

#ifdef __cplusplus
    inline float &operator[](const int &Index)
    {
        return elements[Index];
    }
#endif
} Vec2;

typedef union Vec3
{
    struct
    {
        float x, y, z;
    };

    struct
    {
        float u, v, w;
    };

    struct
    {
        float r, g, b;
    };

    struct
    {
        Vec2 xy;
        float _Ignored0;
    };

    struct
    {
        float _Ignored1;
        Vec2 yz;
    };

    struct
    {
        Vec2 uv;
        float _Ignored2;
    };

    struct
    {
        float _Ignored3;
        Vec2 vw;
    };

    float elements[3];

#ifdef __cplusplus
    inline float &operator[](const int &Index)
    {
        return elements[Index];
    }
#endif
} Vec3;

typedef union Vec4
{
    struct
    {
        union
        {
            Vec3 xyz;
            struct
            {
                float x, y, z;
            };
        };

        float w;
    };
    struct
    {
        union
        {
            Vec3 RGB;
            struct
            {
                float r, g, b;
            };
        };

        float A;
    };

    struct
    {
        Vec2 xy;
        float _Ignored0;
        float _Ignored1;
    };

    struct
    {
        float _Ignored2;
        Vec2 yz;
        float _Ignored3;
    };

    struct
    {
        float _Ignored4;
        float _Ignored5;
        Vec2 zw;
    };

    float elements[4];

#ifdef HANDMADE_MATH__USE_SSE
    __m128 SSE;
#endif

#ifdef __cplusplus
    inline float &operator[](const int &Index)
    {
        return elements[Index];
    }
#endif
} Vec4;

typedef union Mat2
{
    float elements[2][2];
    Vec2 columns[2];

#ifdef __cplusplus
    inline Vec2 &operator[](const int &Index)
    {
        return columns[Index];
    }
#endif
} Mat2;
    
typedef union Mat3
{
    float elements[3][3];
    Vec3 columns[3];

#ifdef __cplusplus
    inline Vec3 &operator[](const int &Index)
    {
        return columns[Index];
    }
#endif
} Mat3;

typedef union Mat4
{
    float elements[4][4];
    Vec4 columns[4];

#ifdef __cplusplus
    inline Vec4 &operator[](const int &Index)
    {
        return columns[Index];
    }
#endif
} Mat4;

typedef union Quat
{
    struct
    {
        union
        {
            Vec3 xyz;
            struct
            {
                float x, y, z;
            };
        };

        float w;
    };

    float elements[4];

#ifdef HANDMADE_MATH__USE_SSE
    __m128 SSE;
#endif
} Quat;

typedef signed int Bool;

/*
 * Angle unit conversion functions
 */
static inline float to_rad(float Angle)
{
#if defined(HANDMADE_MATH_USE_RADIANS)
    float Result = Angle;
#elif defined(HANDMADE_MATH_USE_DEGREES) 
    float Result = Angle * deg_to_rad;
#elif defined(HANDMADE_MATH_USE_TURNS)
    float Result = Angle * turn_to_rad;
#endif
    
    return Result;
}

static inline float to_deg(float Angle)
{
#if defined(HANDMADE_MATH_USE_RADIANS)
    float Result = Angle * rad_to_deg;
#elif defined(HANDMADE_MATH_USE_DEGREES) 
    float Result = Angle;
#elif defined(HANDMADE_MATH_USE_TURNS)
    float Result = Angle * turn_to_deg;
#endif
    
    return Result;
}

static inline float to_turn(float Angle)
{
#if defined(HANDMADE_MATH_USE_RADIANS)
    float Result = Angle * rad_to_turn;
#elif defined(HANDMADE_MATH_USE_DEGREES) 
    float Result = Angle * deg_to_turn;
#elif defined(HANDMADE_MATH_USE_TURNS)
    float Result = Angle;
#endif
    
    return Result;
}

/*
 * Floating-point math functions
 */

COVERAGE(m_sin, 1)
static inline float m_sin(float Angle)
{
    ASSERT_COVERED(m_sin);
    return HMM_SINF(HMM_ANGLE_USER_TO_INTERNAL(Angle));
}

COVERAGE(m_cos, 1)
static inline float m_cos(float Angle)
{
    ASSERT_COVERED(m_cos);
    return HMM_COSF(HMM_ANGLE_USER_TO_INTERNAL(Angle));
}

COVERAGE(m_tan, 1)
static inline float m_tan(float Angle)
{
    ASSERT_COVERED(m_tan);
    return HMM_TANF(HMM_ANGLE_USER_TO_INTERNAL(Angle));
}

COVERAGE(m_acos, 1)
static inline float m_acos(float Arg)
{
    ASSERT_COVERED(m_acos);
    return HMM_ANGLE_INTERNAL_TO_USER(HMM_ACOSF(Arg));
}

COVERAGE(m_sqrt, 1)
static inline float m_sqrt(float Float)
{
    ASSERT_COVERED(m_sqrt);

    float Result;

#ifdef HANDMADE_MATH__USE_SSE
    __m128 In = _mm_set_ss(Float);
    __m128 Out = _mm_sqrt_ss(In);
    Result = _mm_cvtss_f32(Out);
#else
    Result = HMM_SQRTF(Float);
#endif

    return Result;
}

COVERAGE(invsqrt, 1)
static inline float invsqrt(float Float)
{
    ASSERT_COVERED(invsqrt);

    float Result;

    Result = 1.0f/m_sqrt(Float);

    return Result;
}


/*
 * Utility functions
 */

COVERAGE(lerp, 1)
static inline float lerp(float A, float Time, float b)
{
    ASSERT_COVERED(lerp);
    return (1.0f - Time) * A + Time * b;
}

COVERAGE(clamp, 1)
static inline float clamp(float Min, float Value, float Max)
{
    ASSERT_COVERED(clamp);

    float Result = Value;

    if (Result < Min)
    {
        Result = Min;
    }

    if (Result > Max)
    {
        Result = Max;
    }

    return Result;
}


/*
 * Vector initialization
 */

COVERAGE(V2, 1)
static inline Vec2 V2(float x, float y)
{
    ASSERT_COVERED(V2);

    Vec2 Result;
    Result.x = x;
    Result.y = y;

    return Result;
}

COVERAGE(V3, 1)
static inline Vec3 V3(float x, float y, float z)
{
    ASSERT_COVERED(V3);

    Vec3 Result;
    Result.x = x;
    Result.y = y;
    Result.z = z;

    return Result;
}

COVERAGE(V4, 1)
static inline Vec4 V4(float x, float y, float z, float w)
{
    ASSERT_COVERED(V4);

    Vec4 Result;

#ifdef HANDMADE_MATH__USE_SSE
    Result.SSE = _mm_setr_ps(x, y, z, w);
#else
    Result.x = x;
    Result.y = y;
    Result.z = z;
    Result.w = w;
#endif

    return Result;
}

COVERAGE(V4V, 1)
static inline Vec4 V4V(Vec3 Vector, float w)
{
    ASSERT_COVERED(V4V);

    Vec4 Result;

#ifdef HANDMADE_MATH__USE_SSE
    Result.SSE = _mm_setr_ps(Vector.x, Vector.y, Vector.z, w);
#else
    Result.xyz = Vector;
    Result.w = w;
#endif

    return Result;
}


/*
 * Binary vector operations
 */

COVERAGE(add_v2, 1)
static inline Vec2 add_v2(Vec2 left, Vec2 right)
{
    ASSERT_COVERED(add_v2);

    Vec2 Result;
    Result.x = left.x + right.x;
    Result.y = left.y + right.y;

    return Result;
}

COVERAGE(add_v3, 1)
static inline Vec3 add_v3(Vec3 left, Vec3 right)
{
    ASSERT_COVERED(add_v3);

    Vec3 Result;
    Result.x = left.x + right.x;
    Result.y = left.y + right.y;
    Result.z = left.z + right.z;

    return Result;
}

COVERAGE(add_v4, 1)
static inline Vec4 add_v4(Vec4 left, Vec4 right)
{
    ASSERT_COVERED(add_v4);

    Vec4 Result;

#ifdef HANDMADE_MATH__USE_SSE
    Result.SSE = _mm_add_ps(left.SSE, right.SSE);
#else
    Result.x = left.x + right.x;
    Result.y = left.y + right.y;
    Result.z = left.z + right.z;
    Result.w = left.w + right.w;
#endif

    return Result;
}

COVERAGE(sub_v2, 1)
static inline Vec2 sub_v2(Vec2 left, Vec2 right)
{
    ASSERT_COVERED(sub_v2);

    Vec2 Result;
    Result.x = left.x - right.x;
    Result.y = left.y - right.y;

    return Result;
}

COVERAGE(sub_v3, 1)
static inline Vec3 sub_v3(Vec3 left, Vec3 right)
{
    ASSERT_COVERED(sub_v3);

    Vec3 Result;
    Result.x = left.x - right.x;
    Result.y = left.y - right.y;
    Result.z = left.z - right.z;

    return Result;
}

COVERAGE(sub_v4, 1)
static inline Vec4 sub_v4(Vec4 left, Vec4 right)
{
    ASSERT_COVERED(sub_v4);

    Vec4 Result;

#ifdef HANDMADE_MATH__USE_SSE
    Result.SSE = _mm_sub_ps(left.SSE, right.SSE);
#else
    Result.x = left.x - right.x;
    Result.y = left.y - right.y;
    Result.z = left.z - right.z;
    Result.w = left.w - right.w;
#endif

    return Result;
}

COVERAGE(mul_v2, 1)
static inline Vec2 mul_v2(Vec2 left, Vec2 right)
{
    ASSERT_COVERED(mul_v2);

    Vec2 Result;
    Result.x = left.x * right.x;
    Result.y = left.y * right.y;

    return Result;
}

COVERAGE(mul_v2f, 1)
static inline Vec2 mul_v2f(Vec2 left, float right)
{
    ASSERT_COVERED(mul_v2f);

    Vec2 Result;
    Result.x = left.x * right;
    Result.y = left.y * right;

    return Result;
}

COVERAGE(mul_v3, 1)
static inline Vec3 mul_v3(Vec3 left, Vec3 right)
{
    ASSERT_COVERED(mul_v3);

    Vec3 Result;
    Result.x = left.x * right.x;
    Result.y = left.y * right.y;
    Result.z = left.z * right.z;

    return Result;
}

COVERAGE(mul_v3f, 1)
static inline Vec3 mul_v3f(Vec3 left, float right)
{
    ASSERT_COVERED(mul_v3f);

    Vec3 Result;
    Result.x = left.x * right;
    Result.y = left.y * right;
    Result.z = left.z * right;

    return Result;
}

COVERAGE(mul_v4, 1)
static inline Vec4 mul_v4(Vec4 left, Vec4 right)
{
    ASSERT_COVERED(mul_v4);

    Vec4 Result;

#ifdef HANDMADE_MATH__USE_SSE
    Result.SSE = _mm_mul_ps(left.SSE, right.SSE);
#else
    Result.x = left.x * right.x;
    Result.y = left.y * right.y;
    Result.z = left.z * right.z;
    Result.w = left.w * right.w;
#endif

    return Result;
}

COVERAGE(mul_v4f, 1)
static inline Vec4 mul_v4f(Vec4 left, float right)
{
    ASSERT_COVERED(mul_v4f);

    Vec4 Result;

#ifdef HANDMADE_MATH__USE_SSE
    __m128 Scalar = _mm_set1_ps(right);
    Result.SSE = _mm_mul_ps(left.SSE, Scalar);
#else
    Result.x = left.x * right;
    Result.y = left.y * right;
    Result.z = left.z * right;
    Result.w = left.w * right;
#endif

    return Result;
}

COVERAGE(div_v2, 1)
static inline Vec2 div_v2(Vec2 left, Vec2 right)
{
    ASSERT_COVERED(div_v2);

    Vec2 Result;
    Result.x = left.x / right.x;
    Result.y = left.y / right.y;

    return Result;
}

COVERAGE(div_v2f, 1)
static inline Vec2 div_v2f(Vec2 left, float right)
{
    ASSERT_COVERED(div_v2f);

    Vec2 Result;
    Result.x = left.x / right;
    Result.y = left.y / right;

    return Result;
}

COVERAGE(div_v3, 1)
static inline Vec3 div_v3(Vec3 left, Vec3 right)
{
    ASSERT_COVERED(div_v3);

    Vec3 Result;
    Result.x = left.x / right.x;
    Result.y = left.y / right.y;
    Result.z = left.z / right.z;

    return Result;
}

COVERAGE(div_v3f, 1)
static inline Vec3 div_v3f(Vec3 left, float right)
{
    ASSERT_COVERED(div_v3f);

    Vec3 Result;
    Result.x = left.x / right;
    Result.y = left.y / right;
    Result.z = left.z / right;

    return Result;
}

COVERAGE(div_v4, 1)
static inline Vec4 div_v4(Vec4 left, Vec4 right)
{
    ASSERT_COVERED(div_v4);

    Vec4 Result;

#ifdef HANDMADE_MATH__USE_SSE
    Result.SSE = _mm_div_ps(left.SSE, right.SSE);
#else
    Result.x = left.x / right.x;
    Result.y = left.y / right.y;
    Result.z = left.z / right.z;
    Result.w = left.w / right.w;
#endif

    return Result;
}

COVERAGE(div_v4f, 1)
static inline Vec4 div_v4f(Vec4 left, float right)
{
    ASSERT_COVERED(div_v4f);

    Vec4 Result;

#ifdef HANDMADE_MATH__USE_SSE
    __m128 Scalar = _mm_set1_ps(right);
    Result.SSE = _mm_div_ps(left.SSE, Scalar);
#else
    Result.x = left.x / right;
    Result.y = left.y / right;
    Result.z = left.z / right;
    Result.w = left.w / right;
#endif

    return Result;
}

COVERAGE(eq_v2, 1)
static inline Bool eq_v2(Vec2 left, Vec2 right)
{
    ASSERT_COVERED(eq_v2);
    return left.x == right.x && left.y == right.y;
}

COVERAGE(eq_v3, 1)
static inline Bool eq_v3(Vec3 left, Vec3 right)
{
    ASSERT_COVERED(eq_v3);
    return left.x == right.x && left.y == right.y && left.z == right.z;
}

COVERAGE(eq_v4, 1)
static inline Bool eq_v4(Vec4 left, Vec4 right)
{
    ASSERT_COVERED(eq_v4);
    return left.x == right.x && left.y == right.y && left.z == right.z && left.w == right.w;
}

COVERAGE(dot_v2, 1)
static inline float dot_v2(Vec2 left, Vec2 right)
{
    ASSERT_COVERED(dot_v2);
    return (left.x * right.x) + (left.y * right.y);
}

COVERAGE(dot_v3, 1)
static inline float dot_v3(Vec3 left, Vec3 right)
{
    ASSERT_COVERED(dot_v3);
    return (left.x * right.x) + (left.y * right.y) + (left.z * right.z);
}

COVERAGE(dot_v4, 1)
static inline float dot_v4(Vec4 left, Vec4 right)
{
    ASSERT_COVERED(dot_v4);

    float Result;

    // NOTE(zak): IN the future if we wanna check what version SSE is support
    // we can use _mm_dp_ps (4.3) but for now we will use the old way.
    // Or a r = _mm_mul_ps(v1, v2), r = _mm_hadd_ps(r, r), r = _mm_hadd_ps(r, r) for SSE3
#ifdef HANDMADE_MATH__USE_SSE
    __m128 SSEResultOne = _mm_mul_ps(left.SSE, right.SSE);
    __m128 SSEResultTwo = _mm_shuffle_ps(SSEResultOne, SSEResultOne, _MM_SHUFFLE(2, 3, 0, 1));
    SSEResultOne = _mm_add_ps(SSEResultOne, SSEResultTwo);
    SSEResultTwo = _mm_shuffle_ps(SSEResultOne, SSEResultOne, _MM_SHUFFLE(0, 1, 2, 3));
    SSEResultOne = _mm_add_ps(SSEResultOne, SSEResultTwo);
    _mm_store_ss(&Result, SSEResultOne);
#else
    Result = ((left.x * right.x) + (left.z * right.z)) + ((left.y * right.y) + (left.w * right.w));
#endif

    return Result;
}

COVERAGE(cross, 1)
static inline Vec3 cross(Vec3 left, Vec3 right)
{
    ASSERT_COVERED(cross);

    Vec3 Result;
    Result.x = (left.y * right.z) - (left.z * right.y);
    Result.y = (left.z * right.x) - (left.x * right.z);
    Result.z = (left.x * right.y) - (left.y * right.x);

    return Result;
}


/*
 * Unary vector operations
 */

COVERAGE(len_sqrv2, 1)
static inline float len_sqrv2(Vec2 A)
{
    ASSERT_COVERED(len_sqrv2);
    return dot_v2(A, A);
}

COVERAGE(len_sqrv3, 1)
static inline float len_sqrv3(Vec3 A)
{
    ASSERT_COVERED(len_sqrv3);
    return dot_v3(A, A);
}

COVERAGE(len_sqrv4, 1)
static inline float len_sqrv4(Vec4 A)
{
    ASSERT_COVERED(len_sqrv4);
    return dot_v4(A, A);
}

COVERAGE(len_v2, 1)
static inline float len_v2(Vec2 A)
{
    ASSERT_COVERED(len_v2);
    return m_sqrt(len_sqrv2(A));
}

COVERAGE(len_v3, 1)
static inline float len_v3(Vec3 A)
{
    ASSERT_COVERED(len_v3);
    return m_sqrt(len_sqrv3(A));
}

COVERAGE(len_v4, 1)
static inline float len_v4(Vec4 A)
{
    ASSERT_COVERED(len_v4);
    return m_sqrt(len_sqrv4(A));
}

COVERAGE(norm_v2, 1)
static inline Vec2 norm_v2(Vec2 A)
{
    ASSERT_COVERED(norm_v2);
    return mul_v2f(A, invsqrt(dot_v2(A, A)));
}

COVERAGE(norm_v3, 1)
static inline Vec3 norm_v3(Vec3 A)
{
    ASSERT_COVERED(norm_v3);
    return mul_v3f(A, invsqrt(dot_v3(A, A)));
}

COVERAGE(norm_v4, 1)
static inline Vec4 norm_v4(Vec4 A)
{
    ASSERT_COVERED(norm_v4);
    return mul_v4f(A, invsqrt(dot_v4(A, A)));
}

/*
 * Utility vector functions
 */

COVERAGE(lerp_v2, 1)
static inline Vec2 lerp_v2(Vec2 A, float Time, Vec2 b) 
{
    ASSERT_COVERED(lerp_v2);
    return add_v2(mul_v2f(A, 1.0f - Time), mul_v2f(b, Time));
}

COVERAGE(lerp_v3, 1)
static inline Vec3 lerp_v3(Vec3 A, float Time, Vec3 b) 
{
    ASSERT_COVERED(lerp_v3);
    return add_v3(mul_v3f(A, 1.0f - Time), mul_v3f(b, Time));
}

COVERAGE(lerp_v4, 1)
static inline Vec4 lerp_v4(Vec4 A, float Time, Vec4 b) 
{
    ASSERT_COVERED(lerp_v4);
    return add_v4(mul_v4f(A, 1.0f - Time), mul_v4f(b, Time));
}

/*
 * SSE stuff
 */

COVERAGE(linear_combine_v4m4, 1)
static inline Vec4 linear_combine_v4m4(Vec4 left, Mat4 right)
{
    ASSERT_COVERED(linear_combine_v4m4);

    Vec4 Result;
#ifdef HANDMADE_MATH__USE_SSE
    Result.SSE = _mm_mul_ps(_mm_shuffle_ps(left.SSE, left.SSE, 0x00), right.columns[0].SSE);
    Result.SSE = _mm_add_ps(Result.SSE, _mm_mul_ps(_mm_shuffle_ps(left.SSE, left.SSE, 0x55), right.columns[1].SSE));
    Result.SSE = _mm_add_ps(Result.SSE, _mm_mul_ps(_mm_shuffle_ps(left.SSE, left.SSE, 0xaa), right.columns[2].SSE));
    Result.SSE = _mm_add_ps(Result.SSE, _mm_mul_ps(_mm_shuffle_ps(left.SSE, left.SSE, 0xff), right.columns[3].SSE));
#else
    Result.x = left.elements[0] * right.columns[0].x;
    Result.y = left.elements[0] * right.columns[0].y;
    Result.z = left.elements[0] * right.columns[0].z;
    Result.w = left.elements[0] * right.columns[0].w;

    Result.x += left.elements[1] * right.columns[1].x;
    Result.y += left.elements[1] * right.columns[1].y;
    Result.z += left.elements[1] * right.columns[1].z;
    Result.w += left.elements[1] * right.columns[1].w;

    Result.x += left.elements[2] * right.columns[2].x;
    Result.y += left.elements[2] * right.columns[2].y;
    Result.z += left.elements[2] * right.columns[2].z;
    Result.w += left.elements[2] * right.columns[2].w;

    Result.x += left.elements[3] * right.columns[3].x;
    Result.y += left.elements[3] * right.columns[3].y;
    Result.z += left.elements[3] * right.columns[3].z;
    Result.w += left.elements[3] * right.columns[3].w;
#endif

    return Result;
}

/*
 * 2x2 Matrices
 */

COVERAGE(M2, 1)
static inline Mat2 M2(void)
{
    ASSERT_COVERED(M2);
    Mat2 Result = {0};
    return Result;
}

COVERAGE(M2D, 1)
static inline Mat2 M2D(float Diagonal)
{
    ASSERT_COVERED(M2D);
    
    Mat2 Result = {0};
    Result.elements[0][0] = Diagonal;
    Result.elements[1][1] = Diagonal;

    return Result;
}

COVERAGE(transpose_m2, 1)
static inline Mat2 transpose_m2(Mat2 Matrix)
{
    ASSERT_COVERED(transpose_m2);
    
    Mat2 Result = Matrix;

    Result.elements[0][1] = Matrix.elements[1][0];
    Result.elements[1][0] = Matrix.elements[0][1];
    
    return Result;
}

COVERAGE(add_m2, 1)
static inline Mat2 add_m2(Mat2 left, Mat2 right)
{
    ASSERT_COVERED(add_m2);
    
    Mat2 Result;

    Result.elements[0][0] = left.elements[0][0] + right.elements[0][0];
    Result.elements[0][1] = left.elements[0][1] + right.elements[0][1];
    Result.elements[1][0] = left.elements[1][0] + right.elements[1][0];
    Result.elements[1][1] = left.elements[1][1] + right.elements[1][1];
   
    return Result;    
}

COVERAGE(sub_m2, 1)
static inline Mat2 sub_m2(Mat2 left, Mat2 right)
{
    ASSERT_COVERED(sub_m2);
    
    Mat2 Result;

    Result.elements[0][0] = left.elements[0][0] - right.elements[0][0];
    Result.elements[0][1] = left.elements[0][1] - right.elements[0][1];
    Result.elements[1][0] = left.elements[1][0] - right.elements[1][0];
    Result.elements[1][1] = left.elements[1][1] - right.elements[1][1];
    
    return Result;
}

COVERAGE(mul_m2v2, 1)
static inline Vec2 mul_m2v2(Mat2 Matrix, Vec2 Vector)
{
    ASSERT_COVERED(mul_m2v2);
    
    Vec2 Result;

    Result.x = Vector.elements[0] * Matrix.columns[0].x;
    Result.y = Vector.elements[0] * Matrix.columns[0].y;

    Result.x += Vector.elements[1] * Matrix.columns[1].x;
    Result.y += Vector.elements[1] * Matrix.columns[1].y;

    return Result;    
}

COVERAGE(mul_m2, 1)
static inline Mat2 mul_m2(Mat2 left, Mat2 right)
{
    ASSERT_COVERED(mul_m2);
    
    Mat2 Result;
    Result.columns[0] = mul_m2v2(left, right.columns[0]);
    Result.columns[1] = mul_m2v2(left, right.columns[1]);

    return Result;    
}

COVERAGE(mul_m2f, 1)
static inline Mat2 mul_m2f(Mat2 Matrix, float Scalar)
{
    ASSERT_COVERED(mul_m2f);
    
    Mat2 Result;

    Result.elements[0][0] = Matrix.elements[0][0] * Scalar;
    Result.elements[0][1] = Matrix.elements[0][1] * Scalar;
    Result.elements[1][0] = Matrix.elements[1][0] * Scalar;
    Result.elements[1][1] = Matrix.elements[1][1] * Scalar;
    
    return Result;
}

COVERAGE(div_m2f, 1)
static inline Mat2 div_m2f(Mat2 Matrix, float Scalar)
{
    ASSERT_COVERED(div_m2f);
    
    Mat2 Result;

    Result.elements[0][0] = Matrix.elements[0][0] / Scalar;
    Result.elements[0][1] = Matrix.elements[0][1] / Scalar;
    Result.elements[1][0] = Matrix.elements[1][0] / Scalar;
    Result.elements[1][1] = Matrix.elements[1][1] / Scalar;

    return Result;
}

COVERAGE(determinant_m2, 1)
static inline float determinant_m2(Mat2 Matrix) 
{
    ASSERT_COVERED(determinant_m2);
    return Matrix.elements[0][0]*Matrix.elements[1][1] - Matrix.elements[0][1]*Matrix.elements[1][0];
}


COVERAGE(invgeneral_m2, 1)
static inline Mat2 invgeneral_m2(Mat2 Matrix) 
{
    ASSERT_COVERED(invgeneral_m2);

    Mat2 Result;
    float InvDeterminant = 1.0f / determinant_m2(Matrix);
    Result.elements[0][0] = InvDeterminant * +Matrix.elements[1][1];
    Result.elements[1][1] = InvDeterminant * +Matrix.elements[0][0];
    Result.elements[0][1] = InvDeterminant * -Matrix.elements[0][1];
    Result.elements[1][0] = InvDeterminant * -Matrix.elements[1][0];

    return Result;
}

/*
 * 3x3 Matrices
 */

COVERAGE(M3, 1)
static inline Mat3 M3(void)
{
    ASSERT_COVERED(M3);
    Mat3 Result = {0};
    return Result;
}

COVERAGE(M3D, 1)
static inline Mat3 M3D(float Diagonal)
{
    ASSERT_COVERED(M3D);
    
    Mat3 Result = {0};
    Result.elements[0][0] = Diagonal;
    Result.elements[1][1] = Diagonal;
    Result.elements[2][2] = Diagonal;

    return Result;
}

COVERAGE(transpose_m3, 1)
static inline Mat3 transpose_m3(Mat3 Matrix)
{
    ASSERT_COVERED(transpose_m3);

    Mat3 Result = Matrix;

    Result.elements[0][1] = Matrix.elements[1][0];
    Result.elements[0][2] = Matrix.elements[2][0];
    Result.elements[1][0] = Matrix.elements[0][1];
    Result.elements[1][2] = Matrix.elements[2][1];
    Result.elements[2][1] = Matrix.elements[1][2];
    Result.elements[2][0] = Matrix.elements[0][2];
    
    return Result;
}

COVERAGE(add_m3, 1)
static inline Mat3 add_m3(Mat3 left, Mat3 right)
{
    ASSERT_COVERED(add_m3);
    
    Mat3 Result;
    
    Result.elements[0][0] = left.elements[0][0] + right.elements[0][0];
    Result.elements[0][1] = left.elements[0][1] + right.elements[0][1];
    Result.elements[0][2] = left.elements[0][2] + right.elements[0][2];
    Result.elements[1][0] = left.elements[1][0] + right.elements[1][0];
    Result.elements[1][1] = left.elements[1][1] + right.elements[1][1];
    Result.elements[1][2] = left.elements[1][2] + right.elements[1][2];
    Result.elements[2][0] = left.elements[2][0] + right.elements[2][0];
    Result.elements[2][1] = left.elements[2][1] + right.elements[2][1];
    Result.elements[2][2] = left.elements[2][2] + right.elements[2][2];

    return Result;    
}

COVERAGE(sub_m3, 1)
static inline Mat3 sub_m3(Mat3 left, Mat3 right)
{
    ASSERT_COVERED(sub_m3);

    Mat3 Result;

    Result.elements[0][0] = left.elements[0][0] - right.elements[0][0];
    Result.elements[0][1] = left.elements[0][1] - right.elements[0][1];
    Result.elements[0][2] = left.elements[0][2] - right.elements[0][2];
    Result.elements[1][0] = left.elements[1][0] - right.elements[1][0];
    Result.elements[1][1] = left.elements[1][1] - right.elements[1][1];
    Result.elements[1][2] = left.elements[1][2] - right.elements[1][2];
    Result.elements[2][0] = left.elements[2][0] - right.elements[2][0];
    Result.elements[2][1] = left.elements[2][1] - right.elements[2][1];
    Result.elements[2][2] = left.elements[2][2] - right.elements[2][2];

    return Result;
}

COVERAGE(mul_m3v3, 1)
static inline Vec3 mul_m3v3(Mat3 Matrix, Vec3 Vector)
{
    ASSERT_COVERED(mul_m3v3);
    
    Vec3 Result;

    Result.x = Vector.elements[0] * Matrix.columns[0].x;
    Result.y = Vector.elements[0] * Matrix.columns[0].y;
    Result.z = Vector.elements[0] * Matrix.columns[0].z;

    Result.x += Vector.elements[1] * Matrix.columns[1].x;
    Result.y += Vector.elements[1] * Matrix.columns[1].y;
    Result.z += Vector.elements[1] * Matrix.columns[1].z;

    Result.x += Vector.elements[2] * Matrix.columns[2].x;
    Result.y += Vector.elements[2] * Matrix.columns[2].y;
    Result.z += Vector.elements[2] * Matrix.columns[2].z;
    
    return Result;    
}

COVERAGE(mul_m3, 1)
static inline Mat3 mul_m3(Mat3 left, Mat3 right)
{
    ASSERT_COVERED(mul_m3);

    Mat3 Result;
    Result.columns[0] = mul_m3v3(left, right.columns[0]);
    Result.columns[1] = mul_m3v3(left, right.columns[1]);
    Result.columns[2] = mul_m3v3(left, right.columns[2]);

    return Result;    
}

COVERAGE(mul_m3f, 1)
static inline Mat3 mul_m3f(Mat3 Matrix, float Scalar)
{
    ASSERT_COVERED(mul_m3f);

    Mat3 Result;

    Result.elements[0][0] = Matrix.elements[0][0] * Scalar;
    Result.elements[0][1] = Matrix.elements[0][1] * Scalar;
    Result.elements[0][2] = Matrix.elements[0][2] * Scalar;
    Result.elements[1][0] = Matrix.elements[1][0] * Scalar;
    Result.elements[1][1] = Matrix.elements[1][1] * Scalar;
    Result.elements[1][2] = Matrix.elements[1][2] * Scalar;
    Result.elements[2][0] = Matrix.elements[2][0] * Scalar;
    Result.elements[2][1] = Matrix.elements[2][1] * Scalar;
    Result.elements[2][2] = Matrix.elements[2][2] * Scalar;

    return Result;            
}

COVERAGE(div_m3, 1)
static inline Mat3 div_m3f(Mat3 Matrix, float Scalar)
{
    ASSERT_COVERED(div_m3);

    Mat3 Result;
    
    Result.elements[0][0] = Matrix.elements[0][0] / Scalar;
    Result.elements[0][1] = Matrix.elements[0][1] / Scalar;
    Result.elements[0][2] = Matrix.elements[0][2] / Scalar;
    Result.elements[1][0] = Matrix.elements[1][0] / Scalar;
    Result.elements[1][1] = Matrix.elements[1][1] / Scalar;
    Result.elements[1][2] = Matrix.elements[1][2] / Scalar;
    Result.elements[2][0] = Matrix.elements[2][0] / Scalar;
    Result.elements[2][1] = Matrix.elements[2][1] / Scalar;
    Result.elements[2][2] = Matrix.elements[2][2] / Scalar;

    return Result;                    
}

COVERAGE(determinant_m3, 1)
static inline float determinant_m3(Mat3 Matrix) 
{
    ASSERT_COVERED(determinant_m3);

    Mat3 Cross;
    Cross.columns[0] = cross(Matrix.columns[1], Matrix.columns[2]);
    Cross.columns[1] = cross(Matrix.columns[2], Matrix.columns[0]);
    Cross.columns[2] = cross(Matrix.columns[0], Matrix.columns[1]);

    return dot_v3(Cross.columns[2], Matrix.columns[2]);
}

COVERAGE(invgeneral_m3, 1)
static inline Mat3 invgeneral_m3(Mat3 Matrix) 
{
    ASSERT_COVERED(invgeneral_m3);

    Mat3 Cross;
    Cross.columns[0] = cross(Matrix.columns[1], Matrix.columns[2]);
    Cross.columns[1] = cross(Matrix.columns[2], Matrix.columns[0]);
    Cross.columns[2] = cross(Matrix.columns[0], Matrix.columns[1]);

    float InvDeterminant = 1.0f / dot_v3(Cross.columns[2], Matrix.columns[2]);

    Mat3 Result;
    Result.columns[0] = mul_v3f(Cross.columns[0], InvDeterminant);
    Result.columns[1] = mul_v3f(Cross.columns[1], InvDeterminant);
    Result.columns[2] = mul_v3f(Cross.columns[2], InvDeterminant);

    return transpose_m3(Result);
}

/*
 * 4x4 Matrices
 */

COVERAGE(M4, 1)
static inline Mat4 M4(void)
{
    ASSERT_COVERED(M4);
    Mat4 Result = {0};
    return Result;
}

COVERAGE(M4D, 1)
static inline Mat4 M4D(float Diagonal)
{
    ASSERT_COVERED(M4D);

    Mat4 Result = {0};
    Result.elements[0][0] = Diagonal;
    Result.elements[1][1] = Diagonal;
    Result.elements[2][2] = Diagonal;
    Result.elements[3][3] = Diagonal;

    return Result;
}

COVERAGE(transpose_m4, 1)
static inline Mat4 transpose_m4(Mat4 Matrix)
{
    ASSERT_COVERED(transpose_m4);

    Mat4 Result = Matrix;
#ifdef HANDMADE_MATH__USE_SSE
    _MM_TRANSPOSE4_PS(Result.columns[0].SSE, Result.columns[1].SSE, Result.columns[2].SSE, Result.columns[3].SSE);
#else
    Result.elements[0][1] = Matrix.elements[1][0];
    Result.elements[0][2] = Matrix.elements[2][0];
    Result.elements[0][3] = Matrix.elements[3][0];
    Result.elements[1][0] = Matrix.elements[0][1];
    Result.elements[1][2] = Matrix.elements[2][1];
    Result.elements[1][3] = Matrix.elements[3][1];
    Result.elements[2][1] = Matrix.elements[1][2];
    Result.elements[2][0] = Matrix.elements[0][2];
    Result.elements[2][3] = Matrix.elements[3][2];
    Result.elements[3][1] = Matrix.elements[1][3];
    Result.elements[3][2] = Matrix.elements[2][3];
    Result.elements[3][0] = Matrix.elements[0][3];
#endif

    return Result;
}

COVERAGE(add_m4, 1)
static inline Mat4 add_m4(Mat4 left, Mat4 right)
{
    ASSERT_COVERED(add_m4);

    Mat4 Result;

#ifdef HANDMADE_MATH__USE_SSE
    Result.columns[0].SSE = _mm_add_ps(left.columns[0].SSE, right.columns[0].SSE);
    Result.columns[1].SSE = _mm_add_ps(left.columns[1].SSE, right.columns[1].SSE);
    Result.columns[2].SSE = _mm_add_ps(left.columns[2].SSE, right.columns[2].SSE);
    Result.columns[3].SSE = _mm_add_ps(left.columns[3].SSE, right.columns[3].SSE);
#else
    Result.elements[0][0] = left.elements[0][0] + right.elements[0][0];
    Result.elements[0][1] = left.elements[0][1] + right.elements[0][1];
    Result.elements[0][2] = left.elements[0][2] + right.elements[0][2];
    Result.elements[0][3] = left.elements[0][3] + right.elements[0][3];
    Result.elements[1][0] = left.elements[1][0] + right.elements[1][0];
    Result.elements[1][1] = left.elements[1][1] + right.elements[1][1];
    Result.elements[1][2] = left.elements[1][2] + right.elements[1][2];
    Result.elements[1][3] = left.elements[1][3] + right.elements[1][3];
    Result.elements[2][0] = left.elements[2][0] + right.elements[2][0];
    Result.elements[2][1] = left.elements[2][1] + right.elements[2][1];
    Result.elements[2][2] = left.elements[2][2] + right.elements[2][2];
    Result.elements[2][3] = left.elements[2][3] + right.elements[2][3];
    Result.elements[3][0] = left.elements[3][0] + right.elements[3][0];
    Result.elements[3][1] = left.elements[3][1] + right.elements[3][1];
    Result.elements[3][2] = left.elements[3][2] + right.elements[3][2];
    Result.elements[3][3] = left.elements[3][3] + right.elements[3][3];
#endif

    return Result;
}

COVERAGE(sub_m4, 1)
static inline Mat4 sub_m4(Mat4 left, Mat4 right)
{
    ASSERT_COVERED(sub_m4);

    Mat4 Result;

#ifdef HANDMADE_MATH__USE_SSE
    Result.columns[0].SSE = _mm_sub_ps(left.columns[0].SSE, right.columns[0].SSE);
    Result.columns[1].SSE = _mm_sub_ps(left.columns[1].SSE, right.columns[1].SSE);
    Result.columns[2].SSE = _mm_sub_ps(left.columns[2].SSE, right.columns[2].SSE);
    Result.columns[3].SSE = _mm_sub_ps(left.columns[3].SSE, right.columns[3].SSE);
#else
    Result.elements[0][0] = left.elements[0][0] - right.elements[0][0];
    Result.elements[0][1] = left.elements[0][1] - right.elements[0][1];
    Result.elements[0][2] = left.elements[0][2] - right.elements[0][2];
    Result.elements[0][3] = left.elements[0][3] - right.elements[0][3];
    Result.elements[1][0] = left.elements[1][0] - right.elements[1][0];
    Result.elements[1][1] = left.elements[1][1] - right.elements[1][1];
    Result.elements[1][2] = left.elements[1][2] - right.elements[1][2];
    Result.elements[1][3] = left.elements[1][3] - right.elements[1][3];
    Result.elements[2][0] = left.elements[2][0] - right.elements[2][0];
    Result.elements[2][1] = left.elements[2][1] - right.elements[2][1];
    Result.elements[2][2] = left.elements[2][2] - right.elements[2][2];
    Result.elements[2][3] = left.elements[2][3] - right.elements[2][3];
    Result.elements[3][0] = left.elements[3][0] - right.elements[3][0];
    Result.elements[3][1] = left.elements[3][1] - right.elements[3][1];
    Result.elements[3][2] = left.elements[3][2] - right.elements[3][2];
    Result.elements[3][3] = left.elements[3][3] - right.elements[3][3];
#endif
 
    return Result;
}

COVERAGE(mul_m4, 1)
static inline Mat4 mul_m4(Mat4 left, Mat4 right)
{
    ASSERT_COVERED(mul_m4);

    Mat4 Result;
    Result.columns[0] = linear_combine_v4m4(right.columns[0], left);
    Result.columns[1] = linear_combine_v4m4(right.columns[1], left);
    Result.columns[2] = linear_combine_v4m4(right.columns[2], left);
    Result.columns[3] = linear_combine_v4m4(right.columns[3], left);

    return Result;
}

COVERAGE(mul_m4f, 1)
static inline Mat4 mul_m4f(Mat4 Matrix, float Scalar)
{
    ASSERT_COVERED(mul_m4f);

    Mat4 Result;

#ifdef HANDMADE_MATH__USE_SSE
    __m128 SSEScalar = _mm_set1_ps(Scalar);
    Result.columns[0].SSE = _mm_mul_ps(Matrix.columns[0].SSE, SSEScalar);
    Result.columns[1].SSE = _mm_mul_ps(Matrix.columns[1].SSE, SSEScalar);
    Result.columns[2].SSE = _mm_mul_ps(Matrix.columns[2].SSE, SSEScalar);
    Result.columns[3].SSE = _mm_mul_ps(Matrix.columns[3].SSE, SSEScalar);
#else
    Result.elements[0][0] = Matrix.elements[0][0] * Scalar;
    Result.elements[0][1] = Matrix.elements[0][1] * Scalar;
    Result.elements[0][2] = Matrix.elements[0][2] * Scalar;
    Result.elements[0][3] = Matrix.elements[0][3] * Scalar;
    Result.elements[1][0] = Matrix.elements[1][0] * Scalar;
    Result.elements[1][1] = Matrix.elements[1][1] * Scalar;
    Result.elements[1][2] = Matrix.elements[1][2] * Scalar;
    Result.elements[1][3] = Matrix.elements[1][3] * Scalar;
    Result.elements[2][0] = Matrix.elements[2][0] * Scalar;
    Result.elements[2][1] = Matrix.elements[2][1] * Scalar;
    Result.elements[2][2] = Matrix.elements[2][2] * Scalar;
    Result.elements[2][3] = Matrix.elements[2][3] * Scalar;
    Result.elements[3][0] = Matrix.elements[3][0] * Scalar;
    Result.elements[3][1] = Matrix.elements[3][1] * Scalar;
    Result.elements[3][2] = Matrix.elements[3][2] * Scalar;
    Result.elements[3][3] = Matrix.elements[3][3] * Scalar;
#endif

    return Result;
}

COVERAGE(mul_m4v4, 1)
static inline Vec4 mul_m4v4(Mat4 Matrix, Vec4 Vector)
{
    ASSERT_COVERED(mul_m4v4);
    return linear_combine_v4m4(Vector, Matrix);
}

COVERAGE(div_m4f, 1)
static inline Mat4 div_m4f(Mat4 Matrix, float Scalar)
{
    ASSERT_COVERED(div_m4f);

    Mat4 Result;

#ifdef HANDMADE_MATH__USE_SSE
    __m128 SSEScalar = _mm_set1_ps(Scalar);
    Result.columns[0].SSE = _mm_div_ps(Matrix.columns[0].SSE, SSEScalar);
    Result.columns[1].SSE = _mm_div_ps(Matrix.columns[1].SSE, SSEScalar);
    Result.columns[2].SSE = _mm_div_ps(Matrix.columns[2].SSE, SSEScalar);
    Result.columns[3].SSE = _mm_div_ps(Matrix.columns[3].SSE, SSEScalar);
#else
    Result.elements[0][0] = Matrix.elements[0][0] / Scalar;
    Result.elements[0][1] = Matrix.elements[0][1] / Scalar;
    Result.elements[0][2] = Matrix.elements[0][2] / Scalar;
    Result.elements[0][3] = Matrix.elements[0][3] / Scalar;
    Result.elements[1][0] = Matrix.elements[1][0] / Scalar;
    Result.elements[1][1] = Matrix.elements[1][1] / Scalar;
    Result.elements[1][2] = Matrix.elements[1][2] / Scalar;
    Result.elements[1][3] = Matrix.elements[1][3] / Scalar;
    Result.elements[2][0] = Matrix.elements[2][0] / Scalar;
    Result.elements[2][1] = Matrix.elements[2][1] / Scalar;
    Result.elements[2][2] = Matrix.elements[2][2] / Scalar;
    Result.elements[2][3] = Matrix.elements[2][3] / Scalar;
    Result.elements[3][0] = Matrix.elements[3][0] / Scalar;
    Result.elements[3][1] = Matrix.elements[3][1] / Scalar;
    Result.elements[3][2] = Matrix.elements[3][2] / Scalar;
    Result.elements[3][3] = Matrix.elements[3][3] / Scalar;
#endif

    return Result;
}

COVERAGE(determinant_m4, 1)
static inline float determinant_m4(Mat4 Matrix) 
{
    ASSERT_COVERED(determinant_m4);

    Vec3 C01 = cross(Matrix.columns[0].xyz, Matrix.columns[1].xyz);
    Vec3 C23 = cross(Matrix.columns[2].xyz, Matrix.columns[3].xyz);
    Vec3 B10 = sub_v3(mul_v3f(Matrix.columns[0].xyz, Matrix.columns[1].w), mul_v3f(Matrix.columns[1].xyz, Matrix.columns[0].w));
    Vec3 B32 = sub_v3(mul_v3f(Matrix.columns[2].xyz, Matrix.columns[3].w), mul_v3f(Matrix.columns[3].xyz, Matrix.columns[2].w));
    
    return dot_v3(C01, B32) + dot_v3(C23, B10);
}

COVERAGE(invgeneral_m4, 1)
// Returns a general-purpose inverse of an Mat4. Note that special-purpose inverses of many transformations
// are available and will be more efficient.
static inline Mat4 invgeneral_m4(Mat4 Matrix) 
{
    ASSERT_COVERED(invgeneral_m4);

    Vec3 C01 = cross(Matrix.columns[0].xyz, Matrix.columns[1].xyz);
    Vec3 C23 = cross(Matrix.columns[2].xyz, Matrix.columns[3].xyz);
    Vec3 B10 = sub_v3(mul_v3f(Matrix.columns[0].xyz, Matrix.columns[1].w), mul_v3f(Matrix.columns[1].xyz, Matrix.columns[0].w));
    Vec3 B32 = sub_v3(mul_v3f(Matrix.columns[2].xyz, Matrix.columns[3].w), mul_v3f(Matrix.columns[3].xyz, Matrix.columns[2].w));
    
    float InvDeterminant = 1.0f / (dot_v3(C01, B32) + dot_v3(C23, B10));
    C01 = mul_v3f(C01, InvDeterminant);
    C23 = mul_v3f(C23, InvDeterminant);
    B10 = mul_v3f(B10, InvDeterminant);
    B32 = mul_v3f(B32, InvDeterminant);

    Mat4 Result;
    Result.columns[0] = V4V(add_v3(cross(Matrix.columns[1].xyz, B32), mul_v3f(C23, Matrix.columns[1].w)), -dot_v3(Matrix.columns[1].xyz, C23));
    Result.columns[1] = V4V(sub_v3(cross(B32, Matrix.columns[0].xyz), mul_v3f(C23, Matrix.columns[0].w)), +dot_v3(Matrix.columns[0].xyz, C23));
    Result.columns[2] = V4V(add_v3(cross(Matrix.columns[3].xyz, B10), mul_v3f(C01, Matrix.columns[3].w)), -dot_v3(Matrix.columns[3].xyz, C01));
    Result.columns[3] = V4V(sub_v3(cross(B10, Matrix.columns[2].xyz), mul_v3f(C01, Matrix.columns[2].w)), +dot_v3(Matrix.columns[2].xyz, C01));
        
    return transpose_m4(Result);
}

/*
 * Common graphics transformations
 */

COVERAGE(orthographic_rh_no, 1)
// Produces a right-handed orthographic projection matrix with z ranging from -1 to 1 (the GL convention).
// left, right, Bottom, and Top specify the coordinates of their respective clipping planes.
// Near and Far specify the distances to the near and far clipping planes.
static inline Mat4 orthographic_rh_no(float left, float right, float Bottom, float Top, float Near, float Far)
{
    ASSERT_COVERED(orthographic_rh_no);

    Mat4 Result = {0};

    Result.elements[0][0] = 2.0f / (right - left);
    Result.elements[1][1] = 2.0f / (Top - Bottom);
    Result.elements[2][2] = 2.0f / (Near - Far);
    Result.elements[3][3] = 1.0f;

    Result.elements[3][0] = (left + right) / (left - right);
    Result.elements[3][1] = (Bottom + Top) / (Bottom - Top);
    Result.elements[3][2] = (Near + Far) / (Near - Far);

    return Result;
}

COVERAGE(orthographic_rh_zo, 1)
// Produces a right-handed orthographic projection matrix with z ranging from 0 to 1 (the DirectX convention).
// left, right, Bottom, and Top specify the coordinates of their respective clipping planes.
// Near and Far specify the distances to the near and far clipping planes.
static inline Mat4 orthographic_rh_zo(float left, float right, float Bottom, float Top, float Near, float Far)
{
    ASSERT_COVERED(orthographic_rh_zo);

    Mat4 Result = {0};

    Result.elements[0][0] = 2.0f / (right - left);
    Result.elements[1][1] = 2.0f / (Top - Bottom);
    Result.elements[2][2] = 1.0f / (Near - Far);
    Result.elements[3][3] = 1.0f;

    Result.elements[3][0] = (left + right) / (left - right);
    Result.elements[3][1] = (Bottom + Top) / (Bottom - Top);
    Result.elements[3][2] = (Near) / (Near - Far);

    return Result;
}

COVERAGE(orthographic_lh_no, 1)
// Produces a left-handed orthographic projection matrix with z ranging from -1 to 1 (the GL convention).
// left, right, Bottom, and Top specify the coordinates of their respective clipping planes.
// Near and Far specify the distances to the near and far clipping planes.
static inline Mat4 orthographic_lh_no(float left, float right, float Bottom, float Top, float Near, float Far)
{
    ASSERT_COVERED(orthographic_lh_no);

    Mat4 Result = orthographic_rh_no(left, right, Bottom, Top, Near, Far);
    Result.elements[2][2] = -Result.elements[2][2];
    
    return Result;
}

COVERAGE(orthographic_lh_zo, 1)
// Produces a left-handed orthographic projection matrix with z ranging from 0 to 1 (the DirectX convention).
// left, right, Bottom, and Top specify the coordinates of their respective clipping planes.
// Near and Far specify the distances to the near and far clipping planes.
static inline Mat4 orthographic_lh_zo(float left, float right, float Bottom, float Top, float Near, float Far)
{
    ASSERT_COVERED(orthographic_lh_zo);

    Mat4 Result = orthographic_rh_zo(left, right, Bottom, Top, Near, Far);
    Result.elements[2][2] = -Result.elements[2][2];
    
    return Result;
}

COVERAGE(inv_orthographic, 1)
// Returns an inverse for the given orthographic projection matrix. Works for all orthographic
// projection matrices, regardless of handedness or NDC convention.
static inline Mat4 inv_orthographic(Mat4 OrthoMatrix)
{
    ASSERT_COVERED(inv_orthographic);

    Mat4 Result = {0};
    Result.elements[0][0] = 1.0f / OrthoMatrix.elements[0][0];
    Result.elements[1][1] = 1.0f / OrthoMatrix.elements[1][1];
    Result.elements[2][2] = 1.0f / OrthoMatrix.elements[2][2];
    Result.elements[3][3] = 1.0f;
    
    Result.elements[3][0] = -OrthoMatrix.elements[3][0] * Result.elements[0][0];
    Result.elements[3][1] = -OrthoMatrix.elements[3][1] * Result.elements[1][1];
    Result.elements[3][2] = -OrthoMatrix.elements[3][2] * Result.elements[2][2];

    return Result;
}

COVERAGE(perspective_rh_no, 1)
static inline Mat4 perspective_rh_no(float FOV, float AspectRatio, float Near, float Far)
{
    ASSERT_COVERED(perspective_rh_no);

    Mat4 Result = {0};

    // See https://www.khronos.org/registry/OpenGL-Refpages/gl2.1/xhtml/gluPerspective.xml

    float Cotangent = 1.0f / m_tan(FOV / 2.0f);
    Result.elements[0][0] = Cotangent / AspectRatio;
    Result.elements[1][1] = Cotangent;
    Result.elements[2][3] = -1.0f;

    Result.elements[2][2] = (Near + Far) / (Near - Far);
    Result.elements[3][2] = (2.0f * Near * Far) / (Near - Far);
    
    return Result;
}

COVERAGE(perspective_rh_zo, 1)
static inline Mat4 perspective_rh_zo(float FOV, float AspectRatio, float Near, float Far)
{
    ASSERT_COVERED(perspective_rh_zo);

    Mat4 Result = {0};

    // See https://www.khronos.org/registry/OpenGL-Refpages/gl2.1/xhtml/gluPerspective.xml

    float Cotangent = 1.0f / m_tan(FOV / 2.0f);
    Result.elements[0][0] = Cotangent / AspectRatio;
    Result.elements[1][1] = Cotangent;
    Result.elements[2][3] = -1.0f;

    Result.elements[2][2] = (Far) / (Near - Far);
    Result.elements[3][2] = (Near * Far) / (Near - Far);

    return Result;
}

COVERAGE(perspective_lh_no, 1)
static inline Mat4 perspective_lh_no(float FOV, float AspectRatio, float Near, float Far)
{ 
    ASSERT_COVERED(perspective_lh_no);

    Mat4 Result = perspective_rh_no(FOV, AspectRatio, Near, Far);
    Result.elements[2][2] = -Result.elements[2][2];
    Result.elements[2][3] = -Result.elements[2][3];
    
    return Result;
}

COVERAGE(perspective_lh_zo, 1)
static inline Mat4 perspective_lh_zo(float FOV, float AspectRatio, float Near, float Far)
{ 
    ASSERT_COVERED(perspective_lh_zo);

    Mat4 Result = perspective_rh_zo(FOV, AspectRatio, Near, Far);
    Result.elements[2][2] = -Result.elements[2][2];
    Result.elements[2][3] = -Result.elements[2][3];
    
    return Result;
}

COVERAGE(inv_perspective_rh, 1)
static inline Mat4 inv_perspective_rh(Mat4 PerspectiveMatrix)
{
    ASSERT_COVERED(inv_perspective_rh);

    Mat4 Result = {0};
    Result.elements[0][0] = 1.0f / PerspectiveMatrix.elements[0][0];
    Result.elements[1][1] = 1.0f / PerspectiveMatrix.elements[1][1];
    Result.elements[2][2] = 0.0f;

    Result.elements[2][3] = 1.0f / PerspectiveMatrix.elements[3][2];
    Result.elements[3][3] = PerspectiveMatrix.elements[2][2] * Result.elements[2][3];
    Result.elements[3][2] = PerspectiveMatrix.elements[2][3];

    return Result;
}

COVERAGE(inv_perspective_lh, 1)
static inline Mat4 inv_perspective_lh(Mat4 PerspectiveMatrix)
{
    ASSERT_COVERED(inv_perspective_lh);

    Mat4 Result = {0};
    Result.elements[0][0] = 1.0f / PerspectiveMatrix.elements[0][0];
    Result.elements[1][1] = 1.0f / PerspectiveMatrix.elements[1][1];
    Result.elements[2][2] = 0.0f;

    Result.elements[2][3] = 1.0f / PerspectiveMatrix.elements[3][2];
    Result.elements[3][3] = PerspectiveMatrix.elements[2][2] * -Result.elements[2][3];
    Result.elements[3][2] = PerspectiveMatrix.elements[2][3];

    return Result;
}

COVERAGE(translate, 1)
static inline Mat4 translate(Vec3 Translation)
{
    ASSERT_COVERED(translate);

    Mat4 Result = M4D(1.0f);
    Result.elements[3][0] = Translation.x;
    Result.elements[3][1] = Translation.y;
    Result.elements[3][2] = Translation.z;

    return Result;
}

COVERAGE(inv_translate, 1)
static inline Mat4 inv_translate(Mat4 TranslationMatrix)
{
    ASSERT_COVERED(inv_translate);

    Mat4 Result = TranslationMatrix;
    Result.elements[3][0] = -Result.elements[3][0];
    Result.elements[3][1] = -Result.elements[3][1];
    Result.elements[3][2] = -Result.elements[3][2];

    return Result;
}

COVERAGE(rotate_rh, 1)
static inline Mat4 rotate_rh(float Angle, Vec3 Axis)
{
    ASSERT_COVERED(rotate_rh);

    Mat4 Result = M4D(1.0f);

    Axis = norm_v3(Axis);

    float SinTheta = m_sin(Angle);
    float CosTheta = m_cos(Angle);
    float CosValue = 1.0f - CosTheta;

    Result.elements[0][0] = (Axis.x * Axis.x * CosValue) + CosTheta;
    Result.elements[0][1] = (Axis.x * Axis.y * CosValue) + (Axis.z * SinTheta);
    Result.elements[0][2] = (Axis.x * Axis.z * CosValue) - (Axis.y * SinTheta);

    Result.elements[1][0] = (Axis.y * Axis.x * CosValue) - (Axis.z * SinTheta);
    Result.elements[1][1] = (Axis.y * Axis.y * CosValue) + CosTheta;
    Result.elements[1][2] = (Axis.y * Axis.z * CosValue) + (Axis.x * SinTheta);

    Result.elements[2][0] = (Axis.z * Axis.x * CosValue) + (Axis.y * SinTheta);
    Result.elements[2][1] = (Axis.z * Axis.y * CosValue) - (Axis.x * SinTheta);
    Result.elements[2][2] = (Axis.z * Axis.z * CosValue) + CosTheta;

    return Result;
}

COVERAGE(rotate_lh, 1)
static inline Mat4 rotate_lh(float Angle, Vec3 Axis)
{
    ASSERT_COVERED(rotate_lh);
    /* NOTE(lcf): Matrix will be inverse/transpose of RH. */
    return rotate_rh(-Angle, Axis);
}

COVERAGE(inv_rotate, 1)
static inline Mat4 inv_rotate(Mat4 RotationMatrix)
{
    ASSERT_COVERED(inv_rotate);
    return transpose_m4(RotationMatrix);
}

COVERAGE(scale, 1)
static inline Mat4 scale(Vec3 Scale)
{
    ASSERT_COVERED(scale);

    Mat4 Result = M4D(1.0f);
    Result.elements[0][0] = Scale.x;
    Result.elements[1][1] = Scale.y;
    Result.elements[2][2] = Scale.z;

    return Result;
}

COVERAGE(inv_scale, 1)
static inline Mat4 inv_scale(Mat4 ScaleMatrix) 
{
    ASSERT_COVERED(inv_scale);

    Mat4 Result = ScaleMatrix;
    Result.elements[0][0] = 1.0f / Result.elements[0][0];
    Result.elements[1][1] = 1.0f / Result.elements[1][1];
    Result.elements[2][2] = 1.0f / Result.elements[2][2];

    return Result;
}

static inline Mat4 _LookAt(Vec3 F,  Vec3 S, Vec3 u,  Vec3 Eye)
{
    Mat4 Result;

    Result.elements[0][0] = S.x;
    Result.elements[0][1] = u.x;
    Result.elements[0][2] = -F.x;
    Result.elements[0][3] = 0.0f;

    Result.elements[1][0] = S.y;
    Result.elements[1][1] = u.y;
    Result.elements[1][2] = -F.y;
    Result.elements[1][3] = 0.0f;

    Result.elements[2][0] = S.z;
    Result.elements[2][1] = u.z;
    Result.elements[2][2] = -F.z;
    Result.elements[2][3] = 0.0f;

    Result.elements[3][0] = -dot_v3(S, Eye);
    Result.elements[3][1] = -dot_v3(u, Eye);
    Result.elements[3][2] = dot_v3(F, Eye);
    Result.elements[3][3] = 1.0f;

    return Result;
}

COVERAGE(look_at_rh, 1)
static inline Mat4 look_at_rh(Vec3 Eye, Vec3 Center, Vec3 Up)
{
    ASSERT_COVERED(look_at_rh);

    Vec3 F = norm_v3(sub_v3(Center, Eye));
    Vec3 S = norm_v3(cross(F, Up));
    Vec3 u = cross(S, F);

    return _LookAt(F, S, u, Eye);
}

COVERAGE(look_at_lh, 1)
static inline Mat4 look_at_lh(Vec3 Eye, Vec3 Center, Vec3 Up)
{
    ASSERT_COVERED(look_at_lh);

    Vec3 F = norm_v3(sub_v3(Eye, Center));
    Vec3 S = norm_v3(cross(F, Up));
    Vec3 u = cross(S, F);

    return _LookAt(F, S, u, Eye);
}

COVERAGE(inv_look_at, 1)
static inline Mat4 inv_look_at(Mat4 Matrix)
{
    ASSERT_COVERED(inv_look_at);
    Mat4 Result;

    Mat3 Rotation = {0};
    Rotation.columns[0] = Matrix.columns[0].xyz;
    Rotation.columns[1] = Matrix.columns[1].xyz;
    Rotation.columns[2] = Matrix.columns[2].xyz;
    Rotation = transpose_m3(Rotation);

    Result.columns[0] = V4V(Rotation.columns[0], 0.0f);
    Result.columns[1] = V4V(Rotation.columns[1], 0.0f);
    Result.columns[2] = V4V(Rotation.columns[2], 0.0f);
    Result.columns[3] = mul_v4f(Matrix.columns[3], -1.0f);
    Result.elements[3][0] = -1.0f * Matrix.elements[3][0] /
        (Rotation.elements[0][0] + Rotation.elements[0][1] + Rotation.elements[0][2]);
    Result.elements[3][1] = -1.0f * Matrix.elements[3][1] /
        (Rotation.elements[1][0] + Rotation.elements[1][1] + Rotation.elements[1][2]);
    Result.elements[3][2] = -1.0f * Matrix.elements[3][2] /
        (Rotation.elements[2][0] + Rotation.elements[2][1] + Rotation.elements[2][2]);
    Result.elements[3][3] = 1.0f;

    return Result;
}

/*
 * Quaternion operations
 */

COVERAGE(Q, 1)
static inline Quat Q(float x, float y, float z, float w)
{
    ASSERT_COVERED(Q);

    Quat Result;

#ifdef HANDMADE_MATH__USE_SSE
    Result.SSE = _mm_setr_ps(x, y, z, w);
#else
    Result.x = x;
    Result.y = y;
    Result.z = z;
    Result.w = w;
#endif

    return Result;
}

COVERAGE(QV4, 1)
static inline Quat QV4(Vec4 Vector)
{
    ASSERT_COVERED(QV4);

    Quat Result;

#ifdef HANDMADE_MATH__USE_SSE
    Result.SSE = Vector.SSE;
#else
    Result.x = Vector.x;
    Result.y = Vector.y;
    Result.z = Vector.z;
    Result.w = Vector.w;
#endif

    return Result;
}

COVERAGE(add_q, 1)
static inline Quat add_q(Quat left, Quat right)
{
    ASSERT_COVERED(add_q);

    Quat Result;

#ifdef HANDMADE_MATH__USE_SSE
    Result.SSE = _mm_add_ps(left.SSE, right.SSE);
#else

    Result.x = left.x + right.x;
    Result.y = left.y + right.y;
    Result.z = left.z + right.z;
    Result.w = left.w + right.w;
#endif

    return Result;
}

COVERAGE(sub_q, 1)
static inline Quat sub_q(Quat left, Quat right)
{
    ASSERT_COVERED(sub_q);

    Quat Result;

#ifdef HANDMADE_MATH__USE_SSE
    Result.SSE = _mm_sub_ps(left.SSE, right.SSE);
#else
    Result.x = left.x - right.x;
    Result.y = left.y - right.y;
    Result.z = left.z - right.z;
    Result.w = left.w - right.w;
#endif

    return Result;
}

COVERAGE(mul_q, 1)
static inline Quat mul_q(Quat left, Quat right)
{
    ASSERT_COVERED(mul_q);

    Quat Result;

#ifdef HANDMADE_MATH__USE_SSE
    __m128 SSEResultOne = _mm_xor_ps(_mm_shuffle_ps(left.SSE, left.SSE, _MM_SHUFFLE(0, 0, 0, 0)), _mm_setr_ps(0.f, -0.f, 0.f, -0.f));
    __m128 SSEResultTwo = _mm_shuffle_ps(right.SSE, right.SSE, _MM_SHUFFLE(0, 1, 2, 3));
    __m128 SSEResultThree = _mm_mul_ps(SSEResultTwo, SSEResultOne);

    SSEResultOne = _mm_xor_ps(_mm_shuffle_ps(left.SSE, left.SSE, _MM_SHUFFLE(1, 1, 1, 1)) , _mm_setr_ps(0.f, 0.f, -0.f, -0.f));
    SSEResultTwo = _mm_shuffle_ps(right.SSE, right.SSE, _MM_SHUFFLE(1, 0, 3, 2));
    SSEResultThree = _mm_add_ps(SSEResultThree, _mm_mul_ps(SSEResultTwo, SSEResultOne));

    SSEResultOne = _mm_xor_ps(_mm_shuffle_ps(left.SSE, left.SSE, _MM_SHUFFLE(2, 2, 2, 2)), _mm_setr_ps(-0.f, 0.f, 0.f, -0.f));
    SSEResultTwo = _mm_shuffle_ps(right.SSE, right.SSE, _MM_SHUFFLE(2, 3, 0, 1));
    SSEResultThree = _mm_add_ps(SSEResultThree, _mm_mul_ps(SSEResultTwo, SSEResultOne));

    SSEResultOne = _mm_shuffle_ps(left.SSE, left.SSE, _MM_SHUFFLE(3, 3, 3, 3));
    SSEResultTwo = _mm_shuffle_ps(right.SSE, right.SSE, _MM_SHUFFLE(3, 2, 1, 0));
    Result.SSE = _mm_add_ps(SSEResultThree, _mm_mul_ps(SSEResultTwo, SSEResultOne));
#else
    Result.x =  right.elements[3] * +left.elements[0];
    Result.y =  right.elements[2] * -left.elements[0];
    Result.z =  right.elements[1] * +left.elements[0];
    Result.w =  right.elements[0] * -left.elements[0];

    Result.x += right.elements[2] * +left.elements[1];
    Result.y += right.elements[3] * +left.elements[1];
    Result.z += right.elements[0] * -left.elements[1];
    Result.w += right.elements[1] * -left.elements[1];
    
    Result.x += right.elements[1] * -left.elements[2];
    Result.y += right.elements[0] * +left.elements[2];
    Result.z += right.elements[3] * +left.elements[2];
    Result.w += right.elements[2] * -left.elements[2];

    Result.x += right.elements[0] * +left.elements[3];
    Result.y += right.elements[1] * +left.elements[3];
    Result.z += right.elements[2] * +left.elements[3];
    Result.w += right.elements[3] * +left.elements[3];
#endif

    return Result;
}

COVERAGE(mul_qf, 1)
static inline Quat mul_qf(Quat left, float Multiplicative)
{
    ASSERT_COVERED(mul_qf);

    Quat Result;

#ifdef HANDMADE_MATH__USE_SSE
    __m128 Scalar = _mm_set1_ps(Multiplicative);
    Result.SSE = _mm_mul_ps(left.SSE, Scalar);
#else
    Result.x = left.x * Multiplicative;
    Result.y = left.y * Multiplicative;
    Result.z = left.z * Multiplicative;
    Result.w = left.w * Multiplicative;
#endif

    return Result;
}

COVERAGE(div_qf, 1)
static inline Quat div_qf(Quat left, float Divnd)
{
    ASSERT_COVERED(div_qf);

    Quat Result;

#ifdef HANDMADE_MATH__USE_SSE
    __m128 Scalar = _mm_set1_ps(Divnd);
    Result.SSE = _mm_div_ps(left.SSE, Scalar);
#else
    Result.x = left.x / Divnd;
    Result.y = left.y / Divnd;
    Result.z = left.z / Divnd;
    Result.w = left.w / Divnd;
#endif

    return Result;
}

COVERAGE(dot_q, 1)
static inline float dot_q(Quat left, Quat right)
{
    ASSERT_COVERED(dot_q);

    float Result;

#ifdef HANDMADE_MATH__USE_SSE
    __m128 SSEResultOne = _mm_mul_ps(left.SSE, right.SSE);
    __m128 SSEResultTwo = _mm_shuffle_ps(SSEResultOne, SSEResultOne, _MM_SHUFFLE(2, 3, 0, 1));
    SSEResultOne = _mm_add_ps(SSEResultOne, SSEResultTwo);
    SSEResultTwo = _mm_shuffle_ps(SSEResultOne, SSEResultOne, _MM_SHUFFLE(0, 1, 2, 3));
    SSEResultOne = _mm_add_ps(SSEResultOne, SSEResultTwo);
    _mm_store_ss(&Result, SSEResultOne);
#else
    Result = ((left.x * right.x) + (left.z * right.z)) + ((left.y * right.y) + (left.w * right.w));
#endif

    return Result;
}

COVERAGE(InvQ, 1)
static inline Quat InvQ(Quat left)
{
    ASSERT_COVERED(InvQ);
    
    Quat Result;
    Result.x = -left.x;
    Result.y = -left.y;
    Result.z = -left.z;
    Result.w = left.w;

    return div_qf(Result, (dot_q(left, left)));
}

COVERAGE(norm_q, 1)
static inline Quat norm_q(Quat quat)
{
    ASSERT_COVERED(norm_q);

    /* NOTE(lcf): Take advantage of SSE implementation in norm_v4 */
    Vec4 Vec = {quat.x, quat.y, quat.z, quat.w};
    Vec = norm_v4(Vec);
    Quat Result = {Vec.x, Vec.y, Vec.z, Vec.w};

    return Result;
}

static inline Quat _MixQ(Quat left, float MixLeft, Quat right, float MixRight) {
    Quat Result;

#ifdef HANDMADE_MATH__USE_SSE
    __m128 ScalarLeft = _mm_set1_ps(MixLeft);
    __m128 ScalarRight = _mm_set1_ps(MixRight);
    __m128 SSEResultOne = _mm_mul_ps(left.SSE, ScalarLeft);
    __m128 SSEResultTwo = _mm_mul_ps(right.SSE, ScalarRight);
    Result.SSE = _mm_add_ps(SSEResultOne, SSEResultTwo);
#else
    Result.x = left.x*MixLeft + right.x*MixRight;
    Result.y = left.y*MixLeft + right.y*MixRight;
    Result.z = left.z*MixLeft + right.z*MixRight;
    Result.w = left.w*MixLeft + right.w*MixRight;
#endif

    return Result;
}

COVERAGE(lerp_n, 1)
static inline Quat lerp_n(Quat left, float Time, Quat right)
{
    ASSERT_COVERED(lerp_n);

    Quat Result = _MixQ(left, 1.0f-Time, right, Time);
    Result = norm_q(Result);

    return Result;
}

COVERAGE(lerp_s, 1)
static inline Quat lerp_s(Quat left, float Time, Quat right)
{
    ASSERT_COVERED(lerp_s);

    Quat Result;

    float Cos_Theta = dot_q(left, right);

    if (Cos_Theta < 0.0f) { /* NOTE(lcf): Take shortest path on Hyper-sphere */
        Cos_Theta = -Cos_Theta;
        right = Q(-right.x, -right.y, -right.z, -right.w);
    }
    
    /* NOTE(lcf): Use Normalized Linear interpolation when vectors are roughly not L.I. */
    if (Cos_Theta > 0.9995f) {
        Result = lerp_n(left, Time, right);
    } else {
        float Angle = m_acos(Cos_Theta);
        float MixLeft = m_sin((1.0f - Time) * Angle);
        float MixRight = m_sin(Time * Angle);

        Result = _MixQ(left, MixLeft, right, MixRight);
        Result = norm_q(Result);
    }
    
    return Result;
}

COVERAGE(q_to_m4, 1)
static inline Mat4 q_to_m4(Quat left)
{
    ASSERT_COVERED(q_to_m4);

    Mat4 Result;

    Quat NormalizedQ = norm_q(left);

    float XX, YY, ZZ,
          xy, XZ, yz,
          WX, WY, WZ;

    XX = NormalizedQ.x * NormalizedQ.x;
    YY = NormalizedQ.y * NormalizedQ.y;
    ZZ = NormalizedQ.z * NormalizedQ.z;
    xy = NormalizedQ.x * NormalizedQ.y;
    XZ = NormalizedQ.x * NormalizedQ.z;
    yz = NormalizedQ.y * NormalizedQ.z;
    WX = NormalizedQ.w * NormalizedQ.x;
    WY = NormalizedQ.w * NormalizedQ.y;
    WZ = NormalizedQ.w * NormalizedQ.z;

    Result.elements[0][0] = 1.0f - 2.0f * (YY + ZZ);
    Result.elements[0][1] = 2.0f * (xy + WZ);
    Result.elements[0][2] = 2.0f * (XZ - WY);
    Result.elements[0][3] = 0.0f;

    Result.elements[1][0] = 2.0f * (xy - WZ);
    Result.elements[1][1] = 1.0f - 2.0f * (XX + ZZ);
    Result.elements[1][2] = 2.0f * (yz + WX);
    Result.elements[1][3] = 0.0f;

    Result.elements[2][0] = 2.0f * (XZ + WY);
    Result.elements[2][1] = 2.0f * (yz - WX);
    Result.elements[2][2] = 1.0f - 2.0f * (XX + YY);
    Result.elements[2][3] = 0.0f;

    Result.elements[3][0] = 0.0f;
    Result.elements[3][1] = 0.0f;
    Result.elements[3][2] = 0.0f;
    Result.elements[3][3] = 1.0f;

    return Result;
}

// This method taken from Mike Day at Insomniac Games.
// https://d3cw3dd2w32x2b.cloudfront.net/wp-content/uploads/2015/01/matrix-to-quat.pdf
//
// Note that as mentioned at the top of the paper, the paper assumes the matrix
// would be *post*-multiplied to a vector to rotate it, meaning the matrix is
// the transpose of what we're dealing with. But, because our matrices are
// stored in column-major order, the indices *appear* to match the paper.
//
// For example, m12 in the paper is row 1, column 2. We need to transpose it to
// row 2, column 1. But, because the column comes first when referencing
// elements, it looks like M.elements[1][2].
//
// Don't be confused! Or if you must be confused, at least trust this
// comment. :)
COVERAGE(m4_to_q_rh, 4)
static inline Quat m4_to_q_rh(Mat4 M)
{
    float T;
    Quat q;

    if (M.elements[2][2] < 0.0f) {
        if (M.elements[0][0] > M.elements[1][1]) {
            ASSERT_COVERED(m4_to_q_rh);

            T = 1 + M.elements[0][0] - M.elements[1][1] - M.elements[2][2];
            q = Q(
                T,
                M.elements[0][1] + M.elements[1][0],
                M.elements[2][0] + M.elements[0][2],
                M.elements[1][2] - M.elements[2][1]
            );
        } else {
            ASSERT_COVERED(m4_to_q_rh);

            T = 1 - M.elements[0][0] + M.elements[1][1] - M.elements[2][2];
            q = Q(
                M.elements[0][1] + M.elements[1][0],
                T,
                M.elements[1][2] + M.elements[2][1],
                M.elements[2][0] - M.elements[0][2]
            );
        }
    } else {
        if (M.elements[0][0] < -M.elements[1][1]) {
            ASSERT_COVERED(m4_to_q_rh);

            T = 1 - M.elements[0][0] - M.elements[1][1] + M.elements[2][2];
            q = Q(
                M.elements[2][0] + M.elements[0][2],
                M.elements[1][2] + M.elements[2][1],
                T,
                M.elements[0][1] - M.elements[1][0]
            );
        } else {
            ASSERT_COVERED(m4_to_q_rh);

            T = 1 + M.elements[0][0] + M.elements[1][1] + M.elements[2][2];
            q = Q(
                M.elements[1][2] - M.elements[2][1],
                M.elements[2][0] - M.elements[0][2],
                M.elements[0][1] - M.elements[1][0],
                T
            );
        }
    }

    q = mul_qf(q, 0.5f / m_sqrt(T));

    return q;
}

COVERAGE(m4_to_q_lh, 4)
static inline Quat m4_to_q_lh(Mat4 M)
{
    float T;
    Quat q;

    if (M.elements[2][2] < 0.0f) {
        if (M.elements[0][0] > M.elements[1][1]) {
            ASSERT_COVERED(m4_to_q_lh);

            T = 1 + M.elements[0][0] - M.elements[1][1] - M.elements[2][2];
            q = Q(
                T,
                M.elements[0][1] + M.elements[1][0],
                M.elements[2][0] + M.elements[0][2],
                M.elements[2][1] - M.elements[1][2]
            );
        } else {
            ASSERT_COVERED(m4_to_q_lh);

            T = 1 - M.elements[0][0] + M.elements[1][1] - M.elements[2][2];
            q = Q(
                M.elements[0][1] + M.elements[1][0],
                T,
                M.elements[1][2] + M.elements[2][1],
                M.elements[0][2] - M.elements[2][0]
            );
        }
    } else {
        if (M.elements[0][0] < -M.elements[1][1]) {
            ASSERT_COVERED(m4_to_q_lh);

            T = 1 - M.elements[0][0] - M.elements[1][1] + M.elements[2][2];
            q = Q(
                M.elements[2][0] + M.elements[0][2],
                M.elements[1][2] + M.elements[2][1],
                T,
                M.elements[1][0] - M.elements[0][1]
            );
        } else {
            ASSERT_COVERED(m4_to_q_lh);

            T = 1 + M.elements[0][0] + M.elements[1][1] + M.elements[2][2];
            q = Q(
                M.elements[2][1] - M.elements[1][2],
                M.elements[0][2] - M.elements[2][0],
                M.elements[1][0] - M.elements[0][2],
                T
            );
        }
    }

    q = mul_qf(q, 0.5f / m_sqrt(T));

    return q;
}


COVERAGE(QFromAxisAngle_RH, 1)
static inline Quat QFromAxisAngle_RH(Vec3 Axis, float AngleOfRotation)
{
    ASSERT_COVERED(QFromAxisAngle_RH);

    Quat Result;

    Vec3 AxisNormalized = norm_v3(Axis);
    float SineOfRotation = m_sin(AngleOfRotation / 2.0f);

    Result.xyz = mul_v3f(AxisNormalized, SineOfRotation);
    Result.w = m_cos(AngleOfRotation / 2.0f);

    return Result;
}

COVERAGE(q_from_axis_angle_lh, 1)
static inline Quat q_from_axis_angle_lh(Vec3 Axis, float AngleOfRotation)
{
    ASSERT_COVERED(q_from_axis_angle_lh);

    return QFromAxisAngle_RH(Axis, -AngleOfRotation);
}


#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

COVERAGE(len_v2cpp, 1)
static inline float len(Vec2 A)
{
    ASSERT_COVERED(len_v2cpp);
    return len_v2(A);
}

COVERAGE(len_v3cpp, 1)
static inline float len(Vec3 A)
{
    ASSERT_COVERED(len_v3cpp);
    return len_v3(A);
}

COVERAGE(len_v4cpp, 1)
static inline float len(Vec4 A)
{
    ASSERT_COVERED(len_v4cpp);
    return len_v4(A);
}

COVERAGE(len_sqrv2cpp, 1)
static inline float len_sqr(Vec2 A)
{
    ASSERT_COVERED(len_sqrv2cpp);
    return len_sqrv2(A);
}

COVERAGE(len_sqrv3cpp, 1)
static inline float len_sqr(Vec3 A)
{
    ASSERT_COVERED(len_sqrv3cpp);
    return len_sqrv3(A);
}

COVERAGE(len_sqrv4cpp, 1)
static inline float len_sqr(Vec4 A)
{
    ASSERT_COVERED(len_sqrv4cpp);
    return len_sqrv4(A);
}

COVERAGE(norm_v2cpp, 1)
static inline Vec2 norm(Vec2 A)
{
    ASSERT_COVERED(norm_v2cpp);
    return norm_v2(A);
}

COVERAGE(norm_v3cpp, 1)
static inline Vec3 norm(Vec3 A)
{
    ASSERT_COVERED(norm_v3cpp);
    return norm_v3(A);
}

COVERAGE(norm_v4cpp, 1)
static inline Vec4 norm(Vec4 A)
{
    ASSERT_COVERED(norm_v4cpp);
    return norm_v4(A);
}

COVERAGE(norm_qcpp, 1)
static inline Quat norm(Quat A)
{
    ASSERT_COVERED(norm_qcpp);
    return norm_q(A);
}

COVERAGE(dot_v2cpp, 1)
static inline float dot(Vec2 left, Vec2 VecTwo)
{
    ASSERT_COVERED(dot_v2cpp);
    return dot_v2(left, VecTwo);
}

COVERAGE(dot_v3cpp, 1)
static inline float dot(Vec3 left, Vec3 VecTwo)
{
    ASSERT_COVERED(dot_v3cpp);
    return dot_v3(left, VecTwo);
}

COVERAGE(dot_v4cpp, 1)
static inline float dot(Vec4 left, Vec4 VecTwo)
{
    ASSERT_COVERED(dot_v4cpp);
    return dot_v4(left, VecTwo);
}
 
COVERAGE(lerp_v2cpp, 1)
static inline Vec2 lerp(Vec2 left, float Time, Vec2 right) 
{
    ASSERT_COVERED(lerp_v2cpp);
    return lerp_v2(left, Time, right);
}

COVERAGE(lerp_v3cpp, 1)
static inline Vec3 lerp(Vec3 left, float Time, Vec3 right) 
{
    ASSERT_COVERED(lerp_v3cpp);
    return lerp_v3(left, Time, right);
}

COVERAGE(lerp_v4cpp, 1)
static inline Vec4 lerp(Vec4 left, float Time, Vec4 right) 
{
    ASSERT_COVERED(lerp_v4cpp);
    return lerp_v4(left, Time, right);
}

COVERAGE(transpose_m2cpp, 1)
static inline Mat2 transpose(Mat2 Matrix)
{
    ASSERT_COVERED(transpose_m2cpp);
    return transpose_m2(Matrix);
}

COVERAGE(transpose_m3cpp, 1)
static inline Mat3 transpose(Mat3 Matrix)
{
    ASSERT_COVERED(transpose_m3cpp);
    return transpose_m3(Matrix);
}

COVERAGE(transpose_m4cpp, 1)
static inline Mat4 transpose(Mat4 Matrix)
{
    ASSERT_COVERED(transpose_m4cpp);
    return transpose_m4(Matrix);
}

COVERAGE(determinant_m2cpp, 1)
static inline float determinant(Mat2 Matrix)
{
    ASSERT_COVERED(determinant_m2cpp);
    return determinant_m2(Matrix);
}

COVERAGE(determinant_m3cpp, 1)
static inline float determinant(Mat3 Matrix)
{
    ASSERT_COVERED(determinant_m3cpp);
    return determinant_m3(Matrix);
}

COVERAGE(determinant_m4cpp, 1)
static inline float determinant(Mat4 Matrix)
{
    ASSERT_COVERED(determinant_m4cpp);
    return determinant_m4(Matrix);
}

COVERAGE(invgeneral_m2cpp, 1)
static inline Mat2 invgeneral(Mat2 Matrix)
{
    ASSERT_COVERED(invgeneral_m2cpp);
    return invgeneral_m2(Matrix);
}

COVERAGE(invgeneral_m3cpp, 1)
static inline Mat3 invgeneral(Mat3 Matrix)
{
    ASSERT_COVERED(invgeneral_m3cpp);
    return invgeneral_m3(Matrix);
}

COVERAGE(invgeneral_m4cpp, 1)
static inline Mat4 invgeneral(Mat4 Matrix)
{
    ASSERT_COVERED(invgeneral_m4cpp);
    return invgeneral_m4(Matrix);
}

COVERAGE(dot_qcpp, 1)
static inline float dot(Quat QuatOne, Quat QuatTwo)
{
    ASSERT_COVERED(dot_qcpp);
    return dot_q(QuatOne, QuatTwo);
}

COVERAGE(add_v2cpp, 1)
static inline Vec2 add(Vec2 left, Vec2 right)
{
    ASSERT_COVERED(add_v2cpp);
    return add_v2(left, right);
}

COVERAGE(add_v3cpp, 1)
static inline Vec3 add(Vec3 left, Vec3 right)
{
    ASSERT_COVERED(add_v3cpp);
    return add_v3(left, right);
}

COVERAGE(add_v4cpp, 1)
static inline Vec4 add(Vec4 left, Vec4 right)
{
    ASSERT_COVERED(add_v4cpp);
    return add_v4(left, right);
}

COVERAGE(add_m2cpp, 1)
static inline Mat2 add(Mat2 left, Mat2 right)
{
    ASSERT_COVERED(add_m2cpp);
    return add_m2(left, right);
}

COVERAGE(add_m3cpp, 1)
static inline Mat3 add(Mat3 left, Mat3 right)
{
    ASSERT_COVERED(add_m3cpp);
    return add_m3(left, right);
}

COVERAGE(add_m4cpp, 1)
static inline Mat4 add(Mat4 left, Mat4 right)
{
    ASSERT_COVERED(add_m4cpp);
    return add_m4(left, right);
}

COVERAGE(add_qcpp, 1)
static inline Quat add(Quat left, Quat right)
{
    ASSERT_COVERED(add_qcpp);
    return add_q(left, right);
}

COVERAGE(sub_v2cpp, 1)
static inline Vec2 sub(Vec2 left, Vec2 right)
{
    ASSERT_COVERED(sub_v2cpp);
    return sub_v2(left, right);
}

COVERAGE(sub_v3cpp, 1)
static inline Vec3 sub(Vec3 left, Vec3 right)
{
    ASSERT_COVERED(sub_v3cpp);
    return sub_v3(left, right);
}

COVERAGE(sub_v4cpp, 1)
static inline Vec4 sub(Vec4 left, Vec4 right)
{
    ASSERT_COVERED(sub_v4cpp);
    return sub_v4(left, right);
}

COVERAGE(sub_m2cpp, 1)
static inline Mat2 sub(Mat2 left, Mat2 right)
{
    ASSERT_COVERED(sub_m2cpp);
    return sub_m2(left, right);
}

COVERAGE(sub_m3cpp, 1)
static inline Mat3 sub(Mat3 left, Mat3 right)
{
    ASSERT_COVERED(sub_m3cpp);
    return sub_m3(left, right);
}

COVERAGE(sub_m4cpp, 1)
static inline Mat4 sub(Mat4 left, Mat4 right)
{
    ASSERT_COVERED(sub_m4cpp);
    return sub_m4(left, right);
}

COVERAGE(sub_qcpp, 1)
static inline Quat sub(Quat left, Quat right)
{
    ASSERT_COVERED(sub_qcpp);
    return sub_q(left, right);
}

COVERAGE(mul_v2cpp, 1)
static inline Vec2 mul(Vec2 left, Vec2 right)
{
    ASSERT_COVERED(mul_v2cpp);
    return mul_v2(left, right);
}

COVERAGE(mul_v2fcpp, 1)
static inline Vec2 mul(Vec2 left, float right)
{
    ASSERT_COVERED(mul_v2fcpp);
    return mul_v2f(left, right);
}

COVERAGE(mul_v3cpp, 1)
static inline Vec3 mul(Vec3 left, Vec3 right)
{
    ASSERT_COVERED(mul_v3cpp);
    return mul_v3(left, right);
}

COVERAGE(mul_v3fcpp, 1)
static inline Vec3 mul(Vec3 left, float right)
{
    ASSERT_COVERED(mul_v3fcpp);
    return mul_v3f(left, right);
}

COVERAGE(mul_v4cpp, 1)
static inline Vec4 mul(Vec4 left, Vec4 right)
{
    ASSERT_COVERED(mul_v4cpp);
    return mul_v4(left, right);
}

COVERAGE(mul_v4fcpp, 1)
static inline Vec4 mul(Vec4 left, float right)
{
    ASSERT_COVERED(mul_v4fcpp);
    return mul_v4f(left, right);
}

COVERAGE(mul_m2cpp, 1)
static inline Mat2 mul(Mat2 left, Mat2 right)
{
    ASSERT_COVERED(mul_m2cpp);
    return mul_m2(left, right);
}

COVERAGE(mul_m3cpp, 1)
static inline Mat3 mul(Mat3 left, Mat3 right)
{
    ASSERT_COVERED(mul_m3cpp);
    return mul_m3(left, right);
}

COVERAGE(mul_m4cpp, 1)
static inline Mat4 mul(Mat4 left, Mat4 right)
{
    ASSERT_COVERED(mul_m4cpp);
    return mul_m4(left, right);
}

COVERAGE(mul_m2fcpp, 1)
static inline Mat2 mul(Mat2 left, float right)
{
    ASSERT_COVERED(mul_m2fcpp);
    return mul_m2f(left, right);
}

COVERAGE(mul_m3fcpp, 1)
static inline Mat3 mul(Mat3 left, float right)
{
    ASSERT_COVERED(mul_m3fcpp);
    return mul_m3f(left, right);
}

COVERAGE(mul_m4fcpp, 1)
static inline Mat4 mul(Mat4 left, float right)
{
    ASSERT_COVERED(mul_m4fcpp);
    return mul_m4f(left, right);
}

COVERAGE(mul_m2v2cpp, 1)
static inline Vec2 mul(Mat2 Matrix, Vec2 Vector)
{
    ASSERT_COVERED(mul_m2v2cpp);
    return mul_m2v2(Matrix, Vector);
}

COVERAGE(mul_m3v3cpp, 1)
static inline Vec3 mul(Mat3 Matrix, Vec3 Vector)
{
    ASSERT_COVERED(mul_m3v3cpp);
    return mul_m3v3(Matrix, Vector);
}

COVERAGE(mul_m4v4cpp, 1)
static inline Vec4 mul(Mat4 Matrix, Vec4 Vector)
{
    ASSERT_COVERED(mul_m4v4cpp);
    return mul_m4v4(Matrix, Vector);
}

COVERAGE(mul_qcpp, 1)
static inline Quat mul(Quat left, Quat right)
{
    ASSERT_COVERED(mul_qcpp);
    return mul_q(left, right);
}

COVERAGE(mul_qfcpp, 1)
static inline Quat mul(Quat left, float right)
{
    ASSERT_COVERED(mul_qfcpp);
    return mul_qf(left, right);
}

COVERAGE(div_v2cpp, 1)
static inline Vec2 div(Vec2 left, Vec2 right)
{
    ASSERT_COVERED(div_v2cpp);
    return div_v2(left, right);
}

COVERAGE(div_v2fcpp, 1)
static inline Vec2 div(Vec2 left, float right)
{
    ASSERT_COVERED(div_v2fcpp);
    return div_v2f(left, right);
}

COVERAGE(div_v3cpp, 1)
static inline Vec3 div(Vec3 left, Vec3 right)
{
    ASSERT_COVERED(div_v3cpp);
    return div_v3(left, right);
}

COVERAGE(div_v3fcpp, 1)
static inline Vec3 div(Vec3 left, float right)
{
    ASSERT_COVERED(div_v3fcpp);
    return div_v3f(left, right);
}

COVERAGE(div_v4cpp, 1)
static inline Vec4 div(Vec4 left, Vec4 right)
{
    ASSERT_COVERED(div_v4cpp);
    return div_v4(left, right);
}

COVERAGE(div_v4fcpp, 1)
static inline Vec4 div(Vec4 left, float right)
{
    ASSERT_COVERED(div_v4fcpp);
    return div_v4f(left, right);
}

COVERAGE(div_m2fcpp, 1)
static inline Mat2 div(Mat2 left, float right)
{
    ASSERT_COVERED(div_m2fcpp);
    return div_m2f(left, right);
}

COVERAGE(div_m3fcpp, 1)
static inline Mat3 div(Mat3 left, float right)
{
    ASSERT_COVERED(div_m3fcpp);
    return div_m3f(left, right);
}

COVERAGE(div_m4fcpp, 1)
static inline Mat4 div(Mat4 left, float right)
{
    ASSERT_COVERED(div_m4fcpp);
    return div_m4f(left, right);
}

COVERAGE(div_qfcpp, 1)
static inline Quat div(Quat left, float right)
{
    ASSERT_COVERED(div_qfcpp);
    return div_qf(left, right);
}

COVERAGE(eq_v2cpp, 1)
static inline Bool eq(Vec2 left, Vec2 right)
{
    ASSERT_COVERED(eq_v2cpp);
    return eq_v2(left, right);
}

COVERAGE(eq_v3cpp, 1)
static inline Bool eq(Vec3 left, Vec3 right)
{
    ASSERT_COVERED(eq_v3cpp);
    return eq_v3(left, right);
}

COVERAGE(eq_v4cpp, 1)
static inline Bool eq(Vec4 left, Vec4 right)
{
    ASSERT_COVERED(eq_v4cpp);
    return eq_v4(left, right);
}

COVERAGE(add_v2op, 1)
static inline Vec2 operator+(Vec2 left, Vec2 right)
{
    ASSERT_COVERED(add_v2op);
    return add_v2(left, right);
}

COVERAGE(add_v3op, 1)
static inline Vec3 operator+(Vec3 left, Vec3 right)
{
    ASSERT_COVERED(add_v3op);
    return add_v3(left, right);
}

COVERAGE(add_v4op, 1)
static inline Vec4 operator+(Vec4 left, Vec4 right)
{
    ASSERT_COVERED(add_v4op);
    return add_v4(left, right);
}

COVERAGE(add_m2op, 1)
static inline Mat2 operator+(Mat2 left, Mat2 right)
{
    ASSERT_COVERED(add_m2op);
    return add_m2(left, right);
}

COVERAGE(add_m3op, 1)
static inline Mat3 operator+(Mat3 left, Mat3 right)
{
    ASSERT_COVERED(add_m3op);
    return add_m3(left, right);
}

COVERAGE(add_m4op, 1)
static inline Mat4 operator+(Mat4 left, Mat4 right)
{
    ASSERT_COVERED(add_m4op);
    return add_m4(left, right);
}

COVERAGE(add_qop, 1)
static inline Quat operator+(Quat left, Quat right)
{
    ASSERT_COVERED(add_qop);
    return add_q(left, right);
}

COVERAGE(sub_v2op, 1)
static inline Vec2 operator-(Vec2 left, Vec2 right)
{
    ASSERT_COVERED(sub_v2op);
    return sub_v2(left, right);
}

COVERAGE(sub_v3op, 1)
static inline Vec3 operator-(Vec3 left, Vec3 right)
{
    ASSERT_COVERED(sub_v3op);
    return sub_v3(left, right);
}

COVERAGE(sub_v4op, 1)
static inline Vec4 operator-(Vec4 left, Vec4 right)
{
    ASSERT_COVERED(sub_v4op);
    return sub_v4(left, right);
}

COVERAGE(sub_m2op, 1)
static inline Mat2 operator-(Mat2 left, Mat2 right)
{
    ASSERT_COVERED(sub_m2op);
    return sub_m2(left, right);
}

COVERAGE(sub_m3op, 1)
static inline Mat3 operator-(Mat3 left, Mat3 right)
{
    ASSERT_COVERED(sub_m3op);
    return sub_m3(left, right);
}

COVERAGE(sub_m4op, 1)
static inline Mat4 operator-(Mat4 left, Mat4 right)
{
    ASSERT_COVERED(sub_m4op);
    return sub_m4(left, right);
}

COVERAGE(sub_qop, 1)
static inline Quat operator-(Quat left, Quat right)
{
    ASSERT_COVERED(sub_qop);
    return sub_q(left, right);
}

COVERAGE(mul_v2op, 1)
static inline Vec2 operator*(Vec2 left, Vec2 right)
{
    ASSERT_COVERED(mul_v2op);
    return mul_v2(left, right);
}

COVERAGE(mul_v3op, 1)
static inline Vec3 operator*(Vec3 left, Vec3 right)
{
    ASSERT_COVERED(mul_v3op);
    return mul_v3(left, right);
}

COVERAGE(mul_v4op, 1)
static inline Vec4 operator*(Vec4 left, Vec4 right)
{
    ASSERT_COVERED(mul_v4op);
    return mul_v4(left, right);
}

COVERAGE(mul_m2op, 1)
static inline Mat2 operator*(Mat2 left, Mat2 right)
{
    ASSERT_COVERED(mul_m2op);
    return mul_m2(left, right);
}

COVERAGE(mul_m3op, 1)
static inline Mat3 operator*(Mat3 left, Mat3 right)
{
    ASSERT_COVERED(mul_m3op);
    return mul_m3(left, right);
}

COVERAGE(mul_m4op, 1)
static inline Mat4 operator*(Mat4 left, Mat4 right)
{
    ASSERT_COVERED(mul_m4op);
    return mul_m4(left, right);
}

COVERAGE(mul_qop, 1)
static inline Quat operator*(Quat left, Quat right)
{
    ASSERT_COVERED(mul_qop);
    return mul_q(left, right);
}

COVERAGE(mul_v2fop, 1)
static inline Vec2 operator*(Vec2 left, float right)
{
    ASSERT_COVERED(mul_v2fop);
    return mul_v2f(left, right);
}

COVERAGE(mul_v3fop, 1)
static inline Vec3 operator*(Vec3 left, float right)
{
    ASSERT_COVERED(mul_v3fop);
    return mul_v3f(left, right);
}

COVERAGE(mul_v4fop, 1)
static inline Vec4 operator*(Vec4 left, float right)
{
    ASSERT_COVERED(mul_v4fop);
    return mul_v4f(left, right);
}

COVERAGE(mul_m2fop, 1)
static inline Mat2 operator*(Mat2 left, float right)
{
    ASSERT_COVERED(mul_m2fop);
    return mul_m2f(left, right);
}

COVERAGE(mul_m3fop, 1)
static inline Mat3 operator*(Mat3 left, float right)
{
    ASSERT_COVERED(mul_m3fop);
    return mul_m3f(left, right);
}

COVERAGE(mul_m4fop, 1)
static inline Mat4 operator*(Mat4 left, float right)
{
    ASSERT_COVERED(mul_m4fop);
    return mul_m4f(left, right);
}

COVERAGE(mul_qfop, 1)
static inline Quat operator*(Quat left, float right)
{
    ASSERT_COVERED(mul_qfop);
    return mul_qf(left, right);
}

COVERAGE(mul_v2fopleft, 1)
static inline Vec2 operator*(float left, Vec2 right)
{
    ASSERT_COVERED(mul_v2fopleft);
    return mul_v2f(right, left);
}

COVERAGE(mul_v3fopleft, 1)
static inline Vec3 operator*(float left, Vec3 right)
{
    ASSERT_COVERED(mul_v3fopleft);
    return mul_v3f(right, left);
}

COVERAGE(mul_v4fopleft, 1)
static inline Vec4 operator*(float left, Vec4 right)
{
    ASSERT_COVERED(mul_v4fopleft);
    return mul_v4f(right, left);
}

COVERAGE(mul_m2fopleft, 1)
static inline Mat2 operator*(float left, Mat2 right)
{
    ASSERT_COVERED(mul_m2fopleft);
    return mul_m2f(right, left);
}

COVERAGE(mul_m3fopleft, 1)
static inline Mat3 operator*(float left, Mat3 right)
{
    ASSERT_COVERED(mul_m3fopleft);
    return mul_m3f(right, left);
}

COVERAGE(mul_m4fopleft, 1)
static inline Mat4 operator*(float left, Mat4 right)
{
    ASSERT_COVERED(mul_m4fopleft);
    return mul_m4f(right, left);
}

COVERAGE(mul_qfopleft, 1)
static inline Quat operator*(float left, Quat right)
{
    ASSERT_COVERED(mul_qfopleft);
    return mul_qf(right, left);
}

COVERAGE(mul_m2v2op, 1)
static inline Vec2 operator*(Mat2 Matrix, Vec2 Vector)
{
    ASSERT_COVERED(mul_m2v2op);
    return mul_m2v2(Matrix, Vector);
}

COVERAGE(mul_m3v3op, 1)
static inline Vec3 operator*(Mat3 Matrix, Vec3 Vector)
{
    ASSERT_COVERED(mul_m3v3op);
    return mul_m3v3(Matrix, Vector);
}

COVERAGE(mul_m4v4op, 1)
static inline Vec4 operator*(Mat4 Matrix, Vec4 Vector)
{
    ASSERT_COVERED(mul_m4v4op);
    return mul_m4v4(Matrix, Vector);
}

COVERAGE(div_v2op, 1)
static inline Vec2 operator/(Vec2 left, Vec2 right)
{
    ASSERT_COVERED(div_v2op);
    return div_v2(left, right);
}

COVERAGE(div_v3op, 1)
static inline Vec3 operator/(Vec3 left, Vec3 right)
{
    ASSERT_COVERED(div_v3op);
    return div_v3(left, right);
}

COVERAGE(div_v4op, 1)
static inline Vec4 operator/(Vec4 left, Vec4 right)
{
    ASSERT_COVERED(div_v4op);
    return div_v4(left, right);
}

COVERAGE(div_v2fop, 1)
static inline Vec2 operator/(Vec2 left, float right)
{
    ASSERT_COVERED(div_v2fop);
    return div_v2f(left, right);
}

COVERAGE(div_v3fop, 1)
static inline Vec3 operator/(Vec3 left, float right)
{
    ASSERT_COVERED(div_v3fop);
    return div_v3f(left, right);
}

COVERAGE(div_v4fop, 1)
static inline Vec4 operator/(Vec4 left, float right)
{
    ASSERT_COVERED(div_v4fop);
    return div_v4f(left, right);
}

COVERAGE(div_m4fop, 1)
static inline Mat4 operator/(Mat4 left, float right)
{
    ASSERT_COVERED(div_m4fop);
    return div_m4f(left, right);
}

COVERAGE(div_m3fop, 1)
static inline Mat3 operator/(Mat3 left, float right)
{
    ASSERT_COVERED(div_m3fop);
    return div_m3f(left, right);
}

COVERAGE(div_m2fop, 1)
static inline Mat2 operator/(Mat2 left, float right)
{
    ASSERT_COVERED(div_m2fop);
    return div_m2f(left, right);
}

COVERAGE(div_qfop, 1)
static inline Quat operator/(Quat left, float right)
{
    ASSERT_COVERED(div_qfop);
    return div_qf(left, right);
}

COVERAGE(add_v2assign, 1)
static inline Vec2 &operator+=(Vec2 &left, Vec2 right)
{
    ASSERT_COVERED(add_v2assign);
    return left = left + right;
}

COVERAGE(add_v3assign, 1)
static inline Vec3 &operator+=(Vec3 &left, Vec3 right)
{
    ASSERT_COVERED(add_v3assign);
    return left = left + right;
}

COVERAGE(add_v4assign, 1)
static inline Vec4 &operator+=(Vec4 &left, Vec4 right)
{
    ASSERT_COVERED(add_v4assign);
    return left = left + right;
}

COVERAGE(add_m2assign, 1)
static inline Mat2 &operator+=(Mat2 &left, Mat2 right)
{
    ASSERT_COVERED(add_m2assign);
    return left = left + right;
}

COVERAGE(add_m3assign, 1)
static inline Mat3 &operator+=(Mat3 &left, Mat3 right)
{
    ASSERT_COVERED(add_m3assign);
    return left = left + right;
}

COVERAGE(add_m4assign, 1)
static inline Mat4 &operator+=(Mat4 &left, Mat4 right)
{
    ASSERT_COVERED(add_m4assign);
    return left = left + right;
}

COVERAGE(add_qassign, 1)
static inline Quat &operator+=(Quat &left, Quat right)
{
    ASSERT_COVERED(add_qassign);
    return left = left + right;
}

COVERAGE(sub_v2assign, 1)
static inline Vec2 &operator-=(Vec2 &left, Vec2 right)
{
    ASSERT_COVERED(sub_v2assign);
    return left = left - right;
}

COVERAGE(sub_v3assign, 1)
static inline Vec3 &operator-=(Vec3 &left, Vec3 right)
{
    ASSERT_COVERED(sub_v3assign);
    return left = left - right;
}

COVERAGE(sub_v4assign, 1)
static inline Vec4 &operator-=(Vec4 &left, Vec4 right)
{
    ASSERT_COVERED(sub_v4assign);
    return left = left - right;
}

COVERAGE(sub_m2assign, 1)
static inline Mat2 &operator-=(Mat2 &left, Mat2 right)
{
    ASSERT_COVERED(sub_m2assign);
    return left = left - right;
}

COVERAGE(sub_m3assign, 1)
static inline Mat3 &operator-=(Mat3 &left, Mat3 right)
{
    ASSERT_COVERED(sub_m3assign);
    return left = left - right;
}

COVERAGE(sub_m4assign, 1)
static inline Mat4 &operator-=(Mat4 &left, Mat4 right)
{
    ASSERT_COVERED(sub_m4assign);
    return left = left - right;
}

COVERAGE(sub_qassign, 1)
static inline Quat &operator-=(Quat &left, Quat right)
{
    ASSERT_COVERED(sub_qassign);
    return left = left - right;
}

COVERAGE(mul_v2assign, 1)
static inline Vec2 &operator*=(Vec2 &left, Vec2 right)
{
    ASSERT_COVERED(mul_v2assign);
    return left = left * right;
}

COVERAGE(mul_v3assign, 1)
static inline Vec3 &operator*=(Vec3 &left, Vec3 right)
{
    ASSERT_COVERED(mul_v3assign);
    return left = left * right;
}

COVERAGE(mul_v4assign, 1)
static inline Vec4 &operator*=(Vec4 &left, Vec4 right)
{
    ASSERT_COVERED(mul_v4assign);
    return left = left * right;
}

COVERAGE(mul_v2fassign, 1)
static inline Vec2 &operator*=(Vec2 &left, float right)
{
    ASSERT_COVERED(mul_v2fassign);
    return left = left * right;
}

COVERAGE(mul_v3fassign, 1)
static inline Vec3 &operator*=(Vec3 &left, float right)
{
    ASSERT_COVERED(mul_v3fassign);
    return left = left * right;
}

COVERAGE(mul_v4fassign, 1)
static inline Vec4 &operator*=(Vec4 &left, float right)
{
    ASSERT_COVERED(mul_v4fassign);
    return left = left * right;
}

COVERAGE(mul_m2fassign, 1)
static inline Mat2 &operator*=(Mat2 &left, float right)
{
    ASSERT_COVERED(mul_m2fassign);
    return left = left * right;
}

COVERAGE(mul_m3fassign, 1)
static inline Mat3 &operator*=(Mat3 &left, float right)
{
    ASSERT_COVERED(mul_m3fassign);
    return left = left * right;
}

COVERAGE(mul_m4fassign, 1)
static inline Mat4 &operator*=(Mat4 &left, float right)
{
    ASSERT_COVERED(mul_m4fassign);
    return left = left * right;
}

COVERAGE(mul_qfassign, 1)
static inline Quat &operator*=(Quat &left, float right)
{
    ASSERT_COVERED(mul_qfassign);
    return left = left * right;
}

COVERAGE(div_v2assign, 1)
static inline Vec2 &operator/=(Vec2 &left, Vec2 right)
{
    ASSERT_COVERED(div_v2assign);
    return left = left / right;
}

COVERAGE(div_v3assign, 1)
static inline Vec3 &operator/=(Vec3 &left, Vec3 right)
{
    ASSERT_COVERED(div_v3assign);
    return left = left / right;
}

COVERAGE(div_v4assign, 1)
static inline Vec4 &operator/=(Vec4 &left, Vec4 right)
{
    ASSERT_COVERED(div_v4assign);
    return left = left / right;
}

COVERAGE(div_v2fassign, 1)
static inline Vec2 &operator/=(Vec2 &left, float right)
{
    ASSERT_COVERED(div_v2fassign);
    return left = left / right;
}

COVERAGE(div_v3fassign, 1)
static inline Vec3 &operator/=(Vec3 &left, float right)
{
    ASSERT_COVERED(div_v3fassign);
    return left = left / right;
}

COVERAGE(div_v4fassign, 1)
static inline Vec4 &operator/=(Vec4 &left, float right)
{
    ASSERT_COVERED(div_v4fassign);
    return left = left / right;
}

COVERAGE(div_m4fassign, 1)
static inline Mat4 &operator/=(Mat4 &left, float right)
{
    ASSERT_COVERED(div_m4fassign);
    return left = left / right;
}

COVERAGE(div_qfassign, 1)
static inline Quat &operator/=(Quat &left, float right)
{
    ASSERT_COVERED(div_qfassign);
    return left = left / right;
}

COVERAGE(eq_v2op, 1)
static inline Bool operator==(Vec2 left, Vec2 right)
{
    ASSERT_COVERED(eq_v2op);
    return eq_v2(left, right);
}

COVERAGE(eq_v3op, 1)
static inline Bool operator==(Vec3 left, Vec3 right)
{
    ASSERT_COVERED(eq_v3op);
    return eq_v3(left, right);
}

COVERAGE(eq_v4op, 1)
static inline Bool operator==(Vec4 left, Vec4 right)
{
    ASSERT_COVERED(eq_v4op);
    return eq_v4(left, right);
}

COVERAGE(eq_v2opnot, 1)
static inline Bool operator!=(Vec2 left, Vec2 right)
{
    ASSERT_COVERED(eq_v2opnot);
    return !eq_v2(left, right);
}

COVERAGE(eq_v3opnot, 1)
static inline Bool operator!=(Vec3 left, Vec3 right)
{
    ASSERT_COVERED(eq_v3opnot);
    return !eq_v3(left, right);
}

COVERAGE(eq_v4opnot, 1)
static inline Bool operator!=(Vec4 left, Vec4 right)
{
    ASSERT_COVERED(eq_v4opnot);
    return !eq_v4(left, right);
}

COVERAGE(UnaryMinusV2, 1)
static inline Vec2 operator-(Vec2 In)
{
    ASSERT_COVERED(UnaryMinusV2);

    Vec2 Result;
    Result.x = -In.x;
    Result.y = -In.y;

    return Result;
}

COVERAGE(UnaryMinusV3, 1)
static inline Vec3 operator-(Vec3 In)
{
    ASSERT_COVERED(UnaryMinusV3);

    Vec3 Result;
    Result.x = -In.x;
    Result.y = -In.y;
    Result.z = -In.z;

    return Result;
}

COVERAGE(UnaryMinusV4, 1)
static inline Vec4 operator-(Vec4 In)
{
    ASSERT_COVERED(UnaryMinusV4);

    Vec4 Result;
#if HANDMADE_MATH__USE_SSE
    Result.SSE = _mm_xor_ps(In.SSE, _mm_set1_ps(-0.0f));
#else
    Result.x = -In.x;
    Result.y = -In.y;
    Result.z = -In.z;
    Result.w = -In.w;
#endif

    return Result;
}

#endif /* __cplusplus*/

#ifdef HANDMADE_MATH__USE_C11_GENERICS
#define add(A, b) _Generic((A), \
        Vec2: add_v2, \
        Vec3: add_v3, \
        Vec4: add_v4, \
        Mat2: add_m2, \
        Mat3: add_m3, \
        Mat4: add_m4, \
        Quat: add_q \
)(A, b)

#define sub(A, b) _Generic((A), \
        Vec2: sub_v2, \
        Vec3: sub_v3, \
        Vec4: sub_v4, \
        Mat2: sub_m2, \
        Mat3: sub_m3, \
        Mat4: sub_m4, \
        Quat: sub_q \
)(A, b)

#define mul(A, b) _Generic((b), \
     float: _Generic((A), \
        Vec2: mul_v2f, \
        Vec3: mul_v3f, \
        Vec4: mul_v4f, \
        Mat2: mul_m2f, \
        Mat3: mul_m3f, \
        Mat4: mul_m4f, \
        Quat: mul_qf \
     ), \
     Mat2: mul_m2, \
     Mat3: mul_m3, \
     Mat4: mul_m4, \
     Quat: mul_q, \
     default: _Generic((A), \
        Vec2: mul_v2, \
        Vec3: mul_v3, \
        Vec4: mul_v4, \
        Mat2: mul_m2v2, \
        Mat3: mul_m3v3, \
        Mat4: mul_m4v4 \
    ) \
)(A, b)

#define div(A, b) _Generic((b), \
     float: _Generic((A), \
        Mat2: div_m2f, \
        Mat3: div_m3f, \
        Mat4: div_m4f, \
        Vec2: div_v2f, \
        Vec3: div_v3f, \
        Vec4: div_v4f, \
        Quat: div_qf  \
     ), \
     Mat2: div_m2, \
     Mat3: div_m3, \
     Mat4: div_m4, \
     Quat: div_q, \
     default: _Generic((A), \
        Vec2: div_v2, \
        Vec3: div_v3, \
        Vec4: div_v4  \
    ) \
)(A, b)

#define len(A) _Generic((A), \
        Vec2: len_v2, \
        Vec3: len_v3, \
        Vec4: len_v4  \
)(A)

#define len_sqr(A) _Generic((A), \
        Vec2: len_sqrv2, \
        Vec3: len_sqrv3, \
        Vec4: len_sqrv4  \
)(A)

#define norm(A) _Generic((A), \
        Vec2: norm_v2, \
        Vec3: norm_v3, \
        Vec4: norm_v4  \
)(A)

#define dot(A, b) _Generic((A), \
        Vec2: dot_v2, \
        Vec3: dot_v3, \
        Vec4: dot_v4  \
)(A, b)

#define lerp(A, T, b) _Generic((A), \
        float: lerp, \
        Vec2: lerp_v2, \
        Vec3: lerp_v3, \
        Vec4: lerp_v4 \
)(A, T, b)

#define eq(A, b) _Generic((A), \
        Vec2: eq_v2, \
        Vec3: eq_v3, \
        Vec4: eq_v4  \
)(A, b)

#define transpose(M) _Generic((M), \
        Mat2: transpose_m2, \
        Mat3: transpose_m3, \
        Mat4: transpose_m4  \
)(M)

#define determinant(M) _Generic((M), \
        Mat2: determinant_m2, \
        Mat3: determinant_m3, \
        Mat4: determinant_m4  \
)(M)

#define invgeneral(M) _Generic((M), \
        Mat2: invgeneral_m2, \
        Mat3: invgeneral_m3, \
        Mat4: invgeneral_m4  \
)(M)

#endif

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic pop
#endif

#endif /* HANDMADE_MATH_H */



